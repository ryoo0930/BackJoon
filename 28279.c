//Stack, Queue, Deque - 9
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} Deque;

void initDeque(Deque* dq);
int is_empty(Deque* dq);
void insertFront(Deque* dq, int item);
void insertRear(Deque* dq, int item);
int deleteFront(Deque* dq);
int deleteRear(Deque* dq);
int getFront(Deque* dq);
int getRear(Deque* dq);
int getSize(Deque* dq);


int main(void) {
    Deque dq;
    initDeque(&dq);

    int testCase = 0;
    scanf("%d", &testCase);
    for (int t = 0; t < testCase; t++) {
        int function = 0, value = 0;
        scanf("%d", &function);
        switch (function) {
        case 1:
            scanf("%d", &value);
            insertFront(&dq, value);
            break;

        case 2:
            scanf("%d", &value);
            insertRear(&dq, value);
            break;

        case 3:
            printf("%d\n", deleteFront(&dq));
            break;

        case 4:
            printf("%d\n", deleteRear(&dq));
            break;

        case 5:
            printf("%d\n", getSize(&dq));
            break;

        case 6:
            printf("%d\n", is_empty(&dq));
            break;

        case 7:
            printf("%d\n", getFront(&dq));
            break;

        case 8:
            printf("%d\n", getRear(&dq));
            break;
        }
    }

    return 0;
}

void initDeque(Deque* dq) {
    dq->front = NULL;
    dq->rear = NULL;
    dq->size = 0;
}

int is_empty(Deque* dq) {
    if (dq->front == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

void insertFront(Deque* dq, int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = dq->front;
    newNode->prev = NULL;
    if (is_empty(dq)) {
        dq->rear = newNode;
    }
    else {
        dq->front->prev = newNode;
    }
    dq->front = newNode;
    dq->size++;
}

void insertRear(Deque* dq, int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = NULL;
    newNode->prev = dq->rear;
    if (is_empty(dq)) {
        dq->front = newNode;
    }
    else {
        dq->rear->next = newNode;
    }
    dq->rear = newNode;
    dq->size++;
}

int deleteFront(Deque* dq) {
    if (is_empty(dq)) {
        return -1;
    }
    Node* tempNode = dq->front;
    int data = tempNode->data;
    dq->front = dq->front->next;
    if (dq->front == NULL) {
        dq->rear = NULL;
    }
    else {
        dq->front->prev = NULL;
    }
    free(tempNode);
    dq->size--;
    return data;
}

int deleteRear(Deque* dq) {
    if (is_empty(dq)) {
        return -1;
    }
    Node* tempNode = dq->rear;
    int data = tempNode->data;
    dq->rear = dq->rear->prev;
    if (dq->rear == NULL) {
        dq->front = NULL;
    }
    else {
        dq->rear->next = NULL;
    }
    free(tempNode);
    dq->size--;
    return data;
}

int getFront(Deque* dq) {
    if (is_empty(dq)) {
        return -1;
    }
    return dq->front->data;
}
int getRear(Deque* dq) {
    if (is_empty(dq)) {
        return -1;
    }
    return dq->rear->data;
}

int getSize(Deque* dq) {
    return dq->size;
}
