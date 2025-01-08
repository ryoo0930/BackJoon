#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);

int main(void) {
    int number[7];
    for (int i = 0; i < 7; i++) { scanf("%d", &number[i]); }

    qsort(number, 7, sizeof(int), compare);

    int sum = 0;
    for (int i = 0; i < 7; i++) { if (number[i] % 2 == 1) { sum += number[i]; } }
    if (sum == 0) { printf("-1"); return 0; } // 홀수가 없을 때. -1출력 후 종료.
    printf("%d\n", sum);

    for (int i = 0; i < 7; i++) { if (number[i] % 2 == 1) { printf("%d\n", number[i]); break; } }

    return 0;
}

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
