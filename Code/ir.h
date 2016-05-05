
// struct Operand
typedef struct Operand {
	enum { VARIABLE, CONSTANT, ADDRESS } kind;
	union {
		int var_no;
		int value;
	} u;
} Operand;

// OperandNode exist in the heap
typedef struct OperandNode {
	Operand operand;
	struct OperandNode *next;
} OperandNode;

//struct InterCode
typedef struct InterCode {
	enum { ASSIGN, ADD, SUB, MUL } kind;
	union {
		struct { Operand *left, *right; } assign;
		struct { Operand *result, *op1, *op2; } binop;
	} u;
} InterCode;

// InterCode node exist in the heap
typedef struct InterCodeNode {
	InterCode interCode;
	struct InterCodeNode *next;
} InterCodeNode;


/* ------------------------func-----------------------------*/

//part func (about ir) in the pool.c
OperandNode *getOperandNode();
void deleteOperandNode(OperandNode *o);


// func in translate.c
void preOrderAndTranslate(CSNode *root);
void translateExtDef(CSNode *root);
InterCodeNode *getInterCodeNode();
void deleteInterCodeNode(InterCodeNode *i);
