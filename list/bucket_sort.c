#include "list_int.h"
#include <stdlib.h>
Item* BucketSort(Item* l)
{
    int n=0, min=0, max=0;
    GetMinMaxSize(l, &min, &max, &n);

    if (n < 2) {
        return l;
    }

    // Punto 1
    Item** v = calloc(n, sizeof(Item*));
    //for (int i = 0; i < n; ++i) {
    //    v[i] = NULL; //CreateEmptyList();
    //}

    // Punto 2
    for (Item* tmp = l; !IsEmptyList(tmp); tmp = GetTailList(tmp)) {
        int e = tmp->value;
        int index = (n - 1) * (e - min) / (max - min);
        v[index] = InsertHeadList(&e, v[index]);
    }
    DeleteList(l);

    // Punto 3
    for (int i = 0; i < n; ++i) {
        v[i] = BucketSort(v[i]);
    }

    // Punto 4
    Item* ret = CreateEmptyList();
    for (int i = 0; i < n; ++i) {
        ret = ConcatList(ret, v[i]);
    }

    free(v);
    return ret;
}
