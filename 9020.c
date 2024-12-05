//Goldbach's conjecture
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void sieve(int* arr);

int main(void) {
	int arr[10001] = { 0 };
	for (int i = 2; i <= 10000; i++) {
		arr[i] = i;
	}
	sieve(arr); // Sieve of Eratosthenes

	int testCase = 0;
	scanf("%d", &testCase);
	for (int t = 0; t < testCase; t++) {
		int num = 0;
		scanf("%d", &num);

		int half = num / 2;
		int min = 10000;
		int num1 = 0, num2 = 0;
		for (int i = 2; i <= half; i++) {
			if (arr[i] + arr[num - i] == num) {
				if (min > arr[num - i] - arr[i]) {
					min = arr[num - i] - arr[i];
					num1 = arr[i], num2 = arr[num - i];
				}
			}
		}

		printf("%d %d\n", num1, num2);
	}


	return 0;
}

void sieve(int* arr) {
	for (int i = 2; i <= 100; i++) {
		if (arr[i] != 0) {
			for (int j = i + i; j <= 10000; j += i) {
				arr[j] = 0;
			}
		}
	}
}
