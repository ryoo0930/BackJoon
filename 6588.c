//Goldbach's conjecture
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void sieve(int* arr);

int main(void) {
	int* arr = (int*)malloc(sizeof(int) * 1000001);
	arr[0] = 0, arr[1] = 0;
	for (int i = 2; i <= 1000000; i++) {
		arr[i] = i;
	}
	sieve(arr);

	int num = 0;
	while(scanf("%d", &num) == 1 && num != 0) {
		

		int flag = 0;
		int half = num / 2;
		for (int i = 2; i <= half; i++) {
			if (arr[i] + arr[num - i] == num) {
				printf("%d = %d + %d\n", num, arr[i], arr[num - i]);
				flag = 1;
				break;
			}
		}
		if (!flag) {
			printf("Goldbach's conjecture is wrong.\n");
		}
	}
	free(arr);
	return 0;
}

void sieve(int* arr) {
	for (int i = 2; i <= 1000; i++) {
		if (arr[i] != 0) {
			for (int j = i + i; j <= 1000000; j += i) {
				arr[j] = 0;
			}
		}
	}
}
