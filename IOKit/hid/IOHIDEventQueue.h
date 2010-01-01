/*
 
IOHIDEventQueue.h ... Header for IOHIDEventQueue*** functions.

Copyright (c) 2009  KennyTM~ <kennytm@gmail.com>
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

#ifndef IOKIT_HID_IOHIDEVENTQUEUE_H
#define IOKIT_HID_IOHIDEVENTQUEUE_H 1

#include <CoreFoundation/CoreFoundation.h>
#include "IOHIDEvent.h"

#if __cplusplus
extern "C" {
#endif
	
	typedef struct __IOHIDEventQueue
#if 0
	{
		CFRuntimeBase base;	// 0, 4
		IODataQueueMemory* queue;	// 8
		size_t queueSize;	// c
		int notificationPortType;	// 10, 0 -> associate to hidSystem, 1 -> associate to data queue.
		uint32_t token;	// 14
		int topBitOfToken;	// 18, = token >> 31
	}
#endif
	* IOHIDEventQueueRef;
	
#pragma mark -
#pragma mark Creators
	
	CFTypeID IOHIDEventQueueGetTypeID(void);	
	
	// Token must be nonzero.
	IOHIDEventQueueRef IOHIDEventQueueCreateWithToken(CFAllocatorRef allocator, uint32_t token);
	IOHIDEventQueueRef IOHIDEventQueueCreate(CFAllocatorRef allocator, int notificationPortType, uint32_t token);

#pragma mark -
#pragma mark Accessors
	
	uint32_t IOHIDEventQueueGetToken(IOHIDEventQueueRef queue);
	
	void IOHIDEventQueueSetNotificationPort(IOHIDEventQueueRef queue, mach_port_t port);
	
#pragma mark -
#pragma mark Actions
	
	IOHIDEventRef IOHIDEventQueueDequeueCopy(IOHIDEventQueueRef queue);
	void IOHIDEventQueueEnqueue(IOHIDEventQueueRef queue, IOHIDEventRef event);	// will send a message to the "tickle port" as well.
	
#if __cplusplus
}
#endif

#endif
