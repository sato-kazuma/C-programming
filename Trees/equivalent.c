#include"tree_int.h"

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
void Eqrec(const Node* t1, const  Node* t2, bool* s)
{
	if (IsEmptyTree(t1) || IsEmptyTree(t2))
	{
		return;
	}
	if (IsLeafTree(t1) && (IsLeafTree(t2)))
	{
		if ((t1->value % t2->value) == 0 || (t2->value % t1->value) == 0)
		{
			*s = true;
		}
		else
		{
			*s = false;
		}

	}
	else
	{
		if (t1->value == t2->value)
		{
			*s = true;

		}
		else
		{
			*s = false;

		}
	}

	Eqrec(LeftTree(t1), LeftTree(t1), s);
	Eqrec(RightTree(t1), RightTree(t2), s);

}


bool Equivalenti(const Node* t1, const Node* t2) {
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
	Eqrec(t1, t2, &s);
	return s;
}

//main
#include"tree_int.h"
#include<stdbool.h>
int main(void) {
	ElemType v1[] = { 1,2,3,4,5,6,7,8 };
	Node* t1 = CreateRootTree(&v1[0],
		CreateRootTree(&v1[1],
			CreateRootTree(&v1[3], 
				CreateRootTree(&v1[6], CreateEmptyTree(), CreateEmptyTree()),
				CreateRootTree(&v1[7], CreateEmptyTree(), CreateEmptyTree())),
			CreateRootTree(&v1[4], CreateEmptyTree(), CreateEmptyTree())),
		CreateRootTree(&v1[2], CreateRootTree(&v1[5], CreateEmptyTree(), CreateEmptyTree()),CreateEmptyTree()));
	ElemType v2[]= { 1,2,3,4,5,12,21,2 };
	Node* t2 = CreateRootTree(&v2[0],
		CreateRootTree(&v2[1],
			CreateRootTree(&v1[3],
				CreateRootTree(&v2[6], CreateEmptyTree(), CreateEmptyTree()),
				CreateRootTree(&v2[7], CreateEmptyTree(), CreateEmptyTree())),
			CreateRootTree(&v2[4], CreateEmptyTree(), CreateEmptyTree())),
		CreateRootTree(&v2[2], CreateRootTree(&v2[5], CreateEmptyTree(), CreateEmptyTree()), CreateEmptyTree()));
	bool z= Equivalenti(t1, t2);
	return z;
}
