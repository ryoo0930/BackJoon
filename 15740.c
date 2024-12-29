#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void reverseString(char* str);
int compare(char* num1, char* num2);
void addFunction(char* num1, char* num2, char* result);
void subFunction(char* num1, char* num2, char* result);

int main(void) {
    char num1[10005], num2[10005], result[10005];
    scanf("%s %s", num1, num2);

    bool num1_minus = num1[0] == '-' ? true : false;
    bool num2_minus = num2[0] == '-' ? true : false;

    //abs
    if (num1_minus == true) { memmove(num1, num1 + 1, strlen(num1)); }
    if (num2_minus == true) { memmove(num2, num2 + 1, strlen(num2)); }

    if (num1_minus == num2_minus) {
        addFunction(num1, num2, result);
        num1_minus == true ? printf("-%s", result) : printf("%s", result);
        return 0;
    }

    else {
        if (compare(num1, num2) == 0) {
            printf("0");
        }
        else if (compare(num1, num2) > 0) {
            subFunction(num1, num2, result);
            num1_minus == true ? printf("-%s", result) : printf("%s", result);
        }
        else {
            subFunction(num2, num1, result);
            num2_minus == true ? printf("-%s", result) : printf("%s", result);
        }
        return 0;
    }
    return 0;
}

void reverseString(char* str) {
    int len = strlen(str);
    char* temp = (char*)malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++) {
        temp[i] = str[len - i - 1];
    }
    temp[len] = '\0';
    strcpy(str, temp);
    free(temp);
}

void addFunction(char* num1, char* num2, char* result) {
    reverseString(num1); reverseString(num2);
    int carry = 0, i = 0;
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = len1 > len2 ? len1 : len2;
    for (i = 0; i < maxLen || carry; i++) {
        int digit1 = (i < len1) ? num1[i] - '0' : 0;
        int digit2 = (i < len2) ? num2[i] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result[i] = (sum % 10) + '0';
    }
    result[i] = '\0';
    reverseString(result);
}
void subFunction(char* num1, char* num2, char* result) {
    reverseString(num1); reverseString(num2);
    int borrow = 0, i = 0;
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = len1 > len2 ? len1 : len2;
    for (i = 0; i < maxLen; i++) {
        int digit1 = (i < len1) ? num1[i] - '0' : 0;
        int digit2 = (i < len2) ? num2[i] - '0' : 0;
        int sub = digit1 - digit2 - borrow;
        if (sub < 0) { sub += 10; borrow = 1; }
        else { borrow = 0; }
        result[i] = sub + '0';
    }
    while (i > 0 && result[i - 1] == '0') { i--; }
    result[i] = '\0';
    reverseString(result);
}

int compare(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    if (len1 == len2) { return strcmp(num1, num2); }
    else { return len1 - len2; }
}
