#include <stdio.h>
#include "type.h"

extern int yyparse(void);
extern void yyrestart(FILE *input_file);
extern int yydebug;
extern int MY_LEXER_PRINT_FLAG;

int main(int argc, char** argv) {
	if (argc <= 1) {
		return 1;
	}
	FILE* f = fopen(argv[1], "r");
	if (!f) {
		perror(argv[1]);
		return 1;
	}
	/* one file to check */
	yyrestart(f);
	/*	
		yydebug = 1  			test mode
		MY_LEXER_PRINT_FLAG = 1		print every tokens
	*/
//	yydebug = 1;
//	MY_LEXER_PRINT_FLAG = 1;
	yyparse();
//	if(MY_LEXER_PRINT_FLAG == 1)	printf("******** show the tree *********\n");
//	if(printTreeFlag == 1)			preOrderPrint(treeRoot);
	if(printTreeFlag == 0)	return 1;
	preOrder(treeRoot);
	testSymbol();
	return 0;
}
