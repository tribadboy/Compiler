#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "type.h"
#include "ir.h"

int translateFlag = 1;

void preOrderAndTranslate(CSNode *root) {
	if(root == NULL) {
		printf("the root is null, cannot translate\n");
		translateFlag = 0;
		return;
	}
	if(isStackEmpty() != 1) {
		printf("error, stack is not empty, cannot translate\n");
		translateFlag = 0;
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
	if(isProduction_3(root,MyEXTDEF,MySPECIFIER,MyFUNDEC,MyCOMPST) == 1) {
		translateFunDec(root->firstChild->nextSibling);
		translateCompSt(root->firstChild->nextSibling->nextSibling);
	}
	else {
		printf("cannot translate the ExtDef\n");
		translateFlag = 0;
	}
}

//translate "FunDec -> ...|... "
void translateFunDec(CSNode *root) {
	if(isProduction_4(root,MyFUNDEC,MyID,MyLP,MyVARLIST,MyRP) == 1) {
		char *name = (root->firstChild->type_union).type_id.p_str;
		InterCode *interCode = getAndSetInterCode_FUNCTION(name);
		insertInterCode(interCode);
		CSNode *varlist = root->firstChild->nextSibling->nextSibling;
		translateVarList(varlist);
	}
	else if(isProduction_3(root,MyFUNDEC,MyID,MyLP,MyRP) == 1) {
		char *name = (root->firstChild->type_union).type_id.p_str;
		InterCode *interCode = getAndSetInterCode_FUNCTION(name);
		insertInterCode(interCode);
	}
	else {
		printf("error FunDec production(translate)\n");
		translateFlag = 0;
	}
}

//translate "VarList -> ...|... "
void translateVarList(CSNode *root) {
	if(isProduction_3(root,MyVARLIST,MyPARAMDEC,MyCOMMA,MyVARLIST) == 1) {
		translateParamDec(root->firstChild);
		translateVarList(root->firstChild->nextSibling->nextSibling);
	}
	else if(isProduction_1(root,MyVARLIST,MyPARAMDEC) == 1) {
		translateParamDec(root->firstChild);
	}
	else {
		printf("error VarList production(translate)\n");
		translateFlag = 0;
	}
}

//translate "ParamDec -> ...|... "
void translateParamDec(CSNode *root) {
	if(isProduction_2(root,MyPARAMDEC,MySPECIFIER,MyVARDEC) == 1) {
		CSNode *vardecNode = root->firstChild->nextSibling;
		if(isProduction_1(vardecNode,MyVARDEC,MyID) == 1) {
		}
		else if(isProduction_4(vardecNode,MyVARDEC,MyVARDEC,MyLB,MyINT,MyRB) == 1) {
			//printf(
		}
	}
	else {
		printf("error ParamDec production(translate)\n");
		translateFlag = 0;
	}
}

//translate "CompSt -> ...|... "
void translateCompSt(CSNode *root) {
}
