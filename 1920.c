//1920
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b);
int binsearch(int* data, int size, int key);

int main(void) {

	int testCase = 0;
	scanf("%d", &testCase);

	int* arr = (int*)malloc(sizeof(int) * testCase); // 첫 번째 입력값
	for (int i = 0; i < testCase; i++) {
		scanf("%d ", &arr[i]);
	}

	qsort(arr, testCase, sizeof(int), compare); // 정렬

	int testCase2 = 0;
	scanf("%d", &testCase2);
	int* arr2 = (int*)malloc(sizeof(int) * testCase2); // 두 번째 입력값
	for (int i = 0; i < testCase2; i++) {
		scanf("%d ", &arr2[i]);
	}

	for (int i = 0; i < testCase2; i++) {
		//binsearch(arr, testCase, arr2[i]);
		if (binsearch(arr, testCase, arr2[i]) == 1) {
			printf("1\n");
		}
		else if (binsearch(arr, testCase, arr2[i]) == -1) {
			printf("0\n");
		}
	}

	return 0;
}

int compare(const void* a, const void* b) {
	if (*(int*)a > *(int*)b) { return 1; }
	else if (*(int*)a < *(int*)b) { return -1; }
	else { return 0; }
}

int binsearch(int* data, int size, int key) {
	int low, high, mid;
	low = 0;
	high = size - 1;
	int index = -1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (key == data[mid]) {
			index = 1; // key 값이 있을 때 1 반환.
			break;
		}
		else if(key < data[mid]) {
			high = mid - 1;
		}
		else if (key > data[mid]) {
			low = mid + 1;
		}
	}
	return index; // Key 값이 없을 때.
}