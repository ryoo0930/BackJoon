//1316
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int testCase = 0;
	scanf("%d", &testCase);
	while (getchar() != '\n');

	char** string = (char**)malloc(sizeof(char*) * testCase);
	for (int i = 0; i < testCase; i++) {
		string[i] = (char*)malloc(sizeof(char) * 101);
	}
	for (int i = 0; i < testCase; i++) {
		gets(string[i]);
	}

	int cheker = 0;
	int flag = 0;
	for (int i = 0; i < testCase; i++) {
		int len = strlen(string[i]);
		int check = 0;
		for (int j = 0; j < len - 1; j++) {
			if (string[i][j] != string[i][j + 1]) {
				check = j;
				flag = 0;
				for (int k = j + 1; k < len; k++) {
					if (string[i][j] == string[i][k]) {
						cheker++;
						flag = 1;
						break;
					}
				}
				if (flag == 1) {
					break;
				}
			}
		}
	}
	printf("%d", testCase - cheker);

	return 0;
}