//1181
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
	char* strA = *(char**)a;
	char* strB = *(char**)b;
	int lenA = strlen(strA);
	int lenB = strlen(strB);
	if (lenA == lenB) {
		return strcmp(strA, strB);
	}
	return lenA - lenB;
}

int main(void) {
	int testCase = 0;
	scanf("%d", &testCase);
	getchar();
	char** string = (char**)malloc(sizeof(char*) * testCase);
	for (int i = 0; i < testCase; i++) {
		string[i] = (char*)malloc(sizeof(char) * 51);
		memset(string[i], '0', sizeof(char) * 51);
		gets(string[i]);
	}

	char temp[51] = { 0 };


	qsort(string, testCase, sizeof(char*), compare);

	printf("%s\n", string[0]);
	for (int i = 1; i < testCase; i++) {
		if (strcmp(string[i], string[i - 1]) != 0) {
			printf("%s\n", string[i]);
		}
	}

	return 0;
}