void Prec(int a, int b, int *s) {
	if (b == 0) {
		return;
	}
	else {
		b--;
		(*s) *= a;
		Prec(a, b, s);
	}
}
int Potenza(int a, int b) {
	if (a == 0 && b==0) {
		return 1;
	}
	if (b == 0) {
		return 1;
	}
	if (a == 0) {
		return 0;
	}
	int s = 1;
	Prec(a, b,&s);
	return s;
}
