#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void* a, const void* b);
int checkValue(char* birthday, char* targetDate);

int main(void) {
    char birthday[9];
    scanf("%s", birthday); getchar();

    int dateSize = 0;
    scanf("%d", &dateSize);

    char** date = (char**)malloc(sizeof(char*) * dateSize);
    for (int i = 0; i < dateSize; i++) { date[i] = (char*)malloc(sizeof(char) * 9); }
    for (int i = 0; i < dateSize; i++) { scanf("%s", date[i]); }

    qsort(date, dateSize, sizeof(char*), compare);
    
    int maxValue = 0;
    int index;
    for (int i = 0; i < dateSize; i++) {
        int codingBiorhythm = checkValue(birthday, date[i]);
        if (codingBiorhythm > maxValue) { maxValue = codingBiorhythm; index = i; }
    }

    printf("%s", date[index]);

    for (int i = 0; i < dateSize; i++) { free(date[i]); }
    free(date);

    return 0;
}

int compare(const void* a, const void* b) {
    int num1 = atoi(*(const char**)a);
    int num2 = atoi(*(const char**)b);
    return (num1 > num2) - (num1 < num2);
}

int checkValue(char* birthday, char* targetDate) {
    int result = 1; int i = 0;
    int tempResult;
    tempResult = 0;
    for (i; i < 4; i++) {
        int value1 = birthday[i] - '0';
        int value2 = targetDate[i] - '0';

        int biorhythm = (int)pow((float)(value1 - value2), 2);
        tempResult += biorhythm;
    }
    result *= tempResult;
    
    tempResult = 0;
    for (i; i < 6; i++) {
        int value1 = birthday[i] - '0';
        int value2 = targetDate[i] - '0';

        int biorhythm = (int)pow((float)(value1 - value2), 2);
        tempResult += biorhythm;
    }
    result *= tempResult;
    
    tempResult = 0;
    for (i; i < 8; i++) {
        int value1 = birthday[i] - '0';
        int value2 = targetDate[i] - '0';

        int biorhythm = (int)pow((float)(value1 - value2), 2);
        tempResult += biorhythm;
    }
    result *= tempResult;

    return result;
}
