#ifndef __SIGNAL_H_
#define __SIGNAL_H_

typedef void (*sig_t) (int);
#define SIG_DFL ((sig_t)0)

enum {SIGINT, SIGALRM};
enum {SA_RESTART};

#define signal _signal
sig_t _signal(int sig, sig_t func);

struct _sigaction {
    sig_t sa_handler;
    int sa_flags;
};

#define sigaction _sigaction
int _sigaction();

#define setitimer _setitimer
int _setitimer();

#endif
