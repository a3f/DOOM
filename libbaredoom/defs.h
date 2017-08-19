#ifndef __DEFS_H_
#define __DEFS_H_

#include <stddef.h>
#include <assert.h>

#ifdef __GNUC__
#define _U_ __attribute__((unused))
#else
#define _U_
#endif

#ifndef __abort
#define __abort() assert(0);
#endif

#define __deadcode { __abort(); }
#define __nop { }

#if __STDC_VERSION__ >= 201112L
#define __noreturn _Noreturn
#elif __GNUC__
#define __noreturn __attribute__((__noreturn__))
#else
#define __noreturn
#endif

#endif
