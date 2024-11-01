//11718
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char string[101];
	while (gets(string) != '\0') {

		printf("%s\n", string);
		
		
		for (int i = 0; i < strlen(string); i++) {
			string[i] = '\0';
		}
	}
	return 0;
}