//9086
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int testCase;
	scanf("%d", &testCase);
	while (getchar() != '\n');

	char** string = (char**)malloc(sizeof(char*) * testCase);


	for (int i = 0; i < testCase; i++) {
		string[i] = (char*)malloc(sizeof(char) * 1000);
	}

	for (int i = 0; i < testCase; i++) {
		gets(string[i]);
	}

	for (int i = 0; i < testCase; i++) {
		printf("%c%c\n", string[i][0], string[i][strlen(string[i]) - 1]);
	}


	for (int i = 0; i < testCase; i++) {
		free(string[i]);
	}
	free(string);
	return 0;
}