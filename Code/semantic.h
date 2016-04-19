
/* func in semantic1.c */
void preOrderAndAnalysis(CSNode *root);
void postOrder(CSNode *root);

void handleExtDef(CSNode *root);
SpecialType *handleSpecifier(CSNode *root);
SpecialType *handleStructSpecifier(CSNode *root);
FieldList *handleDefList(CSNode *root, int structFlag, FieldList *list);
FieldList *handleDef(CSNode *root, int structFlag, FieldList *list);
FieldList *handleDecList(CSNode *root, SpecialType *basicType, int structFlag, FieldList *list);
FieldList *handleDec(CSNode *root, SpecialType *basicType, int structFlag, FieldList *list);
FieldList *handleVarDec(CSNode *root, SpecialType *basicType, int structFlag, FieldList *list);
FieldList *handleExtDecList(CSNode *root, SpecialType *basicType);
void handleFunDec(CSNode *root, SpecialType *rel);
FieldList *handleVarList(CSNode *root);
FieldList *handleParamDec(CSNode *root);
void handleCompSt(CSNode *root, SpecialType *rel);
void handleStmtList(CSNode *root, SpecialType *rel);

/* func in semantic2.c */
int compareSpecialType(SpecialType *type1, SpecialType *type2);
void handleStmt(CSNode *root, SpecialType *rel);
SpecialType *handleExp(CSNode *root);

