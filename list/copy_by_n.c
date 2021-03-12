#include"list_int.h"
#include<stdlib.h>
Item* CopiaDaN(const Item* i, int n) {
	if (IsEmptyList(i)){
		return NULL;
	}
	else {
		int cnt = 1;
		Item* new = NULL;
		while (!IsEmptyList(i)) {
			if (cnt >= n) {
				new = InsertBackList(new, GetHeadValueList(i));
				cnt++;
				i = GetTailList(i);
			}
			else {
				i = GetTailList(i);
				cnt++;
			}
		}
		return new;
	}
} 
