#include <float.h>
#include "tree_int.h"
void WriteOrderTreeRecD(const Node* n, int* ind, int* i, double* m)
{
	if (IsEmptyTree(n)) {
		return;
	}

	WriteOrderTreeRecD(LeftTree(n), ind, i, m);

	++(*i);
	if (*i == *ind) {
		*m = n->value;
		return;
	}

	WriteOrderTreeRecD(RightTree(n), ind, i, m);

}
void WriteOrderTreeRecP(const Node* n, int* ind, int* i, double* e1, double* e2, double* m)
{
	if (IsEmptyTree(n)) {
		return;
	}

	WriteOrderTreeRecP(LeftTree(n), ind, i, e1, e2, m);

	++(*i);
	if (*i == *ind) {
		*e1 = n->value;
	}
	if (*i == *ind + 1) {
		*e2 = n->value;
		*m = ((*e1) + (*e2)) / 2;
		return;
	}
	WriteOrderTreeRecP(RightTree(n), ind, i, e1, e2, m);

}


void dimensione(const Node* t, int* dim) {
	if (IsEmptyTree(t)) {
		return;
	}
	else {
		++(*dim);
	}
	dimensione(LeftTree(t), dim);
	dimensione(RightTree(t), dim);
}

double Mediano(const Node* t) {
	if (IsEmptyTree(t))
		return DBL_MAX;
	int dim = 0;
	dimensione(t, &dim);
	double m = 0.0;
	int ind = 0;
	if (dim % 2 != 0) {
		ind = (dim + 1) / 2;
		int i = 0;
		WriteOrderTreeRecD(t, &ind, &i, &m);
	}
	else {
		ind = dim / 2;
		int i = 0;
		double e1 = 0, e2 = 0;
		WriteOrderTreeRecP(t, &ind, &i, &e1, &e2, &m);
	}
	return m;
}

//main
#include"tree_int.h"
int main(void) {
	ElemType v[] = { 21,5,0,4,2,12,18 };
	Node* t = CreateRootTree(&v[0],
		CreateRootTree(&v[3],
			CreateRootTree(&v[2], CreateEmptyTree(), CreateEmptyTree()),
			CreateRootTree(&v[4], CreateEmptyTree(), CreateEmptyTree())),
		CreateRootTree(&v[5],
			CreateRootTree(&v[1], CreateEmptyTree(), CreateEmptyTree()), CreateEmptyTree()));
	double Conta = Mediano(t);
	return 0;
}
