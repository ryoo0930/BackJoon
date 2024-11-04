//8958
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int testCase = 0;
	scanf("%d", &testCase);
	getchar(); // Buffer remove
	char** string = (char**)malloc(sizeof(char*) * testCase);
	for (int i = 0; i < testCase; i++) {
		string[i] = (char*)malloc(sizeof(char) * 81);
		gets(string[i]);
	}

	for (int i = 0; i < testCase; i++) {
		int len = strlen(string[i]);
		int score = 0;
		int correct = 1;
		for (int j = 0; j < len; j++) {
			if (string[i][j] == 'O') {
				score += correct;
				correct++;
			}
			else {
				correct = 1;
			}
		}
		printf("%d\n", score);
	}


	return 0;
}