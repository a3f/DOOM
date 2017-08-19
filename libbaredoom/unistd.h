#if __SYSTEM_UNISTD
#ifdef __GNUC__
#include_next <unistd.h>
#else
#error Requested System unistd, but include_next not available
#endif
#define __UNISTD_H_
#endif

#ifndef __UNISTD_H_

#include <stddef.h>

#ifndef SEEK_SET
#define SEEK_SET 0
#endif
#ifndef SEEK_END
#define SEEK_END 0
#endif

enum { X_OK, R_OK };

typedef unsigned short mode_t;
typedef unsigned int   uid_t;

#define access _access
#define read _read
#define close _close
#define fstat _fstat
#define lseek _lseek
#define setitimer _setitimer
#define write _write
#define gethostname _gethostname
#define getuid _getuid

int _access(const char *path, int mode);
int _read();
int _close();
int _fstat();
int _lseek();
int _setitimer();
int usleep();
int _write();
int _gethostname();
int gettimeofday();
uid_t _getuid();

#endif
