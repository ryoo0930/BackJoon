//5613
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int result = 0, num = 0;
    char sign = NULL;

    scanf("%d", &result);
    while (1) {
        getchar();
        scanf("%c", &sign);
        if (sign == '=') {
            break;
        }

        scanf("%d", &num);

        if (sign == '+') {
            result += num;
        }
        else if (sign == '-') {
            result -= num;
        }
        else if (sign == '*') {
            result *= num;
        }
        else if (sign == '/') {
            result /= num;
        }
    }

    printf("%d", result);

    return 0;
}
