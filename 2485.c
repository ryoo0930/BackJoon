//Aliquot & Multiple & Prime number 2 - 4
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int gcd(int num1, int num2);

int main(void) {
    int size = 0;
    scanf("%d", &size);

    int* arr = (int*)malloc(sizeof(int) * size);
    int* betweenArr = (int*)malloc(sizeof(int) * (size - 1));
    for (int i = 0; i < size; i++) { scanf("%d", &arr[i]); }
    for (int i = 0; i < size - 1; i++) { betweenArr[i] = arr[i + 1] - arr[i]; }

    int gcdResult = betweenArr[0];
    for (int i = 1; i < size - 1; i++) {
        gcdResult = gcd(gcdResult, betweenArr[i]);
    }

    int count = 0;
    for (int i = arr[0]; i <= arr[size - 1]; i += gcdResult) {
        count++;
    }
    count -= size;

    printf("%d", count);

    free(arr);
    free(betweenArr);
    return 0;
}

int gcd(int num1, int num2) {
    int tmp = 1;
    while (tmp != 0) {
        tmp = num1 % num2;
        num1 = num2;
        num2 = tmp;
    }
    return num1;
}
