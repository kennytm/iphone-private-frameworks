#ifndef _IOSURFACE_ACCELERATOR_H
#define _IOSURFACE_ACCELERATOR_H 1

#include <IOSurface/IOSurfaceAPI.h>

typedef IOReturn IOSurfaceAcceleratorReturn;

enum {
	kIOSurfaceAcceleratorSuccess = 0,
};

typedef struct __IOSurfaceAccelerator *IOSurfaceAcceleratorRef;

IOSurfaceAcceleratorReturn IOSurfaceAcceleratorCreate(CFAllocatorRef allocator, uint32_t type, IOSurfaceAcceleratorRef *outAccelerator);
IOSurfaceAcceleratorReturn IOSurfaceAcceleratorTransferSurface(IOSurfaceAcceleratorRef accelerator, IOSurfaceRef sourceSurface, IOSurfaceRef destSurface, CFDictionaryRef dict, void *unknown);

#endif
