//1312
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int A = 0, B = 0;
	int position = 0;
	scanf("%d %d %d", &A, &B, &position);

	A = A % B;
	for (int i = 0; i < position - 1; i++) {
		A = (A * 10) % B;
	}
	A = (A * 10) / B;
	printf("%d", A);

	return 0;
}