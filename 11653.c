//11653
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	int num = 0;
	scanf("%d", &num);

	if (num == 1) { // N이 1인 경우 출력 안함.
		return 0;
	}

	int* arr = (int*)calloc(num + 1, sizeof(int));
	for (int i = 2; i <= num; i++) {
		arr[i] = i;
	}

	int CeilRoot = (int)ceil(sqrt(num));
	for (int i = 2; i <= CeilRoot; i++) {
		if (arr[i] != 0) {
			for (int j = i * i; j <= num; j += i) {
				arr[j] = 0;
			}
		}
	}

	while (num != 1) {
		for (int i = 2; i <= num; i++) {
			if ((arr[i] != 0) && (num % arr[i] == 0)) {
				printf("%d\n", arr[i]);
				num = num / arr[i];
				break;
			}
		}
	}

	free(arr);
	return 0;
}