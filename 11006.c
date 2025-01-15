#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int testCase = 0;
	scanf("%d", &testCase);

	while (testCase--) {
		int N = 0, M = 0;
		scanf("%d %d", &N, &M);

		int one = (2 * M) - N;
		int two = M - one;

		printf("%d %d\n", one, two);
	}

	return 0;
}
