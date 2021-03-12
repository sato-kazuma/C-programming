#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

int ContaElementi(const char* r) {
	int numero = 0;
	int i = 0;
	while (1) {
		if (r[i] == '\0') {
			break;
		}
		++numero;
		++i;
	}
	return numero;
}

void RegoleRec(const char* r, int* v, int* sol, int* usati, int k, int index) {
	if (index == k) { //ho una soluzione
		//Verifico che la soluzione rispetti le regole:
		for (int p = 0; p < (k - 1); ++p) {
			if (r[p] == 'd' || r[p] == 'D') { //se � richiesto di decrementare
				if (sol[p] < sol[p + 1]) {
					return;
				}
			}
			else { //se � richiesto di incrementare
				if (sol[p] > sol[p + 1]) {
					return;
				}
			}
		}
		//Se ho concluso il ciclo significa che sono state rispettate le regole
		//e posso procedere quindi a stampare:
		for (int l = 0; l < k; ++l) {
			printf("%d ", sol[l]);
		}
		printf("\n");
	}

	for (int j = 0; j < k; ++j) {
		if (!usati[j]) {
			sol[index] = v[j];
			usati[j] = 1;
			RegoleRec(r, v, sol, usati, k, index + 1);
			usati[j] = 0;
		}
	}

}

void Regole(const char* r) {
	//conto il numero di regole:
	int num_elem = ContaElementi(r);
	//elementi presenti nel vettore:
	int k = num_elem + 1;
	//genero il vettore di k elementi
	int* v = malloc(k * sizeof(int));
	//Inizializzo il vettore da 1 a k:
	for (int i = 0; i < k; ++i) {
		v[i] = (i + 1);
	}
	//Creo un vettore soluzione:
	int* sol = malloc(k * sizeof(int));
	//Creao un vettore usati:
	int* usati = calloc(k, sizeof(int));
	//Cerco tutte le permutazioni di v:
	RegoleRec(r, v, sol, usati, k, 0);
	free(v);
	free(sol);
	free(usati);
	return;
}

//main
extern Regole(const char* r);
int main(void) {
	char r[] = { 'i','d','i' ,'d','\0'};
	Regole(r);
	return 0;
}

