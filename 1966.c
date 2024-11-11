//1966
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

struct data {
	int index;
	int priority;
};

struct data queue[MAXSIZE]; // ����ü�� �̷���� ť ����.
int front = 0, rear = 0; // ť �⺻ ����.

void enqueue(struct data value);
struct data dequeue();
int checkPri(int priority);

int main(void) {
	int testCase = 0;
	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++) {
		int documentSize = 0, research = 0;
		scanf("%d %d", &documentSize, &research);

		front = rear = 0;  // ť �ʱ�ȭ
		for (int j = 0; j < documentSize; j++) {
			int pri = 0;
			scanf("%d", &pri);
			enqueue((struct data) { j, pri }); // ť�� {j, pri}�������� ������ ����.
		}

		int result = 0;

		while (1) {
			struct data CurrentData = dequeue();
			if (checkPri(CurrentData.priority)) {
				enqueue(CurrentData);
			}
			else {
				result++;

				if (CurrentData.index == research) {
					printf("%d\n", result);
					break;
				}
			}
		}
	}



	return 0;
}

void enqueue(struct data value) {
	queue[rear] = value;
	rear = (rear + 1) % MAXSIZE;
}

struct data dequeue() {
	struct data tmpData = queue[front];
	front = (front + 1) % MAXSIZE;
	return tmpData;
}

int checkPri(int priority) {
	int i = front;
	while (i != rear) {
		if (queue[i].priority > priority) {
			return 1; // ���� �켱�������� ���� ������ ������ 1 ��ȯ
		}
		i = (i + 1) % MAXSIZE;
	}
	return 0; // ������ 0 ��ȯ.
}