#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b);
int compare(const void* a, const void* b);

int main() {
	int testCase = 0;
	scanf("%d", &testCase);

	while (testCase--) {
		int size = 0;
		scanf("%d", &size);

		int* arr = (int*)malloc(sizeof(int) * size);
		for (int i = 0; i < size; i++) { scanf("%d", &arr[i]); }
		qsort(arr, size, sizeof(int), compare);

		long long result = 0;
		for (int i = 0; i < size - 1; i++) {
			for (int j = i + 1; j < size; j++) {
				result += gcd(arr[i], arr[j]);
			}
		}

		printf("%lld\n", result);
	}
	return 0;
}

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}
