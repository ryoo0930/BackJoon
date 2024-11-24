//Sort 11
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct pos {
	int x;
	int compressX;
};

int compare(struct pos* a, struct pos* b);
int binsearch(struct pos* data, int size, int key);

int main(void) {
	int size = 0;
	scanf("%d", &size);
	struct pos* p = (struct pos*)calloc(size, sizeof(struct pos));
	struct pos* tmp = (struct pos*)calloc(size, sizeof(struct pos));
	
	for (int i = 0; i < size; i++) { 
		scanf("%d", &p[i].x);
		tmp[i].x = p[i].x;
	}

	qsort(tmp, size, sizeof(struct pos), compare);

	int index = 0;
	tmp[0].compressX = index;
	for (int i = 1; i < size; i++) {
		if (tmp[i].x != tmp[i - 1].x) {
			index++;
			tmp[i].compressX = index;
		}
		else {
			tmp[i].compressX = index;
		}
	}

	for (int i = 0; i < size; i++) {
		printf("%d ", binsearch(tmp, size, p[i].x));
	}

	return 0;
}

int compare(struct pos* a, struct pos* b) {
	return (a->x - b->x);
}

int binsearch(struct pos* data, int size, int key) {
	int low, high, mid;
	low = 0;
	high = size - 1;
	int index = -1;

	while (low <= high) {
		mid = (low + high) / 2;
		if (key == data[mid].x) {
			index = data[mid].compressX;
			break;
		}
		else if (key < data[mid].x) {
			high = mid - 1;
		}
		else if (key > data[mid].x) {
			low = mid + 1;
		}
	}
	return index; // Key 값이 없을 때.
}
