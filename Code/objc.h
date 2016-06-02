struct  VarDesp;

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
Operand *unwrapOperand(Operand *operand);
VarDesp *checkOpInVarDesp(VarDesp *varDesp, Operand *operand, int size);
void translateObjCode();
void translateBlock(BasicBlock *basicBlock);

void translateInterCode_ASSIGN(InterCode *ic, VarDesp *varDesp);
void translateInterCode_ADD(InterCode *ic, VarDesp *varDesp);
void translateInterCode_SUB(InterCode *ic, VarDesp *varDesp);
void translateInterCode_MUL(InterCode *ic, VarDesp *varDesp);
void translateInterCode_DIV(InterCode *ic, VarDesp *varDesp);
void translateInterCode_LABEL(InterCode *ic, VarDesp *varDesp);
void translateInterCode_FUNCTION(InterCode *ic, VarDesp *varDesp);
void translateInterCode_GOTO(InterCode *ic, VarDesp *varDesp);
void translateInterCode_IF(InterCode *ic, VarDesp *varDesp);
void translateInterCode_RETURN(InterCode *ic, VarDesp *varDesp);
void translateInterCode_DEC(InterCode *ic, VarDesp *varDesp);
void translateInterCode_ARG(InterCode *ic, VarDesp *varDesp);
void translateInterCode_CALL(InterCode *ic, VarDesp *varDesp);
void translateInterCode_PARAM(InterCode *ic, VarDesp *varDesp);
void translateInterCode_READ(InterCode *ic, VarDesp *varDesp);
void translateInterCode_WRITE(InterCode *ic, VarDesp *varDesp);
