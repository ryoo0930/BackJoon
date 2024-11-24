//Sort 3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);

int main(void) {
	int size = 0, cut = 0;
	scanf("%d %d", &size, &cut);
	int* arr = (int*) calloc(size, sizeof(int));
	for (int i = 0; i < size; i++) { scanf("%d", &arr[i]); }
	qsort(arr, size, sizeof(int), compare);
	printf("%d", arr[cut - 1]);

	free(arr);
	return 0;
}

int compare(const void* a, const void* b) {
	return (*(int*)b - *(int*)a);
}
