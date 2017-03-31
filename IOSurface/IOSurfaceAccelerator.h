#ifndef _IOSURFACE_ACCELERATOR_H
#define _IOSURFACE_ACCELERATOR_H 1

#include <IOSurface/IOSurfaceAPI.h>
#include <IOKit/IOReturn.h>

#if __cplusplus
extern "C" {
#endif

typedef IOReturn IOSurfaceAcceleratorReturn;

enum {
	kIOSurfaceAcceleratorSuccess = 0,
};

typedef struct __IOSurfaceAccelerator *IOSurfaceAcceleratorRef;

IOSurfaceAcceleratorReturn IOSurfaceAcceleratorCreate(CFAllocatorRef allocator, uint32_t type, IOSurfaceAcceleratorRef *outAccelerator);
IOSurfaceAcceleratorReturn IOSurfaceAcceleratorTransferSurface(IOSurfaceAcceleratorRef accelerator, IOSurfaceRef sourceSurface, IOSurfaceRef destSurface, CFDictionaryRef dict, void *unknown);

#if __cplusplus
}
#endif

#endif
