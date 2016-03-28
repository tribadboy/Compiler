%{
#include <stdio.h>
#include <stdlib.h>
#include "type.h"
int yyerror(char* s);
int yylex(void);
#define YYDEBUG 1

%}
%locations
/* declared types */
%union {
//	int type_int;
//	float type_float;
//	double type_double;
	CSNode *type_pnode;
}
/* declared tokens */
%token <type_pnode> INT 
%token <type_pnode> FLOAT
%token <type_pnode> ID
%token <type_pnode> SEMI COMMA ASSIGNOP RELOP
%token <type_pnode> PLUS MINUS STAR DIV
%token <type_pnode> AND OR DOT NOT 
%token <type_pnode> TYPE
%token <type_pnode> LP RP LB RB LC RC
%token <type_pnode> STRUCT RETURN IF ELSE WHILE

%type <type_pnode> Program ExtDefList ExtDef ExtDecList Specifier 
%type <type_pnode> StructSpecifier OptTag Tag VarDec FunDec
%type <type_pnode> VarList ParamDec CompSt StmtList Stmt
%type <type_pnode> DefList Def DecList Dec Exp Args

%right ASSIGNOP
%left OR
%left AND
%left RELOP
%left MINUS PLUS
%left DIV STAR
%right NOT 
%left DOT LP RP LB RB

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%%
Program:	ExtDefList	{ $$ = setCSNode(MyPROGRAM,@$.first_line);
				  addChild($$,$1);
				  treeRoot = $$;
				}
  ;
ExtDefList:	ExtDef ExtDefList { $$ = setCSNode(MyEXTDEFLIST,@$.first_line);
				    add2Childs($$,$1,$2);
				  }
  |	/* empty */		  { $$ = NULL; }
  ;
ExtDef:		Specifier ExtDecList SEMI { $$ = setCSNode(MyEXTDEF,@$.first_line);
					    add3Childs($$,$1,$2,$3);
					  }
  |	 error SEMI  		{
  				  $$ = setCSNode(MyEXTDEF,@$.first_line);
				  printf("Error type B at Line %d: Missing specifier.\n",@1.first_line);
				  addChild($$,$2);
				}
  |	Specifier SEMI		{ $$ = setCSNode(MyEXTDEF,@$.first_line);
  				  add2Childs($$,$1,$2);
				}
  |	Specifier FunDec CompSt	{ $$ = setCSNode(MyEXTDEF,@$.first_line);
  				  add3Childs($$,$1,$2,$3);
				}
  ;
ExtDecList:	VarDec		{ $$ = setCSNode(MyEXTDECLIST,@$.first_line);
				  addChild($$,$1);
				}
  |	VarDec COMMA ExtDecList { $$ = setCSNode(MyEXTDECLIST,@$.first_line);
  				  add3Childs($$,$1,$2,$3);
				}
  ;
Specifier:	TYPE		{ $$ = setCSNode(MySPECIFIER,@$.first_line);
				  addChild($$,$1);
				}
  |	StructSpecifier		{ $$ = setCSNode(MySPECIFIER,@$.first_line);
  				  addChild($$,$1);
				}
  ;
StructSpecifier:	STRUCT OptTag LC DefList RC {
				  $$ = setCSNode(MySTRUCTSPECIFIER,@$.first_line);
				  add5Childs($$,$1,$2,$3,$4,$5);
				}
  |	STRUCT OptTag LC DefList error RC {
  				  $$ = setCSNode(MySTRUCTSPECIFIER,@$.first_line);
				  printf("Error type B at Line %d: Missing \")\".\n",@5.first_line);
				  add5Childs($$,$1,$2,$3,$4,$6);
				}
  |	STRUCT	Tag		{ $$ = setCSNode(MySTRUCTSPECIFIER,@$.first_line);
  				  add2Childs($$,$1,$2);
				}
  ;
OptTag:		ID		{ $$ = setCSNode(MyOPTTAG,@$.first_line);
				  addChild($$,$1);
				}
  |	/* empty */		{ $$ = NULL; }
  ;
Tag:	ID			{ $$ = setCSNode(MyTAG,@$.first_line);
				  addChild($$,$1);
				}
  ;
VarDec:		ID		{ $$ = setCSNode(MyVARDEC,@$.first_line);
				  addChild($$,$1);
				}
  |	VarDec LB INT RB	{ $$ = setCSNode(MyVARDEC,@$.first_line);
  				  add4Childs($$,$1,$2,$3,$4);
				}
  |	VarDec LB INT error RB  { $$ = setCSNode(MyVARDEC,@$.first_line);
  				  printf("Error type B at Line %d: Missing \"]\".\n",@4.first_line);
				  add4Childs($$,$1,$2,$3,$5);
				}
  ;
FunDec:		ID LP VarList RP { $$ = setCSNode(MyFUNDEC,@$.first_line);
				   add4Childs($$,$1,$2,$3,$4);
				 }
  |	ID error LP VarList RP		{ $$ = setCSNode(MyFUNDEC,@$.first_line);
  				  printf("Error type B at Line %d: Missing \"(\".\n",@2.first_line);
				  add4Childs($$,$1,$3,$4,$5);
				}
  |	ID LP VarList error RP  { $$ = setCSNode(MyFUNDEC,@$.first_line);
  				  printf("Error type B at Line %d: Missing \")\".\n",@4.first_line);
				  add4Childs($$,$1,$2,$3,$5);
				}
  |	ID LP RP		{ $$ = setCSNode(MyFUNDEC,@$.first_line);
  				  add3Childs($$,$1,$2,$3);
				}
  |	ID error LP RP		{ $$ = setCSNode(MyFUNDEC,@$.first_line);
  				  printf("Error type B at Line %d: Missing \"(\".\n",@2.first_line);
				  add3Childs($$,$1,$3,$4);
				}
  |	ID LP error RP		{ $$ = setCSNode(MyFUNDEC,@$.first_line);
  				  printf("Error type B at Line %d: Missing \")\".\n",@3.first_line);
				  add3Childs($$,$1,$2,$4);
				}
  |	error RP		{ $$ = setCSNode(MyFUNDEC,@$.first_line);
  				  printf("Error type B at Line %d: Missing id.",@1.first_line);
				  addChild($$,$2);
				}
  ;
VarList:	ParamDec COMMA VarList	{
				  $$ = setCSNode(MyVARLIST,@$.first_line);
				  add3Childs($$,$1,$2,$3);
				}
  |	ParamDec		{ $$ = setCSNode(MyVARLIST,@$.first_line);
  				  addChild($$,$1);
				}
  ;
ParamDec:	Specifier VarDec	{
				  $$ = setCSNode(MyPARAMDEC,@$.first_line);
				  add2Childs($$,$1,$2);
				}
  ;
CompSt:		LC DefList StmtList RC	{
				  $$ = setCSNode(MyCOMPST,@$.first_line);
				  add4Childs($$,$1,$2,$3,$4);
				}
  |	error RC		{ $$ = setCSNode(MyCOMPST,@$.first_line);
  				  printf("Error type B at Line %d: Missing \"{\".\n",@1.first_line);
				  addChild($$,$2);
				}
  ;
StmtList:	Stmt StmtList	{ $$ = setCSNode(MySTMTLIST,@$.first_line);
				  add2Childs($$,$1,$2);
				}
  |	/* empty */		{ $$ = NULL; }
  ;
Stmt:		Exp SEMI	{ $$ = setCSNode(MySTMT,@$.first_line);
				  add2Childs($$,$1,$2);
				}
  |	CompSt			{ $$ = setCSNode(MySTMT,@$.first_line);
  				  addChild($$,$1);
				}
  |	RETURN Exp SEMI		{ $$ = setCSNode(MySTMT,@$.first_line);
  				  add3Childs($$,$1,$2,$3);
				}
  |	IF LP Exp RP Stmt	%prec LOWER_THAN_ELSE {
  				  $$ = setCSNode(MySTMT,@$.first_line);
				  add5Childs($$,$1,$2,$3,$4,$5);
				}
  |	IF LP Exp RP Stmt ELSE Stmt	{
  				  $$ = setCSNode(MySTMT,@$.first_line);
				  add7Childs($$,$1,$2,$3,$4,$5,$6,$7);
				}
  |	IF LP Exp RP Exp error ELSE Stmt {
  				 $$ = setCSNode(MySTMT,@$.first_line);
				 printf("Error type B at Line %d: Missing \";\".\n",@6.first_line);
				 CSNode *temp_Stmt = setCSNode(MySTMT,@5.first_line);
				 addChild(temp_Stmt,$5);
				 add7Childs($$,$1,$2,$3,$4,temp_Stmt,$7,$8);
				}
  |	IF LP Exp RP RETURN Exp error ELSE Stmt {
  				 $$ = setCSNode(MySTMT,@$.first_line);
				 printf("Error type B at Line %d: Missing \";\".\n",@7.first_line);
				 CSNode *temp_Stmt = setCSNode(MySTMT,@5.first_line);
				 add2Childs(temp_Stmt,$5,$6);
				 add7Childs($$,$1,$2,$3,$4,temp_Stmt,$8,$9);
			        }

  |	WHILE LP Exp RP Stmt	{ $$ = setCSNode(MySTMT,@$.first_line);
  				  add5Childs($$,$1,$2,$3,$4,$5);
				}
  |	error SEMI		{ $$ = setCSNode(MySTMT,@$.first_line);
  				  printf("Error type B at Line %d: Syntax error\n",@1.first_line);
  				  addChild($$,$2);
				}
  ;
DefList:	Def DefList	{ $$ = setCSNode(MyDEFLIST,@$.first_line);
				  add2Childs($$,$1,$2);
				}
  |	/* empty */		{ $$ = NULL; }
  ;
Def:		Specifier DecList SEMI	{
				  $$ = setCSNode(MyDEF,@$.first_line);
				  add3Childs($$,$1,$2,$3);
				}
  |	Specifier DecList error SEMI	{
  				  $$ = setCSNode(MyDEF,@$.first_line);
				  printf("Error type B at Line %d: Missing \";\".\n",@3.first_line);
				  add3Childs($$,$1,$2,$4);
				}
  ;
DecList:	Dec		{ $$ = setCSNode(MyDECLIST,@$.first_line);
				  addChild($$,$1);
				}
  |	Dec COMMA DecList	{ $$ = setCSNode(MyDECLIST,@$.first_line);
  				  add3Childs($$,$1,$2,$3);
				}
  ;
Dec:		VarDec		{ $$ = setCSNode(MyDEC,@$.first_line);
				  addChild($$,$1);
				}
  |	VarDec ASSIGNOP Exp	{ $$ = setCSNode(MyDEC,@$.first_line);
  				  add3Childs($$,$1,$2,$3);
				}
  ;
Exp:		Exp ASSIGNOP Exp	{
				  $$ = setCSNode(MyEXP,@$.first_line);
				  add3Childs($$,$1,$2,$3);
				}
  |	Exp AND Exp		{ $$ = setCSNode(MyEXP,@$.first_line);
  				  add3Childs($$,$1,$2,$3);
				}
  |	Exp OR Exp		{ $$ = setCSNode(MyEXP,@$.first_line);
  				  add3Childs($$,$1,$2,$3);
				}
  |	Exp RELOP Exp		{ $$ = setCSNode(MyEXP,@$.first_line);
  				  add3Childs($$,$1,$2,$3);
				}
  |	Exp PLUS Exp		{ $$ = setCSNode(MyEXP,@$.first_line);
  				  add3Childs($$,$1,$2,$3);
				}
  |	Exp MINUS Exp		{ $$ = setCSNode(MyEXP,@$.first_line);
  				  add3Childs($$,$1,$2,$3);
				}
  |	Exp STAR Exp		{ $$ = setCSNode(MyEXP,@$.first_line);
				  add3Childs($$,$1,$2,$3);
				}
  |	Exp DIV Exp		{ $$ = setCSNode(MyEXP,@$.first_line);
  				  add3Childs($$,$1,$2,$3);
				}
  |	LP Exp RP		{ $$ = setCSNode(MyEXP,@$.first_line);
  				  add3Childs($$,$1,$2,$3);
				}
  |	LP Exp error RP		{ $$ = setCSNode(MyEXP,@$.first_line);
  				  printf("Error type B at Line %d: Missing \")\".\n",@3.first_line);
				  add3Childs($$,$1,$2,$4);
				}
  |	MINUS Exp		{ $$ = setCSNode(MyEXP,@$.first_line);
  				  add2Childs($$,$1,$2);
				}
  |	NOT Exp			{ $$ = setCSNode(MyEXP,@$.first_line);
  				  add2Childs($$,$1,$2);
				}
  |	ID LP Args RP		{ $$ = setCSNode(MyEXP,@$.first_line);
  				  add4Childs($$,$1,$2,$3,$4);
				}
  |	ID LP RP		{ $$ = setCSNode(MyEXP,@$.first_line);
  				  add3Childs($$,$1,$2,$3);
				}
  |	Exp LB Exp RB		{ $$ = setCSNode(MyEXP,@$.first_line);
  				  add4Childs($$,$1,$2,$3,$4);
				}
  |	Exp DOT ID		{ $$ = setCSNode(MyEXP,@$.first_line);
  				  add3Childs($$,$1,$2,$3);
				}
  |	ID			{ $$ = setCSNode(MyEXP,@$.first_line);
  				  addChild($$,$1);
				}
  |	INT			{ $$ = setCSNode(MyEXP,@$.first_line);
  				  addChild($$,$1);
				}
  |	FLOAT			{ $$ = setCSNode(MyEXP,@$.first_line);
  				  addChild($$,$1);
				}
  |	error RP		{ $$ = setCSNode(MyEXP,@$.first_line);
  				  printf("Error type B at Line %d: Missing \"(\" or id.\n",@1.first_line);
  				  addChild($$,$2);
				}
  |	Exp LB Exp error RB	{ $$ = setCSNode(MyEXP,@$.first_line);
  				  printf("Error type B at Line %d: Missing \"]\".\n",@4.first_line);
				  add4Childs($$,$1,$2,$3,$5);
				}
  ;
Args:	Exp COMMA Args		{ $$ = setCSNode(MyARGS,@$.first_line);
				  add3Childs($$,$1,$2,$3);
				}
  |	Exp			{ $$ = setCSNode(MyARGS,@$.first_line);
  				  addChild($$,$1);
				}
  |	Exp error COMMA Args    { $$ = setCSNode(MyARGS,@$.first_line);
  				  printf("Error type B at Line %d: Missing \",\".\n",@2.first_line);
				  add3Childs($$,$1,$3,$4);
				}
  ;
%%
#include "lex.yy.c"
int yyerror(char* msg) {
//	fprintf(stderr, "error: %s at line %d  %s\n", yytext, yylineno,  msg);
	// when find an error ,do not print the tree
	printTreeFlag = 0;
	return 0;
}
