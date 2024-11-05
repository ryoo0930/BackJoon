//2609
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

gcd(int num1, int num2);

int main(void) {
	int num1 = 0, num2 = 0;
	scanf("%d %d", &num1, &num2);

	int a = 0, b = 0;
	if (num1 > num2) {
		a = num1;
		b = num2;
	}
	else {
		a = num2;
		b = num1;
	}
	int remainder = 1;
	//a = gcd
	while (remainder != 0) {
		remainder = a % b;
		a = b;
		b = remainder;
	}

	printf("%d\n", a);
	printf("%d", (num1 * num2) / a);

	return 0;
}