//11727
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int widthSize = 0;
	scanf("%d", &widthSize);
	int* dp = (int*)calloc(widthSize + 1, sizeof(int));
	dp[1] = 1;
	if (widthSize >= 2) {
		dp[2] = 3;
	}
	for (int i = 3; i <= widthSize; i++) {
		dp[i] = ((2 * dp[i - 2]) + dp[i - 1]) % 10007;
	}

	printf("%d", dp[widthSize]);

	return 0;
}