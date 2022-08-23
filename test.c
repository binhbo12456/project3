#include<stdio.h>
#include <stdlib.h>

int main() {
    // Converting a numeric string
    char str[10];
    scanf("%s", str);
    int x = atoi(str);
    printf("Converting '122': %d\n", x);

    // Converting an alphanumeric string
    char str2[10] = "Hello!";
    x = atoi(str2);
    printf("Converting 'Hello!': %d\n", x);

    // Converting a partial string
    char str3[10] = "99Hello!";
    x = atoi(str3);
    printf("Converting '99Hello!': %d\n", x);
    return 0;
}