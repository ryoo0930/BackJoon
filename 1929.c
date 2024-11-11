//1929
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	int M = 0, N = 0;
	scanf("%d %d", &M, &N);
	
	int* arr = (int*)calloc(N + 1, sizeof(int)); // 0 ~ N까지의 배열 생성.
	for (int i = 2; i <= N; i++) {
		arr[i] = i; // 2 ~ N 까지 배열에 숫자 입력. (arr[2] = 2 ...... arr[N] = N)
	}
	
	int root = ceil(sqrt((float)N)); // 제곱근 구하기. (제곱근을 올림 한 수)
	for (int i = 2; i <= root; i++) {
		if (arr[i] != 0) {
			for (int j = i * 2; j <= N; j += i) {
				arr[j] = 0;
			}
		}
	}

	for (int i = M; i <= N; i++) {
		if (arr[i] != 0) {
			printf("%d ", i);
		}
	}


	free(arr);
	return 0;
}