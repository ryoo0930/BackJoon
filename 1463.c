//1463
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int result(int num);

int main(void) {
	int num = 0;
	scanf("%d", &num);
	printf("%d", result(num));


	return 0;
}

int result(int num) {
	int* dp = (int*)calloc(num + 1, sizeof(int));
	int result = -1;
	for (int i = 2; i <= num; i++) {
		//1�� ���� ���
		dp[i] = dp[i - 1] + 1;
		//2�� ������ �������� ���
		if((i % 2) == 0) {
			if (dp[i] > dp[i / 2] + 1) {
				dp[i] = dp[i / 2] + 1;
			}
		}
		//3���� ������ �������� ���
		if ((i % 3) == 0) {
			if (dp[i] > dp[i / 3] + 1) {
				dp[i] = dp[i / 3] + 1;
			}
		}
	}
	result = dp[num];
	free(dp);
	return result;
}