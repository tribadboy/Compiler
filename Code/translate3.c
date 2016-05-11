#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "type.h"
#include "semantic.h"
#include "ir.h"

//translate   "Exp -> Exp Assign Exp"
void translateExp_1(CSNode *root, Operand *place, int rootTypeFlag){
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

//translate   "Exp -> Exp AND Exp | Exp OR Exp | Exp RELOP Exp | NOT Exp"
void translateExp_2(CSNode *root, Operand *place, int rootTypeFlag){
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

//translate   "Exp -> Exp PLUS Exp"
void translateExp_3(CSNode *root, Operand *place, int rootTypeFlag){
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

//translate   "Exp -> Exp MINUS Exp"
void translateExp_4(CSNode *root, Operand *place, int rootTypeFlag){
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

//translate   "Exp -> Exp STAR Exp"
void translateExp_5(CSNode *root, Operand *place, int rootTypeFlag){
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

//translate   "Exp -> Exp DIV Exp"
void translateExp_6(CSNode *root, Operand *place, int rootTypeFlag){
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

//translate   "Exp -> MINUS Exp"
void translateExp_7(CSNode *root, Operand *place, int rootTypeFlag){
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

//translate   "Exp -> ID LP Args RP"
void translateExp_8(CSNode *root, Operand *place, int rootTypeFlag){
	if(rootTypeFlag == 1) {
		printf("function cannot return variables of structure or array\n");
		translateFlag = 0;
		return;
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
		if(place == NULL) {
			return;
		}
		Operand *zero = getAndSetOperand_CONSTANT(0);
		InterCode *ic2 = getAndSetInterCode_ASSIGN(place,zero);
		insertInterCode(ic2);
	}
	else {
		ArgList *temp = head;
		while(temp != NULL) {
			InterCode *ic = getAndSetInterCode_ARG(temp->operand);
			insertInterCode(ic);
			temp = temp->next;
		}
		if(place == NULL) {
			int temp_no = new_temp();
			Operand *result = getAndSetOperand_TEMP(temp_no);
			InterCode *ic2 = getAndSetInterCode_CALL(result,checkFlag->name);
			insertInterCode(ic2);
			return;
		}
		InterCode *ic3 = getAndSetInterCode_CALL(place,checkFlag->name);
		insertInterCode(ic3);
	}
}

//translate   "Exp -> ID LP RP"
void translateExp_9(CSNode *root, Operand *place, int rootTypeFlag){
	if(rootTypeFlag == 1) {
		printf("function cannot return variables of structure or array\n");
		translateFlag = 0;
		return;
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
		if(place == NULL) {
			int temp_no = new_temp();
			Operand *result = getAndSetOperand_TEMP(temp_no);
			InterCode *ic = getAndSetInterCode_READ(result);
			insertInterCode(ic);
		}
		else {
			InterCode *ic = getAndSetInterCode_READ(place);
			insertInterCode(ic);
		}
	}
	else {
		if(place == NULL) {
			int temp_no = new_temp();
			Operand *result = getAndSetOperand_TEMP(temp_no);
			InterCode *ic = getAndSetInterCode_CALL(result,checkFlag->name);
			insertInterCode(ic);
		}
		else {
			InterCode *ic = getAndSetInterCode_CALL(place,checkFlag->name);
			insertInterCode(ic);
		}
	}
}

//translate   "Exp -> Exp LB Exp RB"
void translateExp_10(CSNode *root, Operand *place, int rootTypeFlag){
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
		if(rootTypeFlag == 1) {
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

//translate   "Exp -> Exp DOT ID"
void translateExp_11(CSNode *root, Operand *place, int rootTypeFlag){
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

