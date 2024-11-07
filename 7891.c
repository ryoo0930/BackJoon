//7891
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int testCase = 0;
	scanf("%d", &testCase);
	for (int i = 0; i < testCase; i++) {
		int num1 = 0, num2 = 0;
		scanf("%d %d", &num1, &num2);
		printf("%d\n", num1 + num2);
	}

	return 0;
}