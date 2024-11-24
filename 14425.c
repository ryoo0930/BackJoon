//Set & Map 2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b);
int binsearch(char** data, int size, char* key);


int main(void) {
	int size = 0, size2 = 0;
	scanf("%d %d", &size, &size2);
	getchar();

	char** string = (char**)calloc(size, sizeof(char*));
	for (int i = 0; i < size; i++) { string[i] = (char*)calloc(501, sizeof(char)); }
	for (int i = 0; i < size; i++) { scanf("%s", string[i]); }

	qsort(string, size, sizeof(char*), compare);
	int count = 0;

	for (int i = 0; i < size2; i++) {
		char tmp[501] = { 0 };
		scanf("%s", &tmp);
		if (binsearch(string, size, tmp) == 1) {
			count++;
		}
	}

	printf("%d", count);

	return 0;
}

int compare(const void* a, const void* b) {
	return strcmp(*(char**)a, *(char**)b);
}

int binsearch(char** data, int size, char* key) {
	int mid;
	int low = 0;
	int high = size - 1;
	int index = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		int tmp = strcmp(data[mid], key);
		if (tmp == 0) {
			index = 1;
			break;
		}
		else if (tmp > 0) {
			high = mid - 1;
		}
		else if (tmp < 0) {
			low = mid + 1;
		}
	}
	return index;
}
