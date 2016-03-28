#include <stdio.h>
#include "type.h"

char *getTypeName(TokenType type) {
	switch(type) {
		case MyINT:		return "INT";
		case MyFLOAT:		return "FLOAT";
		case MyID:		return "ID";
		case MySEMI:		return "SEMI";
		case MyCOMMA:		return "COMMA";
		case MyASSIGNOP:	return "ASSIGNOP";
		case MyRELOP:		return "RELOP";
		case MyPLUS:		return "PLUS";
		case MyMINUS:		return "MINUS";
		case MySTAR:		return "STAR";
		case MyDIV:		return "DIV";
		case MyAND:		return "AND";
		case MyOR:		return "OR";
		case MyDOT:		return "DOT";
		case MyNOT:		return "NOT";
		case MyTYPE:		return "TYPE";
		case MyLP:		return "LP";
		case MyRP:		return "RP";
		case MyLB:		return "LB";
		case MyRB:		return "RB";
		case MyLC:		return "LC";
		case MyRC:		return "RC";
		case MySTRUCT:		return "STRUCT";
		case MyRETURN:		return "RETURN";
		case MyIF:		return "IF";
		case MyELSE:		return "ELSE";
		case MyWHILE:		return "WHILE";
		case MyPROGRAM:		return "Program";
		case MyEXTDEFLIST:	return "ExtDefList";
		case MyEXTDEF:		return "ExtDef";
		case MySPECIFIER:	return "Specifier";
		case MyEXTDECLIST:	return "ExtDecList";
		case MyFUNDEC:		return "FunDec";
		case MyCOMPST:		return "CompSt";
		case MyVARDEC:		return "VarDec";
		case MySTRUCTSPECIFIER: return "StructSpecifier";
		case MyOPTTAG:		return "OptTag";
		case MyDEFLIST:		return "DefList";
		case MyTAG:		return "Tag";
		case MyVARLIST:		return "VarList";
		case MyPARAMDEC:	return "ParamDec";
		case MySTMTLIST:	return "StmtList";
		case MySTMT:		return "Stmt";
		case MyEXP:		return "Exp";
		case MyDEF:		return "Def";
		case MyDECLIST:		return "DecList";
		case MyDEC:		return "Dec";
		case MyARGS:		return "Args";
		default:	printf("no such a type\n");
				return NULL;
	}
}

void printTypeExp(CSNode *pnode) {
	switch(pnode->type) {
		case MyINT:	printf("%s: %d\n",getTypeName(MyINT),(pnode->type_union).type_int.value);	break;
		case MyFLOAT:	printf("%s: %f\n",getTypeName(MyFLOAT),(pnode->type_union).type_float.value);	break;
		case MyID:	printf("%s: %s\n",getTypeName(MyID),(pnode->type_union).type_id.p_str);		break;
		case MyRELOP:	printf("%s: %s\n",getTypeName(MyRELOP),(pnode->type_union).type_relop.token);	break;
		case MyTYPE:	printf("%s: %s\n",getTypeName(MyTYPE),(pnode->type_union).type_type.token);	break;
		case MyPROGRAM:	case MyEXTDEFLIST: case MyEXTDEF: case MyEXTDECLIST:
		case MySPECIFIER: case MySTRUCTSPECIFIER: case MyOPTTAG:
		case MyTAG: case MyVARDEC: case MyFUNDEC: case MyVARLIST:
		case MyPARAMDEC: case MyCOMPST: case MySTMTLIST:
		case MySTMT: case MyDEFLIST: case MyDEF: case MyDECLIST:
		case MyDEC: case MyEXP: case MyARGS:
			printf("%s (%d)\n",getTypeName(pnode->type),pnode->lineNo);
			break;
		case MySEMI: case MyCOMMA: case MyASSIGNOP: case MyPLUS:
		case MyMINUS: case MySTAR: case MyDIV: case MyAND:
		case MyOR: case MyDOT: case MyNOT: case MyLP:
		case MyRP: case MyLB: case MyRB: case MyLC: case MyRC:
		case MySTRUCT: case MyRETURN: case MyIF: case MyELSE:
		case MyWHILE:
			printf("%s\n",getTypeName(pnode->type));
			break;
		default:
			printf("no such a type to print\n");
			return;
		}
	return;
}
	
