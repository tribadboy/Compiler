#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "type.h"

#define P_STACK_SIZE  80
#define MAX_CHARS_IN_ID 36

StackNode pstack[P_STACK_SIZE];
int p_top = -1;
int printTreeFlag = 1;

void push(CSNode *p, int h) {
	if(p_top + 1 == P_STACK_SIZE) {
		printf("stack overflow\n");
		return;
	}
	p_top++;
	pstack[p_top].p_node = p;
	pstack[p_top].high = h;
}

int pop(CSNode **p, int *h) {
	if(p_top == -1) {
		return 0;
	}
	(*p) = pstack[p_top].p_node;
	(*h) = pstack[p_top].high;
	p_top--;
	return 1;
}
/*
void preOrderPrint(CSNode *root) {
	if(root == NULL) {
		return;
	}
	printf("%s\t\t%d\n", getTypeName(root->type), root->lineNo);
	CSNode *temp;
	for(temp = root->firstChild; temp != NULL; temp = temp->nextSibling) {
		preOrderPrint(temp);
	}
}
*/
void preOrderPrint(CSNode *root) {
	if(root == NULL) {
		return;
	}
	int high = 0;
	push(root,high);
	CSNode *temp;
	while(pop(&temp,&high)) {
		for(int i = 0;i < high; i++) {
			printf("  ");
		}
		//printf("%s (%d)\n",getTypeName(temp->type),temp->lineNo);
		printTypeExp(temp);
		if(temp->nextSibling != NULL) {
			push(temp->nextSibling,high);
		}
		if(temp->firstChild != NULL) {
			push(temp->firstChild,high+1);
		}
	}
}
CSNode *setCSNode(TokenType t, int no) {
	PoolNode *p = getNode();
	CSNode *pnode = &(p->p_node);
	pnode->type = t;
	pnode->lineNo = no;
	pnode->firstChild = NULL;
	pnode->nextSibling = NULL;
	return pnode;
}

CSNode *setCSNode_int(TokenType t, int no, int v) {
	if(t != MyINT){
		printf("type is not MyINT, set failed\n");
		return NULL;
	}
	CSNode *pnode = setCSNode(t,no);
	(pnode->type_union).type_int.value = v;
	return pnode;
}

CSNode *setCSNode_float(TokenType t, int no,float v) {
	if(t != MyFLOAT) {
		printf("type is not MyFLOAT, set failed\n");
		return NULL;
	}
	CSNode *pnode = setCSNode(t,no);
	(pnode->type_union).type_float.value = v;
	return pnode;
}

CSNode *setCSNode_id(TokenType t, int no, char *s) {
	if(t != MyID) {
		printf("type is not MyID, set failed\n");
		return NULL;
	}
	CSNode *pnode = setCSNode(t,no);
	char *temp = (char *)malloc(sizeof(char) * MAX_CHARS_IN_ID);
	strcpy(temp,s);
	(pnode->type_union).type_id.p_str = temp;
	return pnode;
}

CSNode *setCSNode_relop(TokenType t, int no, char *s) {
	if(t != MyRELOP) {
		printf("type is not MyRELOP, set failed\n");
		return NULL;
	}
	CSNode *pnode = setCSNode(t,no);
	strcpy((pnode->type_union).type_relop.token,s);
	return pnode;
}

CSNode *setCSNode_type(TokenType t, int no, char *s) {
	if(t != MyTYPE) {
		printf("type is not MyTYPE, set failed\n");
		return NULL;
	}
	CSNode *pnode = setCSNode(t,no);
	strcpy((pnode->type_union).type_type.token,s);
	return pnode;
}

void addEmptyChild(CSNode *root) {
	if(root == NULL) {
		printf("stop 2-1\n");
		return;
	}
	root->firstChild = NULL;
}

void addChild(CSNode *parrent, CSNode *child) {
	if(parrent == NULL) {
		printf("stop 2\n");
		return;
	}
	if(child == NULL) {
		return;		//child  -> empty
	}
	CSNode *first = parrent->firstChild;
	if(first == NULL) {
		parrent->firstChild = child;
		return;
	}
	CSNode *next = first->nextSibling;
	CSNode *next_p = first;
	while(next != NULL) {
		next_p = next_p->nextSibling;
		next = next->nextSibling;
	}
	next_p->nextSibling = child;
}

void add2Childs(CSNode *p, CSNode *c1, CSNode *c2) {
	addChild(p,c1);
	addChild(p,c2);
}

void add3Childs(CSNode *p, CSNode *c1, CSNode *c2, CSNode *c3) {
	addChild(p,c1);
	addChild(p,c2);
	addChild(p,c3);
}

void add4Childs(CSNode *p, CSNode *c1, CSNode *c2, CSNode *c3, CSNode * c4) {
	addChild(p,c1);
	addChild(p,c2);
	addChild(p,c3);
	addChild(p,c4);
}

void add5Childs(CSNode *p,CSNode *c1,CSNode *c2,CSNode *c3,CSNode *c4,CSNode *c5) {
	addChild(p,c1);
	addChild(p,c2);
	addChild(p,c3);
	addChild(p,c4);
	addChild(p,c5);
}

void add6Childs(CSNode *p,CSNode *c1,CSNode *c2,CSNode *c3,CSNode *c4,CSNode *c5,CSNode *c6) {
	addChild(p,c1);
	addChild(p,c2);
	addChild(p,c3);
	addChild(p,c4);
	addChild(p,c5);
	addChild(p,c6);
}

void add7Childs(CSNode *p,CSNode *c1,CSNode *c2,CSNode *c3,CSNode *c4,CSNode *c5,CSNode *c6,CSNode *c7) {
	addChild(p,c1);
	addChild(p,c2);
	addChild(p,c3);
	addChild(p,c4);
	addChild(p,c5);
	addChild(p,c6);
	addChild(p,c7);
}
