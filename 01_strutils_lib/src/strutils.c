#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "strutils.h"

void str_reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void str_trim(char *str) {
    int start = 0, end = strlen(str) - 1;
    while (isspace((unsigned char)str[start])) start++;
    while (end > start && isspace((unsigned char)str[end])) end--;
    str[end + 1] = '\0';
    memmove(str, str + start, end - start + 2);
}

void str_copy_safe(char *dest, const char *src, int max_len) {
    strncpy(dest, src, max_len - 1);
    dest[max_len - 1] = '\0';
}
