//1010
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long result(int num1, int num2);

int main(void) {
	int testCase = 0;
	scanf("%d", &testCase);
	for (int i = 0; i < testCase; i++) {
		int Left = 0, Right = 0;
		scanf("%d %d", &Left, &Right);
		printf("%lld\n", result(Left, Right));
	}
	



	return 0;
}

long long result(int num1, int num2) {
	long long result = 1;
	for (int i = 1; i <= num1; i++) {
		result = result * num2 / i;
		num2--;
	}
	return result;
}