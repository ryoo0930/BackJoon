//1541
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
    char string[51];
    scanf("%s", string);

    int len = strlen(string);
    int result = 0;
    int checkMinus = 0;
    int tempNumber = 0;

    for (int i = 0; i < len; i++) {
        if (string[i] >= '0' && string[i] <= '9') {
            tempNumber = tempNumber * 10 + (string[i] - '0');
        }
        else {
            if (checkMinus) {
                result -= tempNumber;
            }
            else {
                result += tempNumber;
            }

            tempNumber = 0;
            if (string[i] == '-') {
                checkMinus = 1;
            }
        }

    }

    //Last Number
    if (checkMinus) {
        result -= tempNumber;
    }
    else {
        result += tempNumber;
    }

    printf("%d", result);

    return 0;
}
