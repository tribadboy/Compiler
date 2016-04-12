#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "type.h"

static void handleExtDef_1(CSNode *root);
static void handleExtDef_2(CSNode *root);
static void handleExtDef_3(CSNode *root);
static SpecialType *handleSpecifier(CSNode *root);
static FieldList *handleDefList(CSNode *root);

void preOrder(CSNode *root) {
	if(root == NULL) {
		return;
	}
	int high = 0;
	push(root,high);
	CSNode *tmp;
	while(pop(&tmp,&high)) {
		/*
		if(tmp->type == MyID) {
			addSymbol(MyINTVAR,tmp->type_union.type_id.p_str,tmp->lineNo);
		}
		for(int i = 0;i < high; i++) {
			printf("  ");
		}
		printTypeExp(tmp);
		*/
		//check some productions
		if(isProduction_3(tmp,MyEXTDEF,MySPECIFIER,MyEXTDECLIST,MySEMI) == 1) {
			handleExtDef_1(tmp);

		} else if(isProduction_2(tmp,MyEXTDEF,MySPECIFIER,MySEMI) == 1) {
			handleExtDef_2(tmp);

		} else if(isProduction_3(tmp,MyEXTDEF,MySPECIFIER,MyFUNDEC,MyCOMPST) == 1) {
			handleExtDef_3(tmp);

		}
		if(tmp->nextSibling != NULL) {
			push(tmp->nextSibling,high);
		}
		if(tmp->firstChild != NULL) {
			push(tmp->firstChild,high+1);
		}
	}
}
	
//handle production "ExtDef -> Specifier ExtDecList SEMI"
static void handleExtDef_1(CSNode *root) {
	SpecialType *basicType;
	basicType = handleSpecifier(root->firstChild);

	//do sth
	printf("kind: %d\n",(int)(basicType->kind));
}

//handle production "ExtDef -> Specifier SEMI"
static void handleExtDef_2(CSNode *root) {
	SpecialType *basicType;
	basicType = handleSpecifier(root->firstChild);

	//do sth
	printf("kind: %d\n",(int)(basicType->kind));
}

//handle production "ExtDef -> Specifier FunDec CompSt"
static void handleExtDef_3(CSNode *root) {
	SpecialType *basicType;
	basicType = handleSpecifier(root->firstChild);

	//do stf
	printf("kind: %d\n",(int)(basicType->kind));
}

static FieldList *handleDefList(CSNode *root){
	//do sth
	return NULL;
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
				printf("error ,use structure not defined\n");
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



// f is loc of the PoolNode, t -> empty
int isProduction_0(CSNode *f,TokenType t) {
	if(f != NULL && f->type == t && f->firstChild == NULL) {
		return 1;
	} else {
		return 0;
	}
}
	
// t -> c1
int isProduction_1(CSNode *f,TokenType t,TokenType c1) {
	if(f != NULL && f->type == t
		     && f->firstChild != NULL
		     && (f->firstChild)->type == c1
		     && (f->firstChild)->nextSibling == NULL
		     ) {
		return 1;
	} else {
		return 0;
	}
}

// t -> c1 c2
int isProduction_2(CSNode *f,TokenType t,TokenType c1,TokenType c2) {
	if(f != NULL && f->type == t && f->firstChild != NULL) {
		CSNode *tmp1 = f->firstChild;
		if(tmp1->type == c1 && tmp1->nextSibling != NULL) {
			CSNode *tmp2 = tmp1->nextSibling;
			if(tmp2->type == c2 && tmp2->nextSibling == NULL) {
				return 1;
			}
		}
	} else {
		return 0;
	}
}

// t -> c1 c2 c3
int isProduction_3(CSNode *f,TokenType t,TokenType c1,TokenType c2,TokenType c3) {
	if(f != NULL && f->type == t && f->firstChild != NULL) {
		CSNode *tmp1 = f->firstChild;
		if(tmp1->type == c1 && tmp1->nextSibling != NULL) {
			CSNode *tmp2 = tmp1->nextSibling;
			if(tmp2->type == c2 && tmp2->nextSibling != NULL) {
				CSNode *tmp3 = tmp2->nextSibling;
				if(tmp3->type == c3 && tmp3->nextSibling == NULL) {
					return 1;
				}
			}
		}
	} else {
		return 0;
	}
}

//f -> c1 c2 c3 c4
int isProduction_4(CSNode *f,TokenType t,TokenType c1,TokenType c2,TokenType c3,TokenType c4) {
	if(f != NULL && f->type == t && f->firstChild != NULL) {
		CSNode *tmp1 = f->firstChild;
		if(tmp1->type == c1 && tmp1->nextSibling != NULL) {
			CSNode *tmp2 = tmp1->nextSibling;
			if(tmp2->type == c2 && tmp2->nextSibling != NULL) {
				CSNode *tmp3 = tmp2->nextSibling;
				if(tmp3->type == c3 && tmp3->nextSibling != NULL) {
					CSNode *tmp4 = tmp3->nextSibling;
					if(tmp4->type == c4 && tmp4->nextSibling == NULL) {
						return 1;
					}
				}
			}
		}
	} else {
		return 0;
	}
}

//f -> c1 c2 c3 c4 c5
int isProduction_5(CSNode *f,TokenType t,TokenType c1,TokenType c2,TokenType c3,TokenType c4,TokenType c5) {
	if(f != NULL && f->type == t && f->firstChild != NULL) {
		CSNode *tmp1 = f->firstChild;
		if(tmp1->type == c1 && tmp1->nextSibling != NULL) {
			CSNode *tmp2 = tmp1->nextSibling;
			if(tmp2->type == c2 && tmp2->nextSibling != NULL) {
				CSNode *tmp3 = tmp2->nextSibling;
				if(tmp3->type == c3 && tmp3->nextSibling != NULL) {
					CSNode *tmp4 = tmp3->nextSibling;
					if(tmp4->type == c4 && tmp4->nextSibling != NULL) {
						CSNode *tmp5 = tmp4->nextSibling;
						if(tmp5->type == c5 && tmp5->nextSibling == NULL) {
							return 1;
						}
					}
				}
			}
		}
	} else {
		return 0;
	}
}
