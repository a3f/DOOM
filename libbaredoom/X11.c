#include "defs.h"

//! Nulling the cursor
unsigned _XCreatePixmap() { return 0xDEADBEEF; }
//! Nulling the cursor
void *_XCreateGC(void *display, unsigned d, unsigned long valuemask, void*values) {
    if (d == 0xDEADBEEF)
        return NULL;
    
    return XCreateGC(display, d, valuemask, values);
}
//! Nulling the cursor
void _XFillRectangle() __nop
//! Nulling the cursor
void _XCreatePixmapCursor() __nop
//! Nulling the cursor
void _XFreePixmap () __nop
//! Nulling the cursor
void _XFreeGC () __nop
//! Nulling the cursor
void _XDefineCursor() __nop
void _XGrabPointer() __nop
void _XWarpPointer() __nop
