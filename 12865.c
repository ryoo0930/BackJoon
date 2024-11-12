//12865
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct goods {
	int weight;
	int value;
};

int knapsack(struct goods* g, int size, int MaxWeight);

int main(void) {
	int size = 0, MaxWeight = 0;
	scanf("%d %d", &size, &MaxWeight);

	struct goods* g = (struct goods*)calloc(size, sizeof(struct goods));
	for (int i = 0; i < size; i++) {
		scanf("%d %d", &g[i].weight, &g[i].value);
	}

	printf("%d", knapsack(g, size, MaxWeight));



	return 0;
}

int knapsack(struct goods* g, int size, int MaxWeight) {
	int** dp = (int**)calloc(size + 1, sizeof(int*));
	for (int i = 0; i < size + 1; i++) {
		dp[i] = (int*)calloc(MaxWeight + 1, sizeof(int));
	}

	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= MaxWeight; j++) {
			if (g[i - 1].weight <= j) {
				if (dp[i - 1][j] > dp[i - 1][j - g[i - 1].weight] + g[i - 1].value) { // 가치 계산.
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i - 1][j - g[i - 1].weight] + g[i - 1].value;
				}
			}
			else {
				dp[i][j] = dp[i - 1][j]; // 용량이 꽉 찼을 때.
			}
		}
	}

	int MaxValue = dp[size][MaxWeight];
	return MaxValue;
}