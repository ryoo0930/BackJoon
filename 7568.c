//7568
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct person {
	int order;
	int weight;
	int height;
};

int main(void) {
	int testCase = 0;
	scanf("%d", &testCase);

	struct person* p = (struct person*)malloc(sizeof(struct person) * testCase); // 备炼眉 悼利 积己
	for (int i = 0; i < testCase; i++) {
		scanf("%d %d", &p[i].weight, &p[i].height);
	}

	for (int i = 0; i < testCase; i++) {
		int count = 1;
		for (int j = 0; j < testCase; j++) {
			if (p[i].height < p[j].height && p[i].weight < p[j].weight) {
				count++;
			}
			p[i].order = count;
		}
	}

	for (int i = 0; i < testCase; i++) {
		printf("%d ", p[i].order);

	}

	return 0;
}