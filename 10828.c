//10828
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MaxSize 10000
int stack[MaxSize];
int top = -1;

void push(int value);
int pop();
int s_size();
int s_empty();
int s_top();

int main(void) {
	int testCase = 0;
	scanf("%d", &testCase);
	for (int i = 0; i < testCase; i++) {
		char string[6] = { 0 };
		scanf("%s", &string);
		if (strcmp(string, "push") == 0) {
			int tmp = 0;
			scanf("%d", &tmp);
			push(tmp);
		}
		else if (strcmp(string, "pop") == 0) { printf("%d\n", pop()); }
		else if (strcmp(string, "size") == 0) { printf("%d\n", s_size()); }
		else if (strcmp(string, "empty") == 0) { printf("%d\n", s_empty()); }
		else if (strcmp(string, "top") == 0) { printf("%d\n", s_top()); }
	}

	return 0;
}

void push(int value) {
	stack[++top] = value;
}
int pop() {
	if (top == -1) {
		return -1;
	}

	return stack[top--];
}
int s_size() {
	return top + 1;
}
int s_empty() {
	if (top == -1) {
		return 1; // 비어있을 때
	}
	return 0;
}
int s_top() {
	if (top == -1) {
		return -1; // 비어있을 때
	}
	return stack[top];
}