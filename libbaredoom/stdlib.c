#include "stdlib.h"

int atoi(const char *str) {
    int ret = 0;
    char *c = (char *)str;
    if (*c == '-') c++;
    for (; '0' <= *c && *c <= '9'; c++)
        ret = (ret * 10) + (*c - '0');

    return *str == '-' ? -ret : ret;
}

int abs(int i) {
    return i >= 0 ? i : -i;
}

char *_getenv() { return ""; }
