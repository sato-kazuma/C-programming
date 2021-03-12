#include "tree_int.h"

void dimensione(const Node* t1, int* dim) {
	if (IsEmptyTree(t1)) {
		return;
	}

	else {
		++(*dim);
	}
	dimensione(LeftTree(t1), dim);
	dimensione(RightTree(t1), dim);
}

void isorec(const Node* t1, const Node* t2, bool* s) {
	if (IsEmptyTree(t1) || IsEmptyTree(t2))
		return;
	if (t1->left == NULL || t1->right == NULL || t2->right == NULL || t2->left == NULL)
		return;
	
	if (t1->left->value == t2->left->value) {
		*s = true;
		isorec(LeftTree(t1), LeftTree(t2), s);
		return;
	}
	else {
		*s = false;
	}

	if (t1->left->value == t2->right->value) {
		*s = true;
		isorec(LeftTree(t1), RightTree(t2), s);
		return;
	}
	else {
		*s = false;
	}

	if (t1->right->value == t2->left->value) {
		*s = true;
		isorec(RightTree(t1), LeftTree(t2), s);
		return;
	}
	else {
		*s = false;
	}

	if (t1->right->value == t2->right->value) {
		*s = true;
		isorec(RightTree(t1), RightTree(t2), s);
		return;
	}
	else {
		*s = false;
	}

}

bool Isomorfi(const Node* t1, const Node* t2) {
	if (t1 == NULL && t2 == NULL)
		return true;
	if (t1->value != t2->value)
		return false;
	int dim1 = 0, dim2 = 0;
	dimensione(t1, &dim1);
	dimensione(t2, &dim2);
	if (dim1 != dim2)
		return false;
	bool s = false;
	isorec(t1, t2, &s);
	return s;
}
