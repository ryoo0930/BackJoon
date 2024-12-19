#include <stdio.h>

#define MAXSIZE 100000
int heap[MAXSIZE];
int heap_size = 0;

void swap(int* a, int* b);
void push(int num);
int pop();

int main(void) {
    int testCase = 0;
    scanf("%d", &testCase);
    while (testCase-- > 0) {
        int function = 0;
        scanf("%d", &function);

        if (function != 0) {
            push(function);
        }
        else {
            printf("%d\n", pop());
        }
    }
    return 0;
}
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(int num) {
    heap[++heap_size] = num;
    int current = heap_size;

    while (current > 1 && heap[current] < heap[current / 2]) {
        swap(&heap[current], &heap[current / 2]);
        current = current / 2;
    }
}

int pop() {
    if (heap_size == 0) {
        return 0;
    }

    int result = heap[1];
    heap[1] = heap[heap_size--];

    int current = 1;
    while (current * 2 <= heap_size) {
        int child = current * 2;
        if (child + 1 <= heap_size && heap[child] > heap[child + 1]) {
            child += 1;
        }
        if (heap[current] <= heap[child]) { break; }
        swap(&heap[current], &heap[child]);
        current = child;
    }

    return result;
}
