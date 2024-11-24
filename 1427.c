//Sort 6
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b);

int main(void) {
	char string[11] = { 0 };
	scanf("%s", &string);
	int len = strlen(string);
	qsort(string, len, sizeof(char), compare);

	printf("%s", string);
	return 0;
}

int compare(const void* a, const void* b) {
	return strcmp((char*)b, (char*)a);
}
