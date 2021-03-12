int MCDRec(int m, int n) {
	if (n == 0) {
		return m;
	}
	else {
		return MCDRec(n, m % n);
	}
}
int MCD(int m, int n) {
	if (n > m) {
		int a = n;
		n = m;
		m = a;
	}
	int z = MCDRec(m, n);
	return z;
}
int main(void) {
	int m = 2; int n = 10;
	int r = MCD(m, n);
	return 0;
}
