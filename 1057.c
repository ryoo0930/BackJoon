#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int size = 0, personA = 0, personB = 0;
    scanf("%d %d %d", &size, &personA, &personB);

    int result = 0;
    while (personA != personB) {
        result++;
        personA = (personA + 1) / 2;
        personB = (personB + 1) / 2;
    }
    if (size <= 1) {
        result = -1; // 잘못된 경우
    }
    printf("%d", result);

    return 0;
}
