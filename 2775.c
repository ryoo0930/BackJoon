//2775
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int testCase = 0;
	scanf("%d", &testCase);
	for (int i = 0; i < testCase; i++) {
		int num1 = 0, num2 = 0;
		scanf("%d %d", &num1, &num2);
		long long** arr = (int**)malloc(sizeof(long long*) * num1 + 1);
		for (int j = 0; j < num1 + 1; j++) {
			arr[j] = (long long*)malloc(sizeof(long long) * 14);  // (num1 + 1) X 14의 아파트 배열 생성. 높 : num1 + 1, 가로 14.
		}

		for (int j = 0; j < 14; j++) { // 0층 초기화
			arr[0][j] = j + 1;
		}



		for (int j = 1; j < num1 + 1; j++) {
			for (int k = 0; k < num2; k++) {
				long long sum = 0;
				for (int l = 0; l <= k; l++) {
					sum = sum + arr[j - 1][l];
				}
				arr[j][k] = sum;
			}
		}

		printf("%lld\n", arr[num1][num2 - 1]);

	}


	return 0;
}