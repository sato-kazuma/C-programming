#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*
Un cacciatore pu� catturare una preda solo se questa si trova ad una distanza uguale o inferiore di u unit� da lui. Inoltre, ogni cacciatore pu� catturare al massimo una preda.
Utilizzando un algoritmo di backtracking, la funzione CacciatorePreda deve associare ad ogni cacciatore una preda, in modo tale che sia massimo il numero di prede catturate. La funzione deve quindi ritornare un
vettore di interi, allocato dinamicamente, della stessa dimensione di v. Ogni elemento del vettore deve contenere -2 se l'elemento corrisponde ad una preda catturata, -1 se l'elemento corrisponde ad una preda libera o a
un cacciatore senza preda, l'indice della preda catturata se l'elemento corrisponde ad un cacciatore che ha catturato una preda
*/

void Cattura_Rec(const char* v, size_t  n, int u, int* vcurr, signed int i, size_t  cnt)
{
	if (cnt == n || (size_t)i == n)
	{
		return;
	}

	if (v[i] == 'C' || v[i] == 'c')
	{
		for (signed int j = 0; (size_t)j < n; j++)
		{
			if ((v[j] == 'p' || v[j] == 'P') && vcurr[j] == -1 && vcurr[i] == -1)
			{
				if (j - i <= u)
				{
					vcurr[i] = j;
					vcurr[j] = -2;
					cnt = cnt + 1;
				}
			}

		}
		Cattura_Rec(v, n, u, vcurr, i + 1, cnt);
	}
	Cattura_Rec(v, n, u, vcurr, i + 1, cnt);
}

int* CacciatorePreda(const char* v, size_t v_size, int u)
{
	signed int  i = 0;
	int* vcurr = malloc(v_size * sizeof(int));
	size_t cnt = 0;
	for (size_t i = 0; i < v_size; ++i)
	{
		vcurr[i] = -1;
	}
	Cattura_Rec(v, v_size, u, vcurr, i, cnt);
	return vcurr;

}

int main(void) {
	const char v[] = { 'c','C','c','c','p','p'};
	size_t v_size = 6;
	int u = 2;
	int* r = CacciatorePreda(v, v_size, u);
	return 0;
}
