#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main() {
	int size = 0, room_MAX = 0;
	scanf("%d %d", &size, &room_MAX);

	int Boy[6] = { 0, }, Girl[6] = { 0, };
	for (int i = 0; i < size; i++) {
		int gender = 0, grade = 0;
		scanf("%d %d", &gender, &grade);
		if (gender == 0) { Girl[grade - 1]++; }
		else if (gender == 1) { Boy[grade - 1]++; }
	}

	int result = 0;
	for (int i = 0; i < 6; i++) {
		result += Girl[i] / room_MAX;
		result += Boy[i] / room_MAX;
		if (Girl[i] % room_MAX != 0) result++;
		if (Boy[i] % room_MAX != 0) result++;
	}

	printf("%d", result);


	return 0;
}
