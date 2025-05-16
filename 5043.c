#include <stdio.h>
int main() {
	unsigned long long fileSize = 0;
	int maxBit = 0;
	scanf("%lld %d", &fileSize, &maxBit);

	int needBitSize = 0;
	while (fileSize != 0) {
		fileSize = fileSize / 2;
		needBitSize++;
	}

	if (needBitSize <= maxBit + 1) printf("yes\n");
	else printf("no\n");

	return 0;
}
