//Aliquot & Multiple & Prime number 2 - 2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long gcd(long long num1, long long num2);
long long lcm(long long num1, long long num2);

int main(void) {
    long long num1, num2;
    scanf("%lld %lld", &num1, &num2);

    if (num1 > num2) {
        printf("%lld\n", lcm(num1, num2));
    }
    else {
         printf("%lld\n", lcm(num2, num1));
    }
    return 0;
}

long long gcd(long long num1, long long num2) {
    int tmp = 1;
    while (tmp != 0) {
        tmp = num1 % num2;
        num1 = num2;
        num2 = tmp;
    }
    return num1;
}

long long lcm(long long num1, long long num2) {
    return (num1 * num2) / gcd(num1, num2);
}
