//Sort 2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);

int main(void) {
	int arr[5] = { 0 };
	for (int i = 0; i < 5; i++) { scanf("%d", &arr[i]); }
	qsort(arr, 5, sizeof(int), compare);
	int sum = 0;
	for (int i = 0; i < 5; i++) { sum += arr[i]; }

	printf("%d\n", sum / 5);
	printf("%d\n", arr[2]);

	return 0;
}

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}
