//Sort 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int compare(const void* a, const void* b);

int main(void) {
	int size = 0;
	scanf("%d", &size);
	int* arr = (int*)calloc(size, sizeof(int));
	for (int i = 0; i < size; i++) { scanf("%d", &arr[i]); }
	qsort(arr, size, sizeof(int), compare);
	for (int i = 0; i < size; i++) { printf("%d\n", arr[i]); }

	free(arr);
	return 0;
}

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}
