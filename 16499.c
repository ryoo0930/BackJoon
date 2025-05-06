#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char word[11];
}Word;

int compare(const void* a, const void* b);
int hash(Word w);

int main()
{	
	int testCase = 0;
	int result = 0;
	scanf("%d", &testCase);
	
	Word hashTable[100] = { 0 };
	while (testCase--) {
		Word input;
		scanf("%s", input.word);
		qsort(input.word, strlen(input.word), sizeof(char), compare);

		int index = hash(input);
		while (hashTable[index].word[0] != '\0') {
			if (strcmp(hashTable[index].word, input.word) == 0) break;
			else index = (index + 1) % 100;
		}
		if (hashTable[index].word[0] == '\0') {
			strcpy(hashTable[index].word, input.word);
			result++;
		}
	}
	printf("%d", result);

	return 0;
}

int compare(const void* a, const void* b) {
	return *(char*)a - *(char*)b;
}

int hash(Word w) {
	int sum = 0;
	for (int i = 0; w.word[i]; i++) sum += w.word[i];
	return sum % 100;
}
