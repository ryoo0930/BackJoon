#include <stdio.h>
#include <stdlib.h>

void reverseString(char* str);
void addFunction(char* num1, char* num2, char* result);

int main(void) {
	char number1[10002], number2[10002], result[10002];
	scanf("%s %s", number1, number2);

	reverseString(number1); reverseString(number2);
	addFunction(number1, number2, result);

	reverseString(result);

	printf("%s", result);

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
}
