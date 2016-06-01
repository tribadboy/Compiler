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
void setBasicBlockVarDesp();
