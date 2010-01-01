/*
 
IOHIDDisplay.h ... I/O Kit HID Display

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

#ifndef IOHID_DISPLAY_H
#define IOHID_DISPLAY_H

#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/IOKitLib.h>
#include "IOHIDNotification.h"

#if __cplusplus
extern "C" {
#endif
		
	typedef struct __IOHIDDisplay
#if 0
	{
		CFRuntimeBase _base;	// 0, 4
		void* client;	// 8
		io_service_t service;	// c
		CFRunLoopRef runloop;	// 10
		CFStringRef mode;	// 14, *not retained*
		IONotificationPortRef port;	// 18
		io_object_t notification;	// 1c
		CFMutableSetRef removalNotifications;	// 20, set of IOHIDNotification's
		CFMutableDictionaryRef properties;	// 24
		int logLevel;	// 28
		float brightness;	// 34
		float brightnessMin;	// 38
		float brightnessMax;	// 3c
		float brightnessFactor;	// 40;
		float x44;	// 44
		float ambient;	// 4c
		float brightnessAutoWeightMin;	// 54
		float brightnessAutoWeightMax;	// 58
		float x60;	// 60
		float x64;	// 64
		float x68;	// 68
		float x70;	// 70
		float x74;	// 74
		int x78;	// 78
		int x80;	// 80
		CFTimeInterval fadePeriod;	// 84
	}
#endif
	* IOHIDDisplayRef;
	
#pragma mark -
#pragma mark Creators
		
	CFTypeID IOHIDDisplayGetTypeID(void);
	IOHIDDisplayRef _IOHIDDisplayCreate(CFAllocatorRef allocator, io_service_t service);
	
#pragma mark -
#pragma mark Accessors
	
	float _IOHIDDisplayGetAmbient(IOHIDDisplayRef display);
	void _IOHIDDisplaySetAmbient(IOHIDDisplayRef display, float ambient);
	
	float _IOHIDDisplayGetBrightness(IOHIDDisplayRef display);
	void _IOHIDDisplaySetBrightness(IOHIDDisplayRef display, float brightness);
	void _IOHIDDisplaySetBrightnessMax(IOHIDDisplayRef display, float brightnessMax);
	
	void _IOHIDDisplaySetBrightnessFactor(IOHIDDisplayRef display, float factor);
	float _IOHIDDisplayGetBrightnessFactor(IOHIDDisplayRef display);
		
	void IOHIDDisplaySetProperty(IOHIDDisplayRef display, CFStringRef property, CFTypeRef value);
	CFTypeRef IOHIDDisplayGetProperty(IOHIDDisplayRef display, CFStringRef property);
	
	CFTypeRef _IOHIDDisplayGetClient(IOHIDDisplayRef display);
	
#pragma mark -
#pragma mark Actions
	
	void _IOHIDDisplayUnscheduleWithRunLoop(IOHIDDisplayRef display, CFRunLoopRef runloop, CFStringRef mode);
	void _IOHIDDisplayScheduleWithRunLoop(IOHIDDisplayRef display, CFRunLoopRef runloop, CFStringRef mode);
	
	IOHIDNotificationRef IOHIDDisplayCreateRemovalNotification(IOHIDDisplayRef display, IOHIDNotificationCallback callback, void* target, void* refcon);
	
	Boolean _IOHIDDisplayOpen(IOHIDDisplayRef display, CFTypeRef client);
	void _IOHIDDisplayClose(IOHIDDisplayRef display, CFTypeRef client);
	
#pragma mark -
#pragma mark Constants
	
	static const CFStringRef kIOHIDDisplayPropertyBrightness = CFSTR("DisplayBrightness");	// float
	static const CFStringRef kIOHIDDisplayPropertyBrightnessAuto = CFSTR("DisplayBrightnessAuto");	// boolean
	static const CFStringRef kIOHIDDisplayPropertyBrightnessMin = CFSTR("DisplayBrightnessMin");	// float
	static const CFStringRef kIOHIDDisplayPropertyBrightnessMax = CFSTR("DisplayBrightnessMax");	// float
	static const CFStringRef kIOHIDDisplayPropertyBrightnessAutoWeightMax = CFSTR("DisplayBrightnessAutoWeightMax");	// float
	static const CFStringRef kIOHIDDisplayPropertyBrightnessAutoWeightMin = CFSTR("DisplayBrightnessAutoWeightMin");	// float
	static const CFStringRef kIOHIDDisplayPropertyBrightnessFactor = CFSTR("DisplayBrightnessFactor");	// float
	static const CFStringRef kIOHIDDisplayPropertyBrightnessFactorWithFade = CFSTR("DisplayBrightnessFactorWithFade");	// float
	static const CFStringRef kIOHIDDisplayPropertyBrightnessFadePeriod = CFSTR("DisplayBrightnessFadePeriod");	// float
	static const CFStringRef kIOHIDDisplayPropertyLogLevel = CFSTR("LogLevel");	// int	
	
#if __cplusplus
}
#endif

#endif

