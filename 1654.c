//1654
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);
long long binsearch(long long* data, int size, int key);

int main(void) {
	int size = 0, needCable = 0;
	scanf("%d %d", &size, &needCable);
	long long* LANarr = (long long*)calloc(size, sizeof(long long));

	for (int i = 0; i < size; i++) {
		scanf("%d", &LANarr[i]);
	}
	qsort(LANarr, size, sizeof(long long), compare);
	printf("%d", binsearch(LANarr, size, needCable));

	return 0;
}

int compare(const void* a, const void* b) {
	if (*(long long*)a < *(long long*)b) { return -1; }
	else if (*(long long*)a > *(long long*)b) { return 1; }
	else { return 0; }
}

long long binsearch(long long* data, int size, int key){
	long long low, mid, high;
	low = 1;
	high = data[size - 1];
	long long result = 0; // 결과값
	while (low <= high) {
		mid = (low + high) / 2;
		long long index = 0; // 랜선 TMP값
		for (int i = 0; i < size; i++) {
			index += data[i] / mid;
		}

		if (index >= key) {
			low = mid + 1; //index 값과 key값이 같아도 최댓값으로 조정해가면서 결과값 찾기.
			result = mid;
		}
		else if (index < key) {
			high = mid - 1;
		}
	}
	return result;
}