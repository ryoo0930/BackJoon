#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int addDigits(int num);

int main(void) {
    int arr[10001] = { 0 };
    for (int i = 1; i <= 10000; i++) {
        arr[i] = i;
    }

    for (int i = 1; i <= 10000; i++) {
        int result = i;
        if (arr[result] != 0) {
            while (result <= 10000) {
                result = result + addDigits(result);
                if (result > 10000) break;
                arr[result] = 0;
            }
        }
    }

    for (int i = 1; i <= 10000; i++) {
        if (arr[i] != 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}

int addDigits(int num) {
    int result = 0;
    while (num != 0) {
        result += num % 10;
        num /= 10;
    }
    return result;
}
