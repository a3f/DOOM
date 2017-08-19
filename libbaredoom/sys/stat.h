#ifndef __SYS_STAT_H_
#define __SYS_STAT_H_

#define mkdir _mkdir
int _mkdir();
struct stat {
    int st_size;
};

#define fstat _fstat
int _fstat(int fd, struct stat *stat);

#endif
