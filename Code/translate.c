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

//translate "ExtDef -> ...|... "
void translateExtDef(CSNode *root) {
	printf("translate ExtDef here\n");
	if(isProduction_3(root,MyEXTDEF,MySPECIFIER,MyFUNDEC,MyCOMPST) == 1) {
		translateFunDec(root->firstChild->nextSibling);
		translateCompSt(root->firstChild->nextSibling->nextSibling);
	}
	else {
		printf("cannot translate the ExtDef\n");
	}
}

//translate "FunDec -> ...|... "
void translateFunDec(CSNode *root) {
	if(isProduction_4(root,MyFUNDEC,MyID,MyLP,MyVARLIST,MyRP) == 1) {
		//do sth

	}
	else if(isProduction_3(root,MyFUNDEC,MyID,MyLP,MyRP) == 1) {
		char *name = (root->firstChild->type_union).type_id.p_str;
		InterCode *interCode = getAndSetInterCode_FUNCTION(name);
		insertInterCode(interCode);
	}
	else {
		printf("error FunDec production(translate)\n");
	}
}

//translate "CompSt -> ...|... "
void translateCompSt(CSNode *root) {
}
