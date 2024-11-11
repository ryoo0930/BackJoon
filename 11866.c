//11866
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct queue {
	int* queue;
	int size;
	int front;
	int rear;
};

void enqueue(struct queue* q, int value);
int dequeue(struct queue* q);
int is_empty(struct queue* q);

int main(void) {
	int N = 0, K = 0;
	scanf("%d %d", &N, &K);

	struct queue q;
	// ť �ʱ�ȭ.
	q.queue = (int*)calloc(N, sizeof(int));
	q.size = N;
	q.rear = -1;
	q.front = -1;
	// ==================

	for (int i = 0; i < N; i++) {
		enqueue(&q, i + 1);
	}
	

	
	//�似Ǫ�� ������ �� ���
	printf("<");
	for(int i = 0; i < N - 1; i++) {
		for (int j = 0; j < K - 1; j++) {
			enqueue(&q, dequeue(&q));

		}
		printf("%d, ", dequeue(&q));
	 }

	printf("%d>\n", dequeue(&q));


	
	free(q.queue);
	return 0;
}

void enqueue(struct queue* q, int value) {
	if (is_empty(q)) {
		q->front = 0;
	}
	q->rear = (q->rear + 1) % q->size;
	q->queue[q->rear] = value;
}

int dequeue(struct queue* q) {
    int value = q->queue[q->front];
    if (q->front == q->rear) {  // ť�� ������� �ʱ�ȭ
        q->front = -1;
        q->rear = -1;
    }
	else {
        q->front = (q->front + 1) % q->size;
    }
    return value;
}

int is_empty(struct queue* q) {
	return (q->front == -1); // ������� �� 1 | ������� ������ 0 //
}