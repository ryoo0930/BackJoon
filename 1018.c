//1018
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int height = 0, width = 0;
	scanf("%d %d", &height, &width);
	getchar();
	char** string = (char**)malloc(sizeof(char*) * height);
	for (int i = 0; i < height; i++) {
		string[i] = (char*)malloc(sizeof(char) * (width + 1));
		gets(string[i]);
	}
	/*
	//�Է� Ȯ��
	for (int i = 0; i < height; i++) {
		printf("%s\n", string[i]);
	}
	*/

	//�ּڰ��� ���� INT�� 2���� �迭
	int** result = (int**)malloc(sizeof(int*) * (height - 7));
	for (int i = 0; i < height - 7; i++) {
		result[i] = (int*)malloc(sizeof(int) * (width - 7));
	}

	int count = 0;
	int min = 64;
	for(int i = 0; i < height - 7; i++){ // ���� ������
		for (int j = 0; j < width - 7; j++) { // ���� ������
			for (int k = i; k < i + 8; k = k + 2) { // ���� 8��ŭ �ݺ�
				if (string[i][j] == 'B') {
					if (string[k][j] != 'B') count++;
					if (string[k][j + 1] != 'W') count++;
					if (string[k][j + 2] != 'B') count++;
					if (string[k][j + 3] != 'W') count++;
					if (string[k][j + 4] != 'B') count++;
					if (string[k][j + 5] != 'W') count++;
					if (string[k][j + 6] != 'B') count++;
					if (string[k][j + 7] != 'W') count++;

					if (string[k + 1][j] != 'W') count++;
					if (string[k + 1][j + 1] != 'B') count++;
					if (string[k + 1][j + 2] != 'W') count++;
					if (string[k + 1][j + 3] != 'B') count++;
					if (string[k + 1][j + 4] != 'W') count++;
					if (string[k + 1][j + 5] != 'B') count++;
					if (string[k + 1][j + 6] != 'W') count++;
					if (string[k + 1][j + 7] != 'B') count++;
				}
				else {
					if (string[k][j] != 'W') count++;
					if (string[k][j + 1] != 'B') count++;
					if (string[k][j + 2] != 'W') count++;
					if (string[k][j + 3] != 'B') count++;
					if (string[k][j + 4] != 'W') count++;
					if (string[k][j + 5] != 'B') count++;
					if (string[k][j + 6] != 'W') count++;
					if (string[k][j + 7] != 'B') count++;

					if (string[k + 1][j] != 'B') count++;
					if (string[k + 1][j + 1] != 'W') count++;
					if (string[k + 1][j + 2] != 'B') count++;
					if (string[k + 1][j + 3] != 'W') count++;
					if (string[k + 1][j + 4] != 'B') count++;
					if (string[k + 1][j + 5] != 'W') count++;
					if (string[k + 1][j + 6] != 'B') count++;
					if (string[k + 1][j + 7] != 'W') count++;
				}
			}
			if (count > 32) {
				count = 64 - count;
			}
			result[i][j] = count;
			
			if (min > count) {
				min = count;
			}
			count = 0;
		}
	}

	for (int i = 0; i < height - 7; i++) {
		for (int j = 0; j < width - 7; j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	printf("%d", min);








	return 0;
}