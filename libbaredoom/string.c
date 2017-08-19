#include "string.h"
#include "ctype.h"

char *strcat(const char *s1, const char *s2)
{
    size_t len = strlen(s1);
    return strcpy((char*)s1+len, s2);
        
}
int strcmp(const char *s1, const char *s2)
{
    while (*s1 == *s2++)
        if (!*s1++) return 0;

    return *(const unsigned char *)s1 - *(const unsigned char *)--s2;

}
int strncmp(const char *s1, const char *s2, size_t len)
{
    while (len--) {
        if (*s1 != *s2++)
            return *(const unsigned char *)s1 - *(const unsigned char *)--s2;

        if (!*s1++) break;
    }

    return 0;
}
int strcasecmp(const char *s1, const char *s2)
{
    while (toupper(*s1) == toupper(*s2++))
        if (!*s1++) return 0;

    return (unsigned char)toupper(*s1) - (unsigned char)toupper(*--s2);
}
int strncasecmp(const char *s1, const char *s2, size_t len)
{
    while (len--) {
        if (toupper(*s1) != toupper(*s2++))
            return (unsigned char)toupper(*s1) - (unsigned char)toupper(*--s2);

        if (!*s1++) break;
    }

    return 0;
}
char *strcpy(char *dst, const char *src)
{
	char *ret = dst;

    while((*dst++ = *src++))
        ;

	return ret;
}
char *strncpy(char *dst, const char *src, size_t len)
{
    char *ret = dst;

    for (; len; len--) {
        if (!(*dst++ = *src++)) {
            while (--len) *dst++ = '\0';

            break;
        }
    }

	return ret;
}
size_t strlen(const char *s)
{
    size_t len = 0;
    while (*s++) len++;
    return len;
}
void *memset(void *_dst, int ch, size_t len)
{
    unsigned char *dst = _dst;

    while (len--)
        *dst++ = (unsigned char)ch;

    return _dst;
}

int memcmp(const void *_s1, const void *_s2, size_t len)
{
	const unsigned char *s1 = _s1, *s2 = _s2;
	
    while (len--) {
        unsigned char ch1 = *s1++,
                      ch2 = *s2++;
        if (ch1 != ch2)
            return ch1 - ch2;
    }

    return 0;
}

void *memcpy(void *_dst, const void *_src, size_t len)
{
	      unsigned char *dst = _dst;
	const unsigned char *src = _src;

	if (!len) return _dst;

    size_t n = (len + 7) >> 3;
    switch (len & 7) {
    case 0: do { *dst++ = *src++;
    case 7:      *dst++ = *src++;
    case 6:      *dst++ = *src++;
    case 5:      *dst++ = *src++;
    case 4:      *dst++ = *src++;
    case 3:      *dst++ = *src++;
    case 2:      *dst++ = *src++;
    case 1:      *dst++ = *src++;
            } while (--n);
    }

	return _dst;
}
int toupper(int ch)
{
    if ('a' <= ch && ch <= 'z')
        ch ^= 0x20;
    
    return ch;
}

//! describe socket error in multiplayer
char *strerror() { return ""; }
