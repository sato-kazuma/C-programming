#include"list_int.h"
#include<stdlib.h>
#include<string.h>
Item* Sum(const Item* i1, const Item* i2) {
	if (IsEmptyList(i1) && IsEmptyList(i2)) {
		Item* new = CreateEmptyList();
		return new;
	}
	if (IsEmptyList(i1) && !IsEmptyList(i2)) {
		Item* new = NULL;
		while (!IsEmptyList(i2)) {
			new = InsertBackList(new, GetHeadValueList(i2));
			i2 = GetTailList(i2);
		}
		return new;
	}
	if (!IsEmptyList(i1) && IsEmptyList(i2)) {
		Item* new = NULL;
		while (!IsEmptyList(i1)) {
			new = InsertBackList(new, GetHeadValueList(i1));
			i1 = GetTailList(i1);
		}
		return new;
	}
	Item* new = NULL; int cnt = 0;
	 ElemType rip = 0;  ElemType elem = 0;
	while (!IsEmptyList(i1)) {
		if (rip > 0) {
			elem += rip;
		}
		elem = i1->value + i2->value;
		while(elem >= 10) {
			elem -= 10;
			rip++;
		}
		InsertBackList(new, elem);
	}
	Item* new2 = NULL;
	while (!IsEmptyList(new)) {
		while (!IsEmptyList(new)) {
			if (new->value == 0) {
			new = GetTailList(new);
			}
			else {
				while (IsEmptyList(new)) {
				new2 = InsertBackList(new2, GetHeadValueList(new));
				new = GetTailList(new);
				}
				break;
			}
		}
	
	}

}
