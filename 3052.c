//3052
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int arr[10] = { 0 };
	int remainder[10] = { 0 };
	for (int i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < 10; i++) {
		remainder[i] = arr[i] % 42;
	}

	int checkSame = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (remainder[i] == remainder[j]) {
				checkSame++;
				break;
			}
		}
	}

	printf("%d", 10 - checkSame);
	return 0;
}