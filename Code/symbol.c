#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "type.h"
#include "semantic.h"

#define TABLE_SIZE 200

static int initFlag = 0;
static SYNode *hashtable[TABLE_SIZE];
static char myReadFunc[8] = "read";
static char myWriteFunc[8] = "write";
static int var_no = 1;

static void addReadAndWriteFunction();

static void initSymbolTable() {
	initFlag = 1;
	int i;
	for(i = 0; i < TABLE_SIZE; i++) {
		hashtable[i] = NULL;
	}
	addReadAndWriteFunction();
}

//init symbol table, add read() and write() function
static void addReadAndWriteFunction() {
	SYMBOL_FUNC *newContent1 = (SYMBOL_FUNC *)malloc(sizeof(SYMBOL_FUNC));
	SYMBOL_FUNC *newContent2 = (SYMBOL_FUNC *)malloc(sizeof(SYMBOL_FUNC));
	SpecialType *rel1 = (SpecialType *)malloc(sizeof(SpecialType));
	SpecialType *rel2 = (SpecialType *)malloc(sizeof(SpecialType));
	SpecialType *param2 = (SpecialType *)malloc(sizeof(SpecialType));
	rel1->kind = BASIC;
	(rel1->u).basic = 0;
	rel1->size = getSizeOfSpecialType(rel1);
	rel2->kind = BASIC;
	(rel2->u).basic = 0;
	rel2->size = getSizeOfSpecialType(rel2);
	param2->kind = BASIC;
	(param2->u).basic = 0;
	param2->size = getSizeOfSpecialType(param2);
	FieldList *fd2 = getAndSetFieldList(NULL,param2,NULL);
	newContent1->rel = rel1;
	newContent1->param = NULL;
	newContent1->param_num = 0;
	newContent2->rel = rel2;
	newContent2->param = fd2;
	newContent2->param_num = 1;
	
	addSymbol(MyFUNCNAME,0,myReadFunc,0,newContent1);
	addSymbol(MyFUNCNAME,0,myWriteFunc,0,newContent2);
}

static unsigned int hash_djb(char *name) {
	if(name == NULL) {		//location is hashtable[0]
		return 0;
	}
	unsigned int val = 5381;
	for(; *name; ++name) {
		val = (val << 5) + val +  *name;
	}
	return val % (TABLE_SIZE - 1) + 1;  //location is hashtable[1]-hashtable[TABLE_SIZE-1]
}

// check whether the symbol name is same ,if same return pos,or return NULL
// if name is NULL(emptyFlag == 1),  think is no same
SYNode *checkSymbolName(int emptyFlag, char* name) {
	if(initFlag == 0) {
		initSymbolTable();
	}

	if(emptyFlag == 1 && name == NULL) {
		return NULL;
	} else if(emptyFlag == 0 && name != NULL) {	//name is not NULL, and index unit should has no symbol that name is also NULL
		unsigned int index = hash_djb(name);
		SYNode *temp;
		if(hashtable[index] != NULL) {
			temp = hashtable[index];
			if(strcmp(temp->name,name) == 0) {
				return temp;
			}
			while(temp->nextHash != NULL) {
				temp = temp->nextHash;
				if(strcmp(temp->name,name) == 0) {
					return temp;
				}
			}
		}
		return NULL;
	} else {
		printf("error, emptyFlag and name is not match\n");
		return NULL;
	}
}

//only add a symbol in the hashtable, not check whether same
void addSymbol(SymbolType t, int emptyFlag, char* name, int no, void *con) {
	if(initFlag == 0) {
		initSymbolTable();
	}
	
	unsigned int index = hash_djb(name);
/*	SYNode *temp;
	if(hashtable[index] != NULL) {
		temp = hashtable[index];
		//check same
		if(temp->isEmpty == 0 && emptyFlag == 0 && strcmp(temp->name,name) == 0) {
			// should modify and split to serveral types error later
			printf("###find a same name %s at line %d\n",name,no);
			return;
		}
		while(temp->nextHash != NULL) {
			temp = temp->nextHash;
			if(temp->isEmpty == 0 && emptyFlag == 0 && strcmp(temp->name,name) == 0){
				// should modify ......
				printf("###find a same name %s at line %d\n",name,no);
				return;
			}
			
		}
	}
*/
	//not check whether same, get and build a SYNode
	SymbolNode *p = getSymbolNode();
	SYNode *pnode = &(p->s_node);
	pnode->type = t;
	pnode->isEmpty = emptyFlag;
	pnode->lineno = no;
	pnode->name = name;
	pnode->content = con;
	//insert at the head of every unit in the hashtable
	pnode->nextHash = hashtable[index];
	pnode->var_no = var_no++;
	hashtable[index] = pnode;
}

//look the contents in the hashtable for checking
void testSymbol() {
	int i;
	SpecialType *type = NULL;
	void *content = NULL;
	printf("-------------test hashtable-----------------\n");
	for(i = 0; i < TABLE_SIZE; i++) {
		if(hashtable[i] != NULL) {
			SYNode *temp = hashtable[i];
			printf("index: %d\n", i);
			while(temp != NULL) {
				if(i == 0) {
					printf("type: %d\t name: empty\t line: %d\tvar_no: %d\t",(int)temp->type,temp->lineno,temp->var_no);
				} else {
					printf("type: %d\t name: %s\t line: %d\tvar_no: %d\t",(int)temp->type,temp->name,temp->lineno,temp->var_no);
				}
				if(temp->type == MyINTVAR) {
					content = temp->content;
					type = ((SYMBOL_INT *)content)->type;
					printf("size: %d\n",type->size);
				} else if(temp->type == MyFLOATVAR) {
					content = temp->content;
					type = ((SYMBOL_FLOAT *)content)->type;
					printf("size: %d\n",type->size);
				} else if(temp->type == MyARRAYVAR) {
					content = temp->content;
					type = ((SYMBOL_ARRAY *)content)->type;
					printf("size: %d\n",type->size);
				} else if(temp->type == MySTRUCTNAME) {
					content = temp->content;
					type = ((SYMBOL_STRUCTNAME *)content)->type;
					printf("size: %d\n",type->size); 
				} else if(temp->type == MySTRUCTVAR) {
					content = temp->content;
					type = ((SYMBOL_STRUCTVAR *)content)->type;
					printf("size: %d\n",type->size);
				} else if(temp->type == MyFUNCNAME) {
					content = temp->content;
					type = ((SYMBOL_FUNC *)content)->rel;
					printf("size(rel): %d\n",type->size);
				} else {
					printf("error type\n");
				}
				temp = temp->nextHash;
			}
			printf("\n");
		}
	}
}






