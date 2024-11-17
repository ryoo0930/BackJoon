//1308
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct date {
	int year;
	int month;
	int day;
};

int checkDay(struct date* date); // 일수 계산 함수
int checkMonth(struct date* date); // 월수 계산 함수
int checkYear(struct date* date); // 년수 계산 함수
int checkLeapyear(int year); // 윤년 확인 함수
int checkMonthDay(int month); // 월에 몇일 까지 있는지 확인하는 함수

int main(void) {
	struct date* date = (struct date*)calloc(2, sizeof(struct date));
	scanf("%d %d %d", &date[0].year, &date[0].month, &date[0].day); // 현재 날짜.
	scanf("%d %d %d", &date[1].year, &date[1].month, &date[1].day); // 목표 날짜.

	// 1000년 이상 차이 날때. =======================
	if (date[1].year - date[0].year > 1000 || (date[1].year - date[0].year == 1000 && (date[1].month > date[0].month || (date[1].month == date[0].month && date[1].day >= date[0].day)))) {
		printf("gg");
		return 0;
	}

	int result = 0;
	result += checkDay(date);
	result += checkMonth(date);
	result += checkYear(date);
	printf("D-%d", result);

	return 0;
}

int checkDay(struct date* date) {

	int result = 0;
	if (date[0].day < date[1].day) { // 현재 날짜의 Day가 목표 날짜의 Day보다 작을 때
		result = date[1].day - date[0].day;
	}
	else if (date[0].day > date[1].day) { // 월을 하나 넘겨야 할 때
		result = date[1].day - date[0].day;
		if (date[0].month == 2) { //2월달 일 때.
			if (checkLeapyear(date[0].year)) { // 윤년일 때의 2월달 (29일)
				result += 29;
			}
			else { // 윤년이 아닐 때의 2월달 (28일)
				result += 28;
			}
		}
		else {
			result += checkMonthDay(date[0].month);
		}
		date[0].month++;
		if (date[0].month > 12) { // 12월달이 넘어가는 경우
			date[0].year++;
			date[0].month = 1;
		}
	}

	
	return result;
}

int checkMonth(struct date* date) {
	int result = 0;
	if (date[0].month < date[1].month) { // 현재 월이 목표 월보다 작을 때.
		for (int i = date[0].month; i < date[1].month; i++) {
			if (i == 2) {
				if (checkLeapyear(date[0].year)) {
					result += 29;
				}
				else {
					result += 28;
				}
			}
			else {
				result += checkMonthDay(i);
			}
		}
	}
	else if (date[0].month > date[1].month) {
		while (1) {
			if (date[0].month == date[1].month) {
				break;
			}

			if (date[0].month == 2) {
				if (checkLeapyear(date[0].year)) {
					result += 29;
				}
				else {
					result += 28;
				}
			}
			else {
				result += checkMonthDay(date[0].month);
			}

			date[0].month++;
			if (date[0].month == 13) {
				date[0].month = 1;
				date[0].year++;
			}
		}
	}
	return result;
}

int checkYear(struct date* date) {
	int result = 0;
	while (date[0].year < date[1].year) {
		if (checkLeapyear(date[0].year)) {
			result += 366; // 윤년일 때.
		}
		else {
			result += 365; // 윤년이 아닐 때.
		}
		date[0].year++;
	}
	return result;
}

int checkLeapyear(int year) {
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
		return 1; // 윤년
	}
	return 0; // 평년
}

int checkMonthDay(int month) {

	if (month <= 7) {
		if (month % 2 == 1) {
			return 31; // 1, 3, 5, 7월
		}
		else {
			return 30; // 2, 4, 6월
		}
	}
	else {
		if (month % 2 == 1) {
			return 30; // 9, 11월
		}
		else {
			return 31; // 8, 10, 12월
		}
	}
}
 