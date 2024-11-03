//2581
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int M = 0, N = 0;					// M < PRIME NUMBER < N //
	scanf("%d ", &M);
	scanf("%d ", &N);

	int sum = 0;
	int FirstN = 0;
	int cnt = 0;
	int i = 0, j = 0, k = 0;;

	int* arr = (int*)malloc(sizeof(int) * (N - M));
	memset(arr, '0', (N - M) * sizeof(int));
	for (i = M; i <= N; i++) {
		for (j = 2; j < i; j++) {
			if ((i % j) == 0) {
				break;
			}
		}
		if (i == j) {
			cnt++;
			sum += i;
			arr[k] = i;
			k++;
		}
	}

	// 소수가 0개 일 때 //
	if (cnt == 0) {
		printf("-1");
	}
	else {
		printf("%d\n", sum);
		printf("%d", arr[0]);
	}


	return 0;
}