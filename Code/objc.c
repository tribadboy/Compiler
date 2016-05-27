#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "type.h"
#include "ir.h"
#include "objc.h"

#define MAX_NUM_OF_BLOCKS 150

const char *startcode = ".data\n_prompt: .asciiz \"Enter an integer:\"\n_ret: .asciiz \"\\n\"\n.globl main\n.text\nread:\n  li $v0, 4\n  la $a0, _prompt\n  syscall\n  li $v0, 5\n  syscall\n  jr $ra\n\nwrite:\n  li $v0, 1\n  syscall\n  li $v0, 4\n  la $a0, _ret\n  syscall\n  move $v0, $0\n  jr $ra\n\n";



static int sum_of_blocks = 0;
static BasicBlock *blockArr[MAX_NUM_OF_BLOCKS];

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
	
	for(int i = 0;i < sum_of_blocks; i++) {
		BasicBlock *temp = blockArr[i];
		printf("%d	%d->%d\n",i,temp->start,temp->end);
	}

	printf("%s",startcode);

	// do sth
}
