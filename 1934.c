//Aliquot & Multiple & Prime number 2 - 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcd(int num1, int num2);
int lcm(int num1, int num2);

int main(void) {
    int testCase = 0;
    scanf("%d", &testCase);

    for (int i = 0; i < testCase; i++) {
        int num1, num2;
        scanf("%d %d", &num1, &num2);

        if (num1 > num2) {
            printf("%d\n", lcm(num1, num2));
        }
        else {
            printf("%lld\n", lcm(num2, num1));
        }
    }

    return 0;
}

int gcd(int num1, int num2) {
    int tmp = 1;
    while (tmp != 0) {
        tmp = num1 % num2;
        num1 = num2;
        num2 = tmp;
    }
    return num1;
}

int lcm(int num1, int num2) {
    return (num1 * num2) / gcd(num1, num2);
}
