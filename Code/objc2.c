#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "type.h"
#include "ir.h"
#include "objc.h"



void translateInterCode_ASSIGN(InterCode *ic, VarDesp *varDesp, int start, int end, int current) {
	//do sth
}

void translateInterCode_ADD(InterCode *ic, VarDesp *varDesp, int start, int end, int current) {
	//do sth
}

void translateInterCode_SUB(InterCode *ic, VarDesp *varDesp, int start, int end, int current) {
	//do sth
}

void translateInterCode_MUL(InterCode *ic, VarDesp *varDesp, int start, int end, int current) {
	//do sth
}

void translateInterCode_DIV(InterCode *ic, VarDesp *varDesp, int start, int end, int current) {
	//do sth
}

void translateInterCode_LABEL(InterCode *ic, VarDesp *varDesp, int start, int end, int current) {
	int label_no = (ic->u).label_flag.label_no;
	char code[20] = "";
	sprintf(code,"  label%d:\n",label_no);
	strcat(allObjCodes,code);
}

void translateInterCode_FUNCTION(InterCode *ic, VarDesp *varDesp, int start, int end, int current) {
	strcat(allObjCodes,"\n");
	//do sth
}

void translateInterCode_GOTO(InterCode *ic, VarDesp *varDesp ,int start, int end, int current) {
	int goto_no = (ic->u).goto_flag.goto_no;
	char code[20] = "";
	sprintf(code,"  j label%d\n",goto_no);
	strcat(allObjCodes,code);
}

void translateInterCode_IF(InterCode *ic, VarDesp *varDesp, int start, int end, int current) {
	//do sth
}

void translateInterCode_RETURN(InterCode *ic, VarDesp *varDesp, int start, int end, int current) {
	//do sth
}

void translateInterCode_DEC(InterCode *ic, VarDesp *varDesp, int start, int end, int current) {
	//do sth
}

void translateInterCode_ARG(InterCode *ic, VarDesp *varDesp, int start ,int end, int current) {
	//do sth
}

void translateInterCode_CALL(InterCode *ic, VarDesp *varDesp, int start, int end, int current) {
	//do sth
}

void translateInterCode_PARAM(InterCode *ic, VarDesp *varDesp, int start, int end, int current) {
	//do sth
}

void translateInterCode_READ(InterCode *ic, VarDesp *varDesp, int start, int end, int current) {
	//do sth
}

void translateInterCode_WRITE(InterCode *ic, VarDesp *varDesp, int start, int end, int current) {
	//do sth
}

//getReg for operand , just for  variable and temp ( v1 ,  t2)
//start ,end to basicBlock
int getReg(Operand *operand, VarDesp *varDesp, int start, int end, int current) {
	
	//if operand in reg, return reg index
	VarDesp *temp = varDesp;
	while(temp != NULL) {
		Operand *t_operand = temp->operand;
		if(operand->kind == t_operand->kind &&
			operand->kind == VARIABLE &&
			(operand->u).var_no == (t_operand->u).var_no) {
			for(int i = 0;i < 8; i++) {
				if(temp->reg[i] == true) {
					return i;
				}
			}
		}
		else if(operand->kind == t_operand->kind &&
			operand->kind == TEMP &&
			(operand->u).temp_no == (t_operand->u).temp_no) {
			for(int i = 0; i< 8; i++) {
				if(temp->reg[i] == true) {
					return i;
				}
			}
		}
		temp = temp->next;
	}
	
	//if operand not in reg, find a null reg , return reg index
	for(int i = 0;i < 8; i++) {
		if(regDespArr[i] == NULL) {
			return i;
		}
	}

	//find a reg which has other operand
	int far_reg = 0;
	int far_index = current;

	for(int i = 0; i < 8; i++) {
		int index = end;

		RegDesp *first_desp = regDespArr[i];
		RegDesp *reg_desp = first_desp;
		while(reg_desp != NULL) {
			Operand *op = reg_desp->operand;
			if(op == NULL) {
				printf("error, null operand in the regDesp\n");
				return 0;
			}
			for(int j = current; j <= end; j++) {
				//get index for this op	
				InterCode *ic = codes[j];		
				
				if(ic->kind == ASSIGN) {
					Operand *op1 = unwrapOperand((ic->u).assign.left);
					if(compareVariAndTemp(operand,op1)) {
						if(j < index) {
							index = j;
						}
						break;
					}
						
					Operand *op2 = unwrapOperand((ic->u).assign.right);
					if(compareVariAndTemp(operand,op2)) {
						if(j < index) {
							index = j;
						}
						break;
					}
				}
				else if(ic->kind == ADD || ic->kind == SUB
						|| ic->kind == MUL || ic->kind == DIV) {
					Operand *op1 = unwrapOperand((ic->u).binop.result);
					if(compareVariAndTemp(operand,op1)) {
						if(j < index) {
							index = j;
						}
						break;
					}
					Operand *op2 = unwrapOperand((ic->u).binop.op1);
					if(compareVariAndTemp(operand,op2)) {
						if(j < index) {
							index = j;
						}
						break;
					}
					Operand *op3 = unwrapOperand((ic->u).binop.op2);
					if(compareVariAndTemp(operand,op3)) {
						if(j < index) {
							index = j;
						}
						break;
					}
			
				}
				else if(ic->kind == IF) {
					Operand *op1 = unwrapOperand((ic->u).if_flag.left);
					if(compareVariAndTemp(operand,op1)) {
						if(j < index) {
							index = j;
						}
						break;
					}
					Operand *op2 = unwrapOperand((ic->u).if_flag.right);
					if(compareVariAndTemp(operand,op2)) {
						if(j < index) {
							index = j;
						}
						break;
					}
			
				}
				else if(ic->kind == RETURN) {
					Operand *op = unwrapOperand((ic->u).return_flag.result);
					if(compareVariAndTemp(operand,op)) {
						if(j < index) {
							index = j;
						}
						break;
					}
				}
				else if(ic->kind == DEC) {
					Operand *op = unwrapOperand((ic->u).dec_flag.pos);
					if(compareVariAndTemp(operand,op)) {
						if(j < index) {
							index = j;
						}
						break;
					}
				}
				else if(ic->kind == ARG) {
					Operand *op = unwrapOperand((ic->u).arg_flag.arg);
					if(compareVariAndTemp(operand,op)) {
						if(j < index) {
							index = j;
						}
						break;
					}
				}
				else if(ic->kind == CALL) {
					Operand *op = unwrapOperand((ic->u).call_flag.result);
					if(compareVariAndTemp(operand,op)) {
						if(j < index) {
							index = j;
						}
						break;
					}
				}
				else if(ic->kind == PARAM) {
					Operand *op = unwrapOperand((ic->u).param_flag.param);
					if(compareVariAndTemp(operand,op)) {
						if(j < index) {
							index = j;
						}
						break;
					}
				}
				else if(ic->kind == READ) {
					Operand *op = unwrapOperand((ic->u).read_flag.operand);
					if(compareVariAndTemp(operand,op)) {
						if(j < index) {
							index = j;
						}
						break;
					}
				}
				else if(ic->kind == WRITE) {
					Operand *op = unwrapOperand((ic->u).write_flag.operand);
					if(compareVariAndTemp(operand,op)) {
						if(j < index) {
							index = j;
						}
						break;
					}
				}
				// other conditions have no operands
			}
			reg_desp = reg_desp->next;
		}
		if(index > far_index) {
			far_index = index;
			far_reg = i;
		}
	}

	return far_reg;
}

bool compareVariAndTemp(Operand *op1, Operand *op2) {
	if(op1 == NULL || op2 == NULL) {
		return false;
	}
	if(op1->kind == op2->kind && op1->kind == VARIABLE && (op1->u).var_no == (op2->u).var_no) {
		return true;
	}
	else if(op1->kind == op2->kind && op1->kind == TEMP && (op1->u).temp_no == (op2->u).temp_no) {
		return true;
	}
	return false;
}
