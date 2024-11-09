//10773
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int top = -1;

void push(int* stack, int value);
int pop(int* stack);

int main(void) {
	int testCase = 0;
	scanf("%d", &testCase);
	int* stack = (int*)malloc(sizeof(int) * testCase); // 스택 동적 생성.

	for (int i = 0; i < testCase; i++) {
		int num = 0;
		scanf("%d", &num);
		if (num != 0) { push(stack, num); } // 입력값이 0이 아닐 때 PUSH
		else { pop(stack); } // 입력값이 0이면 POP
	}

	int sum = 0;
	while (top > -1) {
		sum += pop(stack); // 스택을 POP시키면서 sum에 더하기.
	}

	printf("%d", sum);

	return 0;
}

void push(int* stack, int value) {
	stack[++top] = value;
}
int pop(int* stack) {
	return stack[top--];
}