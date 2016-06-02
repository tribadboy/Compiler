#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "type.h"
#include "ir.h"
#include "objc.h"

#define MAX_NUM_OF_BLOCKS 150

const char *startCode = ".data\n_prompt: .asciiz \"Enter an integer:\"\n_ret: .asciiz \"\\n\"\n.globl main\n.text\nread:\n  li $v0, 4\n  la $a0, _prompt\n  syscall\n  li $v0, 5\n  syscall\n  jr $ra\n\nwrite:\n  li $v0, 1\n  syscall\n  li $v0, 4\n  la $a0, _ret\n  syscall\n  move $v0, $0\n  jr $ra\n\n";

const char *beforeCall = "  addi $sp, $sp, -40\n  sw $ra, 36($sp)\n  sw $fp, 32($sp)\n  sw $t0, 28($sp)\n  sw $t1, 24($sp)\n  sw $t2, 20($sp)\n  sw $t3, 16($sp)\n  sw $t4, 12($sp)\n  sw $t5, 8($sp)\n  sw $t6, 4($sp)\n  sw $t7, 0($sp)\n";

const char *afterCall = "  lw $ra, 36($sp)\n  lw $fp, 32($sp)\n  lw $t0, 28($sp)\n  lw $t1, 24($sp)\n  lw $t2, 20($sp)\n  lw $t3, 16($sp)\n  lw $t4, 12($sp)\n  lw $t5, 8($sp)\n  lw $t6, 4($sp)\n  lw $t7, 0($sp)\n  addi $sp, $sp, 40\n";

static int sum_of_blocks = 0;
static BasicBlock *blockArr[MAX_NUM_OF_BLOCKS];
char allObjCodes[8000] = "";
#define NUM_OF_D_REGS  8

//reg descriptor	$t0 $t1 ... $t7
RegDesp *regDespArr[NUM_OF_D_REGS];

static void clearRegDespArr() {
	for(int i = 0;i < NUM_OF_D_REGS; i++) {
		if(regDespArr[i] != NULL) {
			RegDesp *temp = regDespArr[i];
			while(temp != NULL) {
				RegDesp *temp2 = temp;
				temp = temp->next;
				releaseRegDespNode(temp2);
			}
			regDespArr[i] = NULL;
		}
	}
}

static void clearVarDesp(VarDesp *varDesp) {
	if(varDesp == NULL) {
		return;
	}
	VarDesp *temp = varDesp;
	while(temp != NULL) {
		for(int i = 0;i < 8; i++) {
			temp->reg[i] = false;
		}
		temp->next;
	}
}

static void insertBlock(BasicBlock *basicBlock) {
	if(sum_of_blocks >= MAX_NUM_OF_BLOCKS) {
		printf("error, the num of basicblocks is over the limit\n");
		return;
	}
	blockArr[sum_of_blocks] = basicBlock;
	sum_of_blocks++;
}

BasicBlock *getAndSetBasicBlockNode(int start, int end) {
	BasicBlockNode *bnode = getBasicBlockNode();
	BasicBlock *b = &(bnode->basicBlock);
	b->start = start;
	b->end = end;
	return b;
}

RegDesp *getAndSetRegDespNode(Operand *operand) {
	RegDespNode *rnode = getRegDespNode();
	RegDesp * r = &(rnode->regDesp);
	r->operand = operand;
	r->next = NULL;
	return r;
}

VarDesp *getAndSetVarDespNode(Operand *operand, int offset) {
	VarDespNode *vnode = getVarDespNode();
	VarDesp *v = &(vnode->varDesp);
	v->operand = operand;
	v->offset = offset;
	v->next = NULL;
	return v;
}

void releaseRegDespNode(RegDesp *r) {
	RegDespNode *rnode = (RegDespNode *)r;
	deleteRegDespNode(rnode);
}

void releaseVarDespNode(VarDesp *v) {
	VarDespNode *vnode = (VarDespNode *)v;
	deleteVarDespNode(vnode);
}

//check the block whether is a function header(be

void getBasicBlocks() {
	int start = 0;
	for(int i = 1;i < sum; i++) {
		InterCode *temp = codes[i];
		if(temp->kind == RETURN ||
		   temp->kind == GOTO	||
		   temp->kind == IF	
		  ) {
			if(start <= i) {
				BasicBlock *basicBlock = getAndSetBasicBlockNode(start,i);
				insertBlock(basicBlock);
				start = i + 1;
			}
		}
		else if(temp->kind == LABEL ||
			temp->kind == FUNCTION
			) {
			if(start <= i-1) {
				BasicBlock *basicBlock = getAndSetBasicBlockNode(start,i-1);
				insertBlock(basicBlock);
				start = i;
			}
		}
	}
	if(start <= sum - 1) {
		BasicBlock *basicBlock = getAndSetBasicBlockNode(start,sum-1);
		insertBlock(basicBlock);
	}
}

void getObjectCode() {

	getBasicBlocks();

	setBasicBlockVarDesp();

	//printBlockVarDesp();	

	translateObjCode();

}

void translateObjCode() {
	for(int i = 0; i< sum_of_blocks; i++) {
		BasicBlock *temp = blockArr[i];
		translateBlock(temp);
	}
}

void translateBlock(BasicBlock *basicBlock) {
	if(basicBlock == NULL) {
		printf("error no basicBlock in the array\n");
		return;
	}

	//before translate block , clear the regdesp and vardesp
	clearRegDespArr();
	clearVarDesp(basicBlock->varDesp);

	//start translate every intercode in block
	int start = basicBlock->start;
	int end = basicBlock->end;
	VarDesp *varDesp = basicBlock->varDesp;
	for(int i = start; i <= end; i++) {
		InterCode *ic = codes[i];
		if(ic == NULL) {
			printf("error no intercode in the basicBlock\n");
			continue;
		}
		if(ic->kind == ASSIGN) {
			translateInterCode_ASSIGN(ic,varDesp,start,end);
		}
		else if(ic->kind == ADD) {
			translateInterCode_ADD(ic,varDesp,start,end);
		}
		else if(ic->kind == SUB) {
			translateInterCode_SUB(ic,varDesp,start,end);
		}
		else if(ic->kind == MUL) {
			translateInterCode_MUL(ic,varDesp,start,end);
		}
		else if(ic->kind == DIV) {
			translateInterCode_DIV(ic,varDesp,start,end);
		}
		else if(ic->kind == LABEL) {
			translateInterCode_LABEL(ic,varDesp,start,end);
		}
		else if(ic->kind == FUNCTION) {
			translateInterCode_FUNCTION(ic,varDesp,start,end);
		}
		else if(ic->kind == GOTO) {
			translateInterCode_GOTO(ic,varDesp,start,end);
		}
		else if(ic->kind == IF) {
			translateInterCode_IF(ic,varDesp,start,end);
		}
		else if(ic->kind == RETURN) {
			translateInterCode_RETURN(ic,varDesp,start,end);
		}
		else if(ic->kind == DEC) {
			translateInterCode_DEC(ic,varDesp,start,end);
		}
		else if(ic->kind == ARG) {
			translateInterCode_ARG(ic,varDesp,start,end);
		}
		else if(ic->kind == CALL) {
			translateInterCode_CALL(ic,varDesp,start,end);
		}
		else if(ic->kind == PARAM) {
			translateInterCode_PARAM(ic,varDesp,start,end);
		}
		else if(ic->kind == READ) {
			translateInterCode_READ(ic,varDesp,start,end);
		}
		else if(ic->kind == WRITE) {
			translateInterCode_WRITE(ic,varDesp,start,end);
		}
		else {
			printf("error InterCode type\n");
		}
	}
}

void printBlockVarDesp() {
	for(int i = 0;i < sum_of_blocks; i++) {
		BasicBlock *temp = blockArr[i];
		printf("%d	%d->%d\n",i,temp->start,temp->end);
		VarDesp *tmp = temp->varDesp;
		while(tmp != NULL) {
			if(tmp->operand->kind == VARIABLE) {
				printf("\t\tv%d\toffset %d\n",(tmp->operand->u).var_no,tmp->offset);
			}
			else if(tmp->operand->kind == TEMP) {
				printf("\t\tt%d\toffset %d\n",(tmp->operand->u).temp_no,tmp->offset);
			}
			tmp = tmp->next;
		}
		printf("\n");
	}
	//printf("%s",startCode);
	//printf("%s",beforeCall);
	//printf("%s",afterCall);

}

//add varDesp for every basic block (regDesp is global)
void setBasicBlockVarDesp() {
	VarDesp *varDesp = NULL;
	for(int i = 0;i < sum_of_blocks; i++) {
		BasicBlock *temp = blockArr[i];
		temp->varDesp = NULL;
		int start = temp->start;
		if(codes[start]->kind == FUNCTION) {
			int end = start + 1;
			while(end < sum) {
				if(codes[end]->kind == FUNCTION) {
					break;
				}
				end++;
			}
			end--;
			temp->varDesp = getVarDespFromFunc(start,end);
			varDesp = temp->varDesp;
		}
		else {
			temp->varDesp = varDesp;
		}
	}
}

//get vardespList  from function  for blocks
VarDesp *getVarDespFromFunc(int start, int end) {
	VarDesp *varDesp = NULL;
	for(int i = start; i <= end; i++) {
		InterCode *tmp = codes[i];
		if(tmp->kind == ASSIGN) {
			Operand *op1 = unwrapOperand((tmp->u).assign.left);
			Operand *op2 = unwrapOperand((tmp->u).assign.right);
			varDesp = checkOpInVarDesp(varDesp,op1,4);
			varDesp = checkOpInVarDesp(varDesp,op2,4);
		}
		else if(tmp->kind == ADD || tmp->kind == SUB
			|| tmp->kind == MUL || tmp->kind == DIV) {
			Operand *op1 = unwrapOperand((tmp->u).binop.result);
			Operand *op2 = unwrapOperand((tmp->u).binop.op1);
			Operand *op3 = unwrapOperand((tmp->u).binop.op2);
			varDesp = checkOpInVarDesp(varDesp,op1,4);
			varDesp = checkOpInVarDesp(varDesp,op2,4);
			varDesp = checkOpInVarDesp(varDesp,op3,4);
		}
		else if(tmp->kind == IF) {
			Operand *op1 = unwrapOperand((tmp->u).if_flag.left);
			Operand *op2 = unwrapOperand((tmp->u).if_flag.right);
			varDesp = checkOpInVarDesp(varDesp,op1,4);
			varDesp = checkOpInVarDesp(varDesp,op2,4);
		}
		else if(tmp->kind == RETURN) {
			Operand *op = unwrapOperand((tmp->u).return_flag.result);
			varDesp = checkOpInVarDesp(varDesp,op,4);
		}
		else if(tmp->kind == DEC) {
			Operand *op = unwrapOperand((tmp->u).dec_flag.pos);
			varDesp = checkOpInVarDesp(varDesp,op,(tmp->u).dec_flag.size);
		}
		else if(tmp->kind == ARG) {
			Operand *op = unwrapOperand((tmp->u).arg_flag.arg);
			varDesp = checkOpInVarDesp(varDesp,op,4);
		}
		else if(tmp->kind == CALL) {
			Operand *op = unwrapOperand((tmp->u).call_flag.result);
			varDesp = checkOpInVarDesp(varDesp,op,4);
		}
		else if(tmp->kind == PARAM) {
			Operand *op = unwrapOperand((tmp->u).param_flag.param);
			varDesp = checkOpInVarDesp(varDesp,op,4);
		}
		else if(tmp->kind == READ) {
			Operand *op = unwrapOperand((tmp->u).read_flag.operand);
			varDesp = checkOpInVarDesp(varDesp,op,4);
		}
		else if(tmp->kind == WRITE) {
			Operand *op = unwrapOperand((tmp->u).write_flag.operand);
			varDesp = checkOpInVarDesp(varDesp,op,4);
		}
		// other conditions have no operands
	}
	return varDesp;
}

Operand *unwrapOperand(Operand *operand) {
	if(operand == NULL) {
		return NULL;
	}
	Operand *tmp = operand;
	while(tmp != NULL) {
		if(tmp->kind == VARIABLE || tmp->kind == CONSTANT 
			|| tmp->kind == TEMP) {
			break;
		}
		else if(tmp->kind == ADDRESS) {
			tmp = (tmp->u).operand_address;
		}
		else {
			tmp = (tmp->u).operand_pointer;
		}
	}
	return tmp;
}

VarDesp *checkOpInVarDesp(VarDesp *varDesp, Operand *operand, int size) {
	if(operand == NULL) {
		return varDesp;
	}
	else if(operand->kind == CONSTANT) {
		return varDesp;
	}
	else {
		if(varDesp == NULL) {
			varDesp = getAndSetVarDespNode(operand,size);
			return varDesp;
		}
		VarDesp *temp = varDesp;
		VarDesp *prev = NULL;
		while(temp != NULL) {
			if(operand->kind == temp->operand->kind &&
				operand->kind == VARIABLE &&
				(operand->u).var_no == (temp->operand->u).var_no) {
				return varDesp;
			}
			else if(operand->kind == temp->operand->kind &&
				operand->kind == TEMP &&
				(operand->u).temp_no == (temp->operand->u).temp_no) {
				return varDesp;
			} 
			prev = temp;
			temp = temp->next;
		}
		prev->next = getAndSetVarDespNode(operand,prev->offset + size);
		return varDesp;
	}
}


void translateInterCode_ASSIGN(InterCode *ic, VarDesp *varDesp, int start, int end) {
	//do sth
}

void translateInterCode_ADD(InterCode *ic, VarDesp *varDesp, int start, int end) {
	//do sth
}

void translateInterCode_SUB(InterCode *ic, VarDesp *varDesp, int start, int end) {
	//do sth
}

void translateInterCode_MUL(InterCode *ic, VarDesp *varDesp, int start, int end) {
	//do sth
}

void translateInterCode_DIV(InterCode *ic, VarDesp *varDesp, int start, int end) {
	//do sth
}

void translateInterCode_LABEL(InterCode *ic, VarDesp *varDesp, int start, int end) {
	//do sth
}

void translateInterCode_FUNCTION(InterCode *ic, VarDesp *varDesp, int start, int end) {
	//do sth
}

void translateInterCode_GOTO(InterCode *ic, VarDesp *varDesp ,int start, int end) {
	//do sth
}

void translateInterCode_IF(InterCode *ic, VarDesp *varDesp, int start, int end) {
	//do sth
}

void translateInterCode_RETURN(InterCode *ic, VarDesp *varDesp, int start, int end) {
	//do sth
}

void translateInterCode_DEC(InterCode *ic, VarDesp *varDesp, int start, int end) {
	//do sth
}

void translateInterCode_ARG(InterCode *ic, VarDesp *varDesp, int start ,int end) {
	//do sth
}

void translateInterCode_CALL(InterCode *ic, VarDesp *varDesp, int start, int end) {
	//do sth
}

void translateInterCode_PARAM(InterCode *ic, VarDesp *varDesp, int start, int end) {
	//do sth
}

void translateInterCode_READ(InterCode *ic, VarDesp *varDesp, int start, int end) {
	//do sth
}

void translateInterCode_WRITE(InterCode *ic, VarDesp *varDesp, int start, int end) {
	//do sth
}
