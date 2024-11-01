//5622
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char string[16];
	gets(string);

	int time = 0;
	for (int i = 0; i < strlen(string); i++) {
		if (string[i] == 65 || string[i] == 66 || string[i] == 67) { //ABC
			time += 3;
		}
		if (string[i] == 68 || string[i] == 69 || string[i] == 70) { //DEF
			time += 4;
		}
		if (string[i] == 71 || string[i] == 72 || string[i] == 73) { //GHI
			time += 5;
		}
		if (string[i] == 74 || string[i] == 75 || string[i] == 76) { //JKL
			time += 6;
		}
		if (string[i] == 77 || string[i] == 78 || string[i] == 79) { //MNO
			time += 7;
		}
		if (string[i] == 80 || string[i] == 81 || string[i] == 82 || string[i] == 83) { //PQRS
			time += 8;
		}
		if (string[i] == 84 || string[i] == 85 || string[i] == 86) { //TUV
			time += 9;
		}
		if (string[i] == 87 || string[i] == 88 || string[i] == 89 || string[i] == 90) { //WXYZ
			time += 10;
		}
	}

	printf("%d", time);

	return 0;
}