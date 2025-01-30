#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);

int main()
{
	int egg = 0, person = 0;
	scanf("%d %d", &egg, &person);

	int* arr = (int*)malloc(sizeof(int) *person);
	for (int i = 0; i < person; i++) scanf("%d", &arr[i]);
	qsort(arr, person, sizeof(int), compare);

	long long result = 0;
	int price = 0;

	for (int i = 0; i < egg && i < person; i++) {
		long long tempResult = 0;
		tempResult = arr[i] * (i + 1);


		if (result <= tempResult) {
			price = arr[i];
			result = tempResult;
		}
	}
	printf("%d %lld", price, result);

	free(arr);
	return 0;
}

int compare(const void* a, const void* b) {
	return *(int*)b - *(int*)a;
}
