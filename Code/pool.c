#include <stdlib.h>
#include <string.h>
#include "type.h"

#define p_NUM 30
#define s_NUM 50
#define t_NUM 20
// PoolNode is a node representing the syntax unit
// SymbolNode is a node representing the symbol in the symbol table

static PoolNode *p_free = NULL;
static SymbolNode *s_free = NULL;

PoolNode *getNode() {
	PoolNode *temp;
	if(p_free == NULL) {
		p_free = (PoolNode *)malloc(sizeof(PoolNode) * p_NUM);
		for(temp = p_free; temp != p_free + p_NUM - 1; temp++) {
			temp->next = temp + 1;
		}
		temp->next = NULL;
	}
	temp = p_free;
	p_free = p_free->next;
	memset(temp,0,sizeof(PoolNode));
	return temp;
}

SymbolNode *getSymbolNode() {
	SymbolNode *temp;
	if(s_free == NULL) {
		s_free = (SymbolNode *)malloc(sizeof(SymbolNode) * s_NUM);
		for(temp = s_free; temp != s_free + s_NUM -1; temp++) {
			temp->next = temp + 1;
		}
		temp->next = NULL;
	}
	temp = s_free;
	s_free = s_free->next;
	memset(temp,0,sizeof(SymbolNode));
	return temp;
}

void deleteNode(PoolNode *p) {
	p->next = p_free;
	p_free = p;
}

void deleteSymbolNode(SymbolNode *s) {
	s->next = s_free;
	s_free = s;
}

