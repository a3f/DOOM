#ifndef __SYSTEM_STDIO
#include "defs.h"
#include "stdio.h"
#include <stddef.h>
#include <stdarg.h>
//! open debug logs, response files and profiles
FILE *fopen() { return NULL; }

//! start sound server
FILE *popen() __deadcode

//! close aforementioned files
int fclose() __nop;

//! write to stdout, stderr, debug log, sound server and profile
int fprintf(FILE *fp, const char *fmt, ...) {
    int ret;
    va_list ap;
    va_start(ap, fmt);
    ret = (vfprintf)(fp, fmt, ap);
    va_end(ap);
    return ret;
}
int vfprintf(FILE *fp _U_, const char *fmt _U_, va_list va _U_) {
    if (fp == stdout)  // TODO user should be able to supply printer func
        {}
    if (fp == stderr)
        {}

    return -1;
}
int printf(const char *fmt, ...) {
    int ret;
    va_list ap;
    ret = vfprintf(stdout, "kek: ", NULL);
    va_start(ap, fmt);
    ret = vfprintf(stdout, fmt, ap);
    va_end(ap);
    return ret;
}
//! flush out stderr after error
int fflush() __deadcode;

//! tell size of response file
int ftell() __deadcode;

//! seek to end of response file to tell file size
int fseek() __deadcode;

//! read in response file
size_t fread() __deadcode;

//! check for EOF mark in defaults file stream
int feof() __deadcode;

//! ask for user confirmation for modified DOOM
int getchar() { return EOF; }

//! disable buffering for stdout
void setbuf() __nop;

//! parse line in defaults file
int fscanf() { return EOF; }

//! report errno message when shmat() fails while InitGraphics()
void perror() __nop;

//! parse string in defaults file and -geom option arguments
int sscanf() { return EOF; }
#endif
