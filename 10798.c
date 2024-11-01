//10798
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char** arr = (char**)malloc(sizeof(char*) * 5);
	for (int i = 0; i < 5; i++) {
		arr[i] = (char*)malloc(sizeof(char*) * 16);
	}

	for (int i = 0; i < 5; i++) {
		memset(arr[i], NULL, 16);
		gets(arr[i]);
	}

	int maxlen = 0;
	for (int i = 0; i < 5; i++) {
		if (maxlen <= strlen(arr[i])) {
			maxlen = strlen(arr[i]);
		}

	}

	for (int i = 0; i < maxlen; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[j][i] == NULL || arr[j][i] == '\0') {
				continue;
			}
			else {
				printf("%c", arr[j][i]);
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		free(arr[i]);
	}
	free(arr);
	return 0;
}