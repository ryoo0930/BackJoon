//2743
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char string[100];
	gets(string);
	printf("%d", strlen(string));
	return 0;
}