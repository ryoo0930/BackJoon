#include <stdio.h>
#include <string.h>

int main(void) {
    char string[51];
    int arr[26] = { 0, };

    scanf("%s", string);
    
    int len = strlen(string);
    for (int i = 0; i < len; i++) {
        arr[string[i] - 'A']++;
    }

    int oddCount = 0;
    for (int i = 0; i < 26; i++) {
        if (arr[i] % 2 == 1) {
            oddCount++;
        }
    }

    if (oddCount >= 2) {
        printf("I'm Sorry Hansoo");
    }

    else {
        int temp = 0;
        for (int i = 0; i < 26; i++) {
            if (arr[i] % 2 == 1) {
                temp = i;
            }
            for (int j = 0; j < arr[i] / 2; j++) {
                printf("%c", i + 'A');
            }
        }
        if (oddCount != 0) { printf("%c", temp + 'A'); }
        for (int i = 25; i >= 0; i--) {
            for (int j = 0; j < arr[i] / 2; j++) {
                printf("%c", i + 'A');
            }
        }
    }

    return 0;
}
