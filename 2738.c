//2738
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int height, width = 0;
	scanf("%d %d", &height, &width);
	int len = height * 2;
	int** arr = (int**)malloc(sizeof(int*) * len);
	

	for (int i = 0; i < len; i++) {
		arr[i] = (int*)malloc(sizeof(int) * width);
	}

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < width; j++) {
			scanf("%d ", &arr[i][j]);
		}
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			printf("%d ", arr[i][j] + arr[i + height][j]);
		}
		printf("\n");
	}

	return 0;
}