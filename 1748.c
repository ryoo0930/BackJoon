#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int num = 0;
    scanf("%d", &num);

    int count = 0;
    int digits = 1;
    long long count_10 = 10;
    for (int i = 1; i <= num; i++) {
        if (i == count_10) {
            count_10 *= 10;
            digits++;
        }
        count += digits;
    }
    printf("%d", count);
    return 0;
}
