#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "type.h"
#include "semantic.h"

//compare two specialType, equal return 1, else return 0
int compareSpecialType(SpecialType *type1, SpecialType *type2) {
	if(type1->kind == type2->kind) {
		if(type1->kind == BASIC) {
			if((type1->u).basic == (type2->u).basic) {
				return 1;
			}
			else {
				printf("type error, int != float\n");
				return 0;
			}
		}
		else if(type1->kind == ARRAY) {
			return compareSpecialType((type1->u).array.elem,(type2->u).array.elem);
		}
		else{
			FieldList *fd1 = (type1->u).structure;
			FieldList *fd2 = (type2->u).structure;
			if(fd1 == fd2) {
				return 1;
			}
			else if(fd1 == NULL || fd2 == NULL) {
				return 0;
			}
			while(fd1 != NULL && fd2 != NULL) {
				if(compareSpecialType(fd1->type,fd2->type) == 0) {
					return 0;
				}
				fd1 = fd1->tail;
				fd2 = fd2->tail;
			}
			if(fd1 == NULL && fd2 == NULL) {
				return 1;
			}
		}
	}
	else {
		printf("type cannot match\n");
		return 0;
	}
}

//handle production "Stmt -> ...|... "
void handleStmt(CSNode *root, SpecialType *rel) {
	if(isProduction_2(root,MySTMT,MyEXP,MySEMI) == 1) {
		SpecialType *expType = NULL;
		expType = handleExp(root->firstChild);
	}
	else if(isProduction_1(root,MySTMT,MyCOMPST) == 1) {
		handleCompSt(root->firstChild,rel);
	}
	else if(isProduction_3(root,MySTMT,MyRETURN,MyEXP,MySEMI) == 1) {
		SpecialType *expType = NULL;
		expType = handleExp(root->firstChild->nextSibling);
		if(compareSpecialType(rel,expType) == 0) {
			printf("type cannot match in return\n");
		}
		//
	}
	else if(isProduction_5(root,MySTMT,MyIF,MyLP,MyEXP,MyRP,MySTMT) == 1) {
	}
	else if(isProduction_7(root,MySTMT,MyIF,MyLP,MyEXP,MyRP,MySTMT,MyELSE,MySTMT) == 1) {
	}
	else if(isProduction_5(root,MySTMT,MyWHILE,MyLP,MyEXP,MyRP,MySTMT) == 1) {
	}
	else {
		printf("error Stmt production\n");
	}
}

//handle production "Exp -> ...|... "
//maybe it waste some time , should modify later
SpecialType *handleExp(CSNode *root) {
	if(isProduction_3(root,MyEXP,MyEXP,MyASSIGNOP,MyEXP) == 1) {
		return NULL;
	}
	else if(isProduction_3(root,MyEXP,MyEXP,MyAND,MyEXP) == 1) {
		return NULL;
	}
	else if(isProduction_3(root,MyEXP,MyEXP,MyOR,MyEXP) == 1) {
		return NULL;
	}
	else if(isProduction_3(root,MyEXP,MyEXP,MyRELOP,MyEXP) == 1) {
		return NULL;
	}
	else if(isProduction_3(root,MyEXP,MyEXP,MyPLUS,MyEXP) == 1) {
		return NULL;
	}
	else if(isProduction_3(root,MyEXP,MyEXP,MyMINUS,MyEXP) == 1) {
		return NULL;
	}
	else if(isProduction_3(root,MyEXP,MyEXP,MySTAR,MyEXP) == 1) {
		return NULL;
	}
	else if(isProduction_3(root,MyEXP,MyEXP,MyDIV,MyEXP) == 1) {
		return NULL;
	}
	else if(isProduction_3(root,MyEXP,MyLP,MyEXP,MyRP) == 1) {
		return NULL;
	}
	else if(isProduction_2(root,MyEXP,MyMINUS,MyEXP) == 1) {
		return NULL;
	}
	else if(isProduction_2(root,MyEXP,MyNOT,MyEXP) == 1) {
		return NULL;
	}
	else if(isProduction_4(root,MyEXP,MyID,MyLP,MyARGS,MyRP) == 1) {
		return NULL;
	}
	else if(isProduction_3(root,MyEXP,MyID,MyLP,MyRP) == 1) {
		return NULL;
	}
	else if(isProduction_4(root,MyEXP,MyEXP,MyLB,MyEXP,MyRB) == 1) {
		return NULL;
	}
	else if(isProduction_3(root,MyEXP,MyEXP,MyDOT,MyID) == 1) {
		return NULL;
	}
	else if(isProduction_1(root,MyEXP,MyID) == 1) {
		return NULL;
	}
	else if(isProduction_1(root,MyEXP,MyINT) == 1) {
		return NULL;
	}
	else if(isProduction_1(root,MyEXP,MyFLOAT) == 1) {
		return NULL;
	}
	else {
		printf("error Exp production\n");
		return NULL;
	}
}

