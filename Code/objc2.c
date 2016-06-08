#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "type.h"
#include "ir.h"
#include "objc.h"


static int param_count = 0;
static int reg_save_count = 10;

void translateInterCode_ASSIGN(InterCode *ic, VarDesp *varDesp, int start, int end, int current) {

	Operand *right = (ic->u).assign.right;
	Operand *left = (ic->u).assign.left;
	putOperandToCertainReg("$a0",right,varDesp,start,end,current);
	putCertainRegToOperand("$a0",left,varDesp,start,end,current);
	if(current == end) {
		storeRegValue(varDesp);
	}
}

void translateInterCode_ADD(InterCode *ic, VarDesp *varDesp, int start, int end, int current) {
	Operand *op1 = (ic->u).binop.op1;
	Operand *op2 = (ic->u).binop.op2;
	Operand *result = (ic->u).binop.result;
	putOperandToCertainReg("$a1",op1,varDesp,start,end,current);
	putOperandToCertainReg("$a2",op2,varDesp,start,end,current);
	char code[30] = "  add $a0, $a1, $a2\n";
	strcat(allObjCodes,code);
	putCertainRegToOperand("$a0",result,varDesp,start,end,current);
	if(current == end) {
		storeRegValue(varDesp);
	}
}

void translateInterCode_SUB(InterCode *ic, VarDesp *varDesp, int start, int end, int current) {
	Operand *op1 = (ic->u).binop.op1;
	Operand *op2 = (ic->u).binop.op2;
	Operand *result = (ic->u).binop.result;
	putOperandToCertainReg("$a1",op1,varDesp,start,end,current);
	putOperandToCertainReg("$a2",op2,varDesp,start,end,current);
	char code[30] = "  sub $a0, $a1, $a2\n";
	strcat(allObjCodes,code);
	putCertainRegToOperand("$a0",result,varDesp,start,end,current);
	if(current == end) {
		storeRegValue(varDesp);
	}
}

void translateInterCode_MUL(InterCode *ic, VarDesp *varDesp, int start, int end, int current) {
	Operand *op1 = (ic->u).binop.op1;
	Operand *op2 = (ic->u).binop.op2;
	Operand *result = (ic->u).binop.result;
	putOperandToCertainReg("$a1",op1,varDesp,start,end,current);
	putOperandToCertainReg("$a2",op2,varDesp,start,end,current);
	char code[30] = "  mul $a0, $a1, $a2\n";
	strcat(allObjCodes,code);
	putCertainRegToOperand("$a0",result,varDesp,start,end,current);
	if(current == end) {
		storeRegValue(varDesp);
	}
}

void translateInterCode_DIV(InterCode *ic, VarDesp *varDesp, int start, int end, int current) {
	Operand *op1 = (ic->u).binop.op1;
	Operand *op2 = (ic->u).binop.op2;
	Operand *result = (ic->u).binop.result;
	putOperandToCertainReg("$a1",op1,varDesp,start,end,current);
	putOperandToCertainReg("$a2",op2,varDesp,start,end,current);
	char code[40] = "  div $a1, $a2\n  mflo $a0\n";
	strcat(allObjCodes,code);
	putCertainRegToOperand("$a0",result,varDesp,start,end,current);
	if(current == end) {
		storeRegValue(varDesp);
	}
}

void translateInterCode_LABEL(InterCode *ic, VarDesp *varDesp, int start, int end, int current) {
	int label_no = (ic->u).label_flag.label_no;
	char code[20] = "";
	sprintf(code,"label%d:\n",label_no);
	strcat(allObjCodes,code);
	if(current == end) {
		storeRegValue(varDesp);
	}
}

void translateInterCode_FUNCTION(InterCode *ic, VarDesp *varDesp, int start, int end, int current) {
	strcat(allObjCodes,"\n");
	param_count = 0;
	char code1[50] = "";
	char *func_name = (ic->u).func_flag.func_name;
	if(strcmp(func_name,"main") == 0) {
		sprintf(code1,"%s:\n",func_name);
	} else {
		sprintf(code1,"%s_abc:\n",func_name);
	}
	strcat(allObjCodes,code1);
	char code2[30] = "  move $fp, $sp\n";
	strcat(allObjCodes,code2);
	int size = 0;
	VarDesp *tmp = varDesp;
	while(tmp != NULL) {
		size = tmp->offset;
		tmp = tmp->next;
	}
	char code3[30] = "";
	sprintf(code3,"  addi $sp, $sp, -%d\n",size);
	strcat(allObjCodes,code3);
	if(current == end) {
		storeRegValue(varDesp);
	}
}

void translateInterCode_GOTO(InterCode *ic, VarDesp *varDesp ,int start, int end, int current) {
	if(current == end) {
		storeRegValue(varDesp);
	}
	int goto_no = (ic->u).goto_flag.goto_no;
	char code[20] = "";
	sprintf(code,"  j label%d\n",goto_no);
	strcat(allObjCodes,code);
}

void translateInterCode_IF(InterCode *ic, VarDesp *varDesp, int start, int end, int current) {
	Operand *left = (ic->u).if_flag.left;
	Operand *right = (ic->u).if_flag.right;
	char *rel_token = (ic->u).if_flag.rel_token;
	int no = (ic->u).if_flag.no;
/*
	if(left->kind != TEMP || right->kind != TEMP) {
		printf("error, rel token operand is not temp\n");
		return;
	}
*/
/*
	int leftRegIndex = getReg(left,varDesp,start,end,current);
	getRegCode(leftRegIndex,left,false,varDesp);
	int rightRegIndex = getReg(right,varDesp,start,end,current);
	getRegCode(rightRegIndex,right,false,varDesp);
*/
	putOperandToCertainReg("$a1",left,varDesp,start,end,current);
	putOperandToCertainReg("$a2",right,varDesp,start,end,current);
	
	if(current == end) {
		storeRegValue(varDesp);
	}
	char code[50] = "";
	char rel_flag[10] = "";
	if(strcmp(rel_token,"==") == 0) strcat(rel_flag,"beq");
	else if(strcmp(rel_token,"!=") == 0) strcat(rel_flag,"bne");
	else if(strcmp(rel_token, ">") == 0) strcat(rel_flag,"bgt");
	else if(strcmp(rel_token, "<") == 0) strcat(rel_flag,"blt");
	else if(strcmp(rel_token,">=") == 0) strcat(rel_flag,"bge");
	else if(strcmp(rel_token,"<=") == 0) strcat(rel_flag,"ble");
	else {
		printf("error rel_token\n");
		return;
	}

	sprintf(code,"  %s $a1, $a2, label%d\n",rel_flag,no);
	strcat(allObjCodes,code);
}

void translateInterCode_RETURN(InterCode *ic, VarDesp *varDesp, int start, int end, int current) {
	Operand *result = (ic->u).return_flag.result;
	char code1[30] = "  move $sp, $fp\n";
	strcat(allObjCodes,code1);
	putOperandToCertainReg("$v0",result,varDesp,start,end,current);
	if(current == end) {
		storeRegValue(varDesp);
	}
	char code2[30] = "  jr $ra\n";
	strcat(allObjCodes,code2);
}

void putOperandToCertainReg(char *regName, Operand *operand, VarDesp *varDesp, int start, int end, int current) {
	if(operand->kind == CONSTANT) {
		int value = (operand->u).value;
		char code[30] = "";
		sprintf(code,"  li %s, %d\n",regName,value);
		strcat(allObjCodes,code);
	} 
	else if(operand->kind == ADDRESS) {
		Operand *w_operand = unwrapOperand(operand);
		int regIndex = getReg(w_operand,varDesp,start,end,current);
		getRegCode(regIndex,w_operand,true,varDesp);
		char code[30] = "";
		sprintf(code,"  move %s, $t%d\n",regName,regIndex);
		strcat(allObjCodes,code);
	} else if(operand->kind == POINTER) {
		Operand *w_operand = unwrapOperand(operand);
		int regIndex = getReg(w_operand,varDesp,start,end,current);
		getRegCode(regIndex,w_operand,false,varDesp);
		char code[30] = "";
		sprintf(code,"  lw %s, 0($t%d)\n",regName,regIndex);
		strcat(allObjCodes,code);
	} else {
		int regIndex = getReg(operand,varDesp,start,end,current);
		getRegCode(regIndex,operand,false,varDesp);
		char code[30] = "";
		sprintf(code,"  move %s, $t%d\n",regName,regIndex);
		strcat(allObjCodes,code);
	}
}

void putCertainRegToOperand(char *regName, Operand *operand, VarDesp *varDesp, int start, int end, int current) {
	if(operand->kind == CONSTANT || operand->kind == ADDRESS) {
		printf("error,cannot assign certain reg to a constant or a address\n");
		return;
	}
	else if(operand->kind == POINTER) {
		Operand *w_operand = unwrapOperand(operand);
		int regIndex = getReg(w_operand,varDesp,start,end,current);
		getRegCode(regIndex,w_operand,false,varDesp);
		char code[30] = "";
		sprintf(code,"  sw %s, 0($t%d)\n",regName,regIndex);
		strcat(allObjCodes,code);
	}
	else {
		int regIndex = getReg(operand,varDesp,start,end,current);
		getRegCode(regIndex,operand,false,varDesp);
		changeRegCode(regIndex,operand,varDesp);
		char code[30] = "";
		sprintf(code,"  move $t%d, %s\n",regIndex,regName);
		strcat(allObjCodes,code);
	}
}


	

void translateInterCode_DEC(InterCode *ic, VarDesp *varDesp, int start, int end, int current) {
	//do nothing
}

void translateInterCode_ARG(InterCode *ic, VarDesp *varDesp, int start ,int end, int current) {
	//do nothing
}

void translateInterCode_CALL(InterCode *ic, VarDesp *varDesp, int start, int end, int current) {
	int arg_count = 0;
	for(int i = current - 1; i >= start; i--) {
		if(codes[i]->kind != ARG)	break;
		arg_count++;
	}
	if(arg_count > 4) {
		char code[30] = "";
		sprintf(code,"  addi, $sp, $sp, -%d\n",(arg_count-4)*4);
		strcat(allObjCodes,code);
	}
	for(int i = arg_count; i >= 1; i--) {
		Operand *arg_op = (codes[current-i]->u).arg_flag.arg;
		if(i > 4) {
			char regName[20] = "$a0";
			putOperandToCertainReg(regName,arg_op,varDesp,start,end,current);
			char code_tmp[30] = "";
			sprintf(code_tmp,"  sw $a0, %d($sp)\n",(i-5)*4);
			strcat(allObjCodes,code_tmp);
		}
		else {
			char regName[20] = "";
			sprintf(regName,"$a%d",i-1);
			putOperandToCertainReg(regName,arg_op,varDesp,start,end,current);
		}
	}
	strcat(allObjCodes,beforeCall);
	char *func_name = (ic->u).call_flag.func_name;
	Operand *result = (ic->u).call_flag.result;
	char code2[50] = "";
	if(strcmp(func_name,"main") == 0) {
		sprintf(code2,"  jal %s\n",func_name);
	} else {
		sprintf(code2,"  jal %s_abc\n",func_name);
	}
	strcat(allObjCodes,code2);
	strcat(allObjCodes,afterCall);
	
	char *regName = "$v0";
	putCertainRegToOperand(regName,result,varDesp,start,end,current);

	if(current == end) {
		storeRegValue(varDesp);
	}
}

void translateInterCode_PARAM(InterCode *ic, VarDesp *varDesp, int start, int end, int current) {
	param_count++;
	Operand *operand = (ic->u).param_flag.param;
	VarDesp *opVarDesp = findVarDespInVarDespList(operand,varDesp);
	if(opVarDesp == NULL) {
		printf("error,cannot find param operand in vardesp\n");
		return;
	}

	int offset = opVarDesp->offset;
	if(param_count <= 4) {
		char code[30] = "";
		sprintf(code,"  sw $a%d, -%d($fp)\n",param_count-1,offset);
		strcat(allObjCodes,code);
	} else {
		char code1[30] = "";
		int param_offset = (param_count - 5 + reg_save_count) * 4;
		sprintf(code1,"  lw $a0, %d($fp)\n",param_offset);
		strcat(allObjCodes,code1);
		char code2[30] = "";
		sprintf(code2,"  sw $a0, -%d($fp)\n",offset);
		strcat(allObjCodes,code2);
	}
	if(current == end) {
		storeRegValue(varDesp);
	}
}

void translateInterCode_READ(InterCode *ic, VarDesp *varDesp, int start, int end, int current) {
	Operand *operand = (ic->u).read_flag.operand;
	strcat(allObjCodes,callRead);
	char *regName = "$v0";
	putCertainRegToOperand(regName,operand,varDesp,start,end,current);
	if(current == end) {
		storeRegValue(varDesp);
	}
}

void translateInterCode_WRITE(InterCode *ic, VarDesp *varDesp, int start, int end, int current) {
	Operand *operand = (ic->u).write_flag.operand;
	char *regName = "$a0";
	putOperandToCertainReg(regName,operand,varDesp,start,end,current);
	strcat(allObjCodes,callWrite);
	if(current == end) {
		storeRegValue(varDesp);
	}
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

//operand should be v1 or t2
void getRegCode(int regIndex, Operand *operand, bool isAddr, VarDesp *varDesp) {
	VarDesp *opVarDesp = findVarDespInVarDespList(operand, varDesp);
	if(opVarDesp == NULL) {
		printf("error,cannot find var in vardesp\n");
		return;
	}

	//find a empty reg or the operand not exist in the reg
	if(findRegDespInRegDespList(operand,regDespArr[regIndex]) == NULL) {
		RegDesp *reg_desp = regDespArr[regIndex];
		while(reg_desp != NULL) {
			//reg has some other operands, check them in vardesp
			Operand *other_operand = reg_desp->operand;
			VarDesp *other_vardesp = findVarDespInVarDespList(other_operand,varDesp);
			if(other_vardesp == NULL) {
				printf("error,cannot find var in vardesp(reg)\n");
				return;
			}
			other_vardesp->reg[regIndex] = false;
			if(other_vardesp->self == false) {
				bool storeFlag = true;
				for(int i = 0;i < 8; i++) {
					if(other_vardesp->reg[i] == true) {
						storeFlag = false;
						break;
					}
				}
				if(storeFlag == true) {
					int offset = other_vardesp->offset;
					char code[30] = "";
					sprintf(code,"  sw $t%d, -%d($fp)\n",regIndex,offset);
					strcat(allObjCodes,code);
					other_vardesp->self = true;
				}
			}
			reg_desp = reg_desp->next;
		}

		if(isAddr) {
			char code[30] = "";
			sprintf(code,"  addi $t%d, $fp, -%d\n",regIndex,opVarDesp->offset);
			strcat(allObjCodes,code);
		}
		else {
			char code[30] = "";
			sprintf(code,"  lw $t%d, -%d($fp)\n",regIndex,opVarDesp->offset);
			strcat(allObjCodes,code);
		}

		regDespArr[regIndex] = NULL;
		RegDesp * newRegDesp = getAndSetRegDespNode(operand);
		regDespArr[regIndex] = newRegDesp;
		VarDesp *tmp1 = varDesp;
		while(tmp1 != NULL) {
			if(tmp1 == opVarDesp) {	
				tmp1->reg[regIndex] = true;
			}
			else {
				tmp1->reg[regIndex] = false;
			}
			tmp1 = tmp1->next;
		}	
	}
}

//change reg value code, operand should be v1 or t2
void changeRegCode(int regIndex, Operand *operand, VarDesp *varDesp) {
	VarDesp *opVarDesp = findVarDespInVarDespList(operand, varDesp);
	if(opVarDesp == NULL) {
		printf("error,cannot find var in vardesp\n");
		return;
	}

	//find a empty reg or the operand not exist in the reg
	RegDesp *opRegDesp = findRegDespInRegDespList(operand,regDespArr[regIndex]);
	if(opRegDesp == NULL) {
		printf("error,cannot find var in regdesp\n");
		return;
	}
	else {
		RegDesp *reg_desp = regDespArr[regIndex];
		while(reg_desp != NULL) {
			if(reg_desp != opRegDesp) {
				Operand *other_operand = reg_desp->operand;
				VarDesp *other_vardesp = findVarDespInVarDespList(other_operand,varDesp);
				if(other_vardesp == NULL) {
					printf("error,cannot find var in vardesp(reg)\n");
					return;
				}
				other_vardesp->reg[regIndex] = false;
				if(other_vardesp->self == false) {
					bool storeFlag = true;
					for(int i = 0;i < 8; i++) {
						if(other_vardesp->reg[i] == true) {
							storeFlag = false;
							break;
						}
					}
					if(storeFlag == true) {
						int offset = other_vardesp->offset;
						char code[30] = "";
						sprintf(code,"  sw $t%d, -%d($fp)\n",regIndex,offset);
						strcat(allObjCodes,code);
						other_vardesp->self = true;
					}
				}
			}
			reg_desp = reg_desp->next;
		}

		regDespArr[regIndex] = NULL;
		RegDesp * newRegDesp = getAndSetRegDespNode(operand);
		regDespArr[regIndex] = newRegDesp;
		VarDesp *tmp1 = varDesp;
		while(tmp1 != NULL) {
			if(tmp1 == opVarDesp) {	
				tmp1->self = false;
				for(int i = 0;i < 8; i++) {
					if(i == regIndex){
						tmp1->reg[i] = true;
					} else {
						tmp1->reg[i] = false;
					}
				}
			}
			else {
				tmp1->reg[regIndex] = false;
			}
			tmp1 = tmp1->next;
		}	
	}
}


//find v1 or t1 in regDespArr[x]
RegDesp *findRegDespInRegDespList(Operand *operand, RegDesp *regList) {
	if(regList == NULL) 	return NULL;
	RegDesp *tmp = regList;
	while(tmp != NULL) {
		Operand *op_tmp = tmp->operand;
		if(operand->kind == op_tmp->kind && operand->kind == VARIABLE && (operand->u).var_no == (op_tmp->u).var_no) {
			return tmp;
		}
		else if(operand->kind == op_tmp->kind && operand->kind == TEMP && (operand->u).temp_no == (op_tmp->u).temp_no) {
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}

//find v1 or t1 in varDespList
VarDesp *findVarDespInVarDespList(Operand *operand, VarDesp *varList) {
	if(varList == NULL) 	return NULL;
	VarDesp *tmp = varList;
	while(tmp != NULL) {
		Operand *op_tmp = tmp->operand;
		if(operand->kind == op_tmp->kind && operand->kind == VARIABLE && (operand->u).var_no == (op_tmp->u).var_no) {
			return tmp;
		}
		else if(operand->kind == op_tmp->kind && operand->kind == TEMP && (operand->u).temp_no == (op_tmp->u).temp_no) {
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}

