//27866
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char string[1000];
	int var1;
	gets(string);
	scanf("%d", &var1);

	printf("%c", string[var1 - 1]);
	return 0;
}