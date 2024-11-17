//1308
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct date {
	int year;
	int month;
	int day;
};

int checkDay(struct date* date); // �ϼ� ��� �Լ�
int checkMonth(struct date* date); // ���� ��� �Լ�
int checkYear(struct date* date); // ��� ��� �Լ�
int checkLeapyear(int year); // ���� Ȯ�� �Լ�
int checkMonthDay(int month); // ���� ���� ���� �ִ��� Ȯ���ϴ� �Լ�

int main(void) {
	struct date* date = (struct date*)calloc(2, sizeof(struct date));
	scanf("%d %d %d", &date[0].year, &date[0].month, &date[0].day); // ���� ��¥.
	scanf("%d %d %d", &date[1].year, &date[1].month, &date[1].day); // ��ǥ ��¥.

	// 1000�� �̻� ���� ����. =======================
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
	if (date[0].day < date[1].day) { // ���� ��¥�� Day�� ��ǥ ��¥�� Day���� ���� ��
		result = date[1].day - date[0].day;
	}
	else if (date[0].day > date[1].day) { // ���� �ϳ� �Ѱܾ� �� ��
		result = date[1].day - date[0].day;
		if (date[0].month == 2) { //2���� �� ��.
			if (checkLeapyear(date[0].year)) { // ������ ���� 2���� (29��)
				result += 29;
			}
			else { // ������ �ƴ� ���� 2���� (28��)
				result += 28;
			}
		}
		else {
			result += checkMonthDay(date[0].month);
		}
		date[0].month++;
		if (date[0].month > 12) { // 12������ �Ѿ�� ���
			date[0].year++;
			date[0].month = 1;
		}
	}

	
	return result;
}

int checkMonth(struct date* date) {
	int result = 0;
	if (date[0].month < date[1].month) { // ���� ���� ��ǥ ������ ���� ��.
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
			result += 366; // ������ ��.
		}
		else {
			result += 365; // ������ �ƴ� ��.
		}
		date[0].year++;
	}
	return result;
}

int checkLeapyear(int year) {
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
		return 1; // ����
	}
	return 0; // ���
}

int checkMonthDay(int month) {

	if (month <= 7) {
		if (month % 2 == 1) {
			return 31; // 1, 3, 5, 7��
		}
		else {
			return 30; // 2, 4, 6��
		}
	}
	else {
		if (month % 2 == 1) {
			return 30; // 9, 11��
		}
		else {
			return 31; // 8, 10, 12��
		}
	}
}
 