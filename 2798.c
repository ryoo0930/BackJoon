//2798
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int arr[], int size);

int main(void) {
	int N = 0, M = 0;
	scanf("%d %d", &N, &M);
	int* arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d ", &arr[i]);
	}
	SelectionSort(arr, N); // Á¤·Ä
	int keyI = 0, keyJ = 1, keyK = 2;
	int check = M - (arr[0] + arr[1] + arr[2]);

	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = i + 2; k < N; k++) {
				int sum = arr[i] + arr[j] + arr[k];
				if (check > M - sum && M - sum >= 0) {
					check = M - sum;
					keyI = i;
					keyJ = j;
					keyK = k;
				}
			}
		}
	}
	printf("%d", arr[keyI] + arr[keyJ] + arr[keyK]);

	return 0;
}

void SelectionSort(int arr[], int size)
{
	int min, temp;
	for (int i = 0; i < size - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		if (i != min)
		{
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}