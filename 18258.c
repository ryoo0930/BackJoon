//Stack, Queue, Deque - 6
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAXSIZE 2000000

int queue[MAXSIZE] = { 0 };
int head = -1, rear = -1;

void push(int value);
int pop();
int size();
int empty();
int front();
int back();


int main(void) {
    int testCase = 0;
    scanf("%d", &testCase);
    for (int t = 0; t < testCase; t++) {
        char string[6] = { 0 };
        scanf("%s", &string);

        if (strcmp(string, "push") == 0) {
            int value = 0;
            scanf("%d", &value);
            push(value);
        }
        else if (strcmp(string, "pop") == 0) {
            printf("%d\n", pop());
        }
        else if (strcmp(string, "size") == 0) {
            printf("%d\n", size());
        }
        else if (strcmp(string, "empty") == 0) {
            printf("%d\n", empty());
        }
        else if (strcmp(string, "front") == 0) {
            printf("%d\n", front());
        }
        else if (strcmp(string, "back") == 0) {
            printf("%d\n", back());
        }
    }

    return 0;
}

void push(int value) {
    if (head == -1) {
        head = 0;
    }
    queue[++rear] = value;
}

int pop() {
    if (head == -1 || head > rear) {
        rear = -1;
        head = -1;
        return -1;
    }
    else {
        return queue[head++];
    }

}
int size() {
    if (head == -1) {
        return 0;
    }
    else {
        return (rear - head + 1);
    }
}
int empty() {
    if (head == -1 || head > rear) {
        return 1;
    }
    else {
        return 0;
    }
}
int front() {
    if (head == -1 || head > rear) {
        return -1;
    }
    else {
        return queue[head];
    }
}
int back() {
    if (head == -1 || head > rear) {
        return -1;
    }
    else {
        return queue[rear];
    }
}
