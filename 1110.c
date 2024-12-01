//1110
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
    int num = 0;
    scanf("%d", &num);

    int new_number;
    int count = 0;

    //한번 하기
    int digit_10, digit_1;
    digit_10 = (num % 10) * 10;
    digit_1 = ((num / 10) + (num % 10)) % 10;
    new_number = digit_10 + digit_1;
    count++;

    while (num != new_number) {
        digit_10 = (new_number % 10) *10;
        digit_1 = ((new_number / 10) + (new_number % 10)) % 10;
        new_number = digit_10 + digit_1;
        count++;
    }

    printf("%d", count);

    return 0;
}
