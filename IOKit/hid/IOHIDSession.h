/*
 
IOHIDSession.h ... I/O Kit HID Session

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

#ifndef IOHID_NOTIFICATION_H
#define IOHID_NOTIFICATION_H

#include <CoreFoundation/CoreFoundation.h>
#include "IOHIDDisplay.h"
#include "IOHIDService.h"
#include "IOHIDEvent.h"

#if __cplusplus
extern "C" {
#endif
	
	typedef struct IOHIDSessionWorkSpace {
		uint64_t value;
	} IOHIDSessionWorkSpace;	
	
	typedef struct __IOHIDSession
#if 0
	{
		CFRuntimeBase _base;	// 0, 4
		int isOpen;	// 8
		CFTypeRef client;	// c
		IOHIDSessionCallback callback;	// 10
		void* refcon;	// 14
		IOHIDSessionWorkSpace workSpace;	// 18, 1c
		CFRunLoopRef runloop;	// 20
		pthread_mutex_t lock;	// 24
		pthread_cond_t cond;	// 50
		pthread_mutexattr_t attr;	// 6c
		CFMutableSetRef services;	// 78
		CFMutableSetRef displays;	// 7c
		CFMutableSetRef ALSStates;	// 80
		CFMutableDictionaryRef properties;	// 84
		Boolean     displayStatus;	// 88, initially = true
		float       factor;	// brightnessFactor. 8c, initially = 1
		float       deviceAmbient;	// 94, initially = 0.5
		float       interval;	// displayInternval. 98, initially = 0.402
		float       ALSIntPeriod;	// 9c, initially = 5.5
		float       xa4;	// a4, initially = 0
		float       xa8;	// a8, initially = 5.5
		float       xac;	// ac, initially = -1
		float       xb0;	// b0, initially = 1
		float       backlight;	// b4, initially = 1
		CFTypeRef   xe0;	// e0
		int         displayOrientation;	// e8, initially = 1
		Boolean     orientationEnabled;	// ec, initially = false
		Boolean     ALSIntPeriodOrientationEnabled;	// ed, initially = false
		float       ALSIntPeriodOrientationPortrait;	// f0, initially = 5.5
		float       ALSIntPeriodOrientationPortraitInv;	// f4, initially = 0
		float       ALSIntPeriodOrientationLandscape;	// f8, initially = 0
		int         lockStateToken;	// fc. (for the "com.apple.springboard.lockstate" Darwin notification)
		uint64_t    lockState;	// 100, 104
		mach_port_t lockStateNotifyPort;	// 108 (leads to __IOHIDSessionLockCallback)
		int         bootedCleanlyToken;	// 10c (for the "com.apple.springboard.bootedcleanly" Darwin notification)
		mach_port_t bootedCleanlyNotifyPort;	// 118 (leads to __IOHIDSessionBootCallback)
		int         displayStatusToken;	// 11c (for the "com.apple.iokit.hid.displayStatus" Darwin notification)
		int         substantialTransitionToken;	// 12c (for the "com.apple.mobile.SubstantialTransition" Darwin notification)
		mach_port_t substantialTransitionNotifyPort;	// 130 (leads to __IOHIDSessionTransitionCallback)
		int         thermalNotificationToken;	// 134 (for the kOSThermalNotificationName Darwin notification)
		mach_port_t thermalNotificationNotifyPort;	// 138 (leads to __IOHIDSessionThermalCallback)
		int         thermalLevel;	// 13c, initially = OSThermalNotificationCurrentLevel()
		int         logLevel;	// 144, initially = 6
	}
#endif
	* IOHIDSessionRef;
	
	typedef void(*IOHIDSessionCallback)(CFTypeRef client, void* refcon, IOHIDServiceRef service, IOHIDEventRef event);
	
#pragma mark -
#pragma mark Creators
	
	CFTypeID IOHIDSessionGetTypeID(void);
	IOHIDSessionRef IOHIDSessionCreate(CFAllocatorRef allocator);
		
#pragma mark -
#pragma mark Accessors
	
	CFTypeRef IOHIDSessionGetProperty(IOHIDSessionRef session, CFStringRef key);
	Boolean IOHIDSessionSetProperty(IOHIDSessionRef session, CFStringRef key, CFTypeRef value);
	
	IOHIDSessionWorkSpace IOHIDSessionGetWorkSpace(IOHIDSessionRef session);
	void IOHIDSessionSetWorkSpace(IOHIDSessionRef session, IOHIDSessionWorkSpace workSpace);
	
	Boolean IOHIDSessionGetLockState(IOHIDSessionRef session);
	void IOHIDSessionSetLockState(IOHIDSessionRef session, Boolean lockState);
	
#pragma mark -
#pragma mark Actions
	
	Boolean IOHIDSessionOpen(IOHIDSessionRef session, CFTypeRef client, IOHIDSessionCallback callback, void* refcon)
	void IOHIDSessionClose(IOHIDSessionRef session, CFTypeRef client);
	
	void IOHIDSessionAddService(IOHIDSessionRef, IOHIDServiceRef service);
	void IOHIDSessionRemoveService(IOHIDSessionRef, IOHIDServiceRef service);
	
	void IOHIDSessionAddDisplay(IOHIDSessionRef, IOHIDDisplayRef display);
	void IOHIDSessionRemoveDisplay(IOHIDSessionRef session, IOHIDDisplayRef display);
	
	IOHIDEventRef IOHIDSessionCopyEvent(IOHIDSessionRef session, IOHIDEventType type, IOHIDEventRef event, IOOptionBits options);
		
#pragma mark -
#pragma mark Constants
	
	static const CFStringRef kIOHIDSessionPropertyDisplayOrientation = CFSTR("DisplayOrientation");
	static const CFStringRef kIOHIDSessionPropertyDisplayBrightnessFactor = CFSTR("DisplayBrightnessFactor");
	static const CFStringRef kIOHIDSessionPropertyDisplayBrightnessFactorWithFade = CFSTR("DisplayBrightnessFactorWithFade");
	static const CFStringRef kIOHIDSessionPropertyDisplayBrightnessFactorPending = CFSTR("DisplayBrightnessFactorPending");
	static const CFStringRef kIOHIDSessionPropertyLogLevel = CFSTR("LogLevel");
	static const CFStringRef kIOHIDSessionPropertyALSIntPeriodOrientationEnabled = CFSTR("ALSIntPeriodOrientationEnabled");
	static const CFStringRef kIOHIDSessionPropertyALSIntPeriod = CFSTR("ALSIntPeriod");
	static const CFStringRef kIOHIDSessionPropertyALSIntPeriodOrientationPortrait = CFSTR("ALSIntPeriodOrientationPortrait");
	static const CFStringRef kIOHIDSessionPropertyALSIntPeriodOrientationPortraitInv = CFSTR("ALSIntPeriodOrientationPortraitInv");
	static const CFStringRef kIOHIDSessionPropertyALSIntPeriodOrientationLandscape = CFSTR("ALSIntPeriodOrientationLandscape");
	
#if __cplusplus
}
#endif

#endif

