#include <stdio.h>
#include <string.h>

void find(char *dest, char *src) {
    char *ptr1 = src;
    unsigned int maxLen = 0;
    char *maxStart = NULL;

    while (*ptr1 != 0) {
        char *ptr2 = ptr1;
        char hashTable[256] = {0};

        while (*ptr2 != 0 && !hashTable[*ptr2]) {
            hashTable[*ptr2] = 1;
            ptr2++;
        }

        if (ptr2 - ptr1 > maxLen) {
            maxLen = ptr2 - ptr1;
            maxStart = ptr1;
        }

        ptr1++;
    }

    strncpy(dest, maxStart, maxLen);
    dest[maxLen] = 0;
}


int main() {
    char source[256] = {0};
    char dest[256] = {0};

    scanf("%[^\n]", source);

    find(dest, source);

    printf("%s\n", dest);

    return 0;
}