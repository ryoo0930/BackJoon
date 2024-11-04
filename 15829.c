//15829
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int size = 0;
	scanf("%d", &size);
	getchar();
	char* string = (char*)malloc(sizeof(char) * (size + 1));
	gets(string);

	int len = strlen(string);

	int M = 1234567891;
	int key = 31;

	long long hash = 0;
	long long r = 1;

	for (int i = 0; i < len; i++) {
		hash += ((string[i] - 'a' + 1) * r) % M;
		r *= key;
		r = r % M;
	}

	hash = hash % M;

	printf("%lld", hash);
	return 0;
}