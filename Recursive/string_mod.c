#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>     


void Back(int k, char* v, int i, int n) {


	if (i == k) {

		printf("[");

		for (int j = 0; j < k; ++j) {

			if (j == k - 1) {

				printf("%]}, ", v[j]);
			}
			else
			{
				printf("%c", v[j]);
			}
		}
		return;
	}
	for (int j = 1; j < n; ++j) {

		v[i] = j;
		Back(k, v, i + 1, n);
	}
}


int steps(int n) {

	if (n <= 0 || n >= 26 ) {
		return;
	}
	char* v = malloc(n);
	int i = 0;
	Back(k, v, i, n);
	free(v);
	return;
}




//main
int main(void) {
extern void BacktrackStrMod(int n, int k);
	int n = 2; int k = 3;
	BacktrackStrMod(n, k);
	return 0;
}
