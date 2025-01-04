#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void changeHour(int hour);
void changeMinute(int minute);

int main(void) {
    int hour, minute;
    scanf("%d %d", &hour, &minute);
    
    if (minute == 0) { changeHour(hour); printf(" o' clock"); }
    else if (minute <= 30) {
        changeMinute(minute);
        printf(" past ");
        changeHour(hour);
    }
    else {
        hour++; if (hour == 13) { hour = 1; }
        changeMinute(60 - minute);
        printf(" to ");
        changeHour(hour);
    }
    return 0;
}

void changeHour(int hour) {
    switch (hour) {
    case 1:
        printf("one");
        break;
    case 2:
        printf("two");
        break;
    case 3:
        printf("three");
        break;
    case 4:
        printf("four");
        break;
    case 5:
        printf("five");
        break;
    case 6:
        printf("six");
        break;
    case 7:
        printf("seven");
        break;
    case 8:
        printf("eight");
        break;
    case 9:
        printf("nine");
        break;
    case 10:
        printf("ten");
        break;
    case 11:
        printf("eleven");
        break;
    case 12:
        printf("twelve");
        break;
    }
}

void changeMinute(int minute) {
    switch (minute) {
    case 1:
        printf("one minute");
        break;
    case 2:
        printf("two minutes");
        break;
    case 3:
        printf("three minutes");
        break;
    case 4:
        printf("four minutes");
        break;
    case 5:
        printf("five minutes");
        break;
    case 6:
        printf("six minutes");
        break;
    case 7:
        printf("seven minutes");
        break;
    case 8:
        printf("eight minutes");
        break;
    case 9:
        printf("nine minutes");
        break;
    case 10:
        printf("ten minutes");
        break;
    case 11:
        printf("eleven minutes");
        break;
    case 12:
        printf("twelve minutes");
        break;
    case 13:
        printf("thirteen minutes");
        break;
    case 14:
        printf("fourteen minutes");
        break;
    case 15:
        printf("quarter");
        break;
    case 16:
        printf("sixteen minutes");
        break;
    case 17:
        printf("seventeen minutes");
        break;
    case 18:
        printf("eighteen minutes");
        break;
    case 19:
        printf("nineteen minutes");
        break;
    case 20:
        printf("twenty minutes");
        break;
    case 21:
        printf("twenty one minutes");
        break;
    case 22:
        printf("twenty two minutes");
        break;
    case 23:
        printf("twenty three minutes");
        break;
    case 24:
        printf("twenty four minutes");
        break;
    case 25:
        printf("twenty five minutes");
        break;
    case 26:
        printf("twenty six minutes");
        break;
    case 27:
        printf("twenty seven minutes");
        break;
    case 28:
        printf("twenty eight minutes");
        break;
    case 29:
        printf("twenty nine minutes");
        break;
    case 30:
        printf("half");
        break;
    }
}
