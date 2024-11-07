//10814
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct person {
	int age;
	char name[101];
};

int compare(struct person* a, struct person* b);

int main(void) {
	int testCase = 0;
	scanf("%d", &testCase);
	struct person* p = (struct person*)malloc(sizeof(struct person) * testCase);
	for (int i = 0; i < testCase; i++) {
		scanf("%d %s", &p[i].age, &p[i].name);
	}

	qsort((struct person*)p, testCase, sizeof(struct person), compare);

	for (int i = 0; i < testCase; i++) {
		printf("%d %s\n", p[i].age, p[i].name);
	}

	return 0;
}

int compare(struct person* a, struct person* b) {
	if (a->age > b->age) { return 1; }
	else if (a->age < b->age) { return -1; }
	else { return a->name - b->name; }
}