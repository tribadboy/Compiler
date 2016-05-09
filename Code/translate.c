#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "type.h"
#include "ir.h"
#include "semantic.h"

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
	if(testSymbolMulArray() == 1) {
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
	else if(isProduction_3(root,MyEXTDEF,MySPECIFIER,MyEXTDECLIST,MySEMI) == 1) {
		printf("error, global variables exist\n");
		translateFlag = 0;
	}
	else if(isProduction_2(root,MyEXTDEF,MySPECIFIER,MySEMI) == 1) {
		// check mul-array in the struct
		// sooner in function testSymbolMulArray()
		// do nothing
	}
	else {
		printf("error ExtDef production(translate)\n");
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
			int emptyFlag = 0;
			char *name = (vardecNode->firstChild->type_union).type_id.p_str;
			SYNode *checkFlag = NULL;
			checkFlag = checkSymbolName(emptyFlag,name);
			if(checkFlag == NULL) {
				printf("error, not find symbol in the symbol table\n");
				translateFlag = 0;
				return;
			}
			int var_no = checkFlag->var_no;
			Operand *operand = getAndSetOperand_VARIABLE(var_no);
			InterCode *interCode = getAndSetInterCode_PARAM(operand);
			insertInterCode(interCode);
		}
		else if(isProduction_4(vardecNode,MyVARDEC,MyVARDEC,MyLB,MyINT,MyRB) == 1) {
			printf("Cannot translate: Code contains parameters of array type.\n");
			translateFlag = 0;
		}
		else {
			printf("error VarDec production(translate)\n");
			translateFlag = 0;
		}
	}
	else {
		printf("error ParamDec production(translate)\n");
		translateFlag = 0;
	}
}

//translate "CompSt -> ...|... "
void translateCompSt(CSNode *root) {
	if(isProduction_4(root,MyCOMPST,MyLC,MyDEFLIST,MySTMTLIST,MyRC) == 1) {
		translateDefList(root->firstChild->nextSibling);
		translateStmtList(root->firstChild->nextSibling->nextSibling);
	}
	else if(isProduction_2(root,MyCOMPST,MyLC,MyRC) == 1) {
		printf("Warning: the function has no value to return.\n");
	}
	else if(isProduction_3(root,MyCOMPST,MyLC,MyDEFLIST,MyRC) == 1) {
		translateDefList(root->firstChild->nextSibling);
	}
	else if(isProduction_3(root,MyCOMPST,MyLC,MySTMTLIST,MyRC) == 1) {
		translateStmtList(root->firstChild->nextSibling);
	}
	else {
		printf("error CompSt production(translate)\n");
		translateFlag = 0;
	}
}

//translate "DefList -> ...|... "
void translateDefList(CSNode *root) {
	if(isProduction_2(root,MyDEFLIST,MyDEF,MyDEFLIST) == 1) {
		translateDef(root->firstChild);
		translateDefList(root->firstChild->nextSibling);
	}
	else if(isProduction_1(root,MyDEFLIST,MyDEF) == 1) {
		translateDef(root->firstChild);
	}
	else {
		printf("error DefList production(translate)\n");
		translateFlag = 0;
	}
}

//translate "Def -> ...|... "
void translateDef(CSNode *root) {
	if(isProduction_3(root,MyDEF,MySPECIFIER,MyDECLIST,MySEMI) == 1) {
		translateDecList(root->firstChild->nextSibling);
	}
	else {
		printf("error Def production(translate)\n");
		translateFlag = 0;
	}
}

//translate "DecList -> ...|... "
void translateDecList(CSNode *root) {
	if(isProduction_1(root,MyDECLIST,MyDEC) == 1) {
		translateDec(root->firstChild);
	}
	else if(isProduction_3(root,MyDECLIST,MyDEC,MyCOMMA,MyDECLIST) == 1) {
		translateDec(root->firstChild);
		translateDecList(root->firstChild->nextSibling->nextSibling);
	}
	else {
		printf("error DecList production(translate)\n");
		translateFlag = 0;
	}
}

//translate "Dec -> ...|... "
void translateDec(CSNode *root) {
	if(isProduction_1(root,MyDEC,MyVARDEC) == 1) {
		translateVarDec(root->firstChild);
	}
	else if(isProduction_3(root,MyDEC,MyVARDEC,MyASSIGNOP,MyEXP) == 1) {
		translateVarDec(root->firstChild);

		//do sth about assign =
	}
	else {
		printf("error Dec production(translate)\n");
		translateFlag = 0;
	}
}

//translate "VarDec -> ...|... "
void translateVarDec(CSNode *root) {
	if(isProduction_1(root,MyVARDEC,MyID) == 1) {
		int emptyFlag = 0;
		char *name = (root->firstChild->type_union).type_id.p_str;
		SYNode *checkFlag = NULL;
		checkFlag = checkSymbolName(emptyFlag,name);
		if(checkFlag == NULL) {
			printf("error, not find symbol in the symbol table\n");
			translateFlag = 0;
			return;
		}
		SymbolType type = checkFlag->type;
		if(type == MyARRAYVAR) {
			SYMBOL_ARRAY *con = (SYMBOL_ARRAY *)(checkFlag->content);
			SpecialType *elemType = (con->type->u).array.elem;
			if(elemType->kind == ARRAY) {
				printf("Cannot translate: Code contains variables of multi-dimensional array type.\n");
				translateFlag = 0;
				return;
			}
			int var_no = checkFlag->var_no;
			int size = con->type->size;
			Operand *operand = getAndSetOperand_VARIABLE(var_no);
			InterCode *interCode = getAndSetInterCode_DEC(operand,size);
			insertInterCode(interCode);
		}
		else if(type == MySTRUCTVAR) {
			SYMBOL_STRUCTVAR *con = (SYMBOL_STRUCTVAR *)(checkFlag->content);
			int var_no = checkFlag->var_no;
			int size = con->type->size;
			Operand *operand = getAndSetOperand_VARIABLE(var_no);
			InterCode *interCode = getAndSetInterCode_DEC(operand,size);
			insertInterCode(interCode);
		}

	}
	else if(isProduction_4(root,MyVARDEC,MyVARDEC,MyLB,MyINT,MyRB) == 1) {
		translateVarDec(root->firstChild);
	}
	else {
		printf("error VarDec production(translate)\n");
		translateFlag = 0;
	}
}

//translate "StmtList -> ...|... "
void translateStmtList(CSNode *root) {
	if(isProduction_2(root,MySTMTLIST,MySTMT,MySTMTLIST) == 1) {
		translateStmt(root->firstChild);
		translateStmtList(root->firstChild->nextSibling);
	}
	else if(isProduction_1(root,MySTMTLIST,MySTMT) == 1) {
		translateStmt(root->firstChild);
	}
	else {
		printf("error StmtList production(translate)\n");
		translateFlag = 0;
	}
}
