//2108
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct modeIndex {
	int index;
	int count;
};

int compare(const void* a, const void* b);
int S_compare(struct modeIndex* a, struct modeIndex* b);
int mode(int* arr, int size);

int main(void) {
	int testCase = 0;
	scanf("%d", &testCase);
	int* arr = (int*)calloc(testCase, sizeof(int));

	long long sum = 0; //��� ����� ���� SUM��.
	for (int i = 0; i < testCase; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i]; //��� ����� ���� SUM��.
	}
	qsort(arr, testCase, sizeof(int), compare); // ����

	//��� ���
	printf("%d\n", (int)round((double)sum / testCase));
	//�߾Ӱ�
	printf("%d\n", arr[testCase / 2]);
	//�ֺ�
	printf("%d\n", mode(arr, testCase));
	//����
	printf("%d\n", arr[testCase - 1] - arr[0]);


	return 0;
}

int compare(const void* a, const void* b) {
	if (*(int*)a > *(int*)b) { return 1; }
	else if (*(int*)a < *(int*)b) { return -1; }
	else { return 0; }
}

int S_compare(struct modeIndex* a, struct modeIndex* b) {
	if (a->count > b->count) { return -1; }
	else if (a->count < b->count) { return 1; }
	else { return a->index - b->index; } // count�� ������ index ������ ����.
}

int mode(int* arr, int size) {
	int modeIndexSize = 0;
	struct modeIndex* a = (struct modeIndex*)calloc(size, sizeof(struct modeIndex));
	for (int i = 0; i < size; i++) {
		int overlap = 0;
		for (int j = 0; j < modeIndexSize; j++) {
			if (arr[i] == a[j].index) {
				a[j].count++;
				overlap = 1;
				break;
			}
		}
		if (!overlap) {
			a[modeIndexSize].index = arr[i];
			a[modeIndexSize].count = 1;
			modeIndexSize++;
		}
	}
	qsort(a, modeIndexSize, sizeof(struct modeIndex), S_compare);
	
	if (a[0].count == a[1].count) {
		return a[1].index; //���� �� ���� ������ �ֺ� �� �� ��°�� ���� ��
	}
	else {
		return a[0].index;
	}
}