

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>     


void Back(int n, char* v, int i) {


	if (i == n) {

		printf("[");

		for (int j = 0; j < n; ++j) {

			if (j == n - 1) {

				printf("%d ], ", v[j]);
			}
			else
			{
				printf("%d", v[j]);
			}
		}
		return;
	}
	for (int j = 1; j < n; ++j) {

		v[i] = j;
		Back(n,v+1,i+1);
	}
}


int steps(int n) {

	if (n <= 0) {
		return 0;
	}
	char* v = malloc(n);
	int i = 0;
	Back(n,v,i);
	free(v);
	return 0;
}

//main
extern int steps(int n);
int main(void) {
	int n = 2;
	int s = steps(n);
	return;
}
