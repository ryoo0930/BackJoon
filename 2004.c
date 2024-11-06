//2004
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct value{
	int check2;
	int check5;
}values;

values getZero(long long num);

int main(void) {
	long long num1 = 0, num2 = 0;
	scanf("%lld %lld", &num1, &num2);

	values Zero1;
	values Zero2;
	values Zero3;
	Zero1 = getZero(num1);
	Zero2 = getZero(num2);
	Zero3 = getZero(num1 - num2);

	int check2 = Zero1.check2 - (Zero2.check2 + Zero3.check2);
	int check5 = Zero1.check5 - (Zero2.check5 + Zero3.check5);
	
	if (check2 < check5) {
		printf("%d", check2);
	}
	else {
		printf("%d", check5);
	}

	return 0;
}

values getZero(long long num) {
	values p;
	p.check2 = 0;
	p.check5 = 0;
	for (long long i = 2; i <= num; i *= 2) {
		p.check2 += num / i;
	}
		
	for (long long i = 5; i <= num; i *= 5) {
		p.check5 += num / i;
	}
	
	return p;
}
