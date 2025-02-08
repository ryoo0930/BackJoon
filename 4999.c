#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char string1[1001];
    char string2[1001];
    scanf("%s", string1);
    scanf("%s", string2);
    
    if(strlen(string1) < strlen(string2)) printf("no");
    else printf("go");
    
    return 0;
}
