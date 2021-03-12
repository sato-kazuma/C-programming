#include<stdlib.h>
void InsertionSort(int* v, size_t v_size) {
	if (v == NULL || v_size <= 1) { return; }
	else {
		for (size_t k = 1; k < v_size; k++) {
			int prec = k - 1, attuale = v[k];
			while (prec >= 0 && attuale < v[prec])
			{
				v[prec + 1] = v[prec]; /* crea lo spazio */
				prec--;
			}
			v[prec + 1] = attuale; /* inserisce l�elemento */
		}
	}
	return;
}
