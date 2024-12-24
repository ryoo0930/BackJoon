#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	float a, b, c;
	scanf("%f %f %f", &a, &b, &c);
	float result = a * c / b;
	printf("%f", result);


	return 0;
}
