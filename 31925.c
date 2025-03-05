#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct dataset {
	char name[11];
	char isStudent[7];
	char isWinner[7];
	int topGrade;
	int grade;
}dataset;

typedef struct stack {
	dataset* data;
	int top;
}stack;

typedef struct sortName {
	char name[11];
}sortName;

int compare(const void* a, const void* b);
int compare2(const void* a, const void* b);
void initStack(stack* s, int size);
void freeStack(stack* s);
void inputStack(stack* s, dataset data);

int main()
{
	int size = 0;
	scanf("%d", &size);

	dataset* ds = (dataset*)malloc(sizeof(dataset) * size);
	for (int i = 0; i < size; i++) {
		scanf("%s %s %s %d %d", &ds[i].name, &ds[i].isStudent, &ds[i].isWinner, &ds[i].topGrade, &ds[i].grade);
	}

	qsort(ds, size, sizeof(dataset), compare);

	stack s;
	initStack(&s, size);

	for (int i = 0; i < size; i++) {
		if (strcmp(ds[i].isStudent, "jaehak") == 0 && strcmp(ds[i].isWinner, "notyet") == 0 && (ds[i].topGrade > 3 || ds[i].topGrade == -1)) {
			inputStack(&s, ds[i]);
		}
	}

	sortName* sN = (sortName*)calloc(10, sizeof(sortName));

	for (int i = 0; i < 10 && i < (s.top + 1); i++) {
		strcpy(sN[i].name, s.data[i].name);
	}

	if (s.top + 1 < 10) {
		qsort(sN, s.top + 1, sizeof(sortName), compare2);
		printf("%d\n", s.top + 1);
		for (int i = 0; i < s.top + 1; i++) {
			printf("%s\n", sN[i].name);
		}
	}

	else {
		qsort(sN, 10, sizeof(sortName), compare2);
		printf("10\n");
		for (int i = 0; i < 10; i++) {
			printf("%s\n", sN[i].name);
		}
	}



	free(sN);
	freeStack(&s);
	free(ds);
	return 0;
}

int compare(const void* a, const void* b) {
	dataset* dsa = (dataset*)a;
	dataset* dsb = (dataset*)b;
	
	return dsa->grade - dsb->grade;
}

int compare2(const void* a, const void* b) {
	sortName* sNa = (sortName*)a;
	sortName* sNb = (sortName*)b;
	return strcmp(sNa->name, sNb->name);
}

void initStack(stack* s, int size) {
	s->data = calloc(size, sizeof(dataset));
	s->top = -1;
}

void inputStack(stack* s, dataset data) {
	s->data[++s->top] = data;
}

void freeStack(stack* s) {
	free(s->data);
}
