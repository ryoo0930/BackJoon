//Set & Map 3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100003

typedef struct Node {
    char name[6];
    struct Node* next;
} Node;

Node* hashTable[MAX_SIZE] = { 0 };

unsigned long hash(char* str);
int compare(const void* a, const void* b);
void insert(const char* name);
void delete(const char* name);

int main(void) {
    int size = 0;
    scanf("%d", &size);

    char name[6], status[6];
    for (int i = 0; i < size; i++) {
        scanf("%s %s", name, status);
        if (strcmp(status, "enter") == 0) {
            insert(name);
        }
        else {
            delete(name);
        }
    }

    char** string = (char**)malloc(sizeof(char*) * size);
    int count = 0;

    for (int i = 0; i < MAX_SIZE; i++) {
        Node* current = hashTable[i];
        while (current != NULL) {
            string[count] = (char*)malloc(sizeof(char) * 6);
            strcpy(string[count], current->name);
            count++;
            current = current->next;
        }
    }

    qsort(string, count, sizeof(char*), compare);
    for (int i = 0; i < count; i++) {
        printf("%s\n", string[i]);
    }

    return 0;
}

void insert(const char* name) {
    unsigned long index = hash(name) % MAX_SIZE;
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

void delete(const char* name) {
    unsigned long index = hash(name) % MAX_SIZE;
    Node* current = hashTable[index];
    Node* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                hashTable[index] = current->next;
            }
            else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

int compare(const void* a, const void* b) {
    const char* str_a = *(const char**)a;
    const char* str_b = *(const char**)b;
    return strcmp(str_b, str_a);
}

unsigned long hash(char* str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}
