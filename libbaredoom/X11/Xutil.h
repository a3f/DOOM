#if __SYSTEM_X11
#ifdef __GNUC__
#include_next <X11/Xutil.h>
#else
#error Requested System X11, but include_next not available
#endif
#define __X11_XUTIL_H_
#endif

#ifndef __X11_XUTIL_H_
#define __X11_XUTIL_H_

typedef struct _XVisual Visual;


typedef struct {
    Visual *visual;
    int screen;
    int depth;
#if defined(__cplusplus) || defined(c_plusplus)
    int c_class;                                  /* C++ */
#else
    int class;
#endif
    unsigned long red_mask;
    unsigned long green_mask;
    unsigned long blue_mask;
    int colormap_size;
    int bits_per_rgb;
} XVisualInfo;

#endif
