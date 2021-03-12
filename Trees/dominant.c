#include"tree_int.h"
void CD_Rec(const Node *t, int *cnt) {
	if (IsEmptyTree(t)) {
		return;
	}
	if (!IsLeafTree(t)) {
		ElemType a=0, b=0, somma = 0;
		if (LeftTree(t) != NULL) {
			a = *GetRootValueTree(LeftTree(t));
		}
		if (RightTree(t)) {
			b = *GetRootValueTree(RightTree(t));
		}
		somma = a + b;
		if (ElemCompare(GetRootValueTree(t), &somma) > 0) {
			(*cnt)++;
		}
	}
	CD_Rec(RightTree(t), cnt);
	CD_Rec(LeftTree(t), cnt);
}
int CountDominant(const Node *t) {
	if (IsEmptyTree(t)) {
		return 0;
	}
	int cnt = 0;
	CD_Rec(t, &cnt);
	return cnt;
}
int main(void) {
	ElemType v[] = { 21,5,0,4,2,12,18 };
	Node* t = CreateRootTree(&v[0],
		CreateRootTree(&v[3], 
		CreateRootTree(&v[2], CreateEmptyTree(), CreateEmptyTree()),
		CreateRootTree(&v[4], CreateEmptyTree(), CreateEmptyTree())), 
		CreateRootTree(&v[5], 
		CreateRootTree(&v[1], CreateEmptyTree(), CreateEmptyTree()), 
		CreateRootTree(&v[6], CreateEmptyTree(), CreateEmptyTree())));
	int Conta = CountDominant(t);
	return 0;
}
