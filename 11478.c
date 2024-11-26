//Set & Map 8
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b);

int main(void) {
    char string[1001];
    scanf("%s", string);

    int len = strlen(string);
    int size = (len * (len + 1)) / 2;

    char** arr = (char**)malloc(sizeof(char*) * size);

    int index = 0;
    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < len - i + 1; j++) {
            arr[index] = calloc(i + 1, sizeof(char));
            strncpy(arr[index++], &string[j], i);
        }
    }

    qsort(arr, size, sizeof(char*), compare);


    int count = size;
    for (int i = 1; i < size; i++) {
        if (strcmp(arr[i - 1], arr[i]) == 0) {
            count--;
        }
    }

    printf("%d", count);

    for (int i = 0; i < size; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}

int compare(const void* a, const void* b) {
    const char* str1 = *(const char**)a;
    const char* str2 = *(const char**)b;
    return strcmp(str1, str2);
}
