#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int sumDigits(int num) {
	int sum = 0;
	while (num > 0) {
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

int main()
{	
	char number[1000001];
	scanf("%s", &number);

	int sum = 0, count = 0;
	if (!number[1] == '\0') {
		for (int i = 0; number[i] != '\0'; i++) {
			sum += number[i] - '0';
		}
		count++;

		while ((sum / 10) != 0) {
			count++;
			sum = sumDigits(sum);
		}
	}
	else {
		sum = number[0] - '0';
	}

	printf("%d\n", count);
	if (sum % 3 == 0) printf("YES");
	else printf("NO");
	
}
