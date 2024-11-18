//11659
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int arrSize = 0, testCase = 0;
	scanf("%d%d", &arrSize, &testCase);
	int* arr = (int*)calloc(arrSize + 1, sizeof(int));

	for (int i = 1; i <= arrSize; i++) {
		scanf("%d", &arr[i]);
	}
	long long* dp = (long long*)calloc(arrSize + 1, sizeof(long long));

	dp[0] = 0;
	dp[1] = arr[1]; // dp 초기값 설정;
	for (int i = 2; i <= arrSize; i++) {
		dp[i] = dp[i - 1] + arr[i];
	}

	for (int i = 0; i < testCase; i++) {
		int num1 = 0, num2 = 0;
		scanf("%d %d", &num1, &num2);
		printf("%lld\n", dp[num2] - dp[num1 - 1]);
	}

	free(dp);
	free(arr);
	return 0;
}