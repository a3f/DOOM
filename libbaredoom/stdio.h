#if __SYSTEM_STDIO
#ifdef __GNUC__
#include_next <stdio.h>
#else
#error Requested System stdio, but include_next not available
#endif
#define __STDIO_H_
#endif

#ifndef __STDIO_H_
#define __STDIO_H_

#include <stddef.h>
#include <stdarg.h>

#define FILE int
#define EOF -1

#define stdout ((FILE*)1)
#define stderr ((FILE*)2)

#ifndef SEEK_SET
#define SEEK_SET 0
#endif
#ifndef SEEK_END
#define SEEK_END 0
#endif

FILE *fopen();
FILE *popen();
int fclose();
int vfprintf(FILE *fp, const char *fmt, va_list va);
int fprintf(FILE *fp, const char *fmt, ...);
int printf(const char *fmt, ...);
int fflush();
int ftell();
int fseek();
size_t fread();
int feof();
int getchar();
void setbuf();
int fscanf();
void perror();
int sscanf();
int sprintf(char *buf, const char *fmt, ...);

#endif
