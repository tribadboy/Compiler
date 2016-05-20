#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "type.h"
#include "semantic.h"

/*
#define FL_STACK_SIZE 30

static FieldList *flstack1[FL_STACK_SIZE];
static FieldList *flstack2[FL_STACK_SIZE];
static int fl_top1 = -1;
static int fl_top2 = -1;

void fl_push(FieldList *f,int id) {
	int fl_top;
	FieldList **flstack;
	if(id == 1) {
		fl_top = fl_top1;
		flstack = flstack1;
	} else if(id == 2) {
		fl_top = fl_top2;
		flstack = flstack2;
	} else {
		printf("stack id is wrong\n");
		return;
	}
	if(fl_top + 1 == FL_STACK_SIZE) {
		printf("stack \"flstack\" overflow\n");
		return;
	}
	if(f == NULL) {
		printf("stack \"flstack\" cannot push a NULL\n");
		return;
	}
	fl_top++;
	flstack[fl_top] = f;
}

FieldList *fl_pop(int id) {
	int fl_top;
	FieldList **flstack;
	if(id == 1) {
		fl_top = fl_top1;
		flstack = flstack1;
	} else if(id == 2) {
		fl_top = fl_top2;
		flstack = flstack2;
	} else {
		printf("stack id is wrong\n");
		return NULL;
	}
	if(fl_top == -1) {
		return NULL;
	}
	FieldList *tmp = flstack[fl_top];
	fl_top--;
	return tmp;
}
*/

//apply a area, get a FieldList node ,but not give back area
FieldList *getAndSetFieldList(char *name, SpecialType *type, FieldList *tail) {
	FieldList *fd = NULL;
	fd = (FieldList *)malloc(sizeof(FieldList));
	fd->name = name;
	fd->type = type;
	fd->tail = tail;
	return fd;
}

//check whether the name is in the list
FieldList *checkSameNameFL(char *name, FieldList *list) {
	FieldList *tmp = list;
	while(tmp != NULL) {
		if(strcmp(name,tmp->name) == 0) {
			return tmp;
		}
		tmp = tmp->tail;
	}
	return NULL;
}

//link two FieldList
FieldList *linkList(FieldList *list1, FieldList *list2) {
	if(list1 == NULL) {
		return list2;
	}
	FieldList *tmp = list1;
	while(tmp->tail != NULL) {
		tmp = tmp->tail;
	}
	tmp->tail = list2;
	return list1;
}

//compare two FieldList , every SpecialType, equal return 1, else return 0
int compareFieldList(FieldList *fd1, FieldList *fd2) {
	if(fd1 == NULL && fd2 == NULL) {
		return 1;
	}
	else if(fd1 == NULL || fd2 == NULL) {
		return 0;
	}
	else {
		FieldList *tmp1 = fd1;
		FieldList *tmp2 = fd2;
		while(tmp1 != NULL && tmp2 != NULL) {
			if(compareSpecialType(tmp1->type,tmp2->type) == 0) {
				return 0;
			}
			tmp1 = tmp1->tail;
			tmp2 = tmp2->tail;
		}
		if(tmp1 == NULL && tmp2 == NULL) {
			return 1;
		}
		return 0;
	}
}


