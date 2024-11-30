//4101
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int num1, num2;
    while (scanf("%d %d", &num1, &num2) == 2 && (num1 != 0 && num2 != 0))
    {
        if (num1 > num2) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }

    return 0;
}
