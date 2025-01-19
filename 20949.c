#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	double PPI;
	unsigned int index;
}Monitor;

int compare(const void* a, const void* b);

int main() {
	int size = 0;
	scanf("%d", &size);

	Monitor* monitors = (Monitor*)malloc(sizeof(Monitor) * size);

	for (int i = 0; i < size; i++) {
		int width = 0, height = 0;
		scanf("%d %d", &width, &height);

		monitors[i].PPI = sqrt(width * width + height * height) / 77;
		monitors[i].index = i + 1;
	}

	qsort(monitors, size, sizeof(Monitor), compare);
	for (int i = 0; i < size; i++) { printf("%d\n", monitors[i].index); }

	return 0;
}

int compare(const void* a, const void* b) {
	Monitor* monitorA = (Monitor*)a;
	Monitor* monitorB = (Monitor*)b;

	if (monitorA->PPI < monitorB->PPI) { return 1; }
	if (monitorA->PPI > monitorB->PPI) { return -1; }
	else return monitorA->index - monitorB->index;
}
