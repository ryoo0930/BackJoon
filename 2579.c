//2579
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int result(int size);

int main(void) {
	int stairSize = 0;
	scanf("%d", &stairSize);
	
	printf("%d", result(stairSize));

	return 0;
}

int result(int size) {
	int* stairScore = (int*)calloc(size + 1, sizeof(int)); // ��� ����.
	int* dp = (int*)calloc(size + 1, sizeof(int));
	int index = -1;
	for (int i = 1; i <= size; i++) {
		scanf("%d", &stairScore[i]);
	}
	dp[1] = stairScore[1]; // ù��°�� �ö󰡰�
	if (size > 1) { dp[2] = stairScore[1] + stairScore[2]; } // �ι�° �� �ö� �� ����.
	for (int i = 3; i <= size; i++) {
		if (dp[i - 2] > (dp[i - 3] + stairScore[i - 1])) {
			dp[i] = dp[i - 2] + stairScore[i];
		}
		else {
			dp[i] = dp[i - 3] + stairScore[i - 1] + stairScore[i];
		}
	}
	index = dp[size];
	return index; 
}