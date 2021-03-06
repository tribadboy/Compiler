struct  VarDesp;
char allObjCodes[100000];
const char *afterCall;
const char *beforeCall;
const char *callRead;
const char *callWrite;

// struct basicBlock
typedef struct BasicBlock {
	int start;
	int end;
	
	VarDesp *varDesp;

} BasicBlock;


// BasicBlockNode exit in the heap
typedef struct BasicBlockNode {
	BasicBlock basicBlock;
	struct BasicBlockNode *next;
} BasicBlockNode;

#define NUM_OF_D_REGS 8
RegDesp *regDespArr[NUM_OF_D_REGS];



/* ------------------------------func------------------------------------*/

//part func about obj code in the pool.c
BasicBlockNode *getBasicBlockNode();
RegDespNode *getRegDespNode();
VarDespNode *getVarDespNode();
void deleteBasicBlockNode(BasicBlockNode *b);
void deleteRegDespNode(RegDespNode *r);
void deleteVarDespNode(VarDespNode *v);


//func in objc.c
void getObjectCode();
void releaseRegDespNode(RegDesp *r);
void releaseVarDespNode(VarDesp *v);
void setBasicBlockVarDesp();
VarDesp *getVarDespFromFunc(int start, int end);
VarDesp *getAndSetVarDespNode(Operand *operand, int offset);
RegDesp *getAndSetRegDespNode(Operand *operand);
Operand *unwrapOperand(Operand *operand);
VarDesp *checkOpInVarDesp(VarDesp *varDesp, Operand *operand, int size);
void translateObjCode();
void translateBlock(BasicBlock *basicBlock);
bool compareVariAndTemp(Operand *op1, Operand *op2);
void storeRegValue(VarDesp *varDesp);
void printBlockVarDesp();

//func in objc2.c
RegDesp *findRegDespInRegDespList(Operand *operand, RegDesp *regList);
VarDesp *findVarDespInVarDespList(Operand *operand, VarDesp *varList);
int getReg(Operand *operand, VarDesp *varDesp, int start, int end, int current);
void getRegCode(int regIndex, Operand *operand, bool isAddr, VarDesp *varDesp);
void changeRegCode(int regIndex, Operand *operand, VarDesp *varDesp);
void putOperandToCertainReg(char *regName, Operand *operand, VarDesp *varDesp, int start, int end, int current);
void putCertainRegToOperand(char *regName, Operand *operand, VarDesp *varDesp, int start, int end, int current);



void translateInterCode_ASSIGN(InterCode *ic, VarDesp *varDesp, int start, int end, int current);
void translateInterCode_ADD(InterCode *ic, VarDesp *varDesp, int start, int end, int current);
void translateInterCode_SUB(InterCode *ic, VarDesp *varDesp, int start, int end, int current);
void translateInterCode_MUL(InterCode *ic, VarDesp *varDesp, int start, int end, int current);
void translateInterCode_DIV(InterCode *ic, VarDesp *varDesp, int start, int end, int current);
void translateInterCode_LABEL(InterCode *ic, VarDesp *varDesp, int start, int end, int current);
void translateInterCode_FUNCTION(InterCode *ic, VarDesp *varDesp, int start, int end, int current);
void translateInterCode_GOTO(InterCode *ic, VarDesp *varDesp, int start, int end, int current);
void translateInterCode_IF(InterCode *ic, VarDesp *varDesp, int start, int end, int current);
void translateInterCode_RETURN(InterCode *ic, VarDesp *varDesp, int start, int end, int current);
void translateInterCode_DEC(InterCode *ic, VarDesp *varDesp, int start, int end, int current);
void translateInterCode_ARG(InterCode *ic, VarDesp *varDesp, int start, int end, int current);
void translateInterCode_CALL(InterCode *ic, VarDesp *varDesp, int start, int end, int current);
void translateInterCode_PARAM(InterCode *ic, VarDesp *varDesp, int start, int end, int current);
void translateInterCode_READ(InterCode *ic, VarDesp *varDesp, int start, int end, int current);
void translateInterCode_WRITE(InterCode *ic, VarDesp *varDesp, int start, int end, int current);
