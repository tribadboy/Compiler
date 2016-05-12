#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "type.h"
#include "ir.h"

#define MAX_CODE_LINE 400

static InterCode *codes[MAX_CODE_LINE];
static int sum = 0;
char allCodes[8000] = "";

void deleteCode(int i) {
	if(i < 0 || i >= sum) {
		printf("error, the index of code cannot delete\n");
		return;
	}
	for(int j = i;j < sum - 1; j++) {
		codes[j] = codes[j+1];
	}
	codes[sum-1] = NULL;
	sum--;
}

void simplyInterCode() {
}

void insertInterCode(InterCode *interCode) {
	if(sum >= MAX_CODE_LINE) {
		printf("error, the line of code is over the limit\n");
		translateFlag = 0;
		return;
	}
	codes[sum] = interCode;
	sum++;
}

static void writeOperand(Operand *o) {
	char s[16];
	if(o->kind == VARIABLE) {
		sprintf(s,"v%d",(o->u).var_no);
		strcat(allCodes,s);
	}
	else if(o->kind == CONSTANT) {
		sprintf(s,"#%d",(o->u).value);
		strcat(allCodes,s);
	}
	else if(o->kind == TEMP) {
		sprintf(s,"t%d",(o->u).temp_no);
		strcat(allCodes,s);
	}
	else if(o->kind == ADDRESS) {
		strcat(allCodes,"&");
		writeOperand((o->u).operand_address);
	}
	else if(o->kind == POINTER) {
		strcat(allCodes,"*");
		writeOperand((o->u).operand_pointer);
	}
	else {
		printf("error,cannot write operand(error kind)\n");
		translateFlag = 0;
	}
}

void writeInterCode() {
	InterCode *temp;
	for(int i = 0; i < sum; i++) {
		temp = codes[i];
		if(temp->kind == ASSIGN) {
			writeOperand((temp->u).assign.left);
			strcat(allCodes," := ");
			writeOperand((temp->u).assign.right);
			strcat(allCodes,"\n");
		}
		else if(temp->kind == ADD) {
			writeOperand((temp->u).binop.result);
			strcat(allCodes," := ");
			writeOperand((temp->u).binop.op1);
			strcat(allCodes," + ");
			writeOperand((temp->u).binop.op2);
			strcat(allCodes,"\n");
		}
		else if(temp->kind == SUB) {
			writeOperand((temp->u).binop.result);
			strcat(allCodes," := ");
			writeOperand((temp->u).binop.op1);
			strcat(allCodes," - ");
			writeOperand((temp->u).binop.op2);
			strcat(allCodes,"\n");
		}
		else if(temp->kind == MUL) {
			writeOperand((temp->u).binop.result);
			strcat(allCodes," := ");
			writeOperand((temp->u).binop.op1);
			strcat(allCodes," * ");
			writeOperand((temp->u).binop.op2);
			strcat(allCodes,"\n");
		}
		else if(temp->kind == DIV) {
			writeOperand((temp->u).binop.result);
			strcat(allCodes," := ");
			writeOperand((temp->u).binop.op1);
			strcat(allCodes," / ");
			writeOperand((temp->u).binop.op2);
			strcat(allCodes,"\n");
		}
		else if(temp->kind == LABEL) {
			char s[20];
			sprintf(s,"LABEL label%d :\n",(temp->u).label_flag.label_no);
			strcat(allCodes,s);
		}
		else if(temp->kind == FUNCTION) {
			strcat(allCodes,"FUNCTION ");
			strcat(allCodes,(temp->u).func_flag.func_name);
			strcat(allCodes," :\n");
		}
		else if(temp->kind == GOTO) {
			char s[20];
			sprintf(s,"GOTO label%d\n",(temp->u).goto_flag.goto_no);
			strcat(allCodes,s);
		}
		else if(temp->kind == IF) {
			strcat(allCodes,"IF ");
			writeOperand((temp->u).if_flag.left);
			strcat(allCodes," ");
			strcat(allCodes,(temp->u).if_flag.rel_token);
			strcat(allCodes," ");
			writeOperand((temp->u).if_flag.right);
			char s[20];
			sprintf(s," GOTO label%d\n",(temp->u).if_flag.no);
			strcat(allCodes,s);
		}
		else if(temp->kind == RETURN) {
			strcat(allCodes,"RETURN ");
			writeOperand((temp->u).return_flag.result);
			strcat(allCodes,"\n");
		}
		else if(temp->kind == DEC) {
			strcat(allCodes,"DEC ");
			writeOperand((temp->u).dec_flag.pos);
			char s[20];
			sprintf(s," %d\n",(temp->u).dec_flag.size);
			strcat(allCodes,s);
		}
		else if(temp->kind == ARG) {
			strcat(allCodes,"ARG ");
			writeOperand((temp->u).arg_flag.arg);
			strcat(allCodes,"\n");
		}
		else if(temp->kind == CALL) {
			writeOperand((temp->u).call_flag.result);
			strcat(allCodes," := CALL ");
			strcat(allCodes,(temp->u).call_flag.func_name);
			strcat(allCodes,"\n");
		}
		else if(temp->kind == PARAM) {
			strcat(allCodes,"PARAM ");
			writeOperand((temp->u).param_flag.param);
			strcat(allCodes,"\n");
		}
		else if(temp->kind == READ) {
			strcat(allCodes,"READ ");
			writeOperand((temp->u).read_flag.operand);
			strcat(allCodes,"\n");
		}
		else if(temp->kind == WRITE) {
			strcat(allCodes,"WRITE ");
			writeOperand((temp->u).write_flag.operand);
			strcat(allCodes,"\n");
		}
		else {
			printf("error, cannot write intercode(kind error)\n");
			translateFlag = 0;
		}
	}
}

// apple an area to set an operand
Operand *getAndSetOperand_VARIABLE(int var_no) {
	OperandNode *onode = getOperandNode();
	Operand *o = &(onode->operand);
	o->kind = VARIABLE;
	(o->u).var_no = var_no;
	return o;
}

Operand *getAndSetOperand_CONSTANT(int value) {
	OperandNode *onode = getOperandNode();
	Operand *o = &(onode->operand);
	o->kind = CONSTANT;
	(o->u).value = value;
	return o;
}

Operand *getAndSetOperand_TEMP(int temp_no) {
	OperandNode *onode = getOperandNode();
	Operand *o = &(onode->operand);
	o->kind = TEMP;
	(o->u).temp_no = temp_no;
	return o;
}

Operand *getAndSetOperand_ADDRESS(Operand *operand_address) {
	OperandNode *onode = getOperandNode();
	Operand *o = &(onode->operand);
	o->kind = ADDRESS;
	(o->u).operand_address = operand_address;
	return o;
}

Operand *getAndSetOperand_POINTER(Operand *operand_pointer) {
	OperandNode *onode = getOperandNode();
	Operand *o = &(onode->operand);
	o->kind = POINTER;
	(o->u).operand_pointer = operand_pointer;
	return o;
}

// interCode
// apply an area to set an interCode
InterCode *getAndSetInterCode_ASSIGN(Operand *left, Operand *right) {
	InterCodeNode *inode = getInterCodeNode();
	InterCode *i = &(inode->interCode);
	i->kind = ASSIGN;
	(i->u).assign.left = left;
	(i->u).assign.right = right;
	return i;
}

InterCode *getAndSetInterCode_ADD(Operand *result, Operand *op1, Operand *op2) {
	InterCodeNode *inode = getInterCodeNode();
	InterCode *i = &(inode->interCode);
	i->kind = ADD;
	(i->u).binop.result = result;
	(i->u).binop.op1 = op1;
	(i->u).binop.op2 = op2;
	return i;
}

InterCode *getAndSetInterCode_SUB(Operand *result, Operand *op1, Operand *op2) {
	InterCodeNode *inode = getInterCodeNode();
	InterCode *i = &(inode->interCode);
	i->kind = SUB;
	(i->u).binop.result = result;
	(i->u).binop.op1 = op1;
	(i->u).binop.op2 = op2;
	return i;
}

InterCode *getAndSetInterCode_MUL(Operand *result, Operand *op1, Operand *op2) {
	InterCodeNode *inode = getInterCodeNode();
	InterCode *i = &(inode->interCode);
	i->kind = MUL;
	(i->u).binop.result = result;
	(i->u).binop.op1 = op1;
	(i->u).binop.op2 = op2;
	return i;
}

InterCode *getAndSetInterCode_DIV(Operand *result, Operand *op1, Operand *op2) {
	InterCodeNode *inode = getInterCodeNode();
	InterCode *i = &(inode->interCode);
	i->kind = DIV;
	(i->u).binop.result = result;
	(i->u).binop.op1 = op1;
	(i->u).binop.op2 = op2;
	return i;
}

InterCode *getAndSetInterCode_LABEL(int label_no) {
	InterCodeNode *inode = getInterCodeNode();
	InterCode *i = &(inode->interCode);
	i->kind = LABEL;
	(i->u).label_flag.label_no = label_no;
	return i;
}

InterCode *getAndSetInterCode_FUNCTION(char *func_name) {
	InterCodeNode *inode = getInterCodeNode();
	InterCode *i = &(inode->interCode);
	i->kind = FUNCTION;
	(i->u).func_flag.func_name = func_name;
	return i;
}

InterCode *getAndSetInterCode_GOTO(int goto_no) {
	InterCodeNode *inode = getInterCodeNode();
	InterCode *i = &(inode->interCode);
	i->kind = GOTO;
	(i->u).goto_flag.goto_no = goto_no;
	return i;
}

InterCode *getAndSetInterCode_IF(Operand *left, Operand *right, char *rel_token, int no) {
	InterCodeNode *inode = getInterCodeNode();
	InterCode *i = &(inode->interCode);
	i->kind = IF;
	(i->u).if_flag.left = left;
	(i->u).if_flag.right = right;
	(i->u).if_flag.rel_token = rel_token;
	(i->u).if_flag.no = no;
	return i;
}

InterCode *getAndSetInterCode_RETURN(Operand *result) {
	InterCodeNode *inode = getInterCodeNode();
	InterCode *i = &(inode->interCode);
	i->kind = RETURN;
	(i->u).return_flag.result = result;
	return i;
}

InterCode *getAndSetInterCode_DEC(Operand *pos, int size) {
	InterCodeNode *inode = getInterCodeNode();
	InterCode *i = &(inode->interCode);
	i->kind = DEC;
	(i->u).dec_flag.pos = pos;
	(i->u).dec_flag.size = size;
	return i;
}

InterCode *getAndSetInterCode_ARG(Operand *arg) {
	InterCodeNode *inode = getInterCodeNode();
	InterCode *i = &(inode->interCode);
	i->kind = ARG;
	(i->u).arg_flag.arg = arg;
	return i;
}

InterCode *getAndSetInterCode_CALL(Operand *result, char *func_name) {
	InterCodeNode *inode = getInterCodeNode();
	InterCode *i = &(inode->interCode);
	i->kind = CALL;
	(i->u).call_flag.result = result;
	(i->u).call_flag.func_name = func_name;
	return i;
}

InterCode *getAndSetInterCode_PARAM(Operand *param) {
	InterCodeNode *inode = getInterCodeNode();
	InterCode *i = &(inode->interCode);
	i->kind = PARAM;
	(i->u).param_flag.param = param;
	return i;
}

InterCode *getAndSetInterCode_READ(Operand *operand) {
	InterCodeNode *inode = getInterCodeNode();
	InterCode *i = &(inode->interCode);
	i->kind = READ;
	(i->u).read_flag.operand = operand;
	return i;
}

InterCode *getAndSetInterCode_WRITE(Operand *operand) {
	InterCodeNode *inode = getInterCodeNode();
	InterCode *i = &(inode->interCode);
	i->kind = WRITE;
	(i->u).write_flag.operand = operand;
	return i;
}
