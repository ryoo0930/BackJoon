//28235
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	int string[10] = { 0 };
	scanf("%s", &string);
	
	if (strcmp(string, "SONGDO") == 0) {
		printf("HIGHSCHOOL");
	}
	else if (strcmp(string, "CODE") == 0) {
		printf("MASTER");
	}
	else if (strcmp(string, "2023") == 0) {
		printf("0611");
	}
	else if (strcmp(string, "ALGORITHM") == 0) {
		printf("CONTEST");
	}

	return 0;
}