/*
 
IOHIDNotification ... I/O Kit HID Notifications

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

#ifndef IOHID_NOTIFICATION_H
#define IOHID_NOTIFICATION_H

#include <CoreFoundation/CoreFoundation.h>

#if __cplusplus
extern "C" {
#endif
	
	typedef void(*IOHIDNotificationCallback)(void* target, void* refcon);
	
	typedef struct __IOHIDNotification
#if 0
	{
		CFRuntimeBase _base;	// 0, 4
		IOHIDNotificationCallback clientCallback;	// 8
		void* clientTarget;	// c
		void* clientRefcon;	// 10
		IOHIDNotificationCallback ownerCallback;	// 14
		void* ownerTarget;	// 18
		void* ownerRefcon;	// 1c
	}
#endif
	* IOHIDNotificationRef;
	
#pragma mark -
#pragma mark Creators
	
	CFTypeID IOHIDNotificationGetTypeID();
	
	IOHIDNotificationRef IOHIDNotificationCreate(CFAllocatorRef allocator,
												 IOHIDNotificationCallback ownerCallback, void* ownerTarget, void* ownerRefcon,
												 IOHIDNotificationCallback clientCallback, void* clientTarget, void* clientRefcon);
	
#pragma mark -
#pragma mark Accessors
	
	IOHIDNotificationCallback IOHIDNotificationGetClientCallback(IOHIDNotificationRef notification);
	void* IOHIDNotificationGetClientTarget(IOHIDNotificationRef notification);
	void* IOHIDNotificationGetClientRefcon(IOHIDNotificationRef notification);
	IOHIDNotificationCallback IOHIDNotificationGetOwnerCallback(IOHIDNotificationRef notification);
	void* IOHIDNotificationGetOwnerTarget(IOHIDNotificationRef notification);
	void* IOHIDNotificationGetOwnerRefcon(IOHIDNotificationRef notification);
		
#if __cplusplus
}
#endif

#endif

