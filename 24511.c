//queuestack
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int front, rear;
    int size;
}Queue;

void initQueue(Queue* q, int size);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);

int main(void) {
    int dataSize = 0;
    scanf("%d", &dataSize);

    int* queuestack = (int*)malloc(sizeof(int) * dataSize);
    for (int i = 0; i < dataSize; i++) { scanf("%d", &queuestack[i]); }
    int* value = (int*)malloc(sizeof(int) * dataSize);
    for (int i = 0; i < dataSize; i++) { scanf("%d", &value[i]); }

    Queue queue;
    initQueue(&queue, dataSize + 1);

    for (int i = dataSize - 1; i >= 0; i--) { 
        if (queuestack[i] == 0) { enqueue(&queue, value[i]); }
    }

    int inputSize = 0;
    scanf("%d", &inputSize);
    int* inputValue = (int*)malloc(sizeof(int) * inputSize);
    for (int i = 0; i < inputSize; i++) { scanf("%d", &inputValue[i]); }

    for (int i = 0; i < inputSize; i++) {
        enqueue(&queue, inputValue[i]);
        printf("%d ", dequeue(&queue));
    }

    return 0;
}

void initQueue(Queue* q, int size) {
    q->data = (int*)malloc(sizeof(int) * size);
    q->front = 0;
    q->rear = -1;
    q->size = size;
}
void enqueue(Queue* q, int value) {
    q->rear = (q->rear + 1) % q->size;
    q->data[q->rear] = value;
}
int dequeue(Queue* q) {
    int result = q->data[q->front];
    q->front = (q->front + 1) % q->size;
    return result;
}
