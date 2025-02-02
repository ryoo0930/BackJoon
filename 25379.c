#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int size = 0;
	scanf("%d", &size);

	int* arr = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) scanf("%d", &arr[i]);


	long long result1 = 0, result2 = 0;
	int even = 0, odd = 0;
	for (int i = 0; i < size; i++) {
		if ((arr[i] % 2) == 0) even++;
		else result1 += even;
	}

	even = 0, odd = 0;
	for (int i = 0; i < size; i++) {
		if ((arr[i] % 2) == 1) odd++;
		else result2 += odd;
	}
	
	result1 > result2 ? printf("%lld", result2) : printf("%lld", result1);
	free(arr);
	return 0;
}
