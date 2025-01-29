#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool checkSame(char** string, int size, int fullLen, int len);

int main() {
	int size = 0;
	scanf("%d", &size);

	char** string = (char**)malloc(sizeof(char*) * size);
	for (int i = 0; i < size; i++) string[i] = (char*)malloc(sizeof(char) * 101);
	for (int i = 0; i < size; i++) scanf("%s", string[i]);

	int len = strlen(string[0]);
	for (int i = 1; i <= len; i++) {
		if (!checkSame(string, size, len, i)) {
			printf("%d", i);
			break;
		}
	}

	for (int i = 0; i < size; i++) free(string[i]);
	free(string);
	return 0;
}

bool checkSame(char** string, int size, int fullLen, int len) {
	bool isSame = false;
	char** newString = (char**)malloc(sizeof(char*) * size);
	for (int i = 0; i < size; i++) newString[i] = (char*)malloc(sizeof(char) * len + 1);
	for (int i = 0; i < size; i++) strcpy(newString[i], string[i] + fullLen - len);

	bool flag = false;
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (strcmp(newString[i], newString[j]) == 0) {
				isSame = true;
				flag = true;
				break;
			}
		}
		if (flag) break;
	}

	for (int i = 0; i < size; i++) free(newString[i]);
	free(newString);
	return isSame;
}
