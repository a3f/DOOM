#ifndef __X11_EXTENSIONS_XSHM_H_
#define __X11_EXTENSIONS_XSHM_H_

#include "X11/Xlib.h"

#define ShmCompletion 0

typedef struct {
    int shmid;
    char *shmaddr;
} XShmSegmentInfo;

#define __ARGS(x) ()

Bool
XShmAttach __ARGS((
        Display *display,
        XShmSegmentInfo *shminfo
));

XImage *
XShmCreateImage __ARGS((
        Display *display,
        Visual *visual,
        unsigned int depth,
        int format,
        char *data,
        XShmSegmentInfo *shminfo,
        unsigned int width, unsigned int height));

Bool
XShmDetach __ARGS((
        Display *display,
        XShmSegmentInfo *shminfo));

Status
XShmGetEventBase __ARGS((Display *display));

Bool
XShmPutImage __ARGS((
        Display *display,
        Drawable d,
        GC gc,
        XImage *image,
        int src_x, int src_y, int dest_x, int dest_y,
        unsigned width, unsigned height,
        Bool send_event));

Bool
XShmQueryExtension __ARGS((Display *display));

#endif
