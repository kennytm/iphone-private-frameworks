/*
 
IOHIDEventSystem.h ... I/O Kit HID Event System

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

// With reference to http://www.opensource.apple.com/source/IOHIDFamily/IOHIDFamily-258.1/IOHIDLib/IOHIDEventServiceClass.h

#ifndef IOHID_EVENT_SYSTEM_H
#define IOHID_EVENT_SYSTEM_H

#include <CoreFoundation/CoreFoundation.h>
#include "IOHIDNotification.h"
#include "IOHIDService.h"
#include "IOHIDEvent.h"
#include "IOHIDEventQueue.h"

#if __cplusplus
extern "C" {
#endif
			
	typedef struct ___IOHIDEventSystem
#if 0
	{
		CFRuntimeBase _base;	// 0, 4
		CFMutableSetRef services;	// 8
		CFMutableSetRef x0c;	// c
		CFMutableSetRef x10;	// 10
		CFMutableSetRef matchNotifications;	// 14
		IONotificationPortRef serviceMatchPort;	// 18
		IONotificationPortRef x1c;	// 1c
		void* x20;	// 20
		IOHIDEventSystemCallback callback;	// 24
		IOHIDSessionRef session;	// 28
		pthread_mutex_t mutex;	// 2c
		CFRunLoopSourceRef migMachSource;	// 58
		CFMutableSetRef queues;	// 5c
	}
#endif
	* IOHIDEventSystemRef;
	
	typedef void(*IOHIDEventSystemCallback)(void* target, void* refcon, IOHIDServiceRef service, IOHIDEventRef event);
	
	CFTypeID IOHIDEventSystemGetTypeID(void);
	IOHIDEventSystemRef IOHIDEventSystemCreate(CFAllocatorRef allocator);
	
	CFArrayRef IOHIDEventSystemCopyMatchingServices(IOHIDEventSystemRef system, CFDictionaryRef propertyTable,
													IOHIDNotificationCallback matchCallback, void* matchTarget, void* matchRefcon, IOHIDNotificationRef* matchNotif);
	void IOHIDEventSystemRegisterQueue(IOHIDEventSystemRef system, IOHIDEventQueueRef queue);
	void IOHIDEventSystemUnregisterQueue(IOHIDEventSystemRef system, IOHIDEventQueueRef queue);
	
	IOHIDEventRef IOHIDEventSystemCopyEvent(IOHIDEventSystemRef system, IOHIDEventType type, IOHIDEventRef event, IOOptionBits options);
	
	CFTypeRef IOHIDEventSystemGetProperty(IOHIDEventSystemRef system, CFStringRef property);
	Boolean IOHIDEventSystemSetProperty(IOHIDEventSystemRef system, CFStringRef property, CFTypeRef value);
	
	Boolean IOHIDEventSystemOpen(IOHIDEventSystemRef system, IOHIDEventSystemCallback callback, void* target, void* refcon, void* unused);
	void IOHIDEventSystemClose(IOHIDEventSystemRef system, void* unused);
	
#if 0
	dlfun("IOHIDEventSystemGetTypeID", "I");
	dlfun("IOHIDEventSystemCreate", "@@");
	dlfun("IOHIDEventSystemCopyMatchingServices", "@@^v^v^v^@");
	dlfun("IOHIDEventSystemRegisterQueue", "v@@");
	dlfun("IOHIDEventSystemUnregisterQueue", "v@@");
	dlfun("IOHIDEventSystemCopyEvent", "@@I@I");
	dlfun("IOHIDEventSystemGetProperty", "@@@");
	dlfun("IOHIDEventSystemSetProperty", "c@@@");
	dlfun("IOHIDEventSystemOpen", "c@^v^v^v^v");
	dlfun("IOHIDEventSystemClose", "v@^v");
#endif
	
#if __cplusplus
}
#endif

#endif

