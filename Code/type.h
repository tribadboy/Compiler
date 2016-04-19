
typedef enum TokenType {
	MyINT	= 1,	MyFLOAT		= 2,	MyID	= 3,	MySEMI	= 4,
	MyCOMMA	= 5,	MyASSIGNOP	= 6,	MyRELOP	= 7,	MyPLUS	= 8,
	MyMINUS	= 9,	MySTAR		= 10,	MyDIV	= 11,	MyAND	= 12,
	MyOR	= 13,	MyDOT		= 14,	MyNOT	= 15,	MyTYPE	= 16,
	MyLP	= 17,	MyRP		= 18,	MyLB	= 19,	MyRB	= 20,
	MyLC	= 21,	MyRC		= 22,	MySTRUCT = 23,	MyRETURN = 24,
	MyIF	= 25,	MyELSE		= 26,	MyWHILE	= 27,	MyPROGRAM = 28,
	MyEXTDEFLIST = 29,	MyEXTDEF = 30,	MySPECIFIER	= 31,
	MyEXTDECLIST = 32,	MyFUNDEC = 33,	MyCOMPST	= 34,
	MyVARDEC     = 35,	MySTRUCTSPECIFIER = 36,		MyOPTTAG	= 37,
	MyDEFLIST    = 38,	MyTAG	= 39,	MyVARLIST	= 40,
	MyPARAMDEC   = 41,	MySTMTLIST	= 42,	MySTMT	= 43,
	MyEXP	     = 44,	MyDEF	= 45,	MyDECLIST	= 46,
	MyDEC	     = 47,	MyARGS	= 48,	MyEOF = 49
} TokenType;
 
typedef enum SymbolType {
	MyINTVAR = 1,	MyFLOATVAR = 2,		MyARRAYVAR = 3,
	MySTRUCTNAME = 4,	MySTRUCTVAR = 5,	MyFUNCNAME = 6
} SymbolType;

/* each TokenType */
typedef struct TYPE_INT          { int value; 	  } TYPE_INT;
typedef struct TYPE_FLOAT        { float value;   } TYPE_FLOAT;
typedef struct TYPE_ID           { char *p_str;   } TYPE_ID;
typedef struct TYPE_SEMI         { 		  } TYPE_SEMI;
typedef struct TYPE_COMMA	 { 		  } TYPE_COMMA;
typedef struct TYPE_ASSIGNOP	 { 		  } TYPE_ASSIGNOP;
typedef struct TYPE_RELOP	 { char token[4]; } TYPE_RELOP;
typedef struct TYPE_PLUS	 {		  } TYPE_PLUS;
typedef struct TYPE_MINUS	 {		  } TYPE_MINUS;
typedef struct TYPE_STAR	 { 		  } TYPE_STAR;
typedef struct TYPE_DIV		 {		  } TYPE_DIV;
typedef struct TYPE_AND		 {		  } TYPE_AND;
typedef struct TYPE_OR		 { 		  } TYPE_OR;
typedef struct TYPE_DOT		 { 		  } TYPE_DOT;
typedef struct TYPE_NOT		 { 		  } TYPE_NOT;
typedef struct TYPE_TYPE	 { char token[8]; } TYPE_TYPE;
typedef struct TYPE_LP		 {		  } TYPE_LP;
typedef struct TYPE_RP		 {		  } TYPE_RP;
typedef struct TYPE_LB		 {		  } TYPE_LB;
typedef struct TYPE_RB		 {		  } TYPE_RB;
typedef struct TYPE_LC		 {		  } TYPE_LC;
typedef struct TYPE_RC		 { 		  } TYPE_RC;
typedef struct TYPE_STRUCT	 {		  } TYPE_STRUCT;
typedef struct TYPE_RETURN	 {		  } TYPE_RETURN;
typedef struct TYPE_IF		 {		  } TYPE_IF;
typedef struct TYPE_ELSE	 {		  } TYPE_ELSE;
typedef struct TYPE_WHILE	 {		  } TYPE_WHILE;
typedef struct TYPE_PROGRAM	 {		  } TYPE_PROGRAM;
typedef struct TYPE_EXTDEFLIST   {		  } TYPE_EXTDEFLIST;
typedef struct TYPE_EXTDEF	 {		  } TYPE_EXTDEF;
typedef struct TYPE_EXTDECLIST   {		  } TYPE_EXTDECLIST;
typedef struct TYPE_SPECIFIER	 {		  } TYPE_SPECIFIER;
typedef struct TYPE_STRUCTSPECIFIER {		} TYPE_STRUCTSPECIFIER;
typedef struct TYPE_OPTTAG	 {		  } TYPE_OPTTAG;
typedef struct TYPE_TAG		 {		  } TYPE_TAG;
typedef struct TYPE_VARDEC	 { 		  } TYPE_VARDEC;
typedef struct TYPE_FUNDEC	 {		  } TYPE_FUNDEC;
typedef struct TYPE_VARLIST	 {		  } TYPE_VARLIST;
typedef struct TYPE_PARAMDEC	 {		  } TYPE_PARAMDEC;
typedef struct TYPE_COMPST	 {		  } TYPE_COMPST;
typedef struct TYPE_STMTLIST	 {		  } TYPE_STMTLIST;
typedef struct TYPE_STMT	 {		  } TYPE_STMT;
typedef struct TYPE_DEFLIST	 {		  } TYPE_DEFLIST;
typedef struct TYPE_DEF		 {		  } TYPE_DEF;
typedef struct TYPE_DECLIST	 {		  } TYPE_DECLIST;
typedef struct TYPE_DEC		 {		  } TYPE_DEC;
typedef struct TYPE_EXP		 {		  } TYPE_EXP;
typedef struct TYPE_ARGS	 {		  } TYPE_ARGS;

typedef union TYPE_UNION {
	TYPE_INT type_int;	TYPE_FLOAT type_float;	TYPE_ID	type_id;
	TYPE_SEMI type_semi;	TYPE_COMMA type_comma;	TYPE_ASSIGNOP type_assignop;
	TYPE_RELOP type_relop;	TYPE_PLUS type_plus;	TYPE_MINUS type_minus;
	TYPE_STAR type_star;	TYPE_DIV type_div;	TYPE_AND type_and;
	TYPE_OR type_or;	TYPE_DOT type_dot;	TYPE_NOT type_not;
	TYPE_TYPE type_type;	TYPE_LP	type_lp;	TYPE_RP type_rp;
	TYPE_LB type_lb;	TYPE_RB type_rb;	TYPE_LC type_lc;
	TYPE_RC type_rc;	TYPE_STRUCT type_struct;
	TYPE_RETURN type_return;	TYPE_IF	type_if;
	TYPE_ELSE type_else;	TYPE_WHILE type_while;
	TYPE_PROGRAM type_program;	TYPE_EXTDEFLIST type_extdeflist;
	TYPE_EXTDEF type_extdef;	TYPE_EXTDECLIST type_extdeclist;
	TYPE_SPECIFIER type_specifier;	TYPE_STRUCTSPECIFIER type_structspecifier;
	TYPE_OPTTAG type_opttag;	TYPE_TAG type_tag;
	TYPE_VARDEC type_vardec;	TYPE_FUNDEC type_fundec;
	TYPE_VARLIST type_varlist;	TYPE_PARAMDEC type_paramdec;
	TYPE_COMPST type_compst;	TYPE_STMTLIST type_stmtlist;
	TYPE_STMT type_stmt;		TYPE_DEFLIST type_deflist;
	TYPE_DEF type_def;		TYPE_DECLIST type_declist;
	TYPE_DEC type_dec;		TYPE_EXP type_exp;
	TYPE_ARGS type_args;
} TYPE_UNION;

struct SpecialType;
typedef struct FieldList {
	char *name;
	struct SpecialType *type;
	struct FieldList *tail;
} FieldList;

typedef struct SpecialType {
	enum { BASIC, ARRAY, STRUCTURE } kind;
	union {
		int basic;	// 0 means int , 1 means float
		struct { struct SpecialType *elem; int size; } array;
		FieldList *structure;
	} u;
} SpecialType;

//symbol type
struct SYNode;
typedef struct SYMBOL_INT { /*int value;*/ } SYMBOL_INT;
typedef struct SYMBOL_FLOAT { /*float value;*/ } SYMBOL_FLOAT;
typedef struct SYMBOL_ARRAY { SpecialType *type; /*void *value;*/ } SYMBOL_ARRAY;
typedef struct SYMBOL_STRUCTNAME { SpecialType *type;} SYMBOL_STRUCTNAME;
typedef struct SYMBOL_STRUCTVAR { SpecialType *type; /*void *value;*/ } SYMBOL_STRUCTVAR;
typedef struct SYMBOL_FUNC { SpecialType *rel; FieldList *param; int param_num; } SYMBOL_FUNC;

typedef struct CSNode {
	enum TokenType type;
	int lineNo;
	struct CSNode	*firstChild;
	struct CSNode	*nextSibling;
	union TYPE_UNION type_union;
} CSNode;

CSNode *treeRoot;		// the root of the syntax tree

int printTreeFlag;

typedef struct StackNode {
	CSNode *p_node;
	int high;
} StackNode;

typedef struct PoolNode {
	CSNode p_node;
	struct PoolNode *next;
} PoolNode;

typedef struct SYNode {
	enum SymbolType type;
	int isEmpty;
	char *name;		// not apply a new area, use CSNode area
	int lineno;
	void *content;		// point to the symbol type struct content
	struct SYNode *nextHash;
} SYNode;

typedef struct SymbolNode {
	struct SYNode s_node;
	struct SymbolNode *next;
} SymbolNode;





/* --------------------------- func --------------------------------*/

/* func in tree.c  */
void push(CSNode *p, int h);
int pop(CSNode **P, int *h);
CSNode *setCSNode(TokenType t, int no);
CSNode *setCSNode_int(TokenType t, int no, int v);
CSNode *setCSNode_float(TokenType t, int no, float v);
CSNode *setCSNode_id(TokenType t, int no, char *s);
CSNode *setCSNode_relop(TokenType t, int no, char *s);
CSNode *setCSNode_type(TokenType t, int no, char *s);
void addEmptyChild(CSNode *root);
void addChild(CSNode *parrent, CSNode *child);
void add2Childs(CSNode *p,CSNode *c1,CSNode *c2);
void add3Childs(CSNode *p,CSNode *c1,CSNode *c2,CSNode *c3);
void add4Childs(CSNode *p,CSNode *c1,CSNode *c2,CSNode *c3,CSNode *c4);
void add5Childs(CSNode *p,CSNode *c1,CSNode *c2,CSNode *c3,CSNode *c4,CSNode *c5);
void add6Childs(CSNode *p,CSNode *c1,CSNode *c2,CSNode *c3,CSNode *c4,CSNode *c5,CSNode *c6);
void add7Childs(CSNode *p,CSNode *c1,CSNode *c2,CSNode *c3,CSNode *c4,CSNode *c5,CSNode *c6,CSNode *c7);
void preOrderPrint(CSNode *root);

/* func  in pool.c */
PoolNode *getNode();
void deleteNode(PoolNode *p);
SymbolNode *getSymbolNode();
void deleteSymbolNode(SymbolNode *p);

/* func in print.c  */
char *getTypeName(TokenType type);
void printTypeExp(CSNode *pnode);

/* func in symbol.c */
SYNode *checkSymbolName(int emptyFlag, char *name);
void addSymbol(SymbolType t, int emptyFlag, char *name, int no, void *con);
void testSymbol();


/* func in production.c */
int isProduction_1(CSNode *f,TokenType t,TokenType c1);
int isProduction_2(CSNode *f,TokenType t,TokenType c1,TokenType c2);
int isProduction_3(CSNode *f,TokenType t,TokenType c1,TokenType c2,TokenType c3);
int isProduction_4(CSNode *f,TokenType t,TokenType c1,TokenType c2,TokenType c3,TokenType c4);
int isProduction_5(CSNode *f,TokenType t,TokenType c1,TokenType c2,TokenType c3,TokenType c4,TokenType c5);
int isProduction_6(CSNode *f,TokenType t,TokenType c1,TokenType c2,TokenType c3,TokenType c4,TokenType c5,TokenType c6);
int isProduction_7(CSNode *f,TokenType t,TokenType c1,TokenType c2,TokenType c3,TokenType c4,TokenType c5,TokenType c6,TokenType c7);
int getParamNum(CSNode *root);


/* func in FieldList.c */
FieldList *getAndSetFieldList(char *name, SpecialType *type, FieldList *tail);
FieldList *checkSameNameFL(char *name, FieldList *list);
FieldList *linkList(FieldList *list1, FieldList *list2);
