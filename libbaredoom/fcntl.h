#ifndef __FCNTL_H_
#define __FCNTL_H_

enum { O_WRONLY, O_RDONLY, O_CREAT, O_TRUNC, O_BINARY };
#define open _open
int _open(const char *path, int oflag, ...);

#endif
