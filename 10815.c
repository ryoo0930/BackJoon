//Set & Map 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);
int binsearch(int* data, int size, int key);

int main(void) {
	int size = 0;
	scanf("%d", &size);
	int* arr = (int*)calloc(size, sizeof(int));
	for (int i = 0; i < size; i++) { scanf("%d", &arr[i]); }

	qsort(arr, size, sizeof(int), compare);

	int size2 = 0;
	scanf("%d", &size2);
	int* arr2 = (int*)calloc(size2, sizeof(int));
	for (int i = 0; i < size2; i++) { scanf("%d", &arr2[i]); }

	for (int i = 0; i < size2; i++) {
		printf("%d ", binsearch(arr, size, arr2[i]));
	}


	free(arr);
	free(arr2);
	return 0;
}

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int binsearch(int* data, int size, int key) {
	int low, high, mid;
	low = 0;
	high = size - 1;
	int index = 0;

	while (low <= high) {
		mid = (low + high) / 2;
		if (key == data[mid]) {
			index = 1;
			break;
		}
		else if (key < data[mid]) {
			high = mid - 1;
		}
		else if (key > data[mid]) {
			low = mid + 1;
		}
	}

	return index; // 값이 있으면 1, 없으면 0
}
