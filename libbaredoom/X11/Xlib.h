#ifndef __X11_XLIB_H_
#define __X11_XLIB_H_

#include_next <X11/Xlib.h>
#include "X11/Xutil.h"

#if 0
typedef int Bool;
typedef int Status;
typedef unsigned long Time;
typedef unsigned char KeyCode;
typedef unsigned int XID;

typedef XID Drawable;
typedef XID Window;
typedef XID Pixmap;
typedef XID Drawable;
typedef XID Colormap;
typedef XID KeySym;
typedef XID Cursor;


typedef struct _XDisplay Display;
typedef struct _XVisual Visual;
typedef struct _XImage {
    int width, height;		/* size of image */
    char *data;			/* pointer to image data */
    int bytes_per_line;		/* accelarator to next line */
} XImage;
typedef struct _XDisplay Display;
typedef struct {
    int function;		/* logical operation */
    Bool graphics_exposures;/* boolean, should exposures be generated */
} XGCValues;
typedef struct _XGC *GC;
typedef union {
    int type;
    struct {
        int type;		/* of event */
        int x, y;		/* pointer x, y coordinates in event window */
        unsigned int state;	/* key or button mask */
        unsigned int button;	/* detail */
    } xbutton;
    struct {
        int type;		/* of event */
        int x, y;		/* pointer x, y coordinates in event window */
        unsigned int keycode;	/* detail */
    } xkey;
    struct {
        int type;		/* of event */
        int count;		/* if non-zero, at least this many more */
    } xexpose;
} XEvent;
typedef struct {
    unsigned long pixel;
    unsigned short red, green, blue;
    char flags;
} XColor;
typedef struct {
    unsigned long border_pixel;	/* border pixel value */
    long event_mask;		/* set of events that should be saved */
    Colormap colormap;		/* color map to be associated with window */
} XSetWindowAttributes;

#define xmotion xbutton

#define GCFunction              (1L<<0)

#define	GXclear			0x0

#define ZPixmap			2

#define NoEventMask			0L
#define KeyPressMask			(1L<<0)  
#define KeyReleaseMask			(1L<<1)  
#define ButtonPressMask			(1L<<2)  
#define ButtonReleaseMask		(1L<<3)  

#define DoRed			(1<<0)
#define DoGreen			(1<<1)
#define DoBlue			(1<<2)


#define Button1			1
#define Button2			2
#define Button3			3
#define Button4			4
#define Button5			5

#define Button1Mask		(1<<8)
#define Button2Mask		(1<<9)
#define Button3Mask		(1<<10)
#define Button4Mask		(1<<11)
#define Button5Mask		(1<<12)

#define None        0L
#define CurrentTime 0L
#define True        1
#define False       0

#define PseudoColor		3


#define KeyPress		2
#define KeyRelease		3
#define ButtonPress		4
#define ButtonRelease		5
#define MotionNotify		6
#define EnterNotify		7
#define LeaveNotify		8
#define FocusIn			9
#define FocusOut		10
#define KeymapNotify		11
#define Expose			12
#define GraphicsExpose		13
#define NoExpose		14
#define VisibilityNotify	15
#define CreateNotify		16
#define DestroyNotify		17
#define UnmapNotify		18
#define MapNotify		19
#define MapRequest		20
#define ReparentNotify		21
#define ConfigureNotify		22
#define ConfigureRequest	23
#define GravityNotify		24
#define ResizeRequest		25
#define CirculateNotify		26
#define CirculateRequest	27
#define PropertyNotify		28
#define SelectionClear		29
#define SelectionRequest	30
#define SelectionNotify		31
#define ColormapNotify		32
#define ClientMessage		33
#define MappingNotify		34
#define GenericEvent		35
#define LASTEvent		36	/* must be bigger than any event # */

enum { InputOutput, InputOnly };
enum { GrabModeSync, GrabModeAsync };
enum { AllocNone, AllocAll };

#define CWBackPixmap		(1L<<0)
#define CWBackPixel		(1L<<1)
#define CWBorderPixmap		(1L<<2)
#define CWBorderPixel           (1L<<3)
#define CWBitGravity		(1L<<4)
#define CWWinGravity		(1L<<5)
#define CWBackingStore          (1L<<6)
#define CWBackingPlanes	        (1L<<7)
#define CWBackingPixel	        (1L<<8)
#define CWOverrideRedirect	(1L<<9)
#define CWSaveUnder		(1L<<10)
#define CWEventMask		(1L<<11)
#define CWDontPropagate	        (1L<<12)
#define CWColormap		(1L<<13)
#define CWCursor	        (1L<<14)

#define GCFunction              (1L<<0)
#define GCPlaneMask             (1L<<1)
#define GCForeground            (1L<<2)
#define GCBackground            (1L<<3)
#define GCLineWidth             (1L<<4)
#define GCLineStyle             (1L<<5)
#define GCCapStyle              (1L<<6)
#define GCJoinStyle		(1L<<7)
#define GCFillStyle		(1L<<8)
#define GCFillRule		(1L<<9) 
#define GCTile			(1L<<10)
#define GCStipple		(1L<<11)
#define GCTileStipXOrigin	(1L<<12)
#define GCTileStipYOrigin	(1L<<13)
#define GCFont 			(1L<<14)
#define GCSubwindowMode		(1L<<15)
#define GCGraphicsExposures     (1L<<16)

#define NoEventMask			0L
#define KeyPressMask			(1L<<0)  
#define KeyReleaseMask			(1L<<1)  
#define ButtonPressMask			(1L<<2)  
#define ButtonReleaseMask		(1L<<3)  
#define EnterWindowMask			(1L<<4)  
#define LeaveWindowMask			(1L<<5)  
#define PointerMotionMask		(1L<<6)  
#define PointerMotionHintMask		(1L<<7)  
#define Button1MotionMask		(1L<<8)  
#define Button2MotionMask		(1L<<9)  
#define Button3MotionMask		(1L<<10) 
#define Button4MotionMask		(1L<<11) 
#define Button5MotionMask		(1L<<12) 
#define ButtonMotionMask		(1L<<13) 
#define KeymapStateMask			(1L<<14)
#define ExposureMask			(1L<<15) 
#define VisibilityChangeMask		(1L<<16) 
#define StructureNotifyMask		(1L<<17) 
#define ResizeRedirectMask		(1L<<18) 
#define SubstructureNotifyMask		(1L<<19) 
#define SubstructureRedirectMask	(1L<<20) 
#define FocusChangeMask			(1L<<21) 
#define PropertyChangeMask		(1L<<22) 
#define ColormapChangeMask		(1L<<23) 
#define OwnerGrabButtonMask		(1L<<24) 
#endif


#define __ARGS2(x) ()

Colormap
_XCreateColormap(Display *display, Window w, Visual *visual, int alloc);

GC _XCreateGC(Display *display, Drawable d, unsigned long valuemask, XGCValues *values);


XImage *
_XCreateImage(Display *display, Visual *visual, unsigned int depth, int format, int offset, char *data, unsigned int width, unsigned int height, int bitmap_pad, int bytes_per_line);

Pixmap
_XCreatePixmap __ARGS2((Display *display, Drawable d, unsigned int width, unsigned int height, unsigned int depth));

int
_XFreePixmap __ARGS2((Display *display, Pixmap pixmap));

int
_XFreeGC __ARGS2((Display *display, GC gc));

Cursor
_XCreatePixmapCursor __ARGS2((Display *display, Pixmap source, Pixmap mask, XColor
        *foreground_color, XColor *background_color, unsigned int x, unsigned int y));

Window
_XCreateWindow __ARGS2((Display *display, Window parent, int x, int y, unsigned int
        width, unsigned int height, unsigned int border_width, int depth, unsigned int
        class, Visual *visual, unsigned long valuemask, XSetWindowAttributes
        *attributes));

int
_XDefineCursor __ARGS2((Display *display, Window w, Cursor cursor));

int
_XFillRectangle __ARGS2((Display *display, Drawable d, GC gc, int x, int y, unsigned int
        width, unsigned int height));

int
_XGrabPointer __ARGS2((Display *display, Window grab_window, Bool owner_events, unsigned
        int event_mask, int pointer_mode, int keyboard_mode, Window confine_to, Cursor
        cursor, Time time));


int
_XInstallColormap(Display *display, Colormap colormap);

KeySym
_XKeycodeToKeysym(Display *display, KeyCode keycode, int index);

int
_XMapWindow(Display *display, Window w);

Status
_XMatchVisualInfo(Display *display, int screen, int depth, int c_class, XVisualInfo *vinfo_return);

int
_XNextEvent(Display *display, XEvent *event_return);

Display *
_XOpenDisplay(char *display_name);

int
_XPending(Display *display);

int
_XPutImage(Display *display, Drawable d, GC gc, XImage *image, int src_x, int
        src_y, int dest_x, int dest_y, unsigned int width, unsigned int height);

int
_XStoreColors(Display *display, Colormap colormap, XColor color[], int ncolors);

int
_XSync(Display *display, Bool discard);

int
_XWarpPointer __ARGS2((Display *display, Window src_w, Window dest_w, int src_x, int src_y,
        unsigned int src_width, unsigned int src_height, int dest_x, int dest_y));

#define XCreatePixmap _XCreatePixmap
#define XCreateGC _XCreateGC
#define XFillRectangle _XFillRectangle
#define XCreatePixmapCursor _XCreatePixmapCursor
#define XFreePixmap _XFreePixmap
#define XFreeGC _XFreeGC
#define XDefineCursor _XDefineCursor
#define XGrabPointer _XGrabPointer
#define XWarpPointer _XWarpPointer

#define _DefaultScreen(dpy)   ((int)dpy)
#define _RootWindow(dpy)   ((int)dpy)
#define __RootWindow(disp, screen_nr) ((Window)disp)
#endif
