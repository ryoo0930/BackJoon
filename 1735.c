//Aliquot & Multiple & Prime number 2 - 3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long gcd(long long num1, long long num2);

int main(void) {
    long long numA1, numA2;
    long long numB1, numB2;
    scanf("%lld %lld", &numA1, &numA2);
    scanf("%lld %lld", &numB1, &numB2);

    long long result1 = (numA1 * numB2) + (numB1 * numA2);
    long long result2 = numA2 * numB2;
    long long gcdNum = gcd(result1, result2);

    printf("%lld %lld", result1 / gcdNum, result2 / gcdNum);

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
