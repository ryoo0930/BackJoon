//1157
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char string[1000001];
	gets(string);

	int len = strlen(string);
	//입력값 대문자로 변경
	for (int i = 0; i < len; i++) {
		if (string[i] >= 97) {
			string[i] = string[i] - 32;
		}
	}

	int alpha[100] = { 0 }; // A - 65 ~ Z - 90
	for (int i = 0; i < len; i++) {
		alpha[string[i]] += 1;
	}
	
	int check = alpha[65];
	int key = 0, same = 0;
	for (int i = 66; i <= 90; i++) {
		if (check < alpha[i]) {
			check = alpha[i];
		}
	}

	for (int i = 65; i <= 90; i++) {
		if (check == alpha[i]) {
			key = i;
			same++;
		}

	}

	if (same == 1) {
		printf("%c", key);
	}
	else {
		printf("?");
	}


	return 0;
}