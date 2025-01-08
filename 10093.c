#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(long long* a, long long* b);

int main(void) {
    long long num1 = 0, num2 = 0;
    scanf("%lld %lld", &num1, &num2);
    long long start = 0, end = 0;
    if (num1 > num2) { start = num2; end = num1; }
    else { start = num1; end = num2; }

    if (start == end) { printf("0"); return 0; }
    printf("%lld\n", end - start - 1);
    for (long long i = start + 1; i < end; i++) { printf("%lld ", i); }

    return 0;
}
