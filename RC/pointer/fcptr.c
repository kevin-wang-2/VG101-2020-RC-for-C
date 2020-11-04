#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int p = 1;
    int q = 2;

    swap(&p, &q);
    printf("%d %d\n", p, q);

    return 0;
}