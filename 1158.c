#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int index;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(int index);
Node* deleteNode(Node** head, Node* target);

int main(void) {
    int size = 0, step = 0;;
    scanf("%d %d", &size, &step);

    Node* head = createNode(1);
    Node* current = head;
    for (int i = 2; i <= size; i++) {
        Node* newNode = createNode(i);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }
    current->next = head;
    head->prev = current;


    printf("<");
    current = head;
    while (head != NULL) {
        for (int i = 1; i < step; i++) {
            current = current->next;
        }
        printf("%d", current->index);
        if (current->next != current) {
            printf(", ");
        }
        current = deleteNode(&head, current);
    }
    printf(">");


    return 0;
}

Node* createNode(int index) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->index = index;
    newNode->next = NULL;
    newNode->prev = NULL;
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
