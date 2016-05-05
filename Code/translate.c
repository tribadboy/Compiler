#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "type.h"
#include "ir.h"

void preOrderAndTranslate(CSNode *root) {
	if(root == NULL) {
		return;
	}
	int high = 0;
	push(root,high);
	CSNode *tmp;
	while(pop(&tmp,&high)) {
		//check type and production 
		
		// ExtDef -> ...|...
		if(tmp->type == MyEXTDEF) {
			translateExtDef(tmp);
		}

		if(tmp->nextSibling != NULL) {
			push(tmp->nextSibling,high);
		}
		if(tmp->firstChild != NULL) {
			push(tmp->firstChild,high+1);
		}
	}
}

void translateExtDef(CSNode *root) {
	printf("translate ExtDef here\n");
}
