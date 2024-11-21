//2805
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);
long long binsearch(int* data, int size, int key);

int main(void) {
	int treeSize = 0, needSize = 0;
	scanf("%d %d", &treeSize, &needSize);

	int* tree = (int*)calloc(treeSize, sizeof(int));
	for (int i = 0; i < treeSize; i++) {
		scanf("%d", &tree[i]);
	}

	qsort(tree, treeSize, sizeof(int), compare);

	
	printf("%lld", binsearch(tree, treeSize, needSize));

	return 0;
}

int compare(const void* a, const void* b) {
	if (*(int*)a > *(int*)b) { return 1; }
	else if (*(int*)a < *(int*)b) { return -1; }
	else { return 0; }

}

long long binsearch(int* data, int size, int key) {
	long long low, mid, high;
	low = 0;
	high = data[size - 1];

	long long result = 0;

	while (low <= high) {
		mid = (low + high) / 2;
		long long index = 0;

		for (int i = 0; i < size; i++) {
			if (data[i] - mid > 0) {
				index += data[i] - mid;
			}
		}

		if (index >= key) {
			low = mid + 1;
			result = mid;
		}
		else if (index < key) {
			high = mid - 1;
		}
	}
	return result;
}