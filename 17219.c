//17219
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data {
	char site[21];
	char password[21];
};

unsigned long hash(const char* str) { // djb2 Hash
	unsigned long hash = 5381;
	int c;

	while ((c = *str++)) {
		hash = ((hash << 5) + hash) + c; // hash * 33 + c
	}

	return hash;
}

int main(void) {
	int siteSize = 0, researchSize = 0;
	scanf("%d %d", &siteSize, &researchSize);
	getchar();

	struct data* site = (struct data*)calloc(siteSize * 2, sizeof(struct data));
	for (int i = 0; i < siteSize; i++) { // 사이트 입력. { 사이트 주소, 비밀번호 }
		char tmpsite[21] = { 0 };
		char tmppassword[21] = { 0 };
		scanf("%s %s", &tmpsite, &tmppassword);
		unsigned int index = hash(tmpsite) % (2 * siteSize);
		while (site[index].site[0] != '\0') { // 이미 값이 있다면 충돌
			index = (index + 1) % (siteSize * 2);  // 선형 탐사로 다음 위치 확인
		}
		strcpy(site[index].site, tmpsite);
		strcpy(site[index].password, tmppassword);
	}

	for (int i = 0; i < researchSize; i++) {
		char tmpsite[21] = { 0 };
		scanf("%s", &tmpsite);
		unsigned int index = hash(tmpsite) % (2 * siteSize);
		while (strcmp(site[index].site, tmpsite) != 0) {
			index = (index + 1) % (siteSize * 2);
		}
		printf("%s\n", site[index].password);
	}

	return 0;
}