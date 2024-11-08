//2164
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int maxSize = 0;

struct Circle_Queue {
	int front;
	int rear;
	int* data;
};

void enqueue(struct Circle_Queue* q, int num);
void dequeue(struct Circle_Queue* q);
void queue_print(struct Circle_Queue* q);

int main(void) {
	int deckSize = 0;
	scanf("%d", &deckSize);
	struct Circle_Queue q;

	//원형 큐 초기화
	q.front = 0;
	q.rear = 0;
	q.data = (int*)malloc(sizeof(int) * deckSize + 1);
	maxSize = deckSize + 1;
	
	//초기 데이터 삽입
	for (int i = 0; i < deckSize; i++) {
		enqueue(&q, i + 1);
	}

	for (int i = 0; i < deckSize - 1; i++) {
		dequeue(&q);
		int front_value = q.data[q.front];
		enqueue(&q, front_value);
		dequeue(&q);
	}

	queue_print(&q);

	return 0;
}

void enqueue(struct Circle_Queue* q, int num) {
	q->data[q->rear] = num;
	q->rear = (q->rear + 1) % maxSize;
}
void dequeue(struct Circle_Queue* q) {
	q->front = (q->front + 1) % maxSize;
}

void queue_print(struct Circle_Queue* q) {
	int i = q->front;
	while (i != q->rear) {
		printf("%d ", q->data[i]);
		i = (i + 1) % maxSize;
	}
}