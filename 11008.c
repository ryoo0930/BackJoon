#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int testCase = 0;
	scanf("%d", &testCase);
	while (testCase--) {
		char string[10001], copy[101];
		scanf("%s %s", string, copy);

		int len = strlen(string), copylen = strlen(copy);
		int result = 0;
		for (int i = 0; i < len; i++) {
			//printf("%c ", string[i]);
			if (strncmp(string + i, copy, copylen) == 0) {
				result++;
				i += copylen - 1;
			}
			else result++;
		}
		printf("%d\n", result);

	}


	return 0;
}
