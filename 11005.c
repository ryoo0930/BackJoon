//11005
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main() {
    int N = 0, B= 0;
    scanf("%d %d", &N, &B);
    char string[40] = { 0 };
    
    int i = 0;
    while (N > 0) {
        int n = N % B;
        N = N / B;
        if (n > 9) {
            string[i] = n + 55;
        }
        else {
            string[i] = n + 48;
        }
        i++;
    }
    int len = strlen(string);
    char number[40] = { 0 };

    for (int i = 0; i < len; i++) {
        number[i] = string[len - i - 1];
    }
    printf("%s\n", number);

    return 0;
}

