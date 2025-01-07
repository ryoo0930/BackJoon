#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int fileSize = 0;
    scanf("%d", &fileSize);

    char** file = (char**)malloc(sizeof(char*) * fileSize);
    for (int i = 0; i < fileSize; i++) { file[i] = (char*)malloc(sizeof(char) * 51); }

    for (int i = 0; i < fileSize; i++) { scanf("%s", file[i]); }

    int len = strlen(file[0]); int index = 0;
    char researchName[51];
    for (index = 0; index < len; index++) {
        for (int i = 0; i < fileSize - 1; i++) {
            if (file[i][index] != file[i + 1][index]) { researchName[index] = '?'; break; }
        }
        if (researchName[index] != '?') { researchName[index] = file[0][index]; }
    }

    researchName[index] = '\0';
    printf("%s", researchName);

    for (int i = 0; i < fileSize; i++) { free(file[i]); }
    free(file);
    return 0;
}
