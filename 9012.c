//9012
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[51] = { 0 };
int top = -1;

void push(char value);
int pop();


int main(void) {
	int testCase = 0;
	scanf("%d", &testCase);
	getchar(); //입력 버퍼 지우기

	char** string = (char**)malloc(sizeof(char*) * testCase); // testCase만큼의 문자열 배열 생성.
	for (int i = 0; i < testCase; i++) {
		string[i] = (char*)malloc(sizeof(char) * 51);
	}

	for (int i = 0; i < testCase; i++) {
		gets(string[i]); // 문자열 입력.
	}
	
	for (int i = 0; i < testCase; i++) {
		int len = strlen(string[i]);

		int count = 0;
		for (int j = 0; j < len; j++) {
			if (string[i][j] == '(' || string[i][j] == '[') {
				push(string[i][j]);
			}
			else if (string[i][j] == ')') {
				if ('(' != pop()) {
					count++;
					break;
				}
			}
			else if (string[i][j] == ']') {
				if ('[' != pop()) {
					count++;
					break;
				}
			}
		}

		if (top == -1 && count == 0) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}

		top = -1; // 스택 초기화.
	}





	return 0;
}

void push(char value) {
	stack[++top] = value;
}

int pop() {
	return stack[top--];
}