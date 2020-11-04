#include <stdio.h>

int main() {
    char str[] = "Hello World!";

    printf("%s\n", (char *)((int *)str + 1) + 2);
    return 0;
}