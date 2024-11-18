//9375
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct set {
	char name[21];
	char kind[21];
};

int compareK(const void* a, const void* b);

int main(void) {
	int testCase = 0;
	scanf("%d", &testCase);
	for (int i = 0; i < testCase; i++) {
		int clothSize = 0;
		scanf("%d", &clothSize);

		struct set* s = (struct set*)calloc(clothSize, sizeof(struct set));
		for (int j = 0; j < clothSize; j++) {
			scanf("%s %s", &s[j].name, &s[j].kind);
		}

		qsort(s, clothSize, sizeof(struct set), compareK); // ���� �������� ����;

		int result = 1;
		int count = 1; // ���� ����;
		for (int j = 0; j < clothSize - 1; j++) {
			if (strcmp(s[j].kind, s[j + 1].kind) == 0) {
				count++;
			}
			else {
				result *= (count + 1); // ���� ������ �� ���� + 1 (�� �Դ� ���);
				count = 1;
			}
		}
		result *= (count + 1); // ������ ���� ó��;
		result--; // �˸��� ��� ����;

		if (clothSize == 0) { // ���� ������ 0�� ��� ó��;
			result = 0;
		}


		printf("%d\n", result);
		free(s);
	}

	return 0;
}

int compareK(const void* a, const void* b) {
	const struct set* setA = (const struct set*)a;
	const struct set* setB = (const struct set*)b;
	return strcmp(setA->kind, setB->kind);
}