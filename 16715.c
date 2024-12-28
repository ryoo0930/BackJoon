#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum(int num, int base);

int main(void) {
    int num = 0;
    scanf("%d", &num);

    int max_sum = -1, best_base = -1;

    for (int base = 2; base <= num; base++) {
        int current_sum = sum(num, base);
        if (current_sum > max_sum) {
            max_sum = current_sum;
            best_base = base;
        }
    }
    printf("%d %d", max_sum, best_base);
    return 0;
}

int sum(int num, int base) {
    int sum = 0;
    while (num > 0) {
        sum += num % base;
        num /= base;
    }
    return sum;
}
