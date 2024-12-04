// 한수 배우겠습니다람쥐썬더
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int num = 0;
    scanf("%d", &num);
    if (num <= 99) {
        printf("%d", num);
    }
    else {
        int result = 99;
        for (int i = 100; i <= num; i++) {
            if (((i / 10) % 10 - (i % 10)) == ((i / 100) % 10 - (i / 10) % 10)) {
                result++;
            }
        }
        if (num == 1000) {
            result--;
        }
        printf("%d", result);
    }

    return 0;
}
