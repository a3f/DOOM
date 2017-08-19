#include "stdlib.h"
#include "defs.h"
#include "string.h"

union header {
    struct {
        size_t len;
    } s;
    char pad[16];
};

extern void *brk(const void *addr);
extern void *sbrk(int incr);

unsigned int roundTo(unsigned int value, unsigned int roundTo)
{
    return (value + (roundTo - 1)) & ~(roundTo - 1);
}

#define ROUND_16B_BOUNDARY(x) ((x + 0xf) & ~0xf)

void *malloc(size_t size) {
    union header *header;
    unsigned char *ret = sbrk(ROUND_16B_BOUNDARY(size) + sizeof (union header));

    header = (union header *)ret;
    if (!ret)
        return NULL;

    ret += sizeof (union header);
    header->s.len = size;
    
    return ret;
}

static union header *mheader(void *ptr) {
    return (union header *)((char*)ptr - sizeof (union header));
}

void free(void *ptr) {
    if (!ptr) return;
    union header *hdr = mheader(ptr);
    if ((size_t)( (char*)sbrk(0) - (char*)ptr ) ==  hdr->s.len)
        brk(hdr);
}

void *realloc(void *ptr, size_t newsize) {
    void *newptr;

    if (!ptr)
        return malloc(newsize);

    free(ptr);
    newptr = malloc(newsize);

    if (!newptr)
        return NULL;

    union header *header = mheader(ptr);

    if (newptr != ptr) {
        size_t cpysize = header->s.len;
        if (cpysize > newsize) cpysize = newsize;
        memcpy(newptr, ptr, cpysize);
    }

    return newptr;
}
