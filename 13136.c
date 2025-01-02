#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	long long width, height, range;
	scanf("%lld %lld %lld", &width, &height, &range);
	long long wid = (width / range) + (width % range > 0 ? 1 : 0);
	long long hei = (height / range) + (height % range > 0 ? 1 : 0);
	printf("%lld", wid * hei);
	return 0;
}
