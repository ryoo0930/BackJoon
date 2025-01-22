#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);

int main() {
	int size = 0, position = 0;
	scanf("%d %d", &size, &position);

	int* arr = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) { scanf("%d", &arr[i]); }

	qsort(arr, size, sizeof(int), compare);
	printf("%d", arr[position - 1]);

	free(arr);
	return 0;
}

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}
