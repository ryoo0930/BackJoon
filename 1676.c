//1676
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int num = 0;
	scanf("%d", &num);

	int count = 0;
	for (int i = 1; i <= num; i++) {
		int num2 = i;
		while ((num2 % 5) == 0) {
			num2 = num2 / 5;
			count++;
		}
	}

	printf("%d", count);
	return 0;
}