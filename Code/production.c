#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "type.h"

// f is loc of the PoolNode, t -> empty
int isProduction_0(CSNode *f,TokenType t) {
	if(f != NULL && f->type == t && f->firstChild == NULL) {
		return 1;
	} else {
		return 0;
	}
}
	
// t -> c1
int isProduction_1(CSNode *f,TokenType t,TokenType c1) {
	if(f != NULL && f->type == t
		     && f->firstChild != NULL
		     && (f->firstChild)->type == c1
		     && (f->firstChild)->nextSibling == NULL
		     ) {
		return 1;
	} else {
		return 0;
	}
}

// t -> c1 c2
int isProduction_2(CSNode *f,TokenType t,TokenType c1,TokenType c2) {
	if(f != NULL && f->type == t && f->firstChild != NULL) {
		CSNode *tmp1 = f->firstChild;
		if(tmp1->type == c1 && tmp1->nextSibling != NULL) {
			CSNode *tmp2 = tmp1->nextSibling;
			if(tmp2->type == c2 && tmp2->nextSibling == NULL) {
				return 1;
			}
		}
	} else {
		return 0;
	}
}

// t -> c1 c2 c3
int isProduction_3(CSNode *f,TokenType t,TokenType c1,TokenType c2,TokenType c3) {
	if(f != NULL && f->type == t && f->firstChild != NULL) {
		CSNode *tmp1 = f->firstChild;
		if(tmp1->type == c1 && tmp1->nextSibling != NULL) {
			CSNode *tmp2 = tmp1->nextSibling;
			if(tmp2->type == c2 && tmp2->nextSibling != NULL) {
				CSNode *tmp3 = tmp2->nextSibling;
				if(tmp3->type == c3 && tmp3->nextSibling == NULL) {
					return 1;
				}
			}
		}
	} else {
		return 0;
	}
}

//f -> c1 c2 c3 c4
int isProduction_4(CSNode *f,TokenType t,TokenType c1,TokenType c2,TokenType c3,TokenType c4) {
	if(f != NULL && f->type == t && f->firstChild != NULL) {
		CSNode *tmp1 = f->firstChild;
		if(tmp1->type == c1 && tmp1->nextSibling != NULL) {
			CSNode *tmp2 = tmp1->nextSibling;
			if(tmp2->type == c2 && tmp2->nextSibling != NULL) {
				CSNode *tmp3 = tmp2->nextSibling;
				if(tmp3->type == c3 && tmp3->nextSibling != NULL) {
					CSNode *tmp4 = tmp3->nextSibling;
					if(tmp4->type == c4 && tmp4->nextSibling == NULL) {
						return 1;
					}
				}
			}
		}
	} else {
		return 0;
	}
}

//f -> c1 c2 c3 c4 c5
int isProduction_5(CSNode *f,TokenType t,TokenType c1,TokenType c2,TokenType c3,TokenType c4,TokenType c5) {
	if(f != NULL && f->type == t && f->firstChild != NULL) {
		CSNode *tmp1 = f->firstChild;
		if(tmp1->type == c1 && tmp1->nextSibling != NULL) {
			CSNode *tmp2 = tmp1->nextSibling;
			if(tmp2->type == c2 && tmp2->nextSibling != NULL) {
				CSNode *tmp3 = tmp2->nextSibling;
				if(tmp3->type == c3 && tmp3->nextSibling != NULL) {
					CSNode *tmp4 = tmp3->nextSibling;
					if(tmp4->type == c4 && tmp4->nextSibling != NULL) {
						CSNode *tmp5 = tmp4->nextSibling;
						if(tmp5->type == c5 && tmp5->nextSibling == NULL) {
							return 1;
						}
					}
				}
			}
		}
	} else {
		return 0;
	}
}
