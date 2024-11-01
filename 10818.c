//10818
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int arrSize = 0;
	scanf("%d", &arrSize);

	int* arr = (int*)malloc(sizeof(int) * arrSize);
	
	for (int i = 0; i < arrSize; i++) {
		scanf("%d ", &arr[i]);
	}

	int minData = arr[0];
	int maxData = arr[0];

	for (int i = 1; i < arrSize; i++) {
		if (minData > arr[i]) {
			minData = arr[i];
		}
		if (maxData < arr[i]) {
			maxData = arr[i];
		}
	}

	printf("%d %d", minData, maxData);
	free(arr);

	return 0;
}