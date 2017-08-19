#ifndef __ALLOCA_H_
#define __ALLOCA_H_

#ifdef __GNUC__
#define alloca(n) __builtin_alloca(n)
#elif __STDC_VERSION__ >= 199901L && !__STDC_NO_VLA__   
/* Could we mimic alloca with VLA but no GNU statement expressions? */
#define alloca(n) ((void*)0)
#else
/* We could mimic alloca using free(stale_alloca) + malloc.
 * A stale a alloca is one deeper in stack than the one we
 * are handling right now
 */
#define alloca(n) ((void*)0)
#endif

#endif
