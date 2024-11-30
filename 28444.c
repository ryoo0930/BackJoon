//28444
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int arr[5] = { 0 };
    for (int i = 0; i < 5; i++) { scanf("%d", &arr[i]); }
    int num1 = arr[0] * arr[1];
    int num2 = arr[2] * arr[3] * arr[4];
    printf("%d", num1 - num2);

    return 0;
}
