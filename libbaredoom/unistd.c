#ifndef __SYSTEM_UNISTD
#include "unistd.h"
#include "stdio.h"
#include "defs.h"
#include "signal.h"
#include "string.h"
#include "WAD.h"
#include "sys/stat.h"

static struct fd {
    unsigned offset;
    enum type { NONE, DSP_FILE, SAVEGAME_FILE, WAD_FILE, DEMO_FILE, SCREENSHOT_FILE } type;
} fds[16];
size_t next_fd = 0;

static const char *strcaseendswith(const char *str, size_t len, const char *end)
{
    int end_off = len - strlen(end);
    if (end_off < 0)
        return NULL;

    return strcasecmp(str + end_off, end) == 0 ? str + end_off : NULL;
}

//! checks existence of sndserver, screenshots and WAD
int _access(const char *path, int mode _U_)
{
    size_t len = strlen(path);
    if (strcaseendswith(path, len, ".pcx"))
        return 0; // we allow screenshots but don't write them

    if (strcaseendswith(path, len, WAD_NAME))
        return 0;

    return -1;
}

/**
 * Open Savegames
 * Reopen WAD when working with development map
 * Open savefiles
 * Open demos
 * Open screenshots
 */
int _open(const char *path, int oflag _U_, ...)
{
    enum type type = NONE;
    size_t len = strlen(path);
#if 0
    if (strcaseendswith(path, len, ".dsg"))
        type = SAVEGAME_FILE;
    else
#endif
    if (strcaseendswith(path, len, ".wad"))
        type = WAD_FILE;

    if (!type) return -1;

    if (next_fd == sizeof(fds))
        next_fd = 0;

    if (fds[next_fd].type) {
        for (; next_fd < sizeof fds / sizeof fds[0]; next_fd++)
            if (!fds[next_fd].type) goto found_spare;

        return -1;
    }

found_spare:
    fds[next_fd].type = type;
    fds[next_fd].offset = 0;

    //printf("opening %s at %d\n", path, (int)next_fd);
    return next_fd++;
}

//! close aforementioned opened files
int _close(int fd)
{
    if (fd == -1) return -1;
    
    fds[fd].type = NONE;
}

//! seek around in WAD file
int _lseek(int fd _U_, int where, int whence _U_) {
    //printf("seeking to %i in fd %d.\n", where, fd);
    return fds[fd].offset = where;
}

//! read savegames and WAD
int _read(int fd_idx, void *buf, size_t nbyte) {
    //printf("reading %u bytes from %d?\n", (int)nbyte, fd_idx);
    if (fd_idx >= 0) {
        struct fd *fd = &fds[fd_idx];
        switch(fd->type) {
            case WAD_FILE:
                if (fd->offset == WAD_len)
                    return 0;
                if (fd->offset + nbyte > WAD_len)
                    nbyte = WAD_len - fd->offset;

                //printf("reading %u bytes from offset %d!\n", (int)nbyte, (int)fd->offset);
                memcpy(buf, WAD + fd->offset, nbyte);
                fd->offset += nbyte;
                return nbyte;
            default:
                ;
        }
    }
    return -1;
}

//! check size of WAD
int _fstat(int fd, struct stat *st) {
     if (fds[fd].type == WAD_FILE) {
        st->st_size = WAD_len;
        return 0;
     }
     return -1;
}

//! Creates directory for config file if -cdrom is passed on the command line
int _mkdir() __deadcode

//! check whether shared memory segment was shmctl'd by current user
uid_t _getuid() __deadcode

//! configure /dev/dsp and non-blocking IO on sockets
int _ioctl() __deadcode

//! register handler for ^C
sig_t _signal(int sig _U_, sig_t func _U_)
{ // XXX pass this to library user soemhow
    return SIG_DFL;
}

//! populate sound buffer at set intervals
int _sigaction() __deadcode

//! set interval for populating sound buffer
int _setitimer() __deadcode

//! Multiplayer
int _recvfrom() __deadcode
//! Multiplayer
void *_gethostbyname() __deadcode
//! Multiplayer
int _gethostname() __deadcode
//! Multiplayer
unsigned _inet_addr() __deadcode
//! Multiplayer
int _bind() __deadcode
//! Multiplayer
int _sendto() __deadcode
//! Multiplayer
int _socket() __deadcode

//! Emitt sound and write savegames
int _write() {
    return -1;
}

/* Give the quitting tone some time to play or wait for packets to be handed to the OS,
 * in multiplayer when quitting. Latter probably a workaround for some system that discards
 * packets that no longer have the process that queued them alive?
 */
int usleep() __nop


#endif
