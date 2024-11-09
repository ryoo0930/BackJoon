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
	int* stack = (int*)malloc(sizeof(int) * testCase); // ���� ���� ����.

	for (int i = 0; i < testCase; i++) {
		int num = 0;
		scanf("%d", &num);
		if (num != 0) { push(stack, num); } // �Է°��� 0�� �ƴ� �� PUSH
		else { pop(stack); } // �Է°��� 0�̸� POP
	}

	int sum = 0;
	while (top > -1) {
		sum += pop(stack); // ������ POP��Ű�鼭 sum�� ���ϱ�.
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