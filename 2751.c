//2751
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);

int main(void) {
	int testCase = 0;
	scanf("%d", &testCase);
	int* arr = (int*)malloc(sizeof(int) * testCase);
	for (int i = 0; i < testCase; i++) {
		scanf("%d", &arr[i]);
	}

	qsort(arr, testCase, sizeof(int), compare);

	for (int i = 0; i < testCase; i++) {
		printf("%d\n", arr[i]);
	}


	return 0;
}

int compare(const void* a, const void* b)
{
	if (*(int*)a > *(int*)b)
		return 1;
	else if (*(int*)a < *(int*)b)
		return -1;
	else
		return 0;
}