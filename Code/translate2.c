#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "type.h"
#include "semantic.h"
#include "ir.h"

static int label_no = 0;
static int temp_no = 0;

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
		if(rootTypeFlag == 1) {
			printf("variables of structure or array cannot assign directly\n");
			translateFlag = 0;
			return;
		}
		int temp_no = new_temp();
		Operand *temp = getAndSetOperand_TEMP(temp_no);
		CSNode *exp1Node = root->firstChild;
		CSNode *exp2Node = exp1Node->nextSibling->nextSibling;
		if(isProduction_1(exp1Node,MyEXP,MyID) == 1) {
			translateExp(exp2Node,temp);
			CSNode *idNode = exp1Node->firstChild;
			char *name = (idNode->type_union).type_id.p_str;
			SYNode *checkFlag = checkSymbolName(0,name);
			int var_no = checkFlag->var_no;
			Operand *v = getAndSetOperand_VARIABLE(var_no);
			InterCode *ic = getAndSetInterCode_ASSIGN(v,temp);
			insertInterCode(ic);
			if(place == NULL) {
				return;
			}
			else {
				InterCode *ic2 = getAndSetInterCode_ASSIGN(place,v);
				insertInterCode(ic2);
			}
		}
		else if(isProduction_4(exp1Node,MyEXP,MyEXP,MyLB,MyEXP,MyRB) == 1) {
			CSNode *exp11Node = exp1Node->firstChild;
			CSNode *exp12Node = exp11Node->nextSibling->nextSibling;
			SpecialType *type = NULL;
			type = handleExp(exp11Node);
			if(type == NULL || type->kind != ARRAY) {
				printf("error, variable or the element is not array type\n");
				translateFlag = 0;
				return;
			}
			int gap = (type->u).array.elem->size;
			int temp1_no = new_temp();
			int temp2_no = new_temp();
			Operand *temp1 = getAndSetOperand_TEMP(temp1_no);
			Operand *temp2 = getAndSetOperand_TEMP(temp2_no);
			translateExp(exp11Node,temp1);
			translateExp(exp12Node,temp2);
			Operand *op_gap = getAndSetOperand_CONSTANT(gap);
			int temp3_no = new_temp();
			Operand *op_allgap = getAndSetOperand_TEMP(temp3_no);
			InterCode *ic1 = getAndSetInterCode_MUL(op_allgap,temp2,op_gap);
			insertInterCode(ic1);
			int temp4_no = new_temp();
			Operand *pos = getAndSetOperand_TEMP(temp4_no);
			InterCode *ic2 = getAndSetInterCode_ADD(pos,temp1,op_allgap);
			insertInterCode(ic2);
			translateExp(exp2Node,temp);
			Operand *pos_v = getAndSetOperand_POINTER(pos);
			InterCode *ic3 = getAndSetInterCode_ASSIGN(pos_v,temp);
			insertInterCode(ic3);
			if(place == NULL) {
				return;
			}
			else {
				InterCode *ic4 = getAndSetInterCode_ASSIGN(place,pos_v);
				insertInterCode(ic4);
			}
		}
		else if(isProduction_3(exp1Node,MyEXP,MyEXP,MyDOT,MyID) == 1) {
			CSNode *exp11Node = exp1Node->firstChild;
			CSNode *idNode = exp11Node->nextSibling->nextSibling;
			SpecialType *type = NULL;
			type = handleExp(exp11Node);
			if(type == NULL || type->kind != STRUCTURE) {
				printf("error, type is not a structure\n");
				translateFlag = 0;
				return;
			}
			int temp1_no = new_temp();
			Operand *temp1 = getAndSetOperand_TEMP(temp1_no);
			translateExp(exp11Node,temp1);
			FieldList *fd = (type->u).structure;
			int gap = 0;
			char *id_name = (idNode->type_union).type_id.p_str;
			while(fd != NULL) {
				if(strcmp(fd->name,id_name) == 0) {
					break;
				}
				int add = fd->type->size;
				gap += add;
				fd = fd->tail;
			}
			int temp3_no = new_temp();
			Operand *pos = getAndSetOperand_TEMP(temp3_no);
			if(gap == 0) {
				InterCode *ic = getAndSetInterCode_ASSIGN(pos,temp1);
				insertInterCode(ic);
			}
			else {
				Operand *op_gap = getAndSetOperand_CONSTANT(gap);
				InterCode *ic = getAndSetInterCode_ADD(pos,temp1,op_gap);
				insertInterCode(ic);
			}
			translateExp(exp2Node,temp);
			Operand *pos_v = getAndSetOperand_POINTER(pos);
			InterCode *ic3 = getAndSetInterCode_ASSIGN(pos_v,temp);
			insertInterCode(ic3);
			if(place == NULL) {
				return;
			}
			else {
				InterCode *ic4 = getAndSetInterCode_ASSIGN(place,pos_v);
				insertInterCode(ic4);
			}
		}
		else {
			printf("error left value\n");
			translateFlag = 0;
		}
	}
	else if(isProduction_3(root,MyEXP,MyEXP,MyAND,MyEXP) == 1 ||
		isProduction_3(root,MyEXP,MyEXP,MyOR,MyEXP) == 1  ||
		isProduction_3(root,MyEXP,MyEXP,MyRELOP,MyEXP) == 1 ||
		isProduction_2(root,MyEXP,MyNOT,MyEXP) == 1) {
		if(rootTypeFlag == 1) {
			printf("root type should be integer\n");
			translateFlag = 0;
			return;
		}
		int label1_no = new_label();
		int label2_no = new_label();
		if(place != NULL) {
			Operand *zero = getAndSetOperand_CONSTANT(0);
			InterCode *ic0 = getAndSetInterCode_ASSIGN(place,zero);
			insertInterCode(ic0);
			translateCondExp(root,label1_no,label2_no);
			InterCode *ic1 = getAndSetInterCode_LABEL(label1_no);
			insertInterCode(ic1);
			Operand *one = getAndSetOperand_CONSTANT(1);
			InterCode *ic2 = getAndSetInterCode_ASSIGN(place,one);
			insertInterCode(ic2);
			InterCode *ic3 = getAndSetInterCode_LABEL(label2_no);
			insertInterCode(ic3);
		}
		else {
			translateCondExp(root,label1_no,label2_no);
			InterCode *ic2 = getAndSetInterCode_LABEL(label1_no);
			insertInterCode(ic2);
			InterCode *ic3 = getAndSetInterCode_LABEL(label2_no);
			insertInterCode(ic3);
		}
	}
	else if(isProduction_3(root,MyEXP,MyEXP,MyPLUS,MyEXP) == 1) {
		if(rootTypeFlag == 1) {
			printf("variables of structure or array cannot add directy\n");
			translateFlag = 0;
			return;
		}
		int temp1_no = new_temp();
		int temp2_no = new_temp();
		Operand *t1 = getAndSetOperand_TEMP(temp1_no);
		Operand *t2 = getAndSetOperand_TEMP(temp2_no);
		CSNode *expNode1 = root->firstChild;
		CSNode *expNode2 = expNode1->nextSibling->nextSibling;
		translateExp(expNode1,t1);
		translateExp(expNode2,t2);
		if(place == NULL) {
			return;
		}
		InterCode *ic = getAndSetInterCode_ADD(place,t1,t2);
		insertInterCode(ic);
	}
	else if(isProduction_3(root,MyEXP,MyEXP,MyMINUS,MyEXP) == 1) {
		if(rootTypeFlag == 1) {
			printf("variables of structure or array cannot sub directly\n");
			translateFlag = 0;
			return;
		}
		int temp1_no = new_temp();
		int temp2_no = new_temp();
		Operand *t1 = getAndSetOperand_TEMP(temp1_no);
		Operand *t2 = getAndSetOperand_TEMP(temp2_no);
		CSNode *expNode1 = root->firstChild;
		CSNode *expNode2 = expNode1->nextSibling->nextSibling;
		translateExp(expNode1,t1);
		translateExp(expNode2,t2);
		if(place == NULL) {
			return;
		}
		InterCode *ic = getAndSetInterCode_SUB(place,t1,t2);
		insertInterCode(ic);
	}
	else if(isProduction_3(root,MyEXP,MyEXP,MySTAR,MyEXP) == 1) {
		if(rootTypeFlag == 1) {
			printf("variabls of structure or array cannot star directly\n");
			translateFlag = 0;
			return;
		}
		int temp1_no = new_temp();
		int temp2_no = new_temp();
		Operand *t1 = getAndSetOperand_TEMP(temp1_no);
		Operand *t2 = getAndSetOperand_TEMP(temp2_no);
		CSNode *expNode1 = root->firstChild;
		CSNode *expNode2 = expNode1->nextSibling->nextSibling;
		translateExp(expNode1,t1);
		translateExp(expNode2,t2);
		if(place == NULL) {
			return;
		}
		InterCode *ic = getAndSetInterCode_MUL(place,t1,t2);
		insertInterCode(ic);
	}
	else if(isProduction_3(root,MyEXP,MyEXP,MyDIV,MyEXP) == 1) {
		if(rootTypeFlag == 1) {
			printf("variables of structure or array cannot div directly\n");
			translateFlag = 0;
			return;
		}
		int temp1_no = new_temp();
		int temp2_no = new_temp();
		Operand *t1 = getAndSetOperand_TEMP(temp1_no);
		Operand *t2 = getAndSetOperand_TEMP(temp2_no);
		CSNode *expNode1 = root->firstChild;
		CSNode *expNode2 = expNode1->nextSibling->nextSibling;
		translateExp(expNode1,t1);
		translateExp(expNode2,t2);
		if(place == NULL) {
			return;
		}
		InterCode *ic = getAndSetInterCode_DIV(place,t1,t2);
		insertInterCode(ic);
	}
	else if(isProduction_3(root,MyEXP,MyLP,MyEXP,MyRP) == 1) {
		CSNode *expNode = root->firstChild->nextSibling;
		translateExp(expNode,place);
	}
	else if(isProduction_2(root,MyEXP,MyMINUS,MyEXP) == 1) {
		if(rootTypeFlag == 1) {
			printf("variables of structure or array cannot follow minus\n");
			translateFlag = 0;
			return;
		}
		int temp_no = new_temp();
		Operand *temp = getAndSetOperand_TEMP(temp_no);
		CSNode *expNode = root->firstChild->nextSibling;
		translateExp(expNode,temp);
		if(place == NULL) {
			return;
		}
		Operand *zero = getAndSetOperand_CONSTANT(0);
		InterCode *ic = getAndSetInterCode_SUB(place,zero,temp);
		insertInterCode(ic);
	}
	else if(isProduction_4(root,MyEXP,MyID,MyLP,MyARGS,MyRP) == 1) {
		if(rootTypeFlag == 1) {
			printf("function cannot return variables of structure or array\n");
			translateFlag = 0;
			return;
		}
		if(place == NULL) {
			int temp_no = new_temp();
			place = getAndSetOperand_TEMP(temp_no);
		}
		int emptyFlag = 0;
		char *name = (root->firstChild->type_union).type_id.p_str;
		SYNode *checkFlag = NULL;
		checkFlag = checkSymbolName(emptyFlag,name);
		if(checkFlag == NULL) {
			printf("error, not find symbol in the symbol table\n");
			translateFlag = 0;
			return;
		}
		ArgList *head = NULL;
		CSNode *argNode = root->firstChild->nextSibling->nextSibling;
		translateArgs(argNode,&head);
		if(strcmp(checkFlag->name,"write") == 0) {
			InterCode *ic = getAndSetInterCode_WRITE(head->operand);
			insertInterCode(ic);
		}
		else {
			ArgList *temp = head;
			while(temp != NULL) {
				InterCode *ic = getAndSetInterCode_ARG(temp->operand);
				insertInterCode(ic);
				temp = temp->next;
			}
			InterCode *ic2 = getAndSetInterCode_CALL(place,checkFlag->name);
			insertInterCode(ic2);
		}
	}
	else if(isProduction_3(root,MyEXP,MyID,MyLP,MyRP) == 1) {
		if(rootTypeFlag == 1) {
			printf("function cannot return variables of structure or array\n");
			translateFlag = 0;
			return;
		}
		if(place == NULL) {
			int temp_no = new_temp();
			place = getAndSetOperand_TEMP(temp_no);
		}
		int emptyFlag = 0;
		char *name = (root->firstChild->type_union).type_id.p_str;
		SYNode *checkFlag = NULL;
		checkFlag = checkSymbolName(emptyFlag,name);
		if(checkFlag == NULL) {
			printf("error, not find symbol in the symbol table\n");
			translateFlag = 0;
			return;
		}
		if(strcmp(checkFlag->name,"read") == 0) {
			InterCode *ic = getAndSetInterCode_READ(place);
			insertInterCode(ic);
		}
		else {
			InterCode *ic = getAndSetInterCode_CALL(place,checkFlag->name);
			insertInterCode(ic);
		}
	}
	else if(isProduction_4(root,MyEXP,MyEXP,MyLB,MyEXP,MyRB) == 1) {
		CSNode *exp1Node = root->firstChild;
		CSNode *exp2Node = exp1Node->nextSibling->nextSibling;
		SpecialType *type = NULL;
		type = handleExp(exp1Node);
		if(type == NULL || type->kind != ARRAY) {
			printf("error, variable or the element is not array type\n");
			translateFlag = 0;
			return;
		}
		int gap = (type->u).array.elem->size;
		int temp1_no = new_temp();
		int temp2_no = new_temp();
		Operand *temp1 = getAndSetOperand_TEMP(temp1_no);
		Operand *temp2 = getAndSetOperand_TEMP(temp2_no);
		translateExp(exp1Node,temp1);
		translateExp(exp2Node,temp2);
		Operand *op_gap = getAndSetOperand_CONSTANT(gap);
		int temp3_no = new_temp();
		Operand *op_allgap = getAndSetOperand_TEMP(temp3_no);
		InterCode *ic1 = getAndSetInterCode_MUL(op_allgap,temp2,op_gap);
		insertInterCode(ic1);
		int temp4_no = new_temp();
		Operand *pos = getAndSetOperand_TEMP(temp4_no);
		InterCode *ic2 = getAndSetInterCode_ADD(pos,temp1,op_allgap);
		insertInterCode(ic2);
		if(place == NULL) {
			return;
		}
		else {
			if(rootTypeFlag ==1) {
				InterCode *ic3 = getAndSetInterCode_ASSIGN(place,pos);
				insertInterCode(ic3);
			}
			else {
				Operand *pos_value = getAndSetOperand_POINTER(pos);
				InterCode *ic3 = getAndSetInterCode_ASSIGN(place,pos_value);
				insertInterCode(ic3);
			}
		}
	}
	else if(isProduction_3(root,MyEXP,MyEXP,MyDOT,MyID) == 1) {
		CSNode *expNode = root->firstChild;
		CSNode *idNode = expNode->nextSibling->nextSibling;
		SpecialType *type = NULL;
		type = handleExp(expNode);
		if(type == NULL || type->kind != STRUCTURE) {
			printf("error, type is not a structure\n");
			translateFlag = 0;
			return;
		}
		int temp1_no = new_temp();
		Operand *temp1 = getAndSetOperand_TEMP(temp1_no);
		translateExp(expNode,temp1);
		FieldList *fd = (type->u).structure;
		int gap = 0;
		char *id_name = (idNode->type_union).type_id.p_str;
		while(fd != NULL) {
			if(strcmp(fd->name,id_name) == 0) {
				break;
			}
			int add = fd->type->size;
			gap += add;
			fd = fd->tail;
		}
		if(place == NULL) {
			return;
		}
		if(rootTypeFlag == 1) {
			if(gap == 0) {
				InterCode *ic = getAndSetInterCode_ASSIGN(place,temp1);
				insertInterCode(ic);
			}
			else {
				Operand *op_gap = getAndSetOperand_CONSTANT(gap);
				InterCode *ic = getAndSetInterCode_ADD(place,temp1,op_gap);
				insertInterCode(ic);
			}
		}
		else {
			if(gap == 0) {
				Operand *pos_value = getAndSetOperand_POINTER(temp1);
				InterCode *ic = getAndSetInterCode_ASSIGN(place,pos_value);
				insertInterCode(ic);
			}
			else {
				Operand *op_gap = getAndSetOperand_CONSTANT(gap);
				int temp_no = new_temp();
				Operand *temp = getAndSetOperand_TEMP(temp_no);
				InterCode *ic1 = getAndSetInterCode_ADD(temp,temp1,op_gap);
				insertInterCode(ic1);
				Operand *temp_v = getAndSetOperand_POINTER(temp);
				InterCode *ic2 = getAndSetInterCode_ASSIGN(place,temp_v);
				insertInterCode(ic2);
			}
		}
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
