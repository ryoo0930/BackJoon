#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);

int main()
{
	int size = 0;
	scanf("%d", &size);

	int* arr = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) scanf("%d", &arr[i]);

	int* height = (int*)calloc(size, sizeof(int));
	int top = -1;

	int startH = arr[0], endH;
	for (int i = 0; i < size - 1; i++) {
		if (arr[i] >= arr[i + 1]) startH = arr[i + 1];
		else if (arr[i] < arr[i + 1]) {
			endH = arr[i + 1];
			height[++top] = endH - startH;
		}
	}

	qsort(height, top + 1, sizeof(int), compare);

	if (top != -1) printf("%d", height[top]);
	else printf("0");

	free(arr);
	free(height);
	return 0;
}

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}
