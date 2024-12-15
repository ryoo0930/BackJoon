#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);
int binsearch(int* data, int size, int key);

int main(void) {
    int size = 0;
    scanf("%d", &size);

    int* arr = (int*)malloc(sizeof(int) * size + 1);
    for (int i = 0; i < size; i++) { scanf("%d", &arr[i]); }

	int key = 0;
	scanf("%d", &key);
	arr[size] = key;

	qsort(arr, size + 1, sizeof(int), compare);
	int key_index = binsearch(arr, size + 1, key);

	int result = 0;
	if (arr[key_index] != arr[key_index - 1] && arr[key_index] != arr[key_index + 1]) {
		result = (arr[key_index] - arr[key_index - 1]) * (arr[key_index + 1] - arr[key_index]);
		result -= 1;
	}

	printf("%d", result);

    return 0;
}

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int binsearch(int* data, int size, int key) {
	int low, high, mid;
	low = 0;
	high = size - 1;
	int index = -1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (key == data[mid]) {
			index = mid;
			break;
		}
		else if (key < data[mid]) {
			high = mid - 1;
		}
		else if (key > data[mid]) {
			low = mid + 1;
		}
	}
	return index;
}
