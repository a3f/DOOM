#if __SYSTEM_X11
#ifdef __GNUC__
#include_next <X11/keysym.h>
#else
#error Requested System X11, but include_next not available
#endif
#define __X11_KEYSYM_H_
#endif

#ifndef __X11_KEYSYM_H_
#define __X11_KEYSYM_H_

enum {
    XK_Left,
    XK_Right,
    XK_Down,
    XK_Up,
    XK_Escape,
    XK_Return,
    XK_Tab,
    XK_F1,
    XK_F2,
    XK_F3,
    XK_F4,
    XK_F5,
    XK_F6,
    XK_F7,
    XK_F8,
    XK_F9,
    XK_F10,
    XK_F11,
    XK_F12,
    XK_BackSpace,
    XK_Delete,
    XK_Pause,
    XK_KP_Equal,
    XK_equal,
    XK_KP_Subtract,
    XK_minus,
    XK_Shift_L,
    XK_Shift_R,
    XK_Control_L,
    XK_Control_R,
    XK_Alt_L,
    XK_Meta_L,
    XK_Alt_R,
    XK_Meta_R,
    XK_space,
    XK_asciitilde,
};

#endif
