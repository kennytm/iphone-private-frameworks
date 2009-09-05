/*

GSEvent.h ... Graphics Service Events.
 
Copyright (c) 2009, KennyTM~
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

#ifndef GSEVENT_H
#define GSEVENT_H

#if __cplusplus
extern "C" {
#endif

	typedef struct __GSEvent* GSEventRef;
	
#if 0
	typedef struct GSPathInfo {
		unsigned char pathIndex;		// 0x0 = 0x5C
		unsigned char pathIdentity;		// 0x1 = 0x5D
		unsigned char pathProximity;	// 0x2 = 0x5E
		CGFloat pathPressure;				// 0x4 = 0x60
		CGFloat pathMajorRadius;		// 0x8 = 0x64
		CGPoint pathLocation;			// 0xC = 0x68
		GSWindowRef pathWindow;			// 0x14 = 0x70
	} GSPathInfo;	// sizeof = 0x18.
	
	typedef enum __GSHandInfoType {
		kGSHandInfoTypeTouchDown = 0,
		kGSHandInfoTypeTouchDragged = 1,
		kGSHandInfoTypeTouchMoved = 4,
		kGSHandInfoTypeTouchUp = 5,
		kGSHandInfoTypeCancel = 8
	} GSHandInfoType;
	
	// A.k.a. XXStruct_$jUSvD
	typedef struct GSHandInfo {
		GSHandInfoType type;	// 0x0 == 0x3C
		short deltaX, deltaY;	// 2, 4 = 0x40, 0x42
		float _0x44;
		float _0x48;
		float width;			// 0x10 == 0x4C
		float _0x50;
		float height;			// 0x18 == 0x54
		float _0x58;
		unsigned char _0x5C;
		unsigned char pathInfosCount;	// 0x22 == 0x5D
		GSPathInfo pathInfos[0];		// 0x60
	} GSHandInfo;	// sizeof = 0x24.
	
	typedef struct __GSScrollWheelInfo {
		int deltaY;
		int deltaX;
	} GSScrollWheelInfo;
	
	typedef struct __GSAccelerometerInfo {
		CGFloat axisX, axisY, axisZ;
	} GSAccelerometerInfo;
	
	typedef struct __GSDeviceOrientationInfo {
		int orientation;
	} GSDeviceOrientationInfo;
	
	typedef struct __GSKeyInfo {
		UniChar keycode, characterIgnoringModifier, character;
		unsigned short characterSet;
		unsigned char isKeyRepeating
	} GSKeyInfo;
	
	typedef struct __GSAccessoryKeyStateInfo {
		short a;
		int b;
	} GSAccessoryKeyStateInfo;
	
	typedef enum __GSEventType {
		kGSEventLeftMouseDown    = 1,
		kGSEventLeftMouseUp      = 2,
		kGSEventMouseMoved       = 5,
		kGSEventLeftMouseDragged = 6,
		
		kGSEventHardwareKeyDown = 13,
		kGSEventKeyDown = kGSEventHardwareKeyDown,
		kGSEventScrollWheel = 22,
		kGSEventAccelerate = 23,
		kGSEventProximityStateChanged = 24,
		kGSEventDeviceOrientationChanged = 50,
		kGSEventUserDefaultsDidChange = 60,
		
		kGSEventResetIdleTimer = 100,
		kGSEventResetIdleDuration = 101,
		kGSEventProcessScript = 200,
		kGSEventDumpUIHierarchy = 500,
		kGSEventDumpScreenContents = 501,
		
		kGSEventMenuButtonDown = 1000,
		
		kGSEventVolumeChanged = 1006,
		kGSEventVolumeUpButtonDown = 1006,
		kGSEventVolumeUpButtonUp = 1007,
		kGSEventVolumeDownButtonDown = 1008,
		kGSEventVolumeDownButtonUp = 1009,
		kGSEventLockButtonDown = 1010,
		kGSEventLockButtonUp = 1011,
		kGSEventRingerOff = 1012,
		kGSEventRingerChanged = 1013,
		kGSEventLockDevice = 1014,
		kGSEventStatusBarMouseDragged = 1016,
		kGSEventStatusBarMouseUp = 1017,
		kGSEventHeadsetButtonDown = 1018,
		kGSEventHeadsetButtonUp = 1019,
		
		kGSEventMotionBegin = 1020,
		
		kGSEventVibrate = 1100,
		kGSEventSetBacklightFactor = 1102,
		kGSEventSetBacklightLevel = 1103,
		
		kGSEventApplicationLaunch = 2000,
		kGSEventApplicationAnimateSuspensionOrResumption = 2001,
		kGSEventAnotherApplicationFinishedLaunching = 2002,
		kGSEventApplicationResume = 2003,
		kGSEventApplicationEndResumeAnimation = 2004,
		kGSEventApplicationBeginSuspendAnimation = 2005,
		kGSEventApplicationHandleTestURL = 2006,
		kGSEventApplicationSuspendEventsOnly = 2007,
		kGSEventApplicationSuspend = 2008,
		kGSEventApplicationExit = 2009,
		kGSEventQuitTopApplication = 2010,
		kGSEventApplicationUpdateSuspendedSettings = 2011,
		
		kGSEventHand = 3001,
		
		kGSEventAccessoryAvailabilityChanged = 4000,
		kGSEventAccessoryKeyStateChanged = 4001,
		kGSEventAccessory = 4002,
		
		kGSEventOutOfLineDataRequest = 5000,
		kGSEventOutOfLineDataResponse = 5001,
		
		kGSEventUrgentMemoryWarning = 6000,
		
		kGSEventShouldRouteToFrontMost = 1<<17
	} GSEventType;
	
	typedef enum __GSEventSubType {
	} GSEventSubType;
	
	typedef enum GSEventFlags {
		kGSEventFlagMaskShift     = 1 << 17,
		kGSEventFlagMaskControl   = 1 << 18,
		kGSEventFlagMaskAlternate = 1 << 19,
		kGSEventFlagMaskCommand   = 1 << 20
	} GSEventFlags;	
	
	typedef struct GSEventRecord {
		GSEventType type; // 0x8
		GSEventSubType subtype;	// 0xC
		CGPoint location; 	// 0x10
		CGPoint windowLocation;	// 0x18
		int windowContextId;	// 0x20
		CFTimeInterval time;	// 0x24
		GSWindowRef window;	// 0x2C
		GSEventFlags flags;	// 0x30
		unsigned senderPID;	// 0x34
		CFIndex infoSize; // 0x38
	} GSEventRecord;
	
#pragma mark -
	
	/// Get the CoreFoundation type identifier of GSEvent.
	CFTypeID GSEventGetTypeID();
	
	void GSEventRegisterEventCallBack(...);
	void GSEventRegisterFindWindowCallBack(...);
	void GSEventRegisterTransformToWindowCoordsCallBack(...);
	
	GSEventHandInfo GSEventGetHandInfo(GSEventRef event);
	GSPathInfo GSEventGetPathInfoAtIndex(GSEventRef event, CFIndex index);
	void GSEventSetPathInfoAtIndex(GSEventRef event, GSPathInfo pathInfo, CFIndex index);
	
	void GSEventSetHandInfoScale(GSEventRef event, CGFloat denominator);
	void GSEventChangeHandInfoToCancel(GSEventRef event);
	
	void GSEventDisableHandEventCoalescing(Boolean disableHandCoalescing);
	
	Boolean GSEventIsHandEvent(GSEventRef event);
	Boolean GSEventShouldRouteToFrontMost(GSEventRef event);
	void GSEventRemoveShouldRouteToFrontMost(GSEventRef event);
	
	GSEventType GSEventGetType(GSEventRef event);
	GSEventSubType GSEventGetSubType(GSEventRef event);
	int GSEventGetWindowContextId(GSEventRef event);
	CGPoint GSEventGetLocationInWindow(GSEventRef event);
	CGPoint GSEventGetOuterMostPathPosition(GSEventRef event);
	CGPoint GSEventGetInnerMostPathPosition(GSEventRef event);
	
	void GSEventSetLocationInWindow(GSEventRef event, CGPoint location);
	void GSEventSetType(GSEventRef event, GSEventType type);
	
	CGFloat GSEventGetDeltaX(GSEventRef event);
	CGFloat GSEventGetDeltaY(GSEventRef event);
	void GSEventSetDeltaX(GSEventRef event, CGFloat deltaX);
	void GSEventSetDeltaY(GSEventRef event, CGFloat deltaY);
	
	CGFloat GSEventAccelerometerAxisX(GSEventRef event);
	CGFloat GSEventAccelerometerAxisY(GSEventRef event);
	CGFloat GSEventAccelerometerAxisZ(GSEventRef event);
	
	// Returns a UIDeviceOrientation. 
	int GSEventDeviceOrientation(GSEventRef event);
	int GSEventGetClickCount(GSEventRef event);
	
	CFTimeInterval GSEventGetTimestamp(GSEventRef event);
	GSWindowRef GSEventGetWindow(GSEventRef event);
	
	unsigned short GSEventGetCharacterSet(GSEventRef event);
	GSEventFlags GSEventGetModifierFlags(GSEventRef event);
	Boolean GSEventIsKeyRepeating(GSEventRef event);
	
	unsigned GSEventGetSenderPID(GSEventRef event);
	const GSEventRecord* _GSEventGetGSEventRecord(GSEventRef event);
	
	// _GSEventConvertFromMachTime
	
	GSAccessoryKeyStateInfo GSEventGetAccessoryKeyStateInfo(GSEventRef event);
	
	const GSEventRecord* GSEventRecordGetRecordDataWithPlist(CFDictionaryRef plist);
	
	void GSEventSendOutOfLineData(...);
	
	
	
	SInt32 _GSEventGetSoundActionID(CFStringRef path);
	void _GSEventPlayAlertOrSystemSoundAtPath(CFStringRef path, Boolean loop, Boolean alert);
	
	SInt32 GSEventPrimeSoundAtPath(CFStringRef path);
	void GSEventStopSoundAtPath(CFStringRef path, Boolean unknown);
	void GSEventPlayAlertSoundAtPath(CFStringRef path);// Equivalent to _GSEventPlayAlertOrSystemSoundAtPath(path, 0, 1)
	void GSEventLoopSoundAtPath(CFStringRef path);// Equivalent to _GSEventPlayAlertOrSystemSoundAtPath(path, 1, 0)
	void GSEventPlaySoundAtPath(CFStringRef path);// Equivalent to _GSEventPlayAlertOrSystemSoundAtPath(path, 0, 0)
	
	GSEventRef GSEventCopy(GSEventRef event);
	GSEventRef GSEventCreateAccessoryKeyStateEvent(GSEventRef event, GSEventFlags flags);
	GSEventRef GSEventCreateWithEventRecord(const GSEventRecord* record);
#endif
	
#if __cplusplus
}
#endif

#endif