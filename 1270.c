#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	long long key;
	int count;
} HashEntry;

typedef struct {
	HashEntry* table;
	int size;
} HashMap;

HashMap* createHashMap(int size) {
	HashMap* map = (HashMap*)malloc(sizeof(HashMap));
	map->size = size;
	map->table = (HashEntry*)calloc(size, sizeof(HashEntry));
	return map;
}

void freeHashMap(HashMap* map) {
	free(map->table);
	free(map);
}

int hash(long long key, int size) {
	return (int)((key % size + size) % size);
}

void insert(HashMap* map, long long key) {
	int index = hash(key, map->size);
	while (true) {
		if (map->table[index].count == 0 || map->table[index].key == key) {
			map->table[index].key = key;
			map->table[index].count++;
			break;
		}
		index = (index + 1) % map->size;
	}

}

int getCount(HashMap* map, long long key) {
	int index = hash(key, map->size);
	while (true) {
		if (map->table[index].count == 0) return 0;
		if (map->table[index].key == key) return map->table[index].count;
		index = (index + 1) % map->size;
	}
}


int main() {
	int testCase = 0;
	scanf("%d", &testCase);

	while (testCase--) {
		int soldierCount = 0;
		scanf("%d", &soldierCount);

		HashMap* map = createHashMap(soldierCount * 2);

		long long half = soldierCount / 2;
		long long soldier = 0;
		long long result = 0;
		bool found = false;

		for (int i = 0; i < soldierCount; i++) {
			scanf("%lld", &soldier);
			insert(map, soldier);

			if (getCount(map, soldier) > half) {
				result = soldier;
				found = true;
			}
		}

		if (found) printf("%lld\n", result);
		else printf("SYJKGW\n");

		freeHashMap(map);
	}

	return 0;
}
