#ifndef __SYS_TIME_H_
#define __SYS_TIME_H_

#include "../time.h"

typedef unsigned int suseconds_t;
struct timeval {
    time_t      tv_sec;
    suseconds_t tv_usec;
};

struct timezone {
    int tz_minuteswest;
    int tz_dsttime;
};

int gettimeofday(struct timeval *tv, struct timezone *tz);

struct itimerval {
    struct timeval it_interval;
    struct timeval it_value;
};
enum { ITIMER_REAL };
int getitimer(int which, struct itimerval *curr_value);

#endif
