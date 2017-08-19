#ifndef __STRING_H_
#define __STRING_H_

#include <stddef.h>

int strcasecmp(const char *s1, const char *s2);
char *strcat(const char *s1, const char *s2);
int strcmp(const char *s1, const char *s2);
char *strerror();
size_t strlen(const char *s);
int strncasecmp(const char *s1, const char *s2, size_t len);
int strncmp(const char *s1, const char *s2, size_t len);
char *strcpy(char *s1, const char *s2);
char *strncpy(char *s1, const char *s2, size_t len);

void *memcpy(void *dst, const void *src, size_t len);
void *memset(void *dst, int ch, size_t len);

#endif
