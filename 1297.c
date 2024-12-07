#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	float D = 0, H = 0, W = 0;
	scanf("%f %f %f", &D, &H, &W);

	double temp = sqrt((H * H) + (W * W));
	int resultH = (int)((D * H) / temp);
	int resultW = (int)((D * W) / temp);
	printf("%d %d", resultH, resultW);

	return 0;
}
