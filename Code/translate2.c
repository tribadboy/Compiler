#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "type.h"
#include "semantic.h"
#include "ir.h"

int label_no = 0;
int temp_no = 0;

static char REL_UNEQUAL[4] = "!=";

int new_label() {
	label_no++;
	return label_no;
}

int new_temp() {
	temp_no++;
	return temp_no;
}
	

//translate production " Stmt -> ...|... "
void translateStmt(CSNode *root) {
	if(isProduction_2(root,MySTMT,MyEXP,MySEMI) == 1) {
		translateExp(root->firstChild,NULL);
	}
	else if(isProduction_1(root,MySTMT,MyCOMPST) == 1) {
		translateCompSt(root->firstChild);
	}
	else if(isProduction_3(root,MySTMT,MyRETURN,MyEXP,MySEMI) == 1) {
		int temp_no = new_temp();
		Operand *place = getAndSetOperand_TEMP(temp_no);
		translateExp(root->firstChild->nextSibling,place);
		InterCode *interCode = getAndSetInterCode_RETURN(place);
		insertInterCode(interCode);
	}
	else if(isProduction_5(root,MySTMT,MyIF,MyLP,MyEXP,MyRP,MySTMT) == 1) {
		int label1_no = new_label();
		int label2_no = new_label();
		CSNode *expNode = root->firstChild->nextSibling->nextSibling;
		CSNode *stmtNode = expNode->nextSibling->nextSibling;
		translateCondExp(expNode,label1_no,label2_no);
		InterCode *ic1 = getAndSetInterCode_LABEL(label1_no);
		insertInterCode(ic1);
		translateStmt(stmtNode);
		InterCode *ic2 = getAndSetInterCode_LABEL(label2_no);
		insertInterCode(ic2);
	}
	else if(isProduction_7(root,MySTMT,MyIF,MyLP,MyEXP,MyRP,MySTMT,MyELSE,MySTMT) == 1) {
		int label1_no = new_label();
		int label2_no = new_label();
		int label3_no = new_label();
		CSNode *expNode = root->firstChild->nextSibling->nextSibling;
		CSNode *stmt1Node = expNode->nextSibling->nextSibling;
		CSNode *stmt2Node = stmt1Node->nextSibling->nextSibling;
		translateCondExp(expNode,label1_no,label2_no);
		InterCode *ic1 = getAndSetInterCode_LABEL(label1_no);
		insertInterCode(ic1);
		translateStmt(stmt1Node);
		InterCode *ic4 = getAndSetInterCode_GOTO(label3_no);
		insertInterCode(ic4);
		InterCode *ic2 = getAndSetInterCode_LABEL(label2_no);
		insertInterCode(ic2);
		translateStmt(stmt2Node);
		InterCode *ic3 = getAndSetInterCode_LABEL(label3_no);
		insertInterCode(ic3);
	}
	else if(isProduction_5(root,MySTMT,MyWHILE,MyLP,MyEXP,MyRP,MySTMT) == 1) {
		int label1_no = new_label();
		int label2_no = new_label();
		int label3_no = new_label();
		CSNode *expNode = root->firstChild->nextSibling->nextSibling;
		CSNode *stmtNode = expNode->nextSibling->nextSibling;
		InterCode *ic1 = getAndSetInterCode_LABEL(label1_no);
		insertInterCode(ic1);
		translateCondExp(expNode,label2_no,label3_no);
		InterCode *ic2 = getAndSetInterCode_LABEL(label2_no);
		insertInterCode(ic2);
		translateStmt(stmtNode);
		InterCode *ic4 = getAndSetInterCode_GOTO(label1_no);
		insertInterCode(ic4);
		InterCode *ic3 = getAndSetInterCode_LABEL(label3_no);
		insertInterCode(ic3);
	}
	else {
		printf("error Stmt production(translate)\n");
		translateFlag = 0;
	}
}

//translate production " Exp -> ...|... "
void translateExp(CSNode *root, Operand *place){
	int rootTypeFlag = 0;	// flag meaning struct or array
	SpecialType *rootType = NULL;
	rootType = handleExp(root);
	if(rootType == NULL) {
		printf("root type error(is null)\n");
		translateFlag = 0;
		return;
	}
	if(rootType->kind == STRUCTURE || rootType->kind == ARRAY) {
		rootTypeFlag = 1;
	}

	// case production
	if(isProduction_3(root,MyEXP,MyEXP,MyASSIGNOP,MyEXP) == 1) {

		translateExp_1(root,place,rootTypeFlag);
	}
	else if(isProduction_3(root,MyEXP,MyEXP,MyAND,MyEXP) == 1 ||
		isProduction_3(root,MyEXP,MyEXP,MyOR,MyEXP) == 1  ||
		isProduction_3(root,MyEXP,MyEXP,MyRELOP,MyEXP) == 1 ||
		isProduction_2(root,MyEXP,MyNOT,MyEXP) == 1) {

		translateExp_2(root,place,rootTypeFlag);
	}
	else if(isProduction_3(root,MyEXP,MyEXP,MyPLUS,MyEXP) == 1) {

		translateExp_3(root,place,rootTypeFlag);
	}
	else if(isProduction_3(root,MyEXP,MyEXP,MyMINUS,MyEXP) == 1) {
		
		translateExp_4(root,place,rootTypeFlag);
	}
	else if(isProduction_3(root,MyEXP,MyEXP,MySTAR,MyEXP) == 1) {
		
		translateExp_5(root,place,rootTypeFlag);
	}
	else if(isProduction_3(root,MyEXP,MyEXP,MyDIV,MyEXP) == 1) {
		
		translateExp_6(root,place,rootTypeFlag);
	}
	else if(isProduction_3(root,MyEXP,MyLP,MyEXP,MyRP) == 1) {
		CSNode *expNode = root->firstChild->nextSibling;
		translateExp(expNode,place);
	}
	else if(isProduction_2(root,MyEXP,MyMINUS,MyEXP) == 1) {
		
		translateExp_7(root,place,rootTypeFlag);
	}
	else if(isProduction_4(root,MyEXP,MyID,MyLP,MyARGS,MyRP) == 1) {
		
		translateExp_8(root,place,rootTypeFlag);
	}
	else if(isProduction_3(root,MyEXP,MyID,MyLP,MyRP) == 1) {
		
		translateExp_9(root,place,rootTypeFlag);
	}
	else if(isProduction_4(root,MyEXP,MyEXP,MyLB,MyEXP,MyRB) == 1) {
		
		translateExp_10(root,place,rootTypeFlag);
	}
	else if(isProduction_3(root,MyEXP,MyEXP,MyDOT,MyID) == 1) {
		
		translateExp_11(root,place,rootTypeFlag);
	}
	else if(isProduction_1(root,MyEXP,MyID) == 1) {
		int emptyFlag = 0;
		char *name = (root->firstChild->type_union).type_id.p_str;
		SYNode *checkFlag = NULL;
		checkFlag = checkSymbolName(emptyFlag,name);
		if(checkFlag == NULL) {
			printf("error, not find symbol in the symbol table\n");
			translateFlag = 0;
			return;
		}
		if(place == NULL) {
			return;
		}
		int var_no = checkFlag->var_no;
		if(var_no < 0) {	
			//DEC struct var or array var, get address
			var_no = -var_no;
			Operand *operand = getAndSetOperand_VARIABLE(var_no);
			Operand *op_addr = getAndSetOperand_ADDRESS(operand);
			InterCode *ic = getAndSetInterCode_ASSIGN(place,op_addr);
			insertInterCode(ic);
		}
		else {
			Operand *operand = getAndSetOperand_VARIABLE(var_no);
			InterCode *ic = getAndSetInterCode_ASSIGN(place,operand);
			insertInterCode(ic);
		}
	}
	else if(isProduction_1(root,MyEXP,MyINT) == 1) {
		if(place == NULL) {
			return;
		}
		int value = (root->firstChild->type_union).type_int.value;
		Operand *v = getAndSetOperand_CONSTANT(value);
		InterCode *ic = getAndSetInterCode_ASSIGN(place,v);
		insertInterCode(ic);
	}
	else if(isProduction_1(root,MyEXP,MyFLOAT) == 1) {
		printf("Cannot translate: Code contains variables of floating type.\n");
		translateFlag = 0;
	}
	else {
		printf("error Exp production(translate)\n");
		translateFlag = 0;
	}

}

//translate production Exp as Condition
void translateCondExp(CSNode *root, int true_no, int false_no) {
	if(isProduction_3(root,MyEXP,MyEXP,MyRELOP,MyEXP) == 1) {
		int temp1_no = new_temp();
		int temp2_no = new_temp();
		CSNode *exp1Node = root->firstChild;
		CSNode *relopNode = exp1Node->nextSibling;
		CSNode *exp2Node = relopNode->nextSibling;
		char *op = (relopNode->type_union).type_relop.token;
		Operand *t1 = getAndSetOperand_TEMP(temp1_no);
		Operand *t2 = getAndSetOperand_TEMP(temp2_no);
		translateExp(exp1Node,t1);
		translateExp(exp2Node,t2);
		InterCode *ic = getAndSetInterCode_IF(t1,t2,op,true_no);
		insertInterCode(ic);
		InterCode *ic2 = getAndSetInterCode_GOTO(false_no);
		insertInterCode(ic2);
	}
	else if(isProduction_2(root,MyEXP,MyNOT,MyEXP) == 1) {
		translateCondExp(root,false_no,true_no);
	}
	else if(isProduction_3(root,MyEXP,MyEXP,MyAND,MyEXP) == 1) {
		int label = new_label();
		CSNode *exp1Node = root->firstChild;
		CSNode *exp2Node = exp1Node->nextSibling->nextSibling;
		translateCondExp(exp1Node,label,false_no);
		InterCode *ic = getAndSetInterCode_LABEL(label);
		insertInterCode(ic);
		translateCondExp(exp2Node,true_no,false_no);
	}
	else if(isProduction_3(root,MyEXP,MyEXP,MyOR,MyEXP) == 1) {
		int label = new_label();
		CSNode *exp1Node = root->firstChild;
		CSNode *exp2Node = exp1Node->nextSibling->nextSibling;
		translateCondExp(exp1Node,true_no,label);
		InterCode *ic = getAndSetInterCode_LABEL(label);
		insertInterCode(ic);
		translateCondExp(exp2Node,true_no,false_no);
	}
	else {
		int temp_no = new_temp();
		Operand *temp = getAndSetOperand_TEMP(temp_no);
		translateExp(root,temp);
		Operand *op2 = getAndSetOperand_CONSTANT(0);
		InterCode *ic = getAndSetInterCode_IF(temp,op2,REL_UNEQUAL,true_no);
		insertInterCode(ic);
		InterCode *ic2 = getAndSetInterCode_GOTO(false_no);
		insertInterCode(ic2);
	}
	// error production not exists
}

//translate production " Args -> ...|... "
void translateArgs(CSNode *root, ArgList** head) {
	if(isProduction_3(root,MyARGS,MyEXP,MyCOMMA,MyARGS) == 1) {
		int temp_no = new_temp();
		Operand *temp = getAndSetOperand_TEMP(temp_no);
		translateExp(root->firstChild,temp);
		ArgList *head_temp = (*head);
		(*head) = (ArgList *)malloc(sizeof(ArgList));
		(*head)->operand = temp;
		(*head)->next = head_temp;
		CSNode *argNode = root->firstChild->nextSibling->nextSibling;
		translateArgs(argNode,head);

	}
	else if(isProduction_1(root,MyARGS,MyEXP) == 1) {
		int temp_no = new_temp();
		Operand *temp = getAndSetOperand_TEMP(temp_no);
		translateExp(root->firstChild,temp);
		ArgList *head_temp = (*head);
		(*head) = (ArgList *)malloc(sizeof(ArgList));
		(*head)->operand = temp;
		(*head)->next = head_temp;
	}
	else {
		printf("error Args production(translate)\n");
		translateFlag = 0;
	}
}
