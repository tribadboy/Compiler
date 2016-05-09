#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "type.h"
#include "ir.h"

//translate production " Stmt -> ...|... "
void translateStmt(CSNode *root) {
	if(isProduction_2(root,MySTMT,MyEXP,MySEMI) == 1) {
	}
	else if(isProduction_1(root,MySTMT,MyCOMPST) == 1) {
	}
	else if(isProduction_3(root,MySTMT,MyRETURN,MyEXP,MySEMI) == 1) {
	}
	else if(isProduction_5(root,MySTMT,MyIF,MyLP,MyEXP,MyRP,MySTMT) == 1) {
	}
	else if(isProduction_7(root,MySTMT,MyIF,MyLP,MyEXP,MyRP,MySTMT,MyELSE,MySTMT) == 1) {
	}
	else if(isProduction_5(root,MySTMT,MyWHILE,MyLP,MyEXP,MyRP,MySTMT) == 1) {
	}
	else {
		printf("error Stmt production(translate)\n");
		translateFlag = 0;
	}
}
