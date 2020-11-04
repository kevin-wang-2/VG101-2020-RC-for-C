#include <stdio.h>

int *initializePointer(int value) {
    int *ret = &value;
    return ret;
}

int main() {
    int *ptr1 = initializePointer(100);
    int *ptr2 = initializePointer(1000);

    printf("%d\n", *ptr1);

    return 0;
}