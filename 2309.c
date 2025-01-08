#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);

int main(void) {
    int height[9];
    for (int i = 0; i < 9; i++) { scanf("%d", &height[i]); }
    qsort(height, 9, sizeof(int), compare);

    int sum = 0; // 아홉 난쟁이의 키를 전부 더한 값 - 두 난쟁이의 키를 더한 값 = 100;
    for (int i = 0; i < 9; i++) { sum += height[i]; }

    int needValue = sum - 100;
    int NOT_1 = 0, NOT_2 = 0;
    for (int i = 0; i < 8; i++) { 
        for (int j = i + 1; j < 9; j++) {
            if (height[i] + height[j] == needValue) { NOT_1 = height[i]; NOT_2 = height[j]; break; }
        } 
    }

    for (int i = 0; i < 9; i++) {
        if (height[i] != NOT_1 && height[i] != NOT_2) { printf("%d\n", height[i]); }
    }



    return 0;
}

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
