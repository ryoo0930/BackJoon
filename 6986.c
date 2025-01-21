#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);

int main() {
	int N = 0, K = 0;
	scanf("%d %d", &N, &K);

	double* arr = (double*)malloc(sizeof(double) * N);
	for (int i = 0; i < N; i++) { scanf("%lf", &arr[i]); }
	qsort(arr, N, sizeof(double), compare);

	//절사 평균
	double Trimmed_mean = 0;
	for (int i = K; i < N - K; i++) { Trimmed_mean += arr[i]; }
	Trimmed_mean = Trimmed_mean / (N - (2 * K));
	printf("%.2lf\n", Trimmed_mean + 0.00000001); // 부동 소수점 오차

	//보정 평균
	for (int i = 0; i < K; i++) { arr[i] = arr[K]; } // 좌측
	for (int i = N - K; i < N; i++) { arr[i] = arr[N - K - 1]; } // 우측

	double Adjusted_mean = 0;
	for (int i = 0; i < N; i++) { Adjusted_mean += arr[i]; }
	Adjusted_mean = Adjusted_mean / N;
	printf("%.2lf\n", Adjusted_mean + 0.00000001);

	free(arr);
	return 0;
}

int compare(const void* a, const void* b) {
	double diff = *(double*)a - *(double*)b;
	if (diff < 0) return -1;
	if (diff > 0) return 1;
	else return 0;
}
