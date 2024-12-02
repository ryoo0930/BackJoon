#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

compare(const void* a, const void* b);

int main(void) {
    int size = 0;
    scanf("%d", &size);


    if (size == 1) {
        int num = 0;
        scanf("%d", &num);
        printf("%d", num * num);
    }
    else {
        int* arr = (int*)malloc(sizeof(int) * size);
        for (int i = 0; i < size; i++) { scanf("%d", &arr[i]); }
        qsort(arr, size, sizeof(int), compare);

        printf("%lld", arr[0] * arr[size - 1]);
    }

    return 0;
}

compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
