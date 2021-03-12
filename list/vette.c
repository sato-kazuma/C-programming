#include"list_int.h"
#include<stdlib.h>

int ContaVette(const Item* i) {
	if (IsEmptyList(i)) { return 0; }
	int cnt1 = 0; int cnt2 = 0; int vetta = 0;
	const Item * tmp = i;
	while(!IsEmptyList(tmp)){
		const Item* tmp2 = tmp->next;
		{
			while (!IsEmptyList(tmp2)) {
				if (ElemCompare(GetHeadValueList(tmp), GetHeadValueList(tmp2)) >=0) {
					cnt2++;
				}
				cnt1++;
				tmp2 = GetTailList(tmp2);
			}
			if (cnt1 == cnt2) {
				vetta++;
			}
			cnt1 = 0; cnt2 = 0;
			tmp = GetTailList(tmp);
		}
	}
	return vetta;
}
