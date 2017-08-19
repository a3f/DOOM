#ifndef __SYS_SHM_H_
#define __SYS_SHM_H_

#include "types.h"
#include "time.h"
#include <stddef.h>

void *shmat();
int shmctl();
int shmdt();
int shmget();

typedef unsigned shmatt_t;

struct shmid_ds {
    struct ipc_perm
    {
        key_t  key;
        unsigned short uid;   /* owner euid and egid */
        unsigned short gid;
        unsigned short cuid;  /* creator euid and egid */
        unsigned short cgid;
        unsigned short mode;  /* access modes see mode flags below */
        unsigned short seq;   /* slot usage sequence number */
    } shm_perm;

    size_t          shm_segsz;   /* Size of segment (bytes) */
    time_t          shm_atime;   /* Last attach time */
    time_t          shm_dtime;   /* Last detach time */
    time_t          shm_ctime;   /* Last change time */
    pid_t           shm_cpid;    /* PID of creator */
    pid_t           shm_lpid;    /* PID of last shmat(2)/shmdt(2) */
    shmatt_t        shm_nattch;  /* No. of current attaches */

};


#endif
