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
	unsigned int val = 5381;
	for(; *name; ++name) {
		val = (val << 5) + val +  *name;
	}
	return val % TABLE_SIZE;
}

// a test func, ignore the type content, just consider the name
// find and add a SYNode

void addSymbol(SymbolType t, char* name, int no) {
	
	unsigned int index = hash_djb(name);
	SYNode *temp;
	if(hashtable[index] != NULL) {
		temp = hashtable[index];
		//check same
		if(temp->type == t && strcmp(temp->name,name) == 0) {
			printf("###find a same name %s in the same type at line %d\n",name,no);
			return;
		}
		while(temp->nextHash != NULL) {
			temp = temp->nextHash;
			if(temp->type == t && strcmp(temp->name,name) == 0){
				printf("###find a same name %s in the same type at line %d\n",name,no);
				return;
			}
			
		}
	}
	//confirm no same, get and build a SYNode
	SymbolNode *p = getSymbolNode();
	SYNode *pnode = &(p->s_node);
	pnode->type = t;
	pnode->lineno = no;
	//cannot find a same name error in the same row
	pnode->name = name;
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
				printf("type: %d\t name: %s\t line: %d\n",(int)temp->type, temp->name, temp->lineno);
				temp = temp->nextHash;
			}
			printf("\n");
		}
	}
}






