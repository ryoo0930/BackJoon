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
		long long lower_numbers = page - (page / factor) * factor; // ���� �ڸ������� ���� ��.
		long long higher_numbers = page / (factor * 10); // ���� �ڸ������� ū ��.

		for (int i = 0; i < 10; i++) {
			counts[i] += higher_numbers * factor; // ���� �ڸ������� ū ������ �ڸ����� �����༭ �ߺ��� �ֱ�.
		}
		for (int i = 0; i < current_digit; i++) {
			counts[i] += factor; // ���� �ڸ����� �� ��Ÿ���� �� �־��ֱ�.
		}
		counts[current_digit] += lower_numbers + 1; // ���� �ڸ� ���ڿ� �ش��ϴ� Ƚ�� �ֱ�.

		counts[0] -= factor; // 0���� �����ϴ� �ߺ� �� ����.
		factor *= 10;
	}
}