//Linked List . Deque
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int index;
    int value;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(int index, int value);
Node* deleteNode(Node** head, Node* target);

int main(void) {
    int size = 0;
    scanf("%d", &size);

    int* values = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) { scanf("%d", &values[i]); }

    // 원형 링크드 리스트 생성.
    Node* head = createNode(1, values[0]);
    Node* current = head;
    for (int i = 1; i < size; i++) {
        Node* newNode = createNode(i + 1, values[i]);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    } 
    current->next = head;
    head->prev = current;


    current = head;
    while (head != NULL) {
        printf("%d ", current->index);
        int step = current->value;
        Node* deleteN = current;
        current = (step > 0) ? current->next : current->prev;
        deleteNode(&head, deleteN);

        if (head == NULL) { break; }

        for (int i = 1; i < abs(step); i++) {
            current = (step > 0) ? current->next : current->prev;
        }
    }


    free(values);
    return 0;
}

Node* createNode(int index, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->index = index;
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node* deleteNode(Node** head, Node* target) {
    if (target->next == target) {
        *head = NULL;
    }
    else {
        target->prev->next = target->next;
        target->next->prev = target->prev;
        if (*head == target) {
            *head = target->next;
        }
    }
    free(target);
}
