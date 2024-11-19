//17626
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	int num = 0;
	scanf("%d", &num);

	int* result = (int*)malloc(sizeof(int) * (num + 1));

	// 배열 초기화.
	result[0] = 0;
	for (int i = 1; i <= num; i++) {
		result[i] = 50000; // 최솟값을 구할 때 방해되지 않도록 최댓값으로 초기화.
	}

	for (int i = 1; i * i <= num; i++) {
		int index = i * i;
		for (int j = index; j <= num; j++) {
			if (result[j - index] + 1 < result[j]) {
				result[j] = result[j - index] + 1;
			}
		}
	}

	printf("%d", result[num]);

	return 0;
}