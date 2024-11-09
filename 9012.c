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
	getchar(); //�Է� ���� �����

	char** string = (char**)malloc(sizeof(char*) * testCase); // testCase��ŭ�� ���ڿ� �迭 ����.
	for (int i = 0; i < testCase; i++) {
		string[i] = (char*)malloc(sizeof(char) * 51);
	}

	for (int i = 0; i < testCase; i++) {
		gets(string[i]); // ���ڿ� �Է�.
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

		top = -1; // ���� �ʱ�ȭ.
	}





	return 0;
}

void push(char value) {
	stack[++top] = value;
}

int pop() {
	return stack[top--];
}