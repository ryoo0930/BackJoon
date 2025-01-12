#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char plaintext[30001], ciphertext[30001];
	char key[30001];

	gets(plaintext);
	gets(key);

	int lenP = strlen(plaintext);
	int lenC = strlen(key);

	int index = 0;
	for (index = 0; index < lenP; index++) {
		if (plaintext[index] == ' ') { ciphertext[index] = ' '; continue; }
		ciphertext[index] = plaintext[index] - (key[index % lenC] - 'a' + 1);
		if (ciphertext[index] < 97) { ciphertext[index] += 26; }
	}
	ciphertext[index] = '\0';

	printf("%s", ciphertext);
	return 0;
}
