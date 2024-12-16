#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int height, width;
    scanf("%d %d", &height, &width);

    char arr[51][51];
    for (int i = 0; i < height; i++) { scanf("%s", arr[i]); }

    int maximum = 1;
    for (int i = 0; i < height - 1; i++) {
        for (int j = 0; j < width - 1; j++) {
            for (int k = j + 1; k < width; k++) {
                if (arr[i][j] == arr[i][k]) {
                    int distance = k - j;
                    if (i + distance < height && arr[i + distance][j] == arr[i][j] && arr[i + distance][k] == arr[i][j]) {
                        int temp_sqare = (distance + 1) * (distance + 1);
                        if (maximum < temp_sqare) { maximum = temp_sqare; }
                    }
                }
            }
        }
    }
    printf("%d", maximum);

    return 0;
}
