#include"tree_int.h"
void LevelCounter(const Node* t, int i, int* level) {
	if (IsEmptyTree(t))
		return;
	if (i > * level)
		*level = i;

	LevelCounter(t->left, i + 1, level);
	LevelCounter(t->right, i + 1, level);
}
int Diameter(const Node* t) {
	if (IsEmptyTree(t)) {
		return 0;
	}
	if (t->left == NULL && t->right == NULL) {
		return 1;
	}
	else {
		int level = 0; int cmp = 0; int tmp = 0;
		LevelCounter(t->left, 1, &level);
		LevelCounter(t->right, 1, &cmp);
		LevelCounter(t, 1, &tmp);
		int res = 0;
		if (level > cmp) {
			res = level;
		}
		else {
			res = cmp;
		}
		res += tmp;
		return res;
	}
}
