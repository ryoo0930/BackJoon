//1929
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	int M = 0, N = 0;
	scanf("%d %d", &M, &N);
	
	int* arr = (int*)calloc(N + 1, sizeof(int)); // 0 ~ N������ �迭 ����.
	for (int i = 2; i <= N; i++) {
		arr[i] = i; // 2 ~ N ���� �迭�� ���� �Է�. (arr[2] = 2 ...... arr[N] = N)
	}
	
	int root = ceil(sqrt((float)N)); // ������ ���ϱ�. (�������� �ø� �� ��)
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