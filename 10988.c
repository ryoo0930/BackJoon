//10988
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char string[1001];
	gets(string);

	int checkSame = 0;

	for (int i = 0; i < strlen(string); i++) {
		if (string[i] != string[strlen(string) - 1 - i]) {
			checkSame++;
			break;
		}
	}
	if (checkSame == 0) {
		printf("1");
	}
	else {
		printf("0");
	}
	return 0;
}