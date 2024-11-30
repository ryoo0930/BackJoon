//10808
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
    char string[101];
    scanf("%s", &string);

    int len = strlen(string);

    int arr[26] = { 0 };
    for (int i = 0; i < len; i++) {
        arr[string[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
