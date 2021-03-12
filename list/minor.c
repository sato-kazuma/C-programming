#include"list_int.h"
#include<stdlib.h>
Item* CreaDaMinori(const Item* i, int v) {
	if (IsEmptyList(i)) {
		return NULL;
	}
	else
	{
		Item* r = NULL;
		while (!IsEmptyList(i)) {
			if (i->value <= v) {
				r = InsertBackList(r, GetHeadValueList(i));
			}
			i = GetTailList(i);
		}
	return r;
	}
}
