//Stack, Queue, Deque - 5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000

int stack[MAXSIZE] = { 0 };
int top = -1;

void push(int value);
int pop();
int peek();

int main(void) {
    int size = 0;
    scanf("%d", &size);

    int* arr = (int*)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 1;
    for (int i = 0; i <= size; i++) {
        if (peek() == count) {
            while (peek() == count) {
                pop();
                count++;
            }
        }

        if (arr[i] == count) {
            count++;
        }
        else if (arr[i] != count) {
            push(arr[i]);
        }

    }

    if ((count - 1) == size) {
        printf("Nice");
    }
    else {
        printf("Sad");
    }

    return 0;
}

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

int peek() {
    return stack[top];
}
