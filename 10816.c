//10816
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define OFFSET 10000000
#define MAX_RANGE 20000001

int main(void) {
	int testCase = 0;
	scanf("%d", &testCase);

	int* count = (int*)calloc(MAX_RANGE, sizeof(int));
	for (int i = 0; i < testCase; i++) {
		int tmp = 0;
		scanf("%d", &tmp);
		count[OFFSET + tmp]++;
	}

	int testCase2 = 0;
	scanf("%d", &testCase2);

	for (int i = 0; i < testCase2; i++) {
		int query = 0;
		scanf("%d", &query);
		printf("%d ", count[query + OFFSET]);
	}

	return 0;
}