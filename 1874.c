//1874
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int top = -1;
int resultTop = -1;
void push(int* stack, int value);
void Rpush(char* stack, char value);
int pop(int* stack);

int main(void) {
	int testCase = 0;
	scanf("%d", &testCase);
	int* inputNum = (int*)calloc(testCase, sizeof(int));
	int* stack = (int*)calloc(testCase, sizeof(int));
	char* resultStack = (char*)calloc(testCase * 2, sizeof(char));

	for (int i = 0; i < testCase; i++) {
		scanf("%d", &inputNum[i]); // °ª ÀÔ·Â.
	}

	int current = 1;
	for (int i = 0; i < testCase; i++) {
		int index = inputNum[i];
		while (current <= index) {
			push(stack, current++);
			Rpush(resultStack, '+');
		}
		if (stack[top] == index) {
			pop(stack);
			Rpush(resultStack, '-');
		}
		else {
			printf("NO\n");
			return 0;
		}
	}
	
	for (int i = 0; i <= resultTop; i++) {
		printf("%c\n", resultStack[i]);
	}

	return 0;
}

void push(int* stack, int value) {
	stack[++top] = value;
}
int pop(int* stack) {
	return stack[top--];
}

void Rpush(char* stack, char value) {
	stack[++resultTop] = value;
}