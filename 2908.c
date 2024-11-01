//2908
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char string[8];
	gets(string);

	char num1[4] = { 0 };
	char num2[4] = { 0 };
	for (int i = 0; i < 3; i++) {
		num1[i] = string[2 - i];
		num2[i] = string[6 - i];
	}

	if (atoi(num1) > atoi(num2)) {
		printf("%s", num1);
	}
	else {
		printf("%s", num2);
	}

	return 0;
}