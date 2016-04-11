#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "type.h"

#define TABLE_SIZE 200

//static int initFlag = 0;
static SYNode *hashtable[TABLE_SIZE];

void initSymbolTable() {
	int i;
	for(i = 0; i < TABLE_SIZE; i++) {
		hashtable[i] = NULL;
	}
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

// a test func, ignore the type content, just consider the name
// find and add a SYNode

// check whether the symbol name is same ,if same return pos,or return NULL
SYNode *checkSymbol(int emptyFlag, char* name) {
	unsigned int index = hash_djb(name);
	SYNode *temp;
	if(hashtable[index] != NULL) {
		temp = hashtable[index];
		if(temp->isEmpty == 0 && emptyFlag == 0 && strcmp(temp->name,name) == 0) {
			return temp;
		}
		while(temp->nextHash != NULL) {
			temp = temp->nextHash;
			if(temp->isEmpty == 0 && emptyFlag == 0 && strcmp(temp->name,name) == 0) {
				return temp;
			}
		}
	}
	return NULL;
}

void addSymbol(SymbolType t, int emptyFlag, char* name, int no, void *pos) {
	
	unsigned int index = hash_djb(name);
	SYNode *temp;
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
	//confirm no same, get and build a SYNode
	SymbolNode *p = getSymbolNode();
	SYNode *pnode = &(p->s_node);
	pnode->type = t;
	pnode->isEmpty = emptyFlag;
	pnode->lineno = no;
	pnode->name = name;
	pnode->content = pos;
	pnode->nextHash = NULL;
	//should modify sth here
	pnode->content = NULL;
	if(hashtable[index] == NULL) {
		hashtable[index] = pnode;
	} else {
		temp->nextHash = pnode;
	}
}

//look the contents in the hashtable for checking
void testSymbol() {
	int i;
	printf("-------------test hashtable-----------------\n");
	for(i = 0; i < TABLE_SIZE; i++) {
		if(hashtable[i] != NULL) {
			SYNode *temp = hashtable[i];
			printf("index: %d\n", i);
			while(temp != NULL) {
				if(i == 0) {
					printf("type: %d\t name: empty\t line: %d\n",(int)temp->type,temp->lineno);
				} else {
					printf("type: %d\t name: %s\t line: %d\n",(int)temp->type, temp->name, temp->lineno);
				}
				temp = temp->nextHash;
			}
			printf("\n");
		}
	}
}






