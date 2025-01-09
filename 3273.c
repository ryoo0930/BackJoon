#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);
int binsearch(int* arr, int size, int key);

int main() {
	int arrSize = 0;
	scanf("%d", &arrSize);
	
	int* arr = (int*)malloc(sizeof(int) * arrSize);
	for (int i = 0; i < arrSize; i++) { scanf("%d", &arr[i]); }
	qsort(arr, arrSize, sizeof(int), compare);

	int pairNumber = 0; int result = 0;
	scanf("%d", &pairNumber);

	for (int i = 0; i < arrSize; i++) {
		int needNumber = pairNumber - arr[i];
		if (binsearch(arr, arrSize, needNumber) != -1) { result++; }
	}
	printf("%d", result / 2);

	free(arr);
	return 0;
}

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int binsearch(int* arr, int size, int key) {
	int low = 0, high = size - 1;
	int mid;
	
	int index = -1;

	while (low <= high) {
		mid = (low + high) / 2;
		if (arr[mid] > key) { high = mid - 1; }
		else if (arr[mid] < key) { low = mid + 1; }
		else { index = mid; break; }
	}

	return index;
}
