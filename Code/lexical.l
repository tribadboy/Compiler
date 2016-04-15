%option yylineno
%{
#include "syntax.tab.h"
int yycolumn = 1;
int myIntTemp = 0;
float myFloatTemp = 0;
int MY_LEXER_PRINT_FLAG = 0;
#define YY_USER_ACTION	\
	yylloc.first_line = yylloc.last_line = yylineno;	\
	yylloc.first_column = yycolumn;	\
	yylloc.last_column = yycolumn + yyleng - 1;	\
	yycolumn += yyleng;
%}
letter		[a-zA-Z]
letter_		[_a-zA-Z]
digit		[0-9]
digits		[0-9]+
dl_		[_a-zA-Z0-9]
ill_dl_		[_89a-wyzA-WYZ]
intnum10	[0-9]|([1-9]{digit}{1,9})
ill_num10	([_a-zA-Z]*)|([0-9]*[_a-zA-Z]{dl_}*)
intnum8		[0][0-7]+
ill_num8	([0]{ill_dl_}{dl_}*)|([0][0-7]+{ill_dl_}{dl_}*)
intnum16	[0][Xx][0-9AaBbCcDdEeFf]+
ill_num16	([0][Xx])|([0][Xx][0-9AaBbCcDdEeFf]*[_g-zG-Z]{dl_}*)
floatnum	({digit}+\.{digit}+)
ill_floatnum	({digit}+\.)|(\.{digit}+)
floatnumE	(({digit}+\.{digit}*)|(\.{digit}+))([Ee][+-]?{digit}+)
ill_floatnumE	(({digit}+)([Ee][+-]?{digit}+))|((({digit}+\.{digit}*)|(\.{digit}+))([Ee][+-]?{ill_num10}))
id		{letter_}({letter_}|{digit}){0,31}
delim		[ \t\r\v]
ws		{delim}+
%%
{intnum10}	{ myIntTemp = atoi(yytext);
		  if(MY_LEXER_PRINT_FLAG == 1)	printf("%d(----)\t",myIntTemp);
		  yylval.type_pnode = setCSNode_int(MyINT,yylineno,myIntTemp);
		  return INT;
		}
{intnum8}	{ myIntTemp = (int)strtol(yytext,NULL,8);
		  if(MY_LEXER_PRINT_FLAG == 1)	printf("%d(0---)\t",myIntTemp);
		  yylval.type_pnode = setCSNode_int(MyINT,yylineno,myIntTemp);
		  return INT;
		}
{ill_num8}	{ printf("Error type A at Line %d: Illegal octal number \"%s\".\n",yylineno,yytext); 
		  printTreeFlag = 0;
		  if(MY_LEXER_PRINT_FLAG == 1)	printf("0(error)\t");
		  yylval.type_pnode = setCSNode_int(MyINT,yylineno,0);
		  return INT;
		}
{intnum16}	{ myIntTemp = (int)strtol(yytext,NULL,16);
		  if(MY_LEXER_PRINT_FLAG == 1)	printf("%d(0x--)\t",myIntTemp);
		  yylval.type_pnode = setCSNode_int(MyINT,yylineno,myIntTemp);
		  return INT;
		}
{ill_num16}	{ printf("Error type A at Line %d: Illegal hexadecimal number \"%s\".\n",yylineno,yytext);
		  printTreeFlag = 0;
		  if(MY_LEXER_PRINT_FLAG == 1)	printf("0(error)\t");
		  yylval.type_pnode = setCSNode_int(MyINT,yylineno,0);
		  return INT;
		}
{floatnum}	{ myFloatTemp = atof(yytext);
		  if(MY_LEXER_PRINT_FLAG == 1)	printf("%f(-.--)\t",myFloatTemp);
		  yylval.type_pnode = setCSNode_float(MyFLOAT,yylineno,myFloatTemp);
		  return FLOAT; 
		}
{ill_floatnum}	{ printf("Error type A at Line %d: Illegal floating point number \"%s\".\n",yylineno,yytext);
		  printTreeFlag = 0;
		  if(MY_LEXER_PRINT_FLAG == 1)	printf("0(error)\t");
		  yylval.type_pnode = setCSNode_float(MyFLOAT,yylineno,0);
		  return FLOAT;
		}
{floatnumE}	{ myFloatTemp = atof(yytext);
		  if(MY_LEXER_PRINT_FLAG == 1)	printf("%f(-E--)\t",myFloatTemp);
		  yylval.type_pnode = setCSNode_float(MyFLOAT,yylineno,myFloatTemp);
		  return FLOAT;
		}
{ill_floatnumE}	{ printf("Error type A at Line %d: Illegal floating point number \"%s\".\n",yylineno,yytext);
		  printTreeFlag = 0;
		  if(MY_LEXER_PRINT_FLAG == 1)	printf("0(error)\t");
		  yylval.type_pnode = setCSNode_float(MyFLOAT,yylineno,0);
		  return FLOAT;
		}
";"		{ if(MY_LEXER_PRINT_FLAG == 1)	printf(";\t");
		  yylval.type_pnode = setCSNode(MySEMI,yylineno);
		  return SEMI; }
","		{ if(MY_LEXER_PRINT_FLAG == 1)	printf(",\t");
		  yylval.type_pnode = setCSNode(MyCOMMA,yylineno);
		  return COMMA; }
"="		{ if(MY_LEXER_PRINT_FLAG == 1)	printf("=\t");
		  yylval.type_pnode = setCSNode(MyASSIGNOP,yylineno);
		  return ASSIGNOP; }
">"		{ 
		  if(MY_LEXER_PRINT_FLAG == 1)	printf(">\t");
		  yylval.type_pnode = setCSNode_relop(MyRELOP,yylineno,">");
		  return RELOP; }
"<"		{ 
		  if(MY_LEXER_PRINT_FLAG == 1)	printf("<\t");
		  yylval.type_pnode = setCSNode_relop(MyRELOP,yylineno,"<");
		  return RELOP; }
">="		{ 
		  if(MY_LEXER_PRINT_FLAG == 1)	printf(">=\t");
		  yylval.type_pnode = setCSNode_relop(MyRELOP,yylineno,">=");
		  return RELOP; }
"<="		{ 
		  if(MY_LEXER_PRINT_FLAG == 1)	printf("<=\t");
		  yylval.type_pnode = setCSNode_relop(MyRELOP,yylineno,"<=");
		  return RELOP; }
"=="		{
		  if(MY_LEXER_PRINT_FLAG == 1)	printf("==\t");
		  yylval.type_pnode = setCSNode_relop(MyRELOP,yylineno,"==");
		  return RELOP; }
"!="		{ 
		  if(MY_LEXER_PRINT_FLAG == 1)	printf("!=\t");
		  yylval.type_pnode = setCSNode_relop(MyRELOP,yylineno,"!=");
		  return RELOP; }
"+"		{ if(MY_LEXER_PRINT_FLAG == 1)	printf("+\t");
		  yylval.type_pnode = setCSNode(MyPLUS,yylineno);
		  return PLUS; }
"-"		{ if(MY_LEXER_PRINT_FLAG == 1)	printf("-\t");
		  yylval.type_pnode = setCSNode(MyMINUS,yylineno);
		  return MINUS; }
"*"		{ if(MY_LEXER_PRINT_FLAG == 1)	printf("*\t");
		  yylval.type_pnode = setCSNode(MySTAR,yylineno);
		  return STAR; }
"/"		{ if(MY_LEXER_PRINT_FLAG == 1)	printf("/\t");
		  yylval.type_pnode = setCSNode(MyDIV,yylineno);
		  return DIV; }
"&&"		{ if(MY_LEXER_PRINT_FLAG == 1)	printf("&&\t");
		  yylval.type_pnode = setCSNode(MyAND,yylineno);
		  return AND; }
"||"		{ if(MY_LEXER_PRINT_FLAG == 1)	printf("||\t");
		  yylval.type_pnode = setCSNode(MyOR,yylineno);
		  return OR; }
"."		{ if(MY_LEXER_PRINT_FLAG == 1)	printf(".\t");
		  yylval.type_pnode = setCSNode(MyDOT,yylineno);
		  return DOT; }
"!"		{ if(MY_LEXER_PRINT_FLAG == 1)	printf("!\t");
		  yylval.type_pnode = setCSNode(MyNOT,yylineno);
		  return NOT; }
"("		{ if(MY_LEXER_PRINT_FLAG == 1)	printf("(\t");
		  yylval.type_pnode = setCSNode(MyLP,yylineno);
		  return LP; }
")"		{ if(MY_LEXER_PRINT_FLAG == 1)	printf(")\t");
		  yylval.type_pnode = setCSNode(MyRP,yylineno);
		  return RP; }
"["		{ if(MY_LEXER_PRINT_FLAG == 1)	printf("[\t");
		  yylval.type_pnode = setCSNode(MyLB,yylineno);
		  return LB; }
"]"		{ if(MY_LEXER_PRINT_FLAG == 1)	printf("]\t");
		  yylval.type_pnode = setCSNode(MyRB,yylineno);
		  return RB; }
"{"		{ if(MY_LEXER_PRINT_FLAG == 1)	printf("{\t");
		  yylval.type_pnode = setCSNode(MyLC,yylineno);
		  return LC; }
"}"		{ if(MY_LEXER_PRINT_FLAG == 1)	printf("}\t");
		  yylval.type_pnode = setCSNode(MyRC,yylineno);
		  return RC; }
"struct"	{ if(MY_LEXER_PRINT_FLAG == 1)	printf("struct\t");
		  yylval.type_pnode = setCSNode(MySTRUCT,yylineno);
		  return STRUCT; }
"return"	{ if(MY_LEXER_PRINT_FLAG == 1)	printf("return\t");
		  yylval.type_pnode = setCSNode(MyRETURN,yylineno);
		  return RETURN; }
"if"		{ if(MY_LEXER_PRINT_FLAG == 1)	printf("if\t");
		  yylval.type_pnode = setCSNode(MyIF,yylineno);
		  return IF; }
"else"		{ if(MY_LEXER_PRINT_FLAG == 1)	printf("else\t");
		  yylval.type_pnode = setCSNode(MyELSE,yylineno);
		  return ELSE; }
"while"		{ if(MY_LEXER_PRINT_FLAG == 1)	printf("while\t");
		  yylval.type_pnode = setCSNode(MyWHILE,yylineno);
		  return WHILE; }
"int"		{ 
		  if(MY_LEXER_PRINT_FLAG == 1)	printf("int\t");
		  yylval.type_pnode = setCSNode_type(MyTYPE,yylineno,"int");
		  return TYPE; }
"float"		{
		  if(MY_LEXER_PRINT_FLAG == 1)	printf("float\t");
		  yylval.type_pnode = setCSNode_type(MyTYPE,yylineno,"float");
		  return TYPE; }
{id}		{
		  if(MY_LEXER_PRINT_FLAG == 1)	printf("%s\t",yytext);
		  yylval.type_pnode = setCSNode_id(MyID,yylineno,yytext);
		  return ID; }
{ws}		{ }
"\n"		{ if(MY_LEXER_PRINT_FLAG == 1)	printf("\\n\n");
		  yycolumn = 1; }
"//"		{ if(MY_LEXER_PRINT_FLAG == 1)	printf("//\t");
		  char c = input();
		  while (c != '\n') {
		  	c = input();
		  }
		}
"/*"		{ if(MY_LEXER_PRINT_FLAG == 1)	printf("/*\t");
		  char c = input();
		  if(c == EOF) {
		  	printf("Error type A at Line %d: Comments met EOF.\n",yylineno);
			exit(0);
		  }
		  char d = input();
		  if(d == EOF) {
		  	printf("Error type A at Line %d: Comments met EOF.\n",yylineno);
			exit(0);
		  }
		  while (c != '*' || d != '/') {
		  	c = d;
			d = input();
			if(d == EOF) {
				printf("Error type A at Line %d: Comments met EOF.\n",yylineno);
				exit(0);
			}
		  }
		  if(MY_LEXER_PRINT_FLAG == 1)	printf("*/\t");
		}
.		{ printf("Error type A at Line %d: Mysterious characters \"%s\".\n", yylineno, yytext);
		  //when find an error , do not print the tree
		  printTreeFlag = 0;
		}
%%





