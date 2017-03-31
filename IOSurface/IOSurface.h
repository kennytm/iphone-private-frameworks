

#ifndef _IOSURFACE_H
#define _IOSURFACE_H 1

#include <Availability2.h>
#define IOSFC_AVAILABLE_STARTING(mac, iphone) __OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_3_0)

#include <sys/cdefs.h>
#include <CoreFoundation/CFBase.h>

/*
Cannot find "IOSurfaceAPI.h"? Since it is not free or open source, the file is
not put here. Nevertheless, if you're using Mac OS X 10.6, you can get a copy
from

	/System/Library/Frameworks/IOSurface.framework/Headers/IOSurfaceAPI.h

*/
#include <IOSurface/IOSurfaceAPI.h>
#include <IOSurface/IOSurfaceAccelerator.h>

#if __cplusplus
extern "C" {
#endif

void IOSurfaceFlushProcessorCaches(IOSurfaceRef surface);

#if __cplusplus
}
#endif

#endif
