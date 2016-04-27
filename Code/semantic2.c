#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "type.h"
#include "semantic.h"

//compare two specialType, equal return 1, else return 0
int compareSpecialType(SpecialType *type1, SpecialType *type2) {
	if(type1 == NULL || type2 == NULL) {
		//printf("type is NULL, fail to compare\n");
		return 0;
	}
	if(type1->kind == type2->kind) {
		if(type1->kind == BASIC) {
			if((type1->u).basic == (type2->u).basic) {
				return 1;
			}
			else {
				//printf("type error, int != float\n");
				return 0;
			}
		}
		else if(type1->kind == ARRAY) {
			return compareSpecialType((type1->u).array.elem,(type2->u).array.elem);
		}
		else{
			FieldList *fd1 = (type1->u).structure;
			FieldList *fd2 = (type2->u).structure;
			if(fd1 == fd2) {
				return 1;
			}
			if(fd1 == NULL && fd2 == NULL) {
				return 1;
			}
			else if(fd1 == NULL || fd2 == NULL) {
				return 0;
			}
			while(fd1 != NULL && fd2 != NULL) {
				if(compareSpecialType(fd1->type,fd2->type) == 0) {
					return 0;
				}
				fd1 = fd1->tail;
				fd2 = fd2->tail;
			}
			if(fd1 == NULL && fd2 == NULL) {
				return 1;
			}
			return 0;
		}
	}
	else {
		//printf("type cannot match\n");
		return 0;
	}
}

//handle production "Stmt -> ...|... "
void handleStmt(CSNode *root, SpecialType *rel) {
	if(isProduction_2(root,MySTMT,MyEXP,MySEMI) == 1) {
		SpecialType *expType = NULL;
		expType = handleExp(root->firstChild);
	}
	else if(isProduction_1(root,MySTMT,MyCOMPST) == 1) {
		handleCompSt(root->firstChild,rel);
	}
	else if(isProduction_3(root,MySTMT,MyRETURN,MyEXP,MySEMI) == 1) {
		SpecialType *expType = NULL;
		expType = handleExp(root->firstChild->nextSibling);
		if(compareSpecialType(rel,expType) == 0) {
			printf("Error type 8 at Line %d: Type mismatched for return.\n",root->firstChild->nextSibling->lineNo);
		}
	}
	else if(isProduction_5(root,MySTMT,MyIF,MyLP,MyEXP,MyRP,MySTMT) == 1) {
		CSNode *expNode = root->firstChild->nextSibling->nextSibling;
		CSNode *stmtNode = expNode->nextSibling->nextSibling;
		SpecialType *expType = NULL;
		expType = handleExp(expNode);
		if(expType == NULL) {
			//printf("type error follow if(\n");
			handleStmt(stmtNode,rel);
			return;
		}
		if(!(expType->kind == BASIC && (expType->u).basic == 0)) {
			printf("Error type 7 at Line %d: Only integer can be the condition for \"if(condition)\".\n",expNode->lineNo);
		}
		handleStmt(stmtNode,rel);
	}
	else if(isProduction_7(root,MySTMT,MyIF,MyLP,MyEXP,MyRP,MySTMT,MyELSE,MySTMT) == 1) {
		CSNode *expNode = root->firstChild->nextSibling->nextSibling;
		CSNode *stmt1Node = expNode->nextSibling->nextSibling;
		CSNode *stmt2Node = stmt1Node->nextSibling->nextSibling;
		SpecialType *expType = NULL;
		expType = handleExp(expNode);
		if(expType == NULL) {
			//printf("type error follow if(\n");
			handleStmt(stmt1Node,rel);
			handleStmt(stmt2Node,rel);
			return;
		}
		if(!(expType->kind == BASIC && (expType->u).basic == 0)) {
			printf("Error type 7 at Line %d: Only interger can be the condition for \"if(condition)\".\n",expNode->lineNo);
		}
		handleStmt(stmt1Node,rel);
		handleStmt(stmt2Node,rel);
	}
	else if(isProduction_5(root,MySTMT,MyWHILE,MyLP,MyEXP,MyRP,MySTMT) == 1) {
		CSNode *expNode = root->firstChild->nextSibling->nextSibling;
		CSNode *stmtNode = expNode->nextSibling->nextSibling;
		SpecialType *expType = NULL;
		expType = handleExp(expNode);
		if(expType == NULL) {
			//printf("type error follow while(\n");
			handleStmt(stmtNode,rel);
			return;
		}
		if(!(expType->kind == BASIC && (expType->u).basic == 0)) {
			printf("Error type 7 at Line %d: Only integer can be the condition for \"while(condition)\".\n",expNode->lineNo);
		}
		handleStmt(stmtNode,rel);
	}
	else {
		printf("error Stmt production\n");
	}
}

//handle production "Exp -> ...|... "
//maybe it waste some time , should modify later
SpecialType *handleExp(CSNode *root) {
	if(isProduction_3(root,MyEXP,MyEXP,MyASSIGNOP,MyEXP) == 1) {
		CSNode *lexp = root->firstChild;
		CSNode *rexp = lexp->nextSibling->nextSibling;
		SpecialType *ltype = NULL;
		SpecialType *rtype = NULL;
		ltype = handleExp(lexp);
		rtype = handleExp(rexp);
		if(!(isProduction_1(lexp,MyEXP,MyID) == 1 || 
		     isProduction_4(lexp,MyEXP,MyEXP,MyLB,MyEXP,MyRB) == 1 || isProduction_3(lexp,MyEXP,MyEXP,MyDOT,MyID) == 1)) {
			printf("Error type 6 at Line %d: The left-hand side of an assignment must be a variable.\n",lexp->lineNo);
			return NULL;
		}
		if(ltype == NULL || rtype == NULL) {
			//printf("left or right has a error, =\n");
			return NULL;
		}
		if(compareSpecialType(ltype,rtype) == 0) {
			printf("Error type 5 at Line %d: Type mismatched for assignment.\n",lexp->nextSibling->lineNo);
			return NULL;
		}
		return ltype;
	}
	else if(isProduction_3(root,MyEXP,MyEXP,MyAND,MyEXP) == 1  	
	     || isProduction_3(root,MyEXP,MyEXP,MyOR,MyEXP) == 1) {
		CSNode *lexp = root->firstChild;
		CSNode *rexp = lexp->nextSibling->nextSibling;
		SpecialType *ltype = NULL;
		SpecialType *rtype = NULL;
		ltype = handleExp(lexp);
		rtype = handleExp(rexp);
		if(ltype == NULL || rtype == NULL) {
			//printf("left or right type has error, || &&\n");
			return NULL;
		}
		if(compareSpecialType(ltype,rtype) == 0) {
			printf("Error type 7 at Line %d: Type mismatched for operands.\n",lexp->nextSibling->lineNo);
			return NULL;
		}
		if(!(ltype->kind == BASIC && (ltype->u).basic == 0)) {
			printf("Error type 7 at Line %d: Type mismatched for operand and operator. The left operand should be an integer.\n",lexp->lineNo);
			return NULL;
		}
		if(!(rtype->kind == BASIC && (rtype->u).basic == 0)) {
			printf("Error type 7 at Line %d: Type mismatched for operand and operator. The right operand should be an integer.\n",rexp->lineNo);
			return NULL;
		}
		return ltype;
	}
	else if(isProduction_3(root,MyEXP,MyEXP,MyRELOP,MyEXP) == 1
	    ||  isProduction_3(root,MyEXP,MyEXP,MyPLUS,MyEXP) == 1
	    ||  isProduction_3(root,MyEXP,MyEXP,MyMINUS,MyEXP) == 1	       ||  isProduction_3(root,MyEXP,MyEXP,MySTAR,MyEXP) == 1
	    ||  isProduction_3(root,MyEXP,MyEXP,MyDIV,MyEXP) == 1
	    ) {
	    	CSNode *lexp = root->firstChild;
		CSNode *rexp = lexp->nextSibling->nextSibling;
		SpecialType *ltype = NULL;
		SpecialType *rtype = NULL;
		ltype = handleExp(lexp);
		rtype = handleExp(rexp);
		if(ltype == NULL || rtype == NULL) {
			//printf("left or right type has error,+-\n");
			return NULL;
		}
		if(compareSpecialType(ltype,rtype) == 0) {
			printf("Error type 7 at Line %d: Type mismatched for operands.\n",lexp->nextSibling->lineNo);
			return NULL;
		}
		if(ltype->kind != BASIC) {
			printf("Error type 7 at Line %d: Type mismatched for operand and operator. The left operand should be an interger or float.\n",lexp->lineNo);
			return NULL;
		}
		if(rtype->kind != BASIC) {
			printf("Error type 7 at Line %d: Type mismatched for operand and operator. The right operand should be an integer or float.\n",rexp->lineNo);
			return NULL;
		}
		return ltype;
	}
	else if(isProduction_3(root,MyEXP,MyLP,MyEXP,MyRP) == 1) {
		SpecialType *type = NULL;
		type = handleExp(root->firstChild->nextSibling);
		return type;
	}
	else if(isProduction_2(root,MyEXP,MyMINUS,MyEXP) == 1) {
		SpecialType *type = NULL;
		CSNode *expNode = root->firstChild->nextSibling;
		type = handleExp(expNode);
		if(type == NULL) {
			//printf("type has error after -\n");
			return NULL;
		}
		if(type->kind != BASIC) {
			printf("Error type 7 at Line %d: Type mismatched for operand and operator. The operand should be an integer or float.\n",expNode->lineNo);
			return NULL;
		}
		return type;
	}
	else if(isProduction_2(root,MyEXP,MyNOT,MyEXP) == 1) {
		SpecialType *type = NULL;
		CSNode *expNode = root->firstChild->nextSibling;
		type = handleExp(expNode);
		if(type == NULL) {
			//printf("type has a error after !\n");
			return NULL;
		}
		if(!(type->kind == BASIC && (type->u).basic == 0)) {
			printf("Error type 7 at Line %d: Type mismatched for operand and operator. The operand should be an integer.\n",expNode->lineNo);
			return NULL;
		}
		return type;
	}
	else if(isProduction_4(root,MyEXP,MyID,MyLP,MyARGS,MyRP) == 1) {
		char *name = (root->firstChild->type_union).type_id.p_str;
		SYNode *checkFlag = NULL;
		checkFlag = checkSymbolName(0,name);
		if(checkFlag == NULL) {
			printf("Error type 2 at Line %d: Undefined function \"%s\".\n",root->firstChild->lineNo,name);
			return NULL;
		}
		if(checkFlag->type != MyFUNCNAME) {
			printf("Error type 11 at Line %d: \"%s\" is not a function.\n",root->firstChild->lineNo,name);
			return NULL;
		}
		SYMBOL_FUNC *fc = (SYMBOL_FUNC *)(checkFlag->content);
		CSNode *argsNode = root->firstChild->nextSibling->nextSibling;
		int countOfArgs = getCountOfArgs(argsNode);
		if(fc->param_num != countOfArgs) {
			printf("Error type 9 at Line %d: The number of arguments and the number of parameters are not equal for function \"%s\".\n",root->firstChild->lineNo,name);
			return NULL;
		}
		FieldList *fd_param = handleArgs(argsNode);
		if(compareFieldList(fc->param,fd_param) == 0) {
			printf("Error type 9 at Line %d: The type of arguments and the type of parameters are not equal for function \"%s\".\n",root->firstChild->lineNo,name);
			return NULL;
		}
		return fc->rel;
	}
	else if(isProduction_3(root,MyEXP,MyID,MyLP,MyRP) == 1) {
		char *name = (root->firstChild->type_union).type_id.p_str;
		SYNode *checkFlag = NULL;
		checkFlag = checkSymbolName(0,name);
		if(checkFlag == NULL) {
			printf("Error type 2 at Line %d: Undefined function \"%s\".\n",root->firstChild->lineNo,name);
			return NULL;
		}
		if(checkFlag->type != MyFUNCNAME) {
			printf("Error type 11 at Line %d: \"%s\" is not a function.\n",root->firstChild->lineNo,name);
			return NULL;
		}
		SYMBOL_FUNC *fc = (SYMBOL_FUNC *)(checkFlag->content);
		if(!(fc->param == NULL && fc->param_num == 0)) {
			printf("Error type 9 at Line %d: The number of arguments and the number of parameters are not equal for function \"%s\".\n",root->firstChild->lineNo,name);
			return NULL;
		}
		return fc->rel;
	}
	else if(isProduction_4(root,MyEXP,MyEXP,MyLB,MyEXP,MyRB) == 1) {
		CSNode *exp1 = root->firstChild;
		CSNode *exp2 = exp1->nextSibling->nextSibling;
		SpecialType *type1 = handleExp(exp1);
		SpecialType *type2 = handleExp(exp2);
		if(type1 == NULL || type2 == NULL) {
			//printf("type has a error , []\n");
			return NULL;
		}
		if(type1->kind != ARRAY) {
			printf("Error type 10 at Line %d: Variable is not an array.\n",exp1->lineNo);
			return NULL;
		}
		if(!(type2->kind == BASIC && (type2->u).basic == 0)) {
			printf("Error type 12 at Line %d: The value between \"[\" and \"]\" is not an interger.\n",exp2->lineNo);
			return NULL;
		}
		return (type1->u).array.elem;
	}
	else if(isProduction_3(root,MyEXP,MyEXP,MyDOT,MyID) == 1) {
		SpecialType *type = NULL;
		type = handleExp(root->firstChild);
		CSNode *idNode = root->firstChild->nextSibling->nextSibling;
		char *name = (idNode->type_union).type_id.p_str;
		if(type == NULL) {
			//printf("type has a error, .id\n");
			return NULL;
		}
		if(type->kind != STRUCTURE) {
			printf("Error type 13 at Line %d: Illegal use of \".\".\n",root->firstChild->nextSibling->lineNo);
			return NULL;
		}
		FieldList *fd = (type->u).structure;
		FieldList *checkFlag = NULL;
		checkFlag = checkSameNameFL(name,fd);
		if(checkFlag == NULL) {
			printf("Error type 14 at Line %d: Non-existent field \"%s\".\n",idNode->lineNo,name);
			return NULL;
		}
		return checkFlag->type;
	}
	else if(isProduction_1(root,MyEXP,MyID) == 1) {
		char *name = (root->firstChild->type_union).type_id.p_str;
		SYNode *checkFlag = NULL;
		checkFlag = checkSymbolName(0,name);
		if(checkFlag == NULL) {
			printf("Error type 1 at Line %d: Undefined variable \"%s\".\n",root->firstChild->lineNo,name);
			return NULL;
		}
		if(checkFlag->type == MySTRUCTNAME || checkFlag->type == MyFUNCNAME) {
			printf("Error type 1 at Line %d: Undefined variable \"%s\",it is a name of a struct or a function, not a variable.\n",root->firstChild->lineNo,name);
			return NULL;
		}
		if(checkFlag->type == MyINTVAR) {
			return ((SYMBOL_INT *)(checkFlag->content))->type;
		}
		if(checkFlag->type == MyFLOATVAR) {
			return ((SYMBOL_FLOAT *)(checkFlag->content))->type;
		}
		if(checkFlag->type == MyARRAYVAR) {
			return ((SYMBOL_ARRAY *)(checkFlag->content))->type;
		}
		if(checkFlag->type == MySTRUCTVAR) {
			return ((SYMBOL_STRUCTVAR *)(checkFlag->content))->type;
		}
		else {
			printf("error type id\n");
			return NULL;
		}
	}
	else if(isProduction_1(root,MyEXP,MyINT) == 1) {
		SpecialType *type = NULL;
		type = (SpecialType *)malloc(sizeof(SpecialType));
		type->kind = BASIC;
		(type->u).basic = 0;
		return type;
		return NULL;
	}
	else if(isProduction_1(root,MyEXP,MyFLOAT) == 1) {
		SpecialType *type = NULL;
		type = (SpecialType *)malloc(sizeof(SpecialType));
		type->kind = BASIC;
		(type->u).basic = 1;
		return type;
	}
	else {
		printf("error Exp production\n");
		return NULL;
	}
}

//handle production " Args -> ...|... "
FieldList *handleArgs(CSNode *root) {
	if(isProduction_3(root,MyARGS,MyEXP,MyCOMMA,MyARGS) == 1) {
		SpecialType *type = handleExp(root->firstChild);
		FieldList *fd1 = getAndSetFieldList(NULL,type,NULL);
		FieldList *fd2 = NULL;
		fd2 = handleArgs(root->firstChild->nextSibling->nextSibling);
		return linkList(fd1,fd2);
	}
	else if(isProduction_1(root,MyARGS,MyEXP) == 1) {
		SpecialType *type = handleExp(root->firstChild);
		FieldList *fd = getAndSetFieldList(NULL,type,NULL);
		return fd;
	}
	else {
		printf("error Args production\n");
		return NULL;
	}
}

//get num of args
int getCountOfArgs(CSNode *root) {
	if(isProduction_3(root,MyARGS,MyEXP,MyCOMMA,MyARGS) == 1) {
		CSNode *argsNode = root->firstChild->nextSibling->nextSibling;
		return 1 + getCountOfArgs(argsNode);
	}
	else if(isProduction_1(root,MyARGS,MyEXP) == 1) {
		return 1;
	}
	else {
		return 0;
	}
}
