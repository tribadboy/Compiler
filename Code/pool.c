#include <stdlib.h>
#include <string.h>
#include "type.h"
#include "ir.h"
#include "objc.h"

#define p_NUM 30
#define s_NUM 50
#define o_NUM 200
#define i_NUM 80
#define b_NUM 60
#define r_NUM 100
#define v_NUM 120

// PoolNode is a node representing the syntax unit
// SymbolNode is a node representing the symbol in the symbol table
// OperandNode is a node representing the Operand in the ir
// InterCodeNode is a node representing the InterCode in the ir
// BasicBlockNode is node representing the basicblock in the ir

static PoolNode *p_free = NULL;
static SymbolNode *s_free = NULL;
static OperandNode *o_free = NULL;
static InterCodeNode *i_free = NULL;
static BasicBlockNode *b_free = NULL;
static RegDespNode *r_free = NULL;
static VarDespNode *v_free = NULL;

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

OperandNode *getOperandNode() {
	OperandNode *temp;
	if(o_free == NULL) {
		o_free = (OperandNode *)malloc(sizeof(OperandNode) * o_NUM);
		for(temp = o_free; temp != o_free + o_NUM - 1; temp++) {
			temp->next = temp + 1;
		}
		temp->next = NULL;
	}
	temp = o_free;
	o_free = o_free->next;
	memset(temp,0,sizeof(OperandNode));
	return temp;
}

InterCodeNode *getInterCodeNode() {
	InterCodeNode *temp;
	if(i_free == NULL) {
		i_free = (InterCodeNode *)malloc(sizeof(InterCodeNode) * i_NUM);
		for(temp = i_free; temp != i_free + i_NUM - 1; temp++) {
			temp->next = temp + 1;
		}
		temp->next = NULL;
	}
	temp = i_free;
	i_free = i_free->next;
	memset(temp,0,sizeof(InterCodeNode));
	return temp;
}

BasicBlockNode *getBasicBlockNode() {
	BasicBlockNode *temp;
	if(b_free == NULL) {
		b_free = (BasicBlockNode *)malloc(sizeof(BasicBlockNode) * b_NUM);
		for(temp = b_free; temp != b_free + b_NUM - 1; temp++) {
			temp->next = temp + 1;
		}
		temp->next = NULL;
	}
	temp = b_free;
	b_free = b_free->next;
	memset(temp,0,sizeof(BasicBlockNode));
	return temp;
}

RegDespNode *getRegDespNode() {
	RegDespNode *temp;
	if(r_free == NULL) {
		r_free = (RegDespNode *)malloc(sizeof(RegDespNode) * r_NUM);
		for(temp = r_free; temp != r_free + r_NUM - 1; temp++) {
			temp->next = temp + 1;
		}
		temp->next = NULL;
	}
	temp = r_free;
	r_free = r_free->next;
	memset(temp,0,sizeof(RegDespNode));
	return temp;
}

VarDespNode *getVarDespNode() {
	VarDespNode *temp;
	if(v_free == NULL) {
		v_free = (VarDespNode *)malloc(sizeof(VarDespNode) * v_NUM);
		for(temp = v_free; temp != v_free + v_NUM - 1; temp++) {
			temp->next = temp + 1;
		}
		temp->next = NULL;
	}
	temp = v_free;
	v_free = v_free->next;
	memset(temp,0,sizeof(VarDespNode));
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

void deleteOperandNode(OperandNode *o) {
	o->next = o_free;
	o_free = o;
}

void deleteInterCodeNode(InterCodeNode *i) {
	i->next = i_free;
	i_free = i;
}

void deleteBasicBlockNode(BasicBlockNode *b) {
	b->next = b_free;
	b_free = b;
}

void deleteRegDespNode(RegDespNode *r) {
	r->next = r_free;
	r_free = r;
}

void deleteVarDespNode(VarDespNode *v) {
	v->next = v_free;
	v_free = v;
}
