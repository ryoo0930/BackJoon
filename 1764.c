//1764
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b);
int binsearch(char** person, int size, char* key);

int main(void) {
	int DL = 0, DS = 0;
	scanf("%d %d", &DL, &DS);
	getchar();
	char** person = (char**)calloc(DL, sizeof(char*)); // ���� ���غ� ����� ���.
	for (int i = 0; i < DL; i++) {
		person[i] = (char*)calloc(21, sizeof(char));;
		scanf("%s", person[i]); 
	}
	
	char** resultPerson = (char**)calloc(DS, sizeof(char*)); // ���� | ����� ��� 
	for (int i = 0; i < DS; i++) {
		resultPerson[i] = (char*)calloc(21, sizeof(char));
	}

	qsort(person, DL, sizeof(char*), compare); // ���� ���غ� ��� ����� ������ ����.

	int RPTop = -1; // ���� �������� �׾� �ø���.
	for (int i = 0; i < DS; i++) {
		char tmpPerson[21] = { 0 };
		scanf("%s", tmpPerson); 
		int result = binsearch(person, DL, tmpPerson);
		if (result != -1) { // ���� ���غ� ����� �޾Ƽ� ���� ���غ� ��� ��ܰ� ��ġ�ϸ� ����|����� ��ܿ� �Է�.
			RPTop++;
			strcpy(resultPerson[RPTop], tmpPerson); // ���ڿ� ����
		}
	}

	qsort(resultPerson, RPTop + 1, sizeof(char*), compare);
	printf("%d\n", RPTop + 1);
	for (int i = 0; i <= RPTop; i++) {
		printf("%s\n", resultPerson[i]);
	}


	return 0;
}

int compare(const void* a, const void* b) {
	return strcmp(*(const char**)a, *(const char**)b);
}

int binsearch(char** person, int size, char* key) {
	int low, high, mid;
	low = 0;
	high = size - 1;
	int index = -1;
	while (low <= high) {
		mid = (low + high) / 2;
		int tmp = strcmp(person[mid], key);
		if (tmp == 0) {
			index = mid;
			break;
		}
		else if (tmp > 0) {
			high = mid - 1;
		}
		else if (tmp < 0) {
			low = mid + 1;
		}
	}
	return index; // Key ���� ���� �� -1 ��ȯ. ������ �迭 ��ġ (mid) ��ȯ.
}