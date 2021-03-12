#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
void conta(const char* str,int *cnt) {
	while (*str != '\0') {
		(*cnt)++;
		*str++;
	}
	return;
}
void rec( const char* str, const char* reverse,int i,int *p) {
	if (str[i] == '\0') {
		return;
	}
	if (str[i] != reverse[i]) {
		*p = false;
		return;
	}
	else{
	rec(str, reverse, i+1 ,p);
	}
}

bool IsPalindromo(const char* str) {
	if (str == NULL) { return false; }
	int cnt = 0; int o = 0; int p = 1;
	conta(str,&cnt);
	if (cnt == 0) { return true; }
	char* reverse = malloc(cnt+1 * sizeof(char));
	for (int u = cnt-1; u>=0; u--) {
		reverse[o] = str[u];
		o++;
	}
	reverse[o] = '\0';
	rec(reverse, str,0,&p);
	free(reverse);
	return p;
}

//main
#include<stdbool.h>
extern bool IsPalindromo(const char* str);
int main(void) {
	char *str = "osso";
	IsPalindromo(str);
	return;
}
