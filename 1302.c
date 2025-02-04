#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[51];
    int count;
}HashEntry;

typedef struct {
    HashEntry* table;
    int size;
}HashMap;

HashMap* createHashMap(int size);
void freeHashMap(HashMap* map);
int hash(char* str, int size);
void insert(HashMap* map, char* title);
int getMaxCount(HashMap* map);

int main() {
    int size = 0;
    scanf("%d", &size);

    HashMap* map = createHashMap(size);

    char title[51];
    for (int i = 0; i < size; i++) {
        scanf("%s", title);
        insert(map, title);
    }
    printf("%s", map->table[getMaxCount(map)].title);

    freeHashMap(map);
    return 0;
}

HashMap* createHashMap(int size) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->table = (HashEntry*)calloc(size, sizeof(HashEntry));
    map->size = size;
    return map;
}

void freeHashMap(HashMap* map) {
    free(map->table);
    free(map);
}

int hash(char* str, int size) {
    int hash = 5381;
    int c;
    while (c = *str++) hash = (((hash << 5) + hash) + c) % size;
    return hash % size;
}

void insert(HashMap* map, char* title) {
    int index = hash(title, map->size);
    while (1) {
        if (map->table[index].count == 0 || strcmp(map->table[index].title, title) == 0) {
            strcpy(map->table[index].title, title);
            map->table[index].count++;
            break;
        }
        index = (index + 1) % map->size;
    }
}

int getMaxCount(HashMap* map) {
    int maxIndex = -1;
    int maxCount = -1;

    for (int i = 0; i < map->size; i++) {
        if (map->table[i].count > maxCount) {
            maxCount = map->table[i].count;
            maxIndex = i;
        }
        else if (map->table[i].count == maxCount) {
            if (strcmp(map->table[maxIndex].title, map->table[i].title) > 0) {
                maxIndex = i;
            }
        }
    }
    return maxIndex;
}
