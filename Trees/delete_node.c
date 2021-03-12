#include"tree_int.h"
Node* MaximumKey(Node *n) {
	while (!IsEmptyTree(RightTree(n))) {
		n = RightTree(n);
	}
	return n;
}
Node* DBSTrec(Node* n, const ElemType* key) {
	if (IsEmptyTree(n)) {
		return NULL;
	}
	if (ElemCompare(key, GetRootValueTree(n)) < 0) {
		n->left = DBSTrec(LeftTree(n), key);
	}
	if (ElemCompare(key, GetRootValueTree(n)) > 0) {
		n->left = DBSTrec(RightTree(n), key);
	}
	else {
		if(IsLeafTree(n)){
			DeleteTree(n);
			return NULL;
		}
		else {
			if (LeftTree(n) && RightTree(n)) {
				Node* predecessore = MaximumKey(LeftTree(n));
				ElemDelete(&n->value);
				n->value = ElemCopy(GetRootValueTree(predecessore));
				n->left = DBSTrec(LeftTree(n),GetRootValueTree(predecessore));
				return n;
			}
			else {
				Node* child = (LeftTree(n)) ? LeftTree(n) : RightTree(n);
				Node* curr = n;
				n = child;
				ElemDelete(&curr->value);
				free(curr);
				return n;
			}
		}
	}
	return n;
}
Node *DeleteBstNode(Node* n, const ElemType *key) {
	if (IsEmptyTree(n)) {
		return n; 
	}
	return DBSTrec(n, key);
}
int main(void) {
	ElemType v[] = { 0,1,2,3,4,5 };
	Node* n = CreateRootTree(&v[0], CreateRootTree(&v[1], CreateRootTree(&v[3], CreateEmptyTree(), CreateEmptyTree()), CreateEmptyTree()), CreateRootTree(&v[2], CreateRootTree(&v[4], CreateEmptyTree(), CreateEmptyTree()), CreateRootTree(&v[5], CreateEmptyTree(), CreateEmptyTree())));
	Node *new=DeleteBstNode(n, &v[2]);
	return 0;
}
