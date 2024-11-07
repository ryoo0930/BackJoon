//25784
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);

int main(void) {
	int num[3] = { 0 };
	for (int i = 0; i < 3; i++) {
		scanf("%d ", &num[i]);
	}
	qsort(num, 3, sizeof(int), compare);
	if ((num[0] + num[1]) == num[2]) {
		printf("1");
	}
	else if ((num[0] * num[1]) == num[2]) {
		printf("2");
	}
	else {
		printf("3");
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