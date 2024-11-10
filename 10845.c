//10845
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAXSIZE 10000
int queue[MAXSIZE] = { 0 };
int front = -1;
int rear = -1;

void push(int value);
int pop();
int q_size();
int q_empty();
int q_front();
int q_back();

int main(void) {
	int testCase = 0;
	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++) {
		char string[6] = { 0 };
		scanf("%s", string);
		if (strcmp(string, "push") == 0) {
			int tmp = 0;
			scanf("%d", &tmp);
			push(tmp);
		}
		if (strcmp(string, "pop") == 0) {
			printf("%d\n", pop());
		}
		if (strcmp(string, "size") == 0) {
			printf("%d\n", q_size());
		}
		if (strcmp(string, "empty") == 0) {
			printf("%d\n", q_empty());
		}
		if (strcmp(string, "front") == 0) {
			printf("%d\n", q_front());
		}
		if (strcmp(string, "back") == 0) {
			printf("%d\n", q_back());
		}
	}

	return 0;
}

void push(int value) {
	if (q_empty() == 1) {
		front = 0;
	}
	rear += 1;
	queue[rear] = value;
}

int pop() {
	if (q_empty() == 1) {
		return -1;
	}


	int value = queue[front];
	if (front == rear) { // ť�� ������� �ʱ�ȭ.
		front = -1;
		rear = -1;
	}
	else {
		front++;
	}
	return value;
}

int q_size() {
	if (q_empty() == 1) {
		return 0;
	}
	return (rear - front + 1);
}

int q_empty() {
	if (front == -1) { // ť�� ������� ��. 1��ȯ.
		return 1; 
	}
	return 0; // ť�� ������� ���� ��.
}

int q_front() {
	if (q_empty() == 1) {
		return -1;
	}
	return queue[front];
}

int q_back() {
	if (q_empty() == 1) {
		return -1;
	}
	return queue[rear];
}
