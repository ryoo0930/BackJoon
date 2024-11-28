#include <stdio.h>

#define MAXSIZE 1000000

int stack[MAXSIZE] = { 0 };
int top = -1;

void f1(int value);
int f2();
int f3();
int f4();
int f5();


int main(void) {
    int testCase = 0;
    scanf("%d", &testCase);
    for (int t = 0; t < testCase; t++) {
        int function = 0, value = 0;
        scanf("%d", &function);
        switch (function) {
            case 1:
                scanf("%d", &value);
                f1(value);
                break;
            case 2:
                printf("%d\n", f2());
                break;
            case 3:
                printf("%d\n", f3());
                break;
            case 4:
                printf("%d\n", f4());
                break;
            case 5:
                printf("%d\n", f5());
                break;
            }
    }
    return 0;
}

void f1(int value) {
    stack[++top] = value;
}
int f2() {
    if (top == -1) {
        return -1;
    }
    else {
        return stack[top--];
    }
}
int f3() {
    return top + 1;
}
int f4() {
    if (top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}
int f5(){
    if (top == -1) {
        return -1;
    }
    else {
        return stack[top];
    }
}
