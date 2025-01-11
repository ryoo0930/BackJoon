#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void function_1(int* arr, int size);
void function_2(int** arr, int size);

int main() {
	int size = 0;
	scanf("%d", &size);

	int** arr = (int**)malloc(sizeof(int*) * size);
	for (int i = 0; i < size; i++) { arr[i] = (int*)malloc(sizeof(int) * size); }
	for (int i = 0; i < size; i++) { for (int j = 0; j < size; j++) { scanf("%d", &arr[i][j]); } }

	int testCase = 0;
	scanf("%d", &testCase);

	while (testCase--) {
		int function = 0; scanf("%d", &function);

		if (function == 1) {
			int row = 0; scanf("%d", &row);
			function_1(arr[row - 1], size);
		}
		else if (function == 2) {
			function_2(arr, size);
		}

	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) { printf("%d ", arr[i][j]); }
		printf("\n");
	}




	for (int i = 0; i < size; i++) { free(arr[i]); }
	free(arr);
	return 0;
}

void function_1(int* arr, int size) {
	int* tempArr = (int*)malloc(sizeof(int) * size);
	tempArr[0] = arr[size - 1];
	for (int i = 0; i < size - 1; i++) { tempArr[i + 1] = arr[i]; }
	for (int i = 0; i < size; i++) { arr[i] = tempArr[i]; }
	free(tempArr);
}

void function_2(int** arr, int size) {
	int** tempArr = (int**)malloc(sizeof(int*) * size);
	for (int i = 0; i < size; i++) { tempArr[i] = (int*)malloc(sizeof(int) * size); }

	for (int i = 0; i < size; i++) { for (int j = 0; j < size; j++) { tempArr[j][size - i - 1] = arr[i][j]; } }
	for (int i = 0; i < size; i++) { for (int j = 0; j < size; j++) { arr[i][j] = tempArr[i][j]; } }

	for (int i = 0; i < size; i++) { free(tempArr[i]); }
	free(tempArr);
}
