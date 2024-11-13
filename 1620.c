//1620
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pair {
	int index;
	char name[21];
};

int compare(const void* a, const void* b);
int binsearch(struct pair* data, int size, char* key);

int main(void) {
	int testCase = 0;
	int question = 0;
	scanf("%d %d", &testCase, &question);
	getchar();
	struct pair* p = (struct pair*)calloc(testCase, sizeof(struct pair));
	for (int i = 0; i < testCase; i++) {
		scanf("%s", p[i].name);
		p[i].index = i + 1;
	}

	struct pair* nameArray = (struct pair*)calloc(testCase, sizeof(struct pair));
	for (int i = 0; i < testCase; i++) {
		nameArray[i] = p[i];
	}

	qsort(nameArray, testCase, sizeof(struct pair), compare); // Name을 입력했을 때에 대응하기 위한 사전순 정리.

	for (int i = 0; i < question; i++) {
		char string[8] = { 0 };
		scanf("%s", string);
		int num = atoi(string);
		if (num != 0) {
			printf("%s\n", p[num - 1].name);
		}
		else {
			printf("%d\n", binsearch(nameArray, testCase, string));
		}

	}

	return 0;
}

int compare(const void* a, const void* b) {
	return strcmp(((struct pair*)a)->name, ((struct pair*)b)->name);
}

int binsearch(struct pair* data, int size, char* key) {
	int low, high, mid;
	low = 0;
	high = size - 1;
	int index = -1;
	while (low <= high) {
		mid = (low + high) / 2;
		int tmp = strcmp(key, data[mid].name);
		if (tmp == 0) {
			index = data[mid].index;
			break;
		}
		else if (tmp < 0) {
			high = mid - 1;
		}
		else if (tmp > 0) {
			low = mid + 1;
		}
	}
	return index; // Key 값이 없을 때 -1.
}