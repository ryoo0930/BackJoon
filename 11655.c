#include <stdio.h>
#include <string.h>

int main(void) {
    char string[101];
    gets(string);

    int len = strlen(string);

    for (int i = 0; i < len; i++) {
        if (string[i] >= 'A' && string[i] < 'N') {
            string[i] = string[i] + 13;
        }
        else if (string[i] >= 'N' && string[i] <= 'Z') {
            string[i] = string[i] % 78 + 'A';
        }

        else if (string[i] >= 'a' && string[i] < 'n') {
            string[i] = string[i] + 13;
        }
        else if (string[i] >= 'n' && string[i] <= 'z') {
            string[i] = string[i] % 110 + 'a';
        }
    }
    
    printf("%s", string);

    return 0;
}
