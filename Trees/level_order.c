#include"tree_int.h"
#include<stdio.h>

void LevelCounter(const Node* t, int i, int* level) {

	if (IsEmptyTree(t))
		return;
	if (i > * level)
		*level = i;

	LevelCounter(t->left, i + 1, level);

	LevelCounter(t->right, i + 1, level);
}

void LevelOrderRec(const Node* t, int i, int level) {

	if (IsEmptyTree(t))
		return;

	if (i == level)
		printf("%d ", t->value);

	LevelOrderRec(t->left, i + 1, level);

	LevelOrderRec(t->right, i + 1, level);
}

void LevelOrder(const Node* t) {

	if (IsEmptyTree(t))
		return;

	if (IsEmptyTree(t->left) && IsEmptyTree(t->right)) {
		printf("%d ", t->value);
		return;
	}
	else {
		printf("%d ", t->value);
	}

	int level = 0;

	LevelCounter(t, 1, &level);

	for (int j = 1; j <= level; ++j) {
		LevelOrderRec(t, 0, j);
	}
}

//main
#include"tree_int.h"
extern void LevelOrder(const Node* t);
int main(void) {
	ElemType v1[] = { 1,2,3,4,5,6,7,8,9 };
	Node* t1 = CreateRootTree(&v1[0],
		CreateRootTree(&v1[1],
			CreateRootTree(&v1[3],
				CreateRootTree(&v1[6], CreateEmptyTree(), CreateEmptyTree()),
				CreateRootTree(&v1[7], CreateEmptyTree(), CreateEmptyTree())),
			CreateRootTree(&v1[4], CreateEmptyTree(), CreateEmptyTree())),
		CreateRootTree(&v1[2], CreateRootTree(&v1[5], CreateEmptyTree(), CreateEmptyTree()), CreateEmptyTree()));
	LevelOrder(t1);
	return;

}
