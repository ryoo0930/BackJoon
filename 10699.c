//10699
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

void SelectionSort(int arr[], int size);

int main(void) {
	time_t orgtime;
	struct tm* pTimeData;

	orgtime = time(NULL);
	pTimeData = localtime(&orgtime);


	printf("%d-%02d-%02d", pTimeData->tm_year + 1900, pTimeData->tm_mon + 1, pTimeData->tm_mday);

	return 0;
}