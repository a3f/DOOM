When targeting a freestanding C implementation, a total of 93 functions would need to be supplied in order for this to link:

## X11 functions

    XCreateColormap
    XCreateGC
    XCreateImage
    XCreatePixmap
    XCreatePixmapCursor
    XCreateWindow
    XDefineCursor
    XFillRectangle
    XFreeGC
    XFreePixmap
    XGrabPointer
    XInstallColormap
    XKeycodeToKeysym
    XMapWindow
    XMatchVisualInfo
    XNextEvent
    XOpenDisplay
    XPending
    XPutImage
    XShmAttach
    XShmCreateImage
    XShmDetach
    XShmGetEventBase
    XShmPutImage
    XShmQueryExtension
    XStoreColors
    XSync
    XWarpPointer

## Unix libc

    access
    mkdir
    open
    popen
    read
    close
    getenv
    gettimeofday
    getuid
    ioctl
    lseek
    fstat
    setitimer
    shmat
    shmctl
    shmdt
    shmget
    sigaction
    signal
    usleep
    write

## General utilities (easy)

    atoi
    exit

## Memory management

    malloc
    realloc

## `<math.h>`

    pow

## `<string.h>`

    strcasecmp
    strcmp
    strcpy
    strerror
    strlen
    strncasecmp
    strncmp
    strncpy
    toupper
    memcpy
    memset
    strcat

## `<stdio.h>`

    fclose
    feof
    fflush
    fopen
    fprintf
    fread
    fscanf
    fseek
    ftell
    getchar
    perror
    printf
    setbuf
    vfprintf
    sprintf
    sscanf

## Sockets

    recvfrom
    gethostbyname
    gethostname
    inet_addr
    bind
    sendto
    socket

