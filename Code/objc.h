
// struct basicBlock
typedef struct BasicBlock {
	int start;
	int end;
	int isFuncHead;	// 0 means false, 1 means true

	// do sth
	// else
} BasicBlock;


// BasicBlockNode exit in the heap
typedef struct BasicBlockNode {
	BasicBlock basicBlock;
	struct BasicBlockNode *next;
} BasicBlockNode;




/* ------------------------------func------------------------------------*/

//part func about obj code in the pool.c
BasicBlockNode *getBasicBlockNode();
void deleteBasicBlockNode();


//func in objc.c
void getObjectCode();
