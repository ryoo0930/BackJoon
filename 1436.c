//1436
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int num = 0;
	scanf("%d", &num);
	int count = 0;

	int num2 = 666; // 1��° ����
	while (1)
	{
		//������ �ڸ��� ���ϱ�
		int cnt = 0; // cnt = ������ �ڸ���.
		int n = num2;
		while (n != 0) {
			n = n / 10;
			cnt++;
		}


		char* string = (char*)malloc(sizeof(char) * (cnt + 1));
		sprintf(string, "%d", num2);

		if (strstr(string, "666") != NULL) {
			count++;
			if (num == count) {
				printf("%s", string);
				break;
			}
		}
		num2++;
	}

	return 0;
}