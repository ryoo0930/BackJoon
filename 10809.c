//10809
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main(void) {
	char string[100];
	scanf("%s", &string);

	for (int i = 97; i < 123; i++) {
		for (int j = 0; j < strlen(string); j++) {
			if (i == string[j]) {
				printf("%d ", j);
				break;
			}
			else if (j == strlen(string) - 1) {
				printf("-1 ");
				break;
			}
		}
	}


	return 0;
}