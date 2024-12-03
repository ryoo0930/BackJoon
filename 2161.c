#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int index;
    struct Node* prev;
    struct Node* next;
}Node;

Node* createNode(int index);
Node* deleteNode(Node** head, Node* target);

int main(void) {
    int size = 0;
    scanf("%d", &size);

    Node* head = createNode(1);
    Node* current = head;
    for (int i = 2; i <= size; i++) {
        Node* newNode = createNode(i);
        newNode->prev = current;
        current->next = newNode;
        current = newNode;
    }
    current->next = head;
    head->prev = current;

    current = head;
    while (head != NULL) {
        printf("%d ", current->index);
        current = deleteNode(&head, current);
        current = current->next;
    }


    return 0;
}

Node* createNode(int index) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->index = index;
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
