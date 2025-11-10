#ifndef STRUTILS_H
#define STRUTILS_H

/* Đảo ngược chuỗi*/
void str_reverse(char *str);

/* Loại bỏ khoảng trắng và đầu cuối*/
void str_trim(char *str);

/* Đảm bảo an toàn khi copy chuỗi */
void str_copy_safe(char *dest, const char *src, int max_len);

#endif