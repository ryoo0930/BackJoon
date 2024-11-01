//2675
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int testCase;
	scanf("%d ", &testCase);

	int* repeat = (int*)malloc(sizeof(int) * testCase);
	char** string = (char**)malloc(sizeof(char*) * testCase);
	for (int i = 0; i < testCase; i++) {
		string[i] = (char*)malloc(sizeof(char) * 20);
	}

	for (int i = 0; i < testCase; i++) {
		scanf("%d ", &repeat[i]);
		gets(string[i]);
	}

	for (int i = 0; i < testCase; i++) {
		for (int j = 0; j < strlen(string[i]); j++) {
			for (int k = 0; k < repeat[i]; k++) {
				printf("%c", string[i][j]);
			}
		}
		printf("\n");
	}

	for (int i = 0; i < testCase; i++) {
		free(string[i]);
	}
	free(string);
	free(repeat);
	
	return 0;
}