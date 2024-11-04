//4153
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void SelectionSort(int arr[], int size);

int main(void) {

	while (1) {

		int arr[3] = { 0 };

		scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0) {
			break;
		}

		SelectionSort(arr, 3);

		for (int i = 0; i < 3; i++) {
			arr[i] = arr[i] * arr[i];
		}

		if (arr[2] == arr[0] + arr[1]) {
			printf("right\n");
		}
		else {
			printf("wrong\n");
		}

	}


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