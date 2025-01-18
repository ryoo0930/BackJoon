#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[11];
	int value;
}auction;

int researchMinValue(auction* participant, int size);
int compare(const void* a, const void* b);

int main() {
	int upperLimit = 0, size = 0;
	scanf("%d %d", &upperLimit, &size);

	auction* participant = (auction*)malloc(sizeof(auction) * size);
	for (int i = 0; i < size; i++) { scanf("%s %d", participant[i].name, &participant[i].value); }

	int minValue = researchMinValue(participant, size);
	for (int i = 0; i < size; i++) {
		if (participant[i].value == minValue) { printf("%s %d\n", participant[i].name, participant[i].value); break; }
	}

	free(participant);
	return 0;
}

int researchMinValue(auction* participant, int size) {
    int frequency[10001] = { 0 };
    for (int i = 0; i < size; i++) { frequency[participant[i].value]++; }

    int minFrequency = size + 1;
    int minValue = 10001;
    
    for (int i = 1; i <= 10000; i++) {
        if (frequency[i] == 1) { minValue = i; break; }
        else if (frequency[i] > 0 && frequency[i] < minFrequency) { minFrequency = frequency[i]; minValue = i; }
        else if (frequency[i] == minFrequency && i < minValue) { minValue = i; }
    }

    return minValue;
}

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}
