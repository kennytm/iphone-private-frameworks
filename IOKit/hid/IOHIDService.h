/*
 
IOHIDService.h ... I/O Kit HID Service

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

// With reference to http://www.opensource.apple.com/source/IOHIDFamily/IOHIDFamily-258.1/IOHIDLib/IOHIDEventServiceClass.h

#ifndef IOHID_SERVICE_H
#define IOHID_SERVICE_H

#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/IOKitLib.h>
#include "IOHIDEvent.h"
#include "IOHIDNotification.h"

#if __cplusplus
extern "C" {
#endif
			
	typedef struct __IOHIDService
#if 0
	{
		CFRuntimeBase _base;	// 0, 4
		CFTypeRef client;	// 8
		io_service_t service;	// c
		void** pluginInterface1;	// 10; GUID = D12C833F-B15B-11DA-902D-0014519758EF
		void** pluginInterface2;	// 14;
		IOCFPlugInInterface** interface;	// 18
		CFRunLoopRef runloop;	// 1c
		CFStringRef mode;	// 20
		IONotificationPortRef notify;	// 24	
		CFMutableSetRef removalNotifications;	// 2c
		void* eventTarget;	// 30
		void* eventRefcon;	// 34
		IOHIDServiceEventCallback eventCallback;	// 38
		uint32_t previousButtonMask;	// 3c
	}
#endif
	* IOHIDServiceRef;

	typedef void(*IOHIDServiceEventCallback)(void* target, void* refcon, IOHIDServiceRef service, IOHIDEventRef event);
	
	/*
	 metaObject->
	 [0] = NULL
	 [4] = IOHIDIUnknown::genericQueryInterface(void*, CFUUIDBytes, void**)
	 [8] = IOHIDIUnknown::genericAddRef(void*)
	 [0x0c] = IOHIDIUnknown::genericRelease(void*)
	 [0x10] = IOHIDEventServiceClass::_open(void*, unsigned long)
	 [0x14] = IOHIDEventServiceClass::_close(void*, unsigned long)
	 [0x18] = IOHIDEventServiceClass::_getProperty(void*, __CFString const*)
	 [0x1c] = IOHIDEventServiceClass::_setProperty(void*, __CFString const*, void const*)
	 [0x20] = IOHIDEventServiceClass::_setEventCallback(void*, void (*)(void*, void*, void*, __IOHIDEvent*, unsigned long), void*, void*)
	 [0x24] = IOHIDEventServiceClass::_scheduleWithRunLoop(void*, __CFRunLoop*, __CFString const*)
	 [0x28] = IOHIDEventServiceClass::_unscheduleFromRunLoop(void*, __CFRunLoop*, __CFString const*)
	 [0x2c] = IOHIDEventServiceClass::_copyEvent(void*, unsigned int, __IOHIDEvent*, unsigned long)
	 */	
	
#pragma mark -
#pragma mark Creators
		
	CFTypeID IOHIDServiceGetTypeID(void);
	IOHIDServiceRef _IOHIDServiceCreate(CFAllocatorRef allocator, io_service_t service);
	
#pragma mark -
#pragma mark Accessors
			
	CFTypeRef IOHIDServiceGetProperty(IOHIDServiceRef service, CFStringRef property);
	Boolean IOHIDServiceSetProperty(IOHIDServiceRef service, CFStringRef property, CFTypeRef value);
	
	CFTypeRef _IOHIDServiceGetClient(IOHIDServiceRef service);
	Boolean _IOHIDServiceMatchPropertyTable(IOHIDServiceRef service, CFDictionaryRef propertyTable);
	
	IOHIDEventRef IOHIDServiceCopyEvent(IOHIDServiceRef service, IOHIDEventType type, IOHIDEventRef event, IOOptionBits options);
	
	void _IOHIDServiceSetEventCallback(IOHIDServiceRef service, IOHIDServiceEventCallback eventCallback, void* target, void* refcon);
	
#pragma mark -
#pragma mark Actions
	
	void _IOHIDServiceScheduleWithRunLoop(IOHIDServiceRef service, CFRunLoopRef runloop, CFStringRef mode);
	void _IOHIDServiceUnscheduleWithRunLoop(IOHIDServiceRef service);
	
	IOHIDNotificationRef IOHIDServiceCreateRemovalNotification(IOHIDServiceRef display, IOHIDNotificationCallback callback, void* target, void* refcon);
	
	Boolean _IOHIDServiceOpen(IOHIDServiceRef service, CFTypeRef client, IOOptionBits options);
	Boolean _IOHIDServiceClose(IOHIDServiceRef service, CFTypeRef client, IOOptionBits options);
	
	
#if __cplusplus
}
#endif

#endif

