#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "type.h"


//void preOrderAndAddSymbols() {
void preOrder(CSNode *root) {
	int high = 0;
	push(root,high);
	CSNode *tmp;
	while(pop(&tmp,&high)) {
		if(tmp->type == MyID) {
			addSymbol(MyINTVAR,tmp->type_union.type_id.p_str,tmp->lineNo);
		}
		if(tmp->nextSibling != NULL) {
			push(tmp->nextSibling,high);
		}
		if(tmp->firstChild != NULL) {
			push(tmp->firstChild,high+1);
		}
	}
}
	
