#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "type.h"

static void handleExtDef(CSNode *root);
static SpecialType *handleSpecifier(CSNode *root);
static FieldList *handleDefList(CSNode *root);
static FieldList *handleDef(CSNode *root);
static FieldList *handleDecList(CSNode *root, SpecialType *basicType);
static FieldList *handleDec(CSNode *root, SpecialType *basicType);
static FieldList *handleVarDec(CSNode *root, SpecialType *basicType);

void preOrder(CSNode *root) {
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
	SpecialType *basicType = NULL;

	if(isProduction_3(root,MyEXTDEF,MySPECIFIER,MyEXTDECLIST,MySEMI) == 1) {
		basicType = handleSpecifier(root->firstChild);

		//do sth
		printf("kind: %d\n",(int)(basicType->kind));
	}
	else if(isProduction_2(root,MyEXTDEF,MySPECIFIER,MySEMI) == 1) {
		basicType = handleSpecifier(root->firstChild);

		//just define struct, ??? shengming
		printf("kind: %d\n",(int)(basicType->kind));
	}
	else if(isProduction_3(root,MyEXTDEF,MySPECIFIER,MyFUNDEC,MyCOMPST) == 1) {
		basicType = handleSpecifier(root->firstChild);

		//do sth
		printf("kind: %d\n",(int)(basicType->kind));
	}
	else {
		printf("error ExtDef produciton\n");
	}
}

//handle production "DefList -> Def DefList | empty"
static FieldList *handleDefList(CSNode *root){
	if(isProduction_2(root,MyDEFLIST,MyDEF,MyDEFLIST) == 1) {
		FieldList *pos1, *pos2;
		pos1 = handleDef(root->firstChild);
		pos2 = handleDefList(root->firstChild->nextSibling);
		if(pos1 == NULL) {
			return pos2;
		}
		FieldList *tmp = pos1;
		while(tmp->tail != NULL) {
			tmp = tmp->tail;
		}
		tmp->tail = pos2;
		return pos1;
	}
	else if(isProduction_0(root,MyDEFLIST) == 1) {
		return NULL;
	}
	else {
		printf("error DefList production\n");
		return NULL;
	}
	return NULL;
}


//handle production "Def -> Specifier DecList SEMI"
static FieldList *handleDef(CSNode *root) {
	if(isProduction_3(root,MyDEF,MySPECIFIER,MyDECLIST,MySEMI) == 1) {
		SpecialType *basicType = NULL;
		basicType = handleSpecifier(root->firstChild);
		if(basicType == NULL) {
			printf("error specifier,fail to handle DecList\n");
			return NULL;
		}
		FieldList *fd_tmp = NULL;
		fd_tmp = handleDecList(root,basicType);
		return fd_tmp;
	}
	else {
		printf("error Def production\n");
		return NULL;
	}
}

//handle production "DecList -> ...|... "
static FieldList *handleDecList(CSNode *root, SpecialType *basicType) {
	if(isProduction_1(root,MyDECLIST,MyDEC) == 1) {
		FieldList *fd_tmp = NULL;
		fd_tmp = handleDec(root->firstChild,basicType);
		return fd_tmp;
	}
	else if(isProduction_3(root,MyDECLIST,MyDEC,MyCOMMA,MyDECLIST) == 1) {
		FieldList *fd1_tmp, *fd2_tmp;
		fd1_tmp = handleDec(root->firstChild,basicType);
		fd2_tmp = handleDecList(root->firstChild->nextSibling->nextSibling,basicType);
		if(fd1_tmp == NULL) {
			return fd2_tmp;
		}
		//handleDec() just get only one FieldList node pointer
		fd1_tmp->tail = fd2_tmp;
		return fd1_tmp;
	}
	else {
		printf("error DecList production\n");
		return NULL;
	}
}


//handle production "Dec -> ...|... "
static FieldList *handleDec(CSNode *root, SpecialType *basicType) {
	if(isProduction_1(root,MyDEC,MyVARDEC) == 1) {
		FieldList *fd_tmp = NULL;
		fd_tmp = handleVarDec(root->firstChild,basicType);
		return fd_tmp;
	}
	else if(isProduction_3(root,MyDEC,MyVARDEC,MyASSIGNOP,MyEXP) == 1) {
		FieldList *fd_tmp;
		fd_tmp = handleVarDec(root->firstChild,basicType);

		//handle assignop exp

		return fd_tmp;
	}
	else {
		printf("error Dec production\n");
		return NULL;
	}
}

//handle production "VarDec -> ...|... "
static FieldList *handleVarDec(CSNode *root, SpecialType *basicType) {
	if(isProduction_1(root,MyVARDEC,MyID) == 1) {
		int emptyFlag = 0;
		char *name = (root->firstChild->type_union).type_id.p_str;
		int no_tmp = root->firstChild->lineNo;
		SYNode *checkFlag = checkSymbolName(emptyFlag,name);
		if(checkFlag != NULL) {
			printf("error, the id is same %s\n",name);
			return NULL;
		}
		SymbolType tp_tmp;
		if(basicType->kind == BASIC && (basicType->u).basic == 0) {
			tp_tmp = MyINTVAR;
			SYMBOL_INT *newContent = (SYMBOL_INT *)malloc(sizeof(SYMBOL_INT));
			addSymbol(tp_tmp,emptyFlag,name,no_tmp,newContent);
		}
		else if(basicType->kind == BASIC && (basicType->u).basic == 1) {
			tp_tmp = MyFLOATVAR;
			SYMBOL_FLOAT *newContent = (SYMBOL_FLOAT *)malloc(sizeof(SYMBOL_FLOAT));
			addSymbol(tp_tmp,emptyFlag,name,no_tmp,newContent);
		}
		else if(basicType->kind == ARRAY) {
			tp_tmp = MyARRAYVAR;
			SYMBOL_ARRAY *newContent = (SYMBOL_ARRAY *)malloc(sizeof(SYMBOL_ARRAY));
			newContent->type = basicType;
			addSymbol(tp_tmp,emptyFlag,name,no_tmp,newContent);
		}
		else if(basicType->kind == STRUCTURE) {
			tp_tmp = MySTRUCTVAR;
			SYMBOL_STRUCTVAR *newContent = (SYMBOL_STRUCTVAR *)malloc(sizeof(SYMBOL_STRUCTVAR));
			newContent->type = basicType;
			addSymbol(tp_tmp,emptyFlag,name,no_tmp,newContent);
		}
		else {
			printf("error basicType,id:%s has no meaning\n",name);
			return NULL;
		}
	}
	else if(isProduction_4(root,MyVARDEC,MyVARDEC,MyLB,MyINT,MyRB) == 1) {
		// int should >= 0
	}
	else {
		printf("error VarDec production\n");
		return NULL;
	}
}

//handle production "Specifier -> ...|... "
//apply a area if it is successful, but not give back
static SpecialType *handleSpecifier(CSNode *root) {
	SpecialType *pos;
	if(isProduction_1(root,MySPECIFIER,MyTYPE) == 1) {
		CSNode *sptmp = root->firstChild;
		char * token_tmp = (sptmp->type_union).type_type.token;
		if(strcmp(token_tmp,"int") == 0) {
			pos = (SpecialType *)malloc(sizeof(SpecialType));
			pos->kind = BASIC;
			(pos->u).basic = 0;
			return pos;
		} else if(strcmp(token_tmp,"float") == 0) {
			pos = (SpecialType *)malloc(sizeof(SpecialType));
			pos->kind = BASIC;
			(pos->u).basic = 1;
			return pos;
		} else {
			printf("error basic ,neither int or float\n");
			return NULL;
		}
	} else if(isProduction_1(root,MySPECIFIER,MySTRUCTSPECIFIER) == 1) {

		if(isProduction_5(root->firstChild,MySTRUCTSPECIFIER,MySTRUCT,MyOPTTAG,MyLC,MyDEFLIST,MyRC) == 1) {
			CSNode *deflist_tmp = root->firstChild->firstChild->nextSibling->nextSibling->nextSibling;
			FieldList *fd_tmp = handleDefList(deflist_tmp);
			

			CSNode *opttag_tmp = root->firstChild->firstChild->nextSibling;
			int emptyFlag;
			char *name;
			int addSymbolFlag = 0;
			if(opttag_tmp->firstChild == NULL) {	//build a noname struct
				emptyFlag = 1;
				name = NULL;		//should add a symbol no name
				addSymbolFlag = 1;
			} else {
				emptyFlag = 0;
				name = (opttag_tmp->firstChild->type_union).type_id.p_str;
				SYNode *checkFlag = checkSymbolName(emptyFlag,name);
				if(checkFlag != NULL) {
					//print error, no add symbol, but still return
					printf("error,build a struct which its name is be used early\n");
					addSymbolFlag = 0;
				} else {
					addSymbolFlag = 1;
				}
			}
			pos = (SpecialType *)malloc(sizeof(SpecialType));
			pos->kind = STRUCTURE;
			(pos->u).structure = fd_tmp;
			if(addSymbolFlag == 1) {
				SYMBOL_STRUCTNAME *newContent = (SYMBOL_STRUCTNAME *)malloc(sizeof(SYMBOL_STRUCTNAME));
				// add a structname symbol, its type is the type(pos) that build soon
				newContent->type = pos;
				int no_tmp = opttag_tmp->lineNo;
				addSymbol(MySTRUCTNAME, emptyFlag, name, no_tmp, newContent);
			}
			return pos;

		} else if(isProduction_2(root->firstChild,MySTRUCTSPECIFIER,MySTRUCT,MyTAG) == 1) {
			char *id = (((root->firstChild)->firstChild)->nextSibling->firstChild->type_union).type_id.p_str;
			SYNode *checkFlag = checkSymbolName(0,id);
			if(checkFlag == NULL) {	//not find id in symbol table
				printf("error??? ,use structure not defined\n");
				return NULL;
			} else {
				if(checkFlag->type == MySTRUCTNAME) {
					return ((SYMBOL_STRUCTNAME *)(checkFlag->content))->type;
				} else {
					printf("error id is same,but not same type\n");
					return NULL;
				}
			}
		} else {
			printf("error StructSpecifier production\n");
			return NULL;
		}
	} else {
		printf("error Specifier production\n");
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




