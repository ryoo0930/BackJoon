#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data);
Node* deleteNode(Node** head, Node* target);
int findOperations(Node* head, int target, int size, int* direction);

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);

    // 원형 연결 리스트 생성
    Node* head = createNode(1);
    Node* current = head;
    for (int i = 2; i <= N; i++) {
        Node* newNode = createNode(i);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }
    current->next = head;
    head->prev = current;

    int* arr = (int*)malloc(sizeof(int) * M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &arr[i]);
    }

    int totalOperations = 0;

    for (int i = 0; i < M; i++) {
        int target = arr[i];
        int direction = 0;

        int operations = findOperations(head, target, N, &direction);
        totalOperations += operations;

        while (operations--) {
            if (direction == 1) {
                head = head->next;
            }
            else if (direction == -1) {
                head = head->prev;
            }
        }

        
        head = deleteNode(&head, head);
        N--;
    }

    printf("%d\n", totalOperations);

    free(arr);
    current = head;

    return 0;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node* deleteNode(Node** head, Node* target) {
    if (target->next == target) {
        *head = NULL;
    }
    else {
        target->next->prev = target->prev;
        target->prev->next = target->next;
        if (*head == target) {
            *head = target->next;
        }
    }

    Node* nextNode = target->next;
    free(target);
    return nextNode;
}

int findOperations(Node* head, int target, int size, int* direction) {
    Node* current = head;
    int leftSteps = 0;
    int rightSteps = 0;

    while (current->data != target) {
        current = current->next;
        leftSteps++;
    }

    current = head;

    while (current->data != target) {
        current = current->prev;
        rightSteps++;
    }

    if (leftSteps <= rightSteps) {
        *direction = 1;
        return leftSteps;
    }
    else {
        *direction = -1;
        return rightSteps;
    }
}
