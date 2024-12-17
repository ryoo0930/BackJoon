#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b);

int main(void) {
    int size = 0;
    scanf("%d", &size);

    char** serial = (char**)malloc(sizeof(char*) * size);
    for (int i = 0; i < size; i++) {
        serial[i] = malloc(sizeof(char) * 51);
        scanf("%s", serial[i]);
    }

    qsort(serial, size, sizeof(char*), compare);

    for (int i = 0; i < size; i++) {
        printf("%s\n", serial[i]);
    }

    return 0;
}

int compare(const void* a, const void* b) {
    char* stringA = *(char**)a;
    char* stringB = *(char**)b;

    int lenA = strlen(stringA);
    int lenB = strlen(stringB);
    
    if (lenA != lenB) { return lenA - lenB; } // 첫번째 조건
    else {
        int countA = 0, countB = 0;
        for (int i = 0; i < lenA; i++) {
            if (stringA[i] >= '0' && stringA[i] <= '9') { countA += stringA[i] - '0'; }
        }
        for (int i = 0; i < lenB; i++) {
            if (stringB[i] >= '0' && stringB[i] <= '9') { countB += stringB[i] - '0'; }
        }
        if (countA != countB) { return countA - countB; } // 두번째 조건
        else {
            return strcmp(stringA, stringB); // 세번째 조건
        }
    }
}
