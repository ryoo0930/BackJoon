#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

unsigned long long binsearch(unsigned long long size);

int main()
{
	int testCase = 0;
	scanf("%d", &testCase);

	while (testCase--) {
		unsigned long long bridge;
		scanf("%lld", &bridge);

		printf("%lld\n", binsearch(bridge));
	}

	return 0;
}

unsigned long long binsearch(unsigned long long size) {
	unsigned long long low = 1;
	unsigned long long high = size;
	unsigned long long mid = 0, answer = 0;

	while (low <= high) {
		mid = (low + high) / 2;

		unsigned long long result = (mid * (mid + 1)) / 2;

		if (result <= size) {
			answer = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return answer;
}
