#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char grade[3];
    scanf("%s", grade);

    if (strcmp(grade, "A+") == 0) { printf("4.3"); }
    else if (strcmp(grade, "A0") == 0) { printf("4.0"); }
    else if (strcmp(grade, "A-") == 0) { printf("3.7"); }
    else if (strcmp(grade, "B+") == 0) { printf("3.3"); }
    else if (strcmp(grade, "B0") == 0) { printf("3.0"); }
    else if (strcmp(grade, "B-") == 0) { printf("2.7"); }
    else if (strcmp(grade, "C+") == 0) { printf("2.3"); }
    else if (strcmp(grade, "C0") == 0) { printf("2.0"); }
    else if (strcmp(grade, "C-") == 0) { printf("1.7"); }
    else if (strcmp(grade, "D+") == 0) { printf("1.3"); }
    else if (strcmp(grade, "D0") == 0) { printf("1.0"); }
    else if (strcmp(grade, "D-") == 0) { printf("0.7"); }
    else if (strcmp(grade, "F") == 0) { printf("0.0"); }

    return 0;
}
