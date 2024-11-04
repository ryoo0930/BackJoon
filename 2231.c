//2231
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int N = 0;
	scanf("%d", &N);

	int count = 0;

	for (int i = 1; i < N; i++) {
		int num = i;
		int sum = i;
		for (int j = i; j > 0; j = j / 10) {
			sum += j % 10;
		}
		if (sum == N) {
			printf("%d", i);
			count++;
			break;
		}
	}

	if (count == 0) {
		printf("0");
	}


	return 0;
}