#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "type.h"

static void handleExtDef(CSNode *root);
static SpecialType *handleSpecifier(CSNode *root);
static SpecialType *handleStructSpecifier(CSNode *root);
static FieldList *handleDefList(CSNode *root, int structFlag, FieldList *list);
static FieldList *handleDef(CSNode *root, int structFlag, FieldList *list);
static FieldList *handleDecList(CSNode *root, SpecialType *basicType, int structFlag, FieldList *list);
static FieldList *handleDec(CSNode *root, SpecialType *basicType, int structFlag, FieldList *list);
static FieldList *handleVarDec(CSNode *root, SpecialType *basicType, int structFlag, FieldList *list);
static FieldList *handleExtDecList(CSNode *root, SpecialType *basicType);
static void handleFunDec(CSNode *root, SpecialType *rel);
static FieldList *handleVarList(CSNode *root);
static FieldList *handleParamDec(CSNode *root);
static void handleCompSt(CSNode *root, SpecialType *rel);
static void handleStmtList(CSNode *root, SpecialType *rel);

void preOrderAndAnalysis(CSNode *root) {
	if(root == NULL) {
		return;
	}
	int high = 0;
	push(root,high);
	CSNode *tmp;
	while(pop(&tmp,&high)) {
		//check some type and productions

		// ExtDef -> ... | ...
		if(tmp->type == MyEXTDEF) {
			handleExtDef(tmp);
		}


		if(tmp->nextSibling != NULL) {
			push(tmp->nextSibling,high);
		}
		if(tmp->firstChild != NULL) {
			push(tmp->firstChild,high+1);
		}
	}
}

//handle production "ExtDef -> ... | ..."
static void handleExtDef(CSNode *root) {

	if(isProduction_3(root,MyEXTDEF,MySPECIFIER,MyEXTDECLIST,MySEMI) == 1) {
		SpecialType *basicType = NULL;
		basicType = handleSpecifier(root->firstChild);
		FieldList *fd = NULL;
		fd = handleExtDecList(root->firstChild->nextSibling,basicType);

	}
	else if(isProduction_2(root,MyEXTDEF,MySPECIFIER,MySEMI) == 1) {
		SpecialType *basicType = NULL;
		basicType = handleSpecifier(root->firstChild);
	}
	else if(isProduction_3(root,MyEXTDEF,MySPECIFIER,MyFUNDEC,MyCOMPST) == 1) {
		SpecialType *rel_type = NULL;
		rel_type = handleSpecifier(root->firstChild);
		handleFunDec(root->firstChild->nextSibling,rel_type);
		handleCompSt(root->firstChild->nextSibling->nextSibling,rel_type);

	}
	else {
		printf("error ExtDef produciton\n");
	}
	return;
}

//handle production "FunDec -> ...|... "
static void handleFunDec(CSNode *root, SpecialType *rel) {
	if(isProduction_4(root,MyFUNDEC,MyID,MyLP,MyVARLIST,MyRP) == 1) {
		CSNode *id_tmp = root->firstChild;
		char *name = (id_tmp->type_union).type_id.p_str;
		int emptyFlag = 0;
		SYNode *checkFlag = checkSymbolName(emptyFlag,name);
		if(checkFlag != NULL) {
			//func name is same, error
			printf("Error type 4 at Line %d: Redefined function \"%s\".\n",id_tmp->lineNo,name);
			return;
		} else {
			FieldList *fd_tmp = handleVarList(root->firstChild->nextSibling->nextSibling);
			//return NULL is error
			if(fd_tmp == NULL) {
				//the param of func is wrong, not store it
				return;
			}
			SYMBOL_FUNC *newContent = (SYMBOL_FUNC *)malloc(sizeof(SYMBOL_FUNC));
			newContent->rel = rel;
			newContent->param = fd_tmp;
			int no_tmp = root->firstChild->lineNo;
			addSymbol(MyFUNCNAME,emptyFlag,name,no_tmp,newContent);
			return;
		}
	}
	else if(isProduction_3(root,MyFUNDEC,MyID,MyLP,MyRP) == 1) {
		char *name = (root->firstChild->type_union).type_id.p_str;
		int emptyFlag = 0;
		SYNode *checkFlag = checkSymbolName(emptyFlag,name);
		if(checkFlag != NULL) {
			printf("Error type 4 at Line %d: Redefined function \"%s\".\n",root->firstChild->lineNo,name);
			return;
		} else {
			FieldList *fd_tmp = NULL;
			SYMBOL_FUNC *newContent = (SYMBOL_FUNC *)malloc(sizeof(SYMBOL_FUNC));
			newContent->rel = rel;
			newContent->param = NULL;
			int no_tmp = root->firstChild->lineNo;
			addSymbol(MyFUNCNAME,emptyFlag,name,no_tmp,newContent);
			return;
		}
	}
	else {
		printf("error FunDec production\n");
	}
	return;
}

//handle production "CompSt -> ...|... "
//DefList and StmtList could be empty
static void handleCompSt(CSNode *root, SpecialType *rel) {
	if(isProduction_4(root,MyCOMPST,MyLC,MyDEFLIST,MySTMTLIST,MyRC) == 1) {
		FieldList *fd = NULL;
		fd = handleDefList(root->firstChild->nextSibling,0,NULL);
		handleStmtList(root->firstChild->nextSibling->nextSibling,rel);

	}
	else if(isProduction_2(root,MyCOMPST,MyLC,MyRC) == 1) { 
		//the func is empty { }, no return value, do nothing
	}
	else if(isProduction_3(root,MyCOMPST,MyLC,MyDEFLIST,MyRC) == 1) {
		FieldList *fd = NULL;
		fd = handleDefList(root->firstChild->nextSibling,0,NULL);
		//no return value
	}
	else if(isProduction_3(root,MyCOMPST,MyLC,MySTMTLIST,MyRC) == 1) {
		handleStmtList(root->firstChild->nextSibling,rel);
	}
	else {
		printf("error CompSt production\n");
	}
}

//handle production "StmtList -> ...|... "
static void handleStmtList(CSNode *root, SpecialType *rel) {
}

//handle production "VarList -> ...|... "
static FieldList *handleVarList(CSNode *root) {
	if(isProduction_3(root,MyVARLIST,MyPARAMDEC,MyCOMMA,MyVARLIST) == 1) {
		FieldList *fd1_tmp, *fd2_tmp;
		fd1_tmp = handleParamDec(root->firstChild);
		fd2_tmp = handleVarList(root->firstChild->nextSibling->nextSibling);
		if(fd1_tmp == NULL) {
			return fd2_tmp;
		}
		//handleParamDec() just get only one FieldList node pointer
		fd1_tmp->tail = fd2_tmp;
		return fd1_tmp;
	}
	else if(isProduction_1(root,MyVARLIST,MyPARAMDEC) == 1) {
		FieldList *fd_tmp = NULL;
		fd_tmp = handleParamDec(root->firstChild);
		return fd_tmp;
	}
	else {
		printf("error VarList production\n");
		return NULL;
	}
	return NULL;
}

//handle production "ParamDec -> Specifier VarDec"
FieldList *handleParamDec(CSNode *root) {
	if(isProduction_2(root,MyPARAMDEC,MySPECIFIER,MyVARDEC) == 1) {
		SpecialType *basicType = NULL;
		basicType = handleSpecifier(root->firstChild);
		FieldList *fd = NULL;
		fd = handleVarDec(root->firstChild->nextSibling,basicType,0,NULL);
		return fd;
	}
	else {
		printf("error ParamDec production\n");
		return NULL;
	}
}

//handle production "DefList -> Def DefList | empty"
static FieldList *handleDefList(CSNode *root, int structFlag, FieldList *list) {
	if(isProduction_2(root,MyDEFLIST,MyDEF,MyDEFLIST) == 1) {
		FieldList *newList = NULL;
		newList = handleDef(root->firstChild,structFlag,list);
		newList = handleDefList(root->firstChild->nextSibling,structFlag,newList);
		return newList;
	}
	else if(isProduction_1(root,MyDEFLIST,MyDEF) == 1) {
		FieldList *fd = NULL;
		fd = handleDef(root->firstChild,structFlag,list);
		return fd;
	}
	else {
		printf("error DefList production\n");
		return NULL;
	}
	return NULL;
}


//handle production "Def -> Specifier DecList SEMI"
static FieldList *handleDef(CSNode *root, int structFlag, FieldList *list) {
	if(isProduction_3(root,MyDEF,MySPECIFIER,MyDECLIST,MySEMI) == 1) {
		SpecialType *basicType = NULL;
		basicType = handleSpecifier(root->firstChild);
		if(basicType == NULL) {
			//type is error, not store var in DecList
			return NULL;
		}
		FieldList *fd_tmp = NULL;
		fd_tmp = handleDecList(root->firstChild->nextSibling,basicType,structFlag,list);
		return fd_tmp;
	}
	else {
		printf("error Def production\n");
		return NULL;
	}
}

//handle production "DecList -> ...|... "
static FieldList *handleDecList(CSNode *root, SpecialType *basicType, int structFlag, FieldList *list) {
	if(isProduction_1(root,MyDECLIST,MyDEC) == 1) {
		FieldList *fd_tmp = NULL;
		fd_tmp = handleDec(root->firstChild,basicType,structFlag,list);
		return fd_tmp;
	}
	else if(isProduction_3(root,MyDECLIST,MyDEC,MyCOMMA,MyDECLIST) == 1) {
		FieldList *newList = NULL;
		newList = handleDec(root->firstChild,basicType,structFlag,list);
		newList = handleDecList(root->firstChild->nextSibling->nextSibling,basicType,structFlag,newList);
		return newList;
	}
	else {
		printf("error DecList production\n");
		return NULL;
	}
}

//handle production "ExtDecList -> ...|..."
static FieldList *handleExtDecList(CSNode *root, SpecialType *basicType) {
	if(isProduction_1(root,MyEXTDECLIST,MyVARDEC) == 1) {
		FieldList *fd_tmp = NULL;
		fd_tmp = handleVarDec(root->firstChild,basicType,0,NULL);
		return fd_tmp;
	}
	else if(isProduction_3(root,MyEXTDECLIST,MyVARDEC,MyCOMMA,MyEXTDECLIST) == 1) {
		FieldList *fd1_tmp, *fd2_tmp;
		fd1_tmp = handleVarDec(root->firstChild,basicType,0,NULL);
		fd2_tmp = handleExtDecList(root->firstChild->nextSibling->nextSibling,basicType);
		if(fd1_tmp == NULL) {
			return fd2_tmp;
		}
		//handleVarDec() just get only one FieldList node pointer
		fd1_tmp->tail = fd2_tmp;
		return fd1_tmp;
	}
	else {
		printf("error ExtDecList production\n");
		return NULL;
	}
}

//handle production "Dec -> ...|... "
static FieldList *handleDec(CSNode *root, SpecialType *basicType, int structFlag, FieldList *list) {
	if(isProduction_1(root,MyDEC,MyVARDEC) == 1) {
		FieldList *fd_tmp = NULL;
		fd_tmp = handleVarDec(root->firstChild,basicType,structFlag,list);
		return fd_tmp;
	}
	else if(isProduction_3(root,MyDEC,MyVARDEC,MyASSIGNOP,MyEXP) == 1) {
		FieldList *fd_tmp;
		fd_tmp = handleVarDec(root->firstChild,basicType,structFlag,list);
		if(structFlag == 1) {
			printf("Error type 15 at Line %d: Initialization in the struct definition.\n",root->firstChild->nextSibling->lineNo);
			return fd_tmp;
		}
		//do sth
		//handle assignop exp

		return fd_tmp;
	}
	else {
		printf("error Dec production\n");
		return NULL;
	}
}

//handle production "VarDec -> ...|... "
static FieldList *handleVarDec(CSNode *root, SpecialType *basicType, int structFlag, FieldList *list) {
	if(isProduction_1(root,MyVARDEC,MyID) == 1) {
		int emptyFlag = 0;
		char *name = (root->firstChild->type_union).type_id.p_str;
		int no_tmp = root->firstChild->lineNo;
		SYNode *checkFlag = checkSymbolName(emptyFlag,name);
		if(checkFlag != NULL) {
			if(structFlag == 1 && checkSameNameFL(name,list) != NULL) {
				printf("Error type 15 at Line %d: Redefined field \"%s\".\n",root->firstChild->lineNo,name);
				return NULL;
			}
			printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",root->firstChild->lineNo,name);
			return NULL;
		}
		SymbolType tp_tmp;
		if(basicType->kind == BASIC && (basicType->u).basic == 0) {
			tp_tmp = MyINTVAR;
			SYMBOL_INT *newContent = (SYMBOL_INT *)malloc(sizeof(SYMBOL_INT));
			addSymbol(tp_tmp,emptyFlag,name,no_tmp,newContent);
			FieldList *fd = getAndSetFieldList(name,basicType,NULL);
			return linkList(list,fd);
		}
		else if(basicType->kind == BASIC && (basicType->u).basic == 1) {
			tp_tmp = MyFLOATVAR;
			SYMBOL_FLOAT *newContent = (SYMBOL_FLOAT *)malloc(sizeof(SYMBOL_FLOAT));
			addSymbol(tp_tmp,emptyFlag,name,no_tmp,newContent);
			FieldList *fd = getAndSetFieldList(name,basicType,NULL);
			return linkList(list,fd);
		}
		else if(basicType->kind == ARRAY) {
			tp_tmp = MyARRAYVAR;
			SYMBOL_ARRAY *newContent = (SYMBOL_ARRAY *)malloc(sizeof(SYMBOL_ARRAY));
			newContent->type = basicType;
			addSymbol(tp_tmp,emptyFlag,name,no_tmp,newContent);
			FieldList *fd = getAndSetFieldList(name,basicType,NULL);
			return linkList(list,fd);
		}
		else if(basicType->kind == STRUCTURE) {
			tp_tmp = MySTRUCTVAR;
			SYMBOL_STRUCTVAR *newContent = (SYMBOL_STRUCTVAR *)malloc(sizeof(SYMBOL_STRUCTVAR));
			newContent->type = basicType;
			addSymbol(tp_tmp,emptyFlag,name,no_tmp,newContent);
			FieldList *fd = getAndSetFieldList(name,basicType,NULL);
			return linkList(list,fd);
		}
		else {
			printf("error basicType,id:%s has no meaning\n",name);
			return NULL;
		}
	}
	else if(isProduction_4(root,MyVARDEC,MyVARDEC,MyLB,MyINT,MyRB) == 1) {
		// int should > 0
		CSNode *int_tmp = root->firstChild->nextSibling->nextSibling;
		int size = (int_tmp->type_union).type_int.value;
		if(size <= 0) {
			printf("Error at Line %d: Array size %d should bigger than 0.\n",int_tmp->lineNo,size);
			return NULL;
		}
		SpecialType *basicType_tmp = NULL;
		basicType_tmp = (SpecialType *)malloc(sizeof(SpecialType));
		basicType_tmp->kind = ARRAY;
		(basicType_tmp->u).array.elem = basicType;
		(basicType_tmp->u).array.size = size;
		FieldList *fd_tmp = NULL;
		fd_tmp = handleVarDec(root->firstChild,basicType_tmp,structFlag,list);
		return fd_tmp;
	}
	else {
		printf("error VarDec production\n");
		return NULL;
	}
}

//handle production "Specifier -> ...|... "
//could apply a area if it is successful, but not give back
static SpecialType *handleSpecifier(CSNode *root) {
	SpecialType *basicType = NULL;
	if(isProduction_1(root,MySPECIFIER,MyTYPE) == 1) {
		char *token_tmp = (root->firstChild->type_union).type_type.token;
		if(strcmp(token_tmp,"int") == 0) {
			basicType = (SpecialType *)malloc(sizeof(SpecialType));
			basicType->kind = BASIC;
			(basicType->u).basic = 0;
			return basicType;
		}
		else if(strcmp(token_tmp,"float") == 0) {
			basicType = (SpecialType *)malloc(sizeof(SpecialType));
			basicType->kind = BASIC;
			(basicType->u).basic = 1;
			return basicType;
		}
		else {
			printf("error basic type, neither int nor float at line %d.\n",root->firstChild->lineNo);
			return NULL;
		}
	}
	else if(isProduction_1(root,MySPECIFIER,MySTRUCTSPECIFIER) == 1) {
		basicType = handleStructSpecifier(root->firstChild);
		return basicType;
	}
	else {
		printf("error Specifier production\n");
		return NULL;
	}
	return NULL;
}

//handle production "StructSpecifier -> ...|... "
//apply a area if it is successful, but not give back
//OptTag could be empty
static SpecialType *handleStructSpecifier(CSNode *root) {
	SpecialType *basicType = NULL;

	//OptTag is not empty
	if(isProduction_5(root,MySTRUCTSPECIFIER,MySTRUCT,MyOPTTAG,MyLC,MyDEFLIST,MyRC) == 1 || isProduction_4(root,MySTRUCTSPECIFIER,MySTRUCT,MyOPTTAG,MyLC,MyRC) == 1) {
		CSNode *opttag_tmp = root->firstChild->nextSibling;
		int emptyFlag = 0;
		char *name = (opttag_tmp->firstChild->type_union).type_id.p_str;
		int addSymbolFlag = 0;
		SYNode *checkFlag = checkSymbolName(emptyFlag,name);
		if(checkFlag != NULL) {
			//print error ,name is same
			printf("Error type 16 at Line %d: Duplicated name \"%s\".\n",opttag_tmp->firstChild->lineNo,name);
			addSymbolFlag = 0;
		}
		else {
			addSymbolFlag = 1;
		}
		FieldList *fd_tmp = NULL;
		CSNode *dl_tmp = root->firstChild->nextSibling->nextSibling->nextSibling;
		if(dl_tmp->type == MyDEFLIST) {
			fd_tmp = handleDefList(dl_tmp,1,NULL);
		}
		basicType = (SpecialType *)malloc(sizeof(SpecialType));
		basicType->kind = STRUCTURE;
		(basicType->u).structure = fd_tmp;
		if(addSymbolFlag == 1) {
			SYMBOL_STRUCTNAME *newContent = (SYMBOL_STRUCTNAME *)malloc(sizeof(SYMBOL_STRUCTNAME));
			// add a structname symbol, its type is the basicType that build soon
			newContent->type = basicType;
			int no_tmp = opttag_tmp->firstChild->lineNo;
			addSymbol(MySTRUCTNAME,emptyFlag,name,no_tmp,newContent);
		}
		return basicType;
	}

	//OptTag is empty
	else if(isProduction_4(root,MySTRUCTSPECIFIER,MySTRUCT,MyLC,MyDEFLIST,MyRC) == 1 || isProduction_3(root,MySTRUCTSPECIFIER,MySTRUCT,MyLC,MyRC) == 1) {
		int emptyFlag = 1;
		char *name = NULL;
		FieldList *fd_tmp = NULL;
		CSNode *dl_tmp = root->firstChild->nextSibling->nextSibling;
		if(dl_tmp->type == MyDEFLIST) {
			fd_tmp = handleDefList(dl_tmp,1,NULL);
		}
		basicType = (SpecialType *)malloc(sizeof(SpecialType));
		basicType->kind = STRUCTURE;
		(basicType->u).structure = fd_tmp;

		//add a structname symbol whose name is empty
		SYMBOL_STRUCTNAME *newContent = (SYMBOL_STRUCTNAME *)malloc(sizeof(SYMBOL_STRUCTNAME));
		newContent->type = basicType;
		//line record the STRUCT position
		int no_tmp = root->firstChild->lineNo;
		addSymbol(MySTRUCTNAME,emptyFlag,name,no_tmp,newContent);

		return basicType;

	}
	else if(isProduction_2(root,MySTRUCTSPECIFIER,MySTRUCT,MyTAG) == 1) {
		CSNode *id_tmp = root->firstChild->nextSibling->firstChild;
		char *name = (id_tmp->type_union).type_id.p_str;
		SYNode *checkFlag = checkSymbolName(0,name);
		if(checkFlag == NULL) {
			//not find symbol in the table
			printf("Error type 17 at Line %d: Undefined structure \"%s\".\n",id_tmp->lineNo,name);
			return NULL;
		}
		else {
			if(checkFlag->type != MySTRUCTNAME) {
				printf("Error type 17 at Line %d: Undefined structure and the name \"%s\" is duplicated.\n",id_tmp->lineNo,name); 
				return NULL;
			}
			else {
				return ((SYMBOL_STRUCTNAME *)(checkFlag->content))->type;
			}
		}
	}
	else {
		printf("error StructSpecifier production\n");
		return NULL;
	}
	return NULL;
}

//post order and compute syn attribute
void postOrder(CSNode *root) {
	if(root == NULL) {
		return;
	}
	int high = 0;
	CSNode *tmp = root;
	while(1) {
		while(tmp != NULL) {
			push(tmp,high);
			high += 1;
			tmp = tmp->firstChild;
		}
		pop(&tmp,&high);
		for(int i = 0; i < high; i++) {
			printf("  ");
		}
		printTypeExp(tmp);
		// if the pop node is root, print the info and exit
		if(tmp == root) {
			return;
		}
		// root node has no siblings
		if(tmp->nextSibling != NULL) {
			tmp = tmp->nextSibling;
		} else {
			tmp = NULL;
		}
	}
}




