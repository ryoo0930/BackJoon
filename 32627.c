#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int alphabet[26] = { 0, };

int main() {
	int length = 0, count = 0;
	scanf("%d %d", &length, &count);

	char* string = (char*)malloc(sizeof(char) * (length + 1));
	scanf("%s", string);

	for (char c = 'a'; c <= 'z'; c++) {
		for (int i = 0; i < length && count > 0; i++) {
			if (string[i] == c) {
				string[i] = '!';
				count--;
			}
		}
	}

	for (int i = 0; i < length; i++) {
		if (string[i] != '!') {
			printf("%c", string[i]);
		}
	}

	free(string);
	return 0;
}
