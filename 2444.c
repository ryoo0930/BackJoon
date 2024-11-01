//2444
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int var = 0;
	scanf("%d", &var);
	for (int i = 0; i < var; i++) {
		for (int j = 1; j < var - i; j++) {
			printf(" ");
		}
		for (int k = 0; k < (2 * i) + 1; k++) {
			printf("*");
		}
		printf("\n");
	}

	for (int i = var - 2; i >= 0; i--) {
		for (int j = 1; j < var - i; j++) {
			printf(" ");
		}
		for (int k = 0; k < (2 * i) + 1; k++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}