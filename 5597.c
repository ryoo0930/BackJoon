//5597
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int arr[], int size);

int main(void) {
	int student[28] = { 0 };
	for (int i = 0; i < 28; i++) {
		scanf("%d ", &student[i]);
	}
	SelectionSort(student, 28);
	int checkST[2] = { 0 };
	for (int i = 0; i < 28; i++) {
		if (student[i] != i + 1) {
			checkST[0] = i + 1;
			break;
		}
	}
	for (int i = 27; i >= 0; i--) {
		if (student[i] != i + 3) {
			checkST[1] = i + 3;
			break;
		}
	}
	printf("%d %d", checkST[0], checkST[1]);
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