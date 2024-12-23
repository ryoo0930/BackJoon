#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char* str);
void addFunction(char* num1, char* num2, char* result);

int main(void) {
    char number1[8], number2[8];
    char* result[17];
    scanf("%s %s", number1, number2);

    addFunction(number1, number2, result);
    printf("%s\n", result);

    return 0;
}

void reverseString(char* str) {
    int len = strlen(str);
    char* temp = (char*)malloc(len + 1);

    for (int i = 0; i < len; i++) {
        temp[i] = str[len - i - 1];
    }
    temp[len] = '\0';

    strcpy(str, temp);
    free(temp);
}

void addFunction(char* num1, char* num2, char* result) {
    reverseString(num1); reverseString(num2);

    int len1 = strlen(num1), len2 = strlen(num2);
    int maxlen = len1 > len2 ? len1 : len2;
    int index = 0;

    for (int i = 0; i < maxlen; i++) {
        int digit1 = (i < len1) ? num1[i] - '0' : 0;
        int digit2 = (i < len2) ? num2[i] - '0' : 0;

        int sum = digit1 + digit2;
        if (sum >= 10) {
            result[index++] = (sum % 10) + '0';
            result[index++] = (sum / 10) + '0';
        }
        else {
            result[index++] = sum + '0';
        }
    }
    result[index] = '\0';

    reverseString(result);
}
