#ifndef __STDLIB_H_
#define __STDLIB_H_

#include "defs.h"

int atoi(const char *str);

int abs(int i);

__noreturn void exit(int ret);
void *malloc(size_t);
void *realloc(void *ptr, size_t size);

//#define getenv _getenv
char *_getenv();
char *getenv();

#define exit(ret) do { volatile int __exit = ret / (volatile int)0; } while (0)

#endif
