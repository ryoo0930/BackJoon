#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);

int main() {
	int size = 0;
	scanf("%d", &size);

	long long* aVal = (long long*)malloc(sizeof(long long) * size);
	long long bVal = 0, a = 0, b = 0;

	for (int i = 0; i < size; i++) {
		scanf("%lld %lld", &aVal[i], &bVal);
		b += bVal;
	}
	qsort(aVal, size, sizeof(long long), compare);
	for (int i = 0; i < size; i++) a += aVal[i] * (i + 1);

	printf("%lld", a + b);
	return 0;
}

int compare(const void* a, const void* b) {
	return *(long long*)a - *(long long*)b;
}
