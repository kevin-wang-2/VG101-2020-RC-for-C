#include <stdio.h>

int add(int a, int b) {
    int c = a + b;
    return c;
}

int main() {
    int p = 1;
    int q = 2;

    int r = add(p, q);
    printf("%d\n", r);
    return 0;
}