#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "type.h"

//apply a area, get a FieldList node ,but not give back area
FieldList *getAndSetFieldList(char *name, SpecialType *type, FieldList *tail) {
	FieldList *fd = NULL;
	fd = (FieldList *)malloc(sizeof(FieldList));
	fd->name = name;
	fd->type = type;
	fd->tail = tail;
	return fd;
}

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



