#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void* a, const void* b);

int main() {
	int A = 0, B = 0, C = 0;
	scanf("%d %d %d", &A, &B, &C);

	for (int i = 1; i <= 10; i++) {
		bool isZero = true;
		for (int j = 1; j <= 10; j++) {
			if (i * A + j * B == C) {
				isZero = false;
				printf("%d ", j);
			}
		}
		if (isZero) { printf("0"); }
		printf("\n");
	}

	return 0;
}
