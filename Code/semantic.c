#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "type.h"


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
			SpecialType tmp_type;
			handleSpecifier(tmp->firstChild,&tmp_type);
			printf("kind: %d\n",(int)(tmp_type.kind));
			//do sth

		} else if(isProduction_2(tmp,MyEXTDEF,MySPECIFIER,MySEMI) == 1) {
			SpecialType tmp_type;
			handleSpecifier(tmp->firstChild,&tmp_type);
			printf("kind: %d\n",(int)(tmp_type.kind));
			// do sth
		} else if(isProduction_3(tmp,MyEXTDEF,MySPECIFIER,MyFUNDEC,MyCOMPST) == 1) {
			SpecialType tmp_type;
			handleSpecifier(tmp->firstChild,&tmp_type);
			printf("kind: %d\n",(int)(tmp_type.kind));
			// do sth
		}
		if(tmp->nextSibling != NULL) {
			push(tmp->nextSibling,high);
		}
		if(tmp->firstChild != NULL) {
			push(tmp->firstChild,high+1);
		}
	}
}
	
void handleSpecifier(CSNode *tmp, SpecialType *pos) {
	if(isProduction_1(tmp,MySPECIFIER,MyTYPE) == 1) {
		pos->kind = BASIC;
		CSNode *sptmp = tmp->firstChild;
		char * tmp = (sptmp->type_union).type_type.token;
		if(strcmp(tmp,"int") == 0) {
			pos->u.basic = 0;
		} else if(strcmp(tmp,"float") == 0) {
			pos->u.basic = 1;
		} else {
			pos->u.basic = 2;	//error
			printf("error basic ,neither int or float\n");
		}
	} else if(isProduction_1(tmp,MySPECIFIER,MySTRUCTSPECIFIER) == 1) {
		pos->kind = STRUCTURE;
		if(isProduction_5(tmp->firstChild,MySTRUCTSPECIFIER,MySTRUCT,MyOPTTAG,MyLC,MyDEFLIST,MyRC) == 1) {
			CSNode *opttag = tmp->firstChild->firstChild->nextSibling;
			int emptyFlag = 0;
			char *name = NULL;
			if(opttag->firstChild == NULL) {
				emptyFlag = 1;
				name = NULL;
			} else {
				emptyFlag = 0;
				name = (opttag->firstChild->type_union).type_id.p_str;
			}
			//should modify later
			FieldList *structtmp;
			structtmp = NULL; // error
			SYMBOL_STRUCTNAME *newNode = (SYMBOL_STRUCTNAME *)malloc(sizeof(SYMBOL_STRUCTNAME));
			newNode->structure = structtmp;
			int no = tmp->firstChild->firstChild->lineNo;
			addSymbol(MySTRUCTNAME, emptyFlag, name, no, newNode);
			(pos->u).structure = structtmp;

		} else if(isProduction_2(tmp->firstChild,MySTRUCTSPECIFIER,MySTRUCT,MyTAG) == 1) {
			char *id = (((tmp->firstChild)->firstChild)->nextSibling->firstChild->type_union).type_id.p_str;
			SYNode *tmp = checkSymbol(0,id);
			if(tmp == NULL) {	//not find id in symbol table
				printf("error ,use structure not defined\n");
				return;
			} else {
				if(tmp->type == MySTRUCTNAME) {
					(pos->u).structure = ((SYMBOL_STRUCTNAME *)(tmp->content))->structure;
				} else {
					printf("error id is same,but not same type\n");
					return;
				}
			}
		} else {
			printf("error StructSpecifier production\n");
		}
	} else {
		printf("error Specifier production\n");
		return;
	}
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
