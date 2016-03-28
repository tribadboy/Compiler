#include <stdlib.h>
#include <string.h>
#include "type.h"

static PoolNode *p_free = NULL;
#define p_NUM 30
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

void deleteNode(PoolNode *p) {
	p->next = p_free;
	p_free = p;
}


