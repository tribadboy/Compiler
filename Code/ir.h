
// struct Operand
typedef struct Operand {
	enum { VARIABLE, CONSTANT, TEMP, ADDRESS, POINTER } kind;
	/*       v1	  #2	   t3	 &t4	   *v6	*/
	union {
		int var_no;
		int value;
		int temp_no;
		struct Operand *operand_address;
		struct Operand *operand_pointer;
	} u;
} Operand;

// OperandNode exist in the heap
typedef struct OperandNode {
	Operand operand;
	struct OperandNode *next;
} OperandNode;

//struct InterCode
typedef struct InterCode {
	enum { ASSIGN, ADD, SUB, MUL ,DIV , LABEL, FUNCTION, GOTO,
		IF, RETURN, DEC, ARG, CALL, PARAM, READ, WRITE } kind;
	union {
		struct { Operand *left, *right; } assign;
		struct { Operand *result, *op1, *op2; } binop;
		struct { int label_no;	  } label_flag;
		struct { char *func_name; } func_flag;
		struct { int goto_no;	  } goto_flag; 
		struct { Operand *left, *right; char *rel_token; int no; } if_flag;
		struct { Operand *result; } return_flag;
		struct { Operand *pos; int size; } dec_flag;
		struct { Operand *arg; } arg_flag;
		struct { Operand *result; char *func_name; } call_flag;
		struct { Operand *param; } param_flag;
		struct { Operand *operand; } read_flag;
		struct { Operand *operand; } write_flag;
	} u;
} InterCode;

// InterCode node exist in the heap
typedef struct InterCodeNode {
	InterCode interCode;
	struct InterCodeNode *next;
} InterCodeNode;

char allCodes[8000];
int translateFlag;

/* ------------------------func-----------------------------*/

//part func (about ir) in the pool.c
OperandNode *getOperandNode();
InterCodeNode *getInterCodeNode();
void deleteOperandNode(OperandNode *o);
void deleteInterCodeNode(InterCodeNode *i);

// func in ir.c
void insertInterCode(InterCode *interCode);
void writeInterCode();
Operand *getAndSetOperand_VARIABLE(int var_no);
Operand *getAndSetOperand_CONSTANT(int value);
Operand *getAndSetOperand_TEMP(int temp_no);
Operand *getAndSetOperand_ADDRESS(Operand *operand_address);
Operand *getAndSetOperand_POINTER(Operand *operand_pointer);
InterCode *getAndSetInterCode_ASSIGn(Operand *left, Operand *right);
InterCode *getAndSetInterCode_ADD(Operand *result, Operand *op1, Operand *op2);
InterCode *getAndSetInterCode_SUB(Operand *result, Operand *op1, Operand *op2);
InterCode *getAndSetInterCode_MUL(Operand *result, Operand *op1, Operand *op2);
InterCode *getAndSetInterCode_DIV(Operand *result, Operand *op1, Operand *op2);
InterCode *getAndSetInterCode_LABEL(int label_no);
InterCode *getAndSetInterCode_FUNCTION(char *func_name);
InterCode *getAndSetInterCode_GOTO(int goto_no);
InterCode *getAndSetInterCode_IF(Operand *left, Operand *right, char *rel_token, int no);
InterCode *getAndSetInterCode_RETURN(Operand *result);
InterCode *getAndSetInterCode_DEC(Operand *pos, int size);
InterCode *getAndSetInterCode_ARG(Operand *arg);
InterCode *getAndSetInterCode_RETURN(Operand *result);
InterCode *getAndSetInterCode_CALL(Operand *result, char *func_name);
InterCode *getAndSetInterCode_PARAM(Operand *param);
InterCode *getAndSetInterCode_READ(Operand *operand);
InterCode *getAndSetInterCode_WRITE(Operand *operand);


// func in translate.c
void preOrderAndTranslate(CSNode *root);
void translateExtDef(CSNode *root);
void translateFunDec(CSNode *root);
void translateVarList(CSNode *root);
void translateParamDec(CSNode *root);
void translateCompSt(CSNode *root);
