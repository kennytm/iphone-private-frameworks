#ifndef _APPLEJPEGSERVICE_H
#define _APPLEJPEGSERVICE_H 1

#include <IOSurface/IOSurface.h>
#include <IOKit/IOKitLib.h>

#define kAppleJPEGServiceName "AppleJPEGDriver"

#define kAppleJPEGInitializeDecoder 0
#define kAppleJPEGStartDecoder      1
#define kAppleJPEGInitializeEncoder 2
#define kAppleJPEGStartEncoder      3

struct JPEGDriverArgs {
	int must_be_zero_1;
	IOSurfaceID src_surface /*in*/;
	size_t src_size /*in*/;
	int must_be_zero_2;
	IOSurfaceID dest_surface /*in*/;
	size_t dest_size /*in*/;
	size_t result_size /*out*/;
	size_t dest_width /*in*/;
	size_t dest_height /*in*/;
	int quality /*in*/;
	int paddingForOS4;
};

#define JPEGDriverArgsSizeOS3 (sizeof(struct JPEGDriverArgs) - sizeof(int))
#define JPEGDriverArgsSizeOS4 (sizeof(struct JPEGDriverArgs))

#endif
