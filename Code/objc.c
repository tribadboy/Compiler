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
	return r;
}

void releaseRegDespNode(RegDesp *r) {
	RegDespNode *rnode = (RegDespNode *)r;
	deleteRegDespNode(rnode);
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
	printf("this is getObjCode()\n");
	getBasicBlocks();

	setBasicBlockVarDesp();

	for(int i = 0;i < sum_of_blocks; i++) {
		BasicBlock *temp = blockArr[i];
		printf("%d	%d->%d\n",i,temp->start,temp->end);
	}
	printf("%s",startCode);
	printf("%s",beforeCall);
	printf("%s",afterCall);

	// do sth
}


//add varDesp for every basic block (regDesp is global)
void setBasicBlockVarDesp() {
}
