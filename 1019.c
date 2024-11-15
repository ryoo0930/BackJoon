//1019
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void result(long long page, long long counts[]);

int main(void) {
	long long page = 0;
	long long counts[10] = { 0 };
	scanf("%lld", &page);

	result(page, counts);
	for (int i = 0; i < 10; i++) {
		printf("%lld ", counts[i]);
	}

	return 0;
}

void result(long long page, long long counts[]) {
	long long factor = 1;

	while (factor <= page) {
		int current_digit = (page / factor) % 10;
		long long lower_numbers = page - (page / factor) * factor; // 현재 자릿수보다 작은 수.
		long long higher_numbers = page / (factor * 10); // 현재 자릿수보다 큰 수.

		for (int i = 0; i < 10; i++) {
			counts[i] += higher_numbers * factor; // 현재 자릿수보다 큰 수에서 자릿수를 곱해줘서 중복값 넣기.
		}
		for (int i = 0; i < current_digit; i++) {
			counts[i] += factor; // 현재 자리까지 더 나타나는 값 넣어주기.
		}
		counts[current_digit] += lower_numbers + 1; // 현재 자리 숫자에 해당하는 횟수 넣기.

		counts[0] -= factor; // 0으로 시작하는 중복 수 제거.
		factor *= 10;
	}
}