//2745
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void) {
	char string[40];
	gets(string);

	int checkSpace = 0;
	int len = strlen(string);
	for (int i = 0; i < len; i++) {
		if (string[i] == ' ') {
			checkSpace = i;
			break;
		}
	}

	char number[32] = { 0 };
	char Cnumeral[3] = { 0 };
	int Inumeral = 0;
	for (int i = 0; i < checkSpace; i++) {
		number[i] = string[i];
	}
	for (int i = 0; i < 2; i++) {
		Cnumeral[i] = string[checkSpace + i + 1];
	}

	Inumeral = atoi(Cnumeral);

	int newlen = strlen(number);
	int num_10 = 0;

	for (int i = 0; i < newlen; i++) {
		if (number[i] >= 'A') {
			int Ipow = pow(Inumeral, newlen - i - 1);
			num_10 += (number[i] - 55) * Ipow;

		}
		else {
			int Ipow = pow(Inumeral, newlen - i - 1);
			num_10 += (number[i] - 48) * Ipow;
		}
	}


	printf("%d", num_10);

	return 0;
}