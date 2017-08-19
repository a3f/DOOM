#include "X11/Xlib.h"
#include "X11/extensions/XShm.h"
#include "defs.h"
#include <stdio.h>

Bool XShmQueryExtension() { return False; }
Bool XShmAttach() __deadcode

XImage *XShmCreateImage () __deadcode

Bool XShmDetach() { return True; }

Status XShmGetEventBase() __deadcode

Bool XShmPutImage() __deadcode
