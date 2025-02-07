#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAXSIZE 10000

typedef struct {
    int data[MAXSIZE];
    int front;
    int rear;
    int size;
}Deque;

void init_deque(Deque* deque);
void push_front(Deque* deque, int data);
void push_back(Deque* deque, int data);
int pop_front(Deque* deque);
int pop_back(Deque* deque);
int print_front(Deque* deque);
int print_back(Deque* deque);
int print_size(Deque* deque);
bool is_empty(Deque* deque);


int main() {
    int testCase = 0;
    scanf("%d", &testCase);

    Deque deque;
    init_deque(&deque);

    
    while (testCase--) {
        char func[11];
        scanf("%s", func);

        if (strcmp(func, "push_front") == 0) {
            int data;
            scanf("%d", &data);
            push_front(&deque, data);
        }
        else if (strcmp(func, "push_back") == 0) {
            int data;
            scanf("%d", &data);
            push_back(&deque, data);
        }
        else if (strcmp(func, "pop_front") == 0) {
            printf("%d\n", pop_front(&deque));
        }
        else if (strcmp(func, "pop_back") == 0) {
            printf("%d\n", pop_back(&deque));
        }
        else if (strcmp(func, "size") == 0) {
            printf("%d\n", print_size(&deque));
        }
        else if (strcmp(func, "empty") == 0) {
            printf("%d\n", is_empty(&deque));
        }
        else if (strcmp(func, "front") == 0) {
            printf("%d\n", print_front(&deque));
        }
        else if (strcmp(func, "back") == 0) {
            printf("%d\n", print_back(&deque));
        }
    }

    return 0;
}

void init_deque(Deque* deque) {
    deque->front = 0;
    deque->rear = 0;
    deque->size = 0;
}

void push_front(Deque* deque, int data) {
    deque->front = (deque->front - 1 + MAXSIZE) % MAXSIZE;
    deque->data[deque->front] = data;
    deque->size++;
}
void push_back(Deque* deque, int data) {
    deque->data[deque->rear] = data;
    deque->rear = (deque->rear + 1) % MAXSIZE;
    deque->size++;
}

int pop_front(Deque* deque) {
    if (is_empty(deque)) return -1;
    int data = deque->data[deque->front];
    deque->front = (deque->front + 1) % MAXSIZE;
    deque->size--;
    return data;
}
int pop_back(Deque* deque) {
    if (is_empty(deque)) return -1;
    deque->rear = (deque->rear - 1 + MAXSIZE) % MAXSIZE;
    int data = deque->data[deque->rear];
    deque->size--;
    return data;
}

int print_front(Deque* deque) {
    if (is_empty(deque)) return -1;
    return deque->data[deque->front];
}
int print_back(Deque* deque) {
    if (is_empty(deque)) return -1;
    int index = (deque->rear - 1 + MAXSIZE) % MAXSIZE;
    return deque->data[index];
}
int print_size(Deque* deque) {
    return deque->size;
}

bool is_empty(Deque* deque) {
    return deque->size == 0;
}
