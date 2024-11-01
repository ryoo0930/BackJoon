//1152
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(void) {
	char string[1000000];
	gets(string);

	int count = 0;
	if (isspace(string[0]) != 0) {
		count--;
	}
	if (isspace(string[strlen(string) - 1]) != 0) {
		count--;
	}


	for (int i = 0; i < strlen(string); i++) {
		if (isspace(string[i]) != 0) {
			count++;
		}
	}
	printf("%d", count + 1);
	return 0;
}