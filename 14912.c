#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int arr[10] = { 0, };

	int num = 0, digit = 0;
	scanf("%d %d", &num, &digit);

	int factor = 1;
	while (factor <= num) {
		int current_digit = (num / factor) % 10;
		int lower_number = num - (num / factor) * factor;
		int higher_number = num / (factor * 10);

		for (int i = 0; i < 10; i++) { arr[i] += higher_number * factor; }
		for (int i = 0; i < current_digit; i++) { arr[i] += factor; }

		arr[current_digit] += lower_number + 1;
		arr[0] -= factor;
		factor *= 10;
	}

	printf("%d", arr[digit]);
	return 0;
}
