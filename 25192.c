#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXUSER 100000

typedef struct Node {
    char* name;
    int session;
    struct Node* next;
} Node;

Node* hashTable[MAXUSER] = { NULL };
int currentSession = 0;

unsigned long hash(const char* str);
Node* createNode(const char* name);
void clearHashTable();

int main(void) {
    int testCase = 0;
    scanf("%d", &testCase);

    int count = 0;
    char input[21] = { 0 };

    for (int t = 0; t < testCase; t++) {
        scanf("%s", input);

        if (strcmp(input, "ENTER") == 0) {
            currentSession++;
        }
        else {
            unsigned long index = hash(input);
            Node* current = hashTable[index];
            int isFound = 0;

            while (current != NULL) {
                if (current->session == currentSession && strcmp(current->name, input) == 0) {
                    isFound = 1;
                    break;
                }
                current = current->next;
            }

            if (!isFound) {
                Node* newNode = createNode(input);
                newNode->session = currentSession;
                newNode->next = hashTable[index];
                hashTable[index] = newNode;
                count++;
            }
        }
    }

    printf("%d\n", count);

    clearHashTable();
    return 0;
}

unsigned long hash(const char* str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % MAXUSER;
}

Node* createNode(const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->name = strdup(name);
    newNode->session = 0;
    newNode->next = NULL;
    return newNode;
}

void clearHashTable() {
    for (int i = 0; i < MAXUSER; i++) {
        Node* current = hashTable[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp->name);
            free(temp);
        }
        hashTable[i] = NULL;
    }
}
