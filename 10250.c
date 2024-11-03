//10250
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int testCase = 0;
	scanf("%d", &testCase);
	int* result = (int*)malloc(sizeof(int) * testCase);
	for (int i = 0; i < testCase; i++) {
		int a = 0, b = 0, c = 0;
		int num1 = 0, num2 = 0;

		scanf("%d %d %d", &a, &b, &c);

		num1 = c % a;
		num2 = c / a;
		if (c % a == 0) {
			result[i] = (a * 100) + num2;
		}
		else {
			num2++;
			result[i] = (num1 * 100) + num2;
		}
	}

	for (int i = 0; i < testCase; i++) {
		printf("%d\n", result[i]);
	}

	return 0;
}