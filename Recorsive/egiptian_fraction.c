#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int arrot(double div) {
	int in = (int)div;
	double resto = div - in;
	if (resto != 0) {
		++in;
		return in;
	}
	else {
		return in;
	}
}

void fraz_rec(int n, int n2, int d, double ris, int mcd) {
	if (d % n == 0) {
		ris = (double)d / (double)n;
		printf("1/%d", arrot(ris));
		return;

	}
	ris = (double)d / (double)n;
	printf("1/%d + ", arrot(ris));
	mcd = d * (arrot(ris));
	n = (mcd / d) * n;
	n2 = (mcd / (arrot(ris)));
	n = n - n2;
	d = mcd;
	fraz_rec(n, n2, d, ris, mcd);
}

void FrazioneEgizia(int n, int d) {
	if (n <= 0 || d <= 0 || n > d) {
		printf("Impossibile convertire la frazione data in frazione egizia");
		return;
	}
	double ris = 0.0;
	fraz_rec(n, 0, d, ris, 0);
	return;
}


//main
int main(void) {
	int n = 7;
	int d = 24;
	FrazioneEgizia(n, d);
	return 0;
}
