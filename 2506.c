//2506
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int size = 0;
	scanf("%d", &size);
	int* arr = (int*)calloc(size, sizeof(int));

	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}

	int result = 0;
	int score = 1;
	for (int i = 0; i < size; i++) {
		if (arr[i] == 1) {
			result += score;
			score++;
		}
		else {
			score = 1;
		}
	}

	printf("%d", result);
	free(arr);
	return 0;
}
