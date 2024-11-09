//4949
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char stack[102] = { 0 }; // 최대 문자열의 수만큼 스택 생성.
int top = -1;

void push(char value);
int pop();


int main(void) {
	while (1) {
		char string[102] = { 0 };
		gets(string);
		if (strcmp(string, ".") == 0) {
			break;
		}
		int len = strlen(string);
		int count = 0;

		for (int i = 0; i < len; i++) {
			if (string[i] == '(' || string[i] == '[') {
				push(string[i]);
			}

			else if (string[i] == ')') {
				if ('(' != pop()) {
					count++;
					break;
				}
			}
			else if (string[i] == ']') {
				if ('[' != pop()) {
					count++;
					break;
				}
			}
		}

		if (top == -1 && count == 0) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}

		top = -1;

	}

	return 0;
}

void push(char value) {
	stack[++top] = value;
}
int pop() {
	return stack[top--];
}
