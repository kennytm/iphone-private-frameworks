/*
 
IOSurfaceClient.h ... IOSurface Client

Copyright (c) 2010  KennyTM~ <kennytm@gmail.com>
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice, 
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.
* Neither the name of the KennyTM~ nor the names of its contributors may be
  used to endorse or promote products derived from this software without
  specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef IOSURFACE_IOSURFACECLIENT_H
#define IOSURFACE_IOSURFACECLIENT_H

#if __cplusplus
extern "C" {
#endif
	
#if 0
	struct IOSurfaceClientUnknown {
		int x00;
		int x04;
		size_t seed;
		size_t inUse;
	};
#endif
	
	typedef struct __IOSurfaceClient 
#if 0
	{
		void* isa;	// 0
		size_t useCount;	// 4
		void* address;	// 8
		IOSurfaceClientID _id;	// c
		size_t allocSize;	// 10
		size_t width;	// 14
		size_t height;	// 18
		size_t bytesPerRow;	// 1c
		int offset;	// 20
		OSType pixelFormat;	// 24
		size_t planeCount;	// 2c
		uint16_t bytesPerElement;	// 34
		uint8_t elementWidth;	// 36
		uint8_t elementHeight;	// 37
		struct IOSurfaceClientUnknown* unknown;	// 3c
		struct {
			struct IOSurfaceClientUnknown* unknown;	// 40
			size_t width;	// 44
			size_t height;	// 48
			int offset;	// 50
			size_t bytesPerRow;	// 54
			uint16_t bytesPerElement;	// 5c
			uint8_t elementWidth;	// 5e
			uint8_t elementHeight;	// 5f
		} planes[];
	}
#endif
	IOSurfaceClientRef;
	
	typedef uint32_t IOSurfaceClientID;
	
#pragma mark Accessors
	IOSurfaceClientID IOSurfaceClientGetID(IOSurfaceClientRef client);
	size_t IOSurfaceClientGetAllocSize(IOSurfaceClientRef client);
	size_t IOSurfaceClientGetWidth(IOSurfaceClientRef client);
	size_t IOSurfaceClientGetHeight(IOSurfaceClientRef client);
	size_t IOSurfaceClientGetBytesPerRow(IOSurfaceClientRef client);
	uint16_t IOSurfaceClientGetBytesPerElement(IOSurfaceClientRef client);
	uint8_t IOSurfaceClientGetElementWidth(IOSurfaceClientRef client);
	uint8_t IOSurfaceClientGetElementHeight(IOSurfaceClientRef client);
	OSType IOSurfaceClientGetPixelFormat(IOSurfaceClientRef client);
	void* IOSurfaceClientGetBaseAddress(IOSurfaceClientRef client);	// return address + offset.
	uint32_t IOSurfaceClientGetSeed(IOSurfaceClientRef client);
	
	uint32_t IOSurfaceClientGetUseCount(IOSurfaceClientRef client);
	bool IOSurfaceClientIsInUse(IOSurfaceClientRef client);
	
#pragma mark Accessors for planes
	size_t IOSurfaceClientGetPlaneCount(IOSurfaceClientRef client);
	size_t IOSurfaceClientGetWidthOfPlane(IOSurfaceClientRef client, size_t planeIndex);
	size_t IOSurfaceClientGetHeightOfPlane(IOSurfaceClientRef client, size_t planeIndex);
	size_t IOSurfaceClientGetBytesPerRowOfPlane(IOSurfaceClientRef client, size_t planeIndex);
	uint16_t IOSurfaceClientGetBytesPerElementOfPlane(IOSurfaceClientRef client, size_t planeIndex);
	uint8_t IOSurfaceClientGetElementWidthOfPlane(IOSurfaceClientRef client, size_t planeIndex);
	uint8_t IOSurfaceClientGetElementHeightOfPlane(IOSurfaceClientRef client, size_t planeIndex);
	void* IOSurfaceClientGetBaseAddressOfPlane(IOSurfaceClientRef client, size_t planeIndex);
	uint32_t IOSurfaceClientGetSeedOfPlane(IOSurfaceClientRef client, size_t planeIndex);
	
#pragma mark Actions
	void IOSurfaceClientDecrementUseCount(IOSurfaceClientRef client);
	void IOSurfaceClientIncrementUseCount(IOSurfaceClientRef client);
	
	void IOSurfaceClientRemoveSurfaceNotify(IOSurfaceClientRef client);
	
#if __cplusplus
}
#endif

#endif