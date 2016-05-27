#include <stdio.h>
#include "type.h"
#include "semantic.h"
#include "ir.h"
#include "objc.h"

extern int yyparse(void);
extern void yyrestart(FILE *input_file);
extern int yydebug;
extern int MY_LEXER_PRINT_FLAG;

int main(int argc, char** argv) {
	if (argc != 3) {
		printf("Please input output file in the command\n");
		return 1;
	}
	FILE *f1, *f2;
	f1 = fopen(argv[1], "r");
	if (!f1) {
		perror(argv[1]);
		return 2;
	}
	f2 = fopen(argv[2],"w");
	if(!f2) {
		perror(argv[2]);
		return 3;
	}

	yyrestart(f1);

//	yydebug = 1;			// test mode
//	MY_LEXER_PRINT_FLAG = 1;	// print every token

	yyparse();
	if(MY_LEXER_PRINT_FLAG == 1)	printf("******** show the tree *********\n");
	if(printTreeFlag == 1) {
		//preOrderPrint(treeRoot);
		preOrderAndAnalysis(treeRoot);
		//testSymbol();
		if(semanticFlag == 1) {
			preOrderAndTranslate(treeRoot);
			if(translateFlag == 1) {
				simplyInterCode();
				writeInterCode();
				fprintf(f2,"%s",allCodes);

				getObjectCode();
			}
		}
	}
	fclose(f1);
	fclose(f2);
	return 0;
}
