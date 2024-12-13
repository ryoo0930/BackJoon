#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
    char number[11];
    scanf("%s", number);

    int len = strlen(number);
    int flag = 0;
    int firstNum = 1, secondNum = 1;
    for (int i = 0; i < len; i++) {
        if (len == 1) {
            break; // 한자리 숫자 예외처리
        }

        for (int j = 0; j < i; j++) {
            firstNum *= (number[j] - '0');
        }
        for (int j = i; j < len; j++) {
            secondNum *= (number[j] - '0');
        }

        if (firstNum == secondNum) {
            printf("YES");
            flag = 1;
            break;
        }
        else {
            firstNum = 1, secondNum = 1;
        }

    }

    if (flag == 0) {
        printf("NO");
    }


    return 0;
}
