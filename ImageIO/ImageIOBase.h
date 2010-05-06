#ifndef __IMAGEIO_BASE__
#define __IMAGEIO_BASE__

#include <Availability.h>
#define IMAGEIO_AVAILABLE_STARTING(_mac,_iphone) __OSX_AVAILABLE_STARTING(_mac,__IPHONE_3_0)
#define IMAGEIO_AVAILABLE_BUT_DEPRECATED(_mac,_macDep,_iphone,_iphoneDep) __OSX_AVAILABLE_BUT_DEPRECATED(_mac,__IPHONE_3_0,_iphone,iphoneDep)

#ifdef __cplusplus
#define IMAGEIO_EXTERN_C_BEGIN extern "C" {
#define IMAGEIO_EXTERN_C_END   }
#define IMAGEIO_EXTERN extern "C"
#else
#define IMAGEIO_EXTERN_C_BEGIN
#define IMAGEIO_EXTERN_C_END
#define IMAGEIO_EXTERN extern
#endif

#endif
