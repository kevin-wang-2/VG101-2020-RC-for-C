#include <stdio.h>

int main() {
    unsigned int x = 0x00636261;

    printf("%s\n", (char *)(&x));
    return 0;
}