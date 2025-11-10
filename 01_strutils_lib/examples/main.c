#include <stdio.h>
#include "strutils.h"

int main() {
    char s1[] = "  Hello Embedded Linux  ";
    char s2[50];

    printf("Chuỗi ban đầu: '%s'\n", s1);

    str_trim(s1);
    printf("Sau khi trim: '%s'\n", s1);

    str_reverse(s1);
    printf("Sau khi đảo ngược: '%s'\n", s1);

    str_copy_safe(s2, "BeagleBone Black", sizeof(s2));
    printf("Copy an toàn: '%s'\n", s2);

    return 0;
}
