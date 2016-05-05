#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "type.h"
#include "ir.h"

#define MAX_CODE_LINE 300

static int initCodeFlag = 0;
static InterCode *codes[MAX_CODE_LINE];
static int sum = 0;

static void initCodeTable() {
	initCodeFlag = 1;
	int i;
	for(i = 0;i < MAX_CODE_LINE; i++) {
		codes[i] = NULL;
	}
}

// do sth
// generate some func to make a code (many types)
