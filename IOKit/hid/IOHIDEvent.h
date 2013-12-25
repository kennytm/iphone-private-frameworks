/*
 
IOHIDEvent.h ... Header for IOHIDEvent*** functions.

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

// With reference to http://www.opensource.apple.com/source/IOHIDFamily/IOHIDFamily-308/IOHIDFamily/IOHIDEvent.h .

#ifndef IOKIT_HID_IOHIDEVENT_H
#define IOKIT_HID_IOHIDEVENT_H 1

//#include <libkern/OSTypes.h>
#include <IOKit/IOTypes.h>
#include <IOKit/hid/IOHIDEventTypes.h>
#include <IOKit/hid/IOHIDEventData.h>
#include <CoreFoundation/CoreFoundation.h>

#if __cplusplus
extern "C" {
#endif
	
	typedef struct __IOHIDEvent
#if 0
	{
		CFRuntimeBase base;	// 0, 4
		AbsoluteTime _timeStamp;	// 8, c
		int x10;	// 10
		int x14;	// 14
		IOOptionBits _options;	// 18
		unsigned _typeMask;	// 1c
		CFMutableArrayRef _children;	// 20
		struct __IOHIDEvent* _parent;	// 24
		
		size_t recordSize;	// 28
		void record[];		
	}
#endif
	* IOHIDEventRef;
	
#pragma mark -
#pragma mark GetTypeID
	
	/*! @function IOHIDEventGetTypeID */
	CFTypeID IOHIDEventGetTypeID(void);
	
#pragma mark -
#pragma mark Generic creation functions
	
	IOHIDEventRef IOHIDEventCreateCopy(CFAllocatorRef allocator, IOHIDEventRef event);
	/*! @function IOHIDEventCreate
	 @abstract Create an IOHIDEvent.
	 @discussion All event-specific parameters are zeroed. */
	IOHIDEventRef IOHIDEventCreate(CFAllocatorRef allocator, IOHIDEventType type, AbsoluteTime timeStamp, IOOptionBits options);
	
	CFMutableDataRef IOHIDEventCreateData(CFAllocatorRef allocator, IOHIDEventRef event);
	IOHIDEventRef IOHIDEventCreateWithData(CFAllocatorRef allocator, CFDataRef data);
	
#pragma mark -
#pragma mark Predefined creation functions
	
	IOHIDEventRef IOHIDEventCreateProgressEvent(CFAllocatorRef allocator, AbsoluteTime timeStamp,
												uint32_t eventType, IOHIDFloat level, IOOptionBits options);
	IOHIDEventRef IOHIDEventCreateVendorDefinedEvent(CFAllocatorRef allocator, AbsoluteTime timeStamp,
													 uint16_t usagePage, uint16_t usage, uint32_t version, const uint8_t* data, uint32_t length, IOOptionBits options);
	IOHIDEventRef IOHIDEventCreateSwipeEvent(CFAllocatorRef allocator, AbsoluteTime timeStamp, IOHIDSwipeMask swipeMask, IOOptionBits options);
	
	/*! @function IOHIDEventCreateDigitizerEvent
	 @abstract Create a digitizer event. You should use the more specialized methods instead. */
	IOHIDEventRef IOHIDEventCreateDigitizerEvent(CFAllocatorRef allocator, AbsoluteTime timeStamp, IOHIDDigitizerTransducerType type,
												 uint32_t index, uint32_t identity, uint32_t eventMask, uint32_t buttonMask,
												 IOHIDFloat x, IOHIDFloat y, IOHIDFloat z, IOHIDFloat tipPressure, IOHIDFloat barrelPressure,
												 Boolean range, Boolean touch, IOOptionBits options);
	IOHIDEventRef IOHIDEventCreateDigitizerFingerEventWithQuality(CFAllocatorRef allocator, AbsoluteTime timeStamp,
																  uint32_t index, uint32_t identity, uint32_t eventMask,
																  IOHIDFloat x, IOHIDFloat y, IOHIDFloat z, IOHIDFloat tipPressure, IOHIDFloat twist,
																  IOHIDFloat minorRadius, IOHIDFloat majorRadius, IOHIDFloat quality, IOHIDFloat density, IOHIDFloat irregularity,
																  Boolean range, Boolean touch, IOOptionBits options);
	/*! @function IOHIDEventCreateDigitizerFingerEvent
	 @abstract Create a finger digitizer event with default qualities.
	 @discussion The default qualities are:
	  - minorRadius = 5 mm,
	  - majorRadius = 5 mm,
	  - quality = 1,
	  - density = 1,
	  - irregularity = 1. */
	IOHIDEventRef IOHIDEventCreateDigitizerFingerEvent(CFAllocatorRef allocator, AbsoluteTime timeStamp,
													   uint32_t index, uint32_t identity, uint32_t eventMask,
													   IOHIDFloat x, IOHIDFloat y, IOHIDFloat z, IOHIDFloat tipPressure, IOHIDFloat twist,
													   Boolean range, Boolean touch, IOOptionBits options);
	IOHIDEventRef IOHIDEventCreateDigitizerStylusEventWithPolarOrientation(CFAllocatorRef allocator, AbsoluteTime timeStamp,
																		   uint32_t index, uint32_t identity, uint32_t eventMask, uint32_t buttonMask,
																		   IOHIDFloat x, IOHIDFloat y, IOHIDFloat z, IOHIDFloat tipPressure, IOHIDFloat barrelPressure,
																		   IOHIDFloat twist, IOHIDFloat altitude, IOHIDFloat azimuth, 
																		   Boolean range, Boolean invert, IOOptionBits options);
	/*! @function IOHIDEventCreateDigitizerStylusEvent
	 @discussion Same as IOHIDEventCreateDigitizerStylusEventWithPolarOrientation? */
	IOHIDEventRef IOHIDEventCreateDigitizerStylusEvent(CFAllocatorRef allocator, AbsoluteTime timeStamp,
													   uint32_t index, uint32_t identity, uint32_t eventMask, uint32_t buttonMask,
													   IOHIDFloat x, IOHIDFloat y, IOHIDFloat z, IOHIDFloat tipPressure, IOHIDFloat barrelPressure,
													   IOHIDFloat twist, IOHIDFloat altitude, IOHIDFloat azimuth, 
													   Boolean range, Boolean invert, IOOptionBits options);

	IOHIDEventRef IOHIDEventCreateProximtyEvent(CFAllocatorRef allocator, AbsoluteTime timeStamp, IOHIDProximityDetectionMask detectionMask, IOOptionBits options);
#define IOHIDEventCreateProximityEvent IOHIDEventCreateProximtyEvent
	IOHIDEventRef IOHIDEventCreateAmbientLightSensorEvent(CFAllocatorRef allocator, AbsoluteTime timeStamp, IOHIDFloat level, IOOptionBits options);
	
	/*! @function IOHIDEventCreateMouseEvent
	 @abstract Create an mouse event, with pressure of 1.0. */
	IOHIDEventRef IOHIDEventCreateMouseEvent(CFAllocatorRef allocator, AbsoluteTime timeStamp,
											 IOHIDFloat x, IOHIDFloat y, IOHIDFloat z, uint32_t buttonMask, IOOptionBits options);
	/*! @function IOHIDEventCreateMouseEventWithPressure
	 @abstract Create an mouse event with pressure.
	 @discussion The mouse is considered clicked when the pressure is > 0.15. */
	IOHIDEventRef IOHIDEventCreateMouseEventWithPressure(CFAllocatorRef allocator, AbsoluteTime timeStamp,
														 IOHIDFloat x, IOHIDFloat y, IOHIDFloat z, uint32_t buttonMask, IOHIDFloat pressure, IOOptionBits options);
	/*! @function IOHIDEventCreateButtonEvent
	 @abstract Create an button event, with pressure of 1.0. */
	IOHIDEventRef IOHIDEventCreateButtonEvent(CFAllocatorRef allocator, AbsoluteTime timeStamp, uint32_t buttonMask, IOOptionBits options);
	/*! @function IOHIDEventCreateButtonEventWithPressure
	 @abstract Create an button event with pressure.
	 @discussion The button is considered pressed when the pressure is > 0.15. */
	IOHIDEventRef IOHIDEventCreateButtonEventWithPressure(CFAllocatorRef allocator, AbsoluteTime timeStamp, uint32_t buttonMask, IOHIDFloat pressure, IOOptionBits options);

	IOHIDEventRef IOHIDEventCreateKeyboardEvent(CFAllocatorRef allocator, AbsoluteTime timeStamp, uint16_t usagePage, uint16_t usage, Boolean down, IOHIDEventOptionBits flags);
	
	IOHIDEventRef IOHIDEventCreateAccelerometerEvent(CFAllocatorRef allocator, AbsoluteTime timeStamp, IOHIDFloat x, IOHIDFloat y, IOHIDFloat z, IOOptionBits options);
	IOHIDEventRef IOHIDEventCreatePolarOrientationEvent(CFAllocatorRef allocator, AbsoluteTime timeStamp, IOHIDFloat x, IOHIDFloat y, IOHIDFloat z, IOOptionBits options);
	IOHIDEventRef IOHIDEventCreateOrientationEvent(CFAllocatorRef allocator, AbsoluteTime timeStamp, IOHIDFloat x, IOHIDFloat y, IOHIDFloat z, IOOptionBits options);
	IOHIDEventRef IOHIDEventCreateVelocityEvent(CFAllocatorRef allocator, AbsoluteTime timeStamp, IOHIDFloat x, IOHIDFloat y, IOHIDFloat z, IOOptionBits options);
	IOHIDEventRef IOHIDEventCreateScaleEvent(CFAllocatorRef allocator, AbsoluteTime timeStamp, IOHIDFloat x, IOHIDFloat y, IOHIDFloat z, IOOptionBits options);
	IOHIDEventRef IOHIDEventCreateScrollEvent(CFAllocatorRef allocator, AbsoluteTime timeStamp, IOHIDFloat x, IOHIDFloat y, IOHIDFloat z, IOOptionBits options);
	IOHIDEventRef IOHIDEventCreateRotationEvent(CFAllocatorRef allocator, AbsoluteTime timeStamp, IOHIDFloat x, IOHIDFloat y, IOHIDFloat z, IOOptionBits options);
	IOHIDEventRef IOHIDEventCreateTranslationEvent(CFAllocatorRef allocator, AbsoluteTime timeStamp, IOHIDFloat x, IOHIDFloat y, IOHIDFloat z, IOOptionBits options);
	
#pragma mark -
#pragma mark Accessors
	
	IOHIDEventType IOHIDEventGetType(IOHIDEventRef event);
	
	AbsoluteTime IOHIDEventGetTimeStamp(IOHIDEventRef event);
	void IOHIDEventSetTimeStamp(IOHIDEventRef event, AbsoluteTime timeStamp);
	
	uint32_t IOHIDEventGetEventFlags(IOHIDEventRef event);
	void IOHIDEventSetEventFlags(IOHIDEventRef event, uint32_t eventFlags);
	Boolean IOHIDEventIsAbsolute(IOHIDEventRef event);
	
	IOHIDEventRef IOHIDEventGetParent(IOHIDEventRef event);
	CFArrayRef IOHIDEventGetChildren(IOHIDEventRef event);
	
	void IOHIDEventGetVendorDefinedData(IOHIDEventRef event, uint32_t* length, uint8_t** data);

#pragma mark -
#pragma mark Subevents
	
	/*! @function IOHIDEventGetEventWithOptions
	 @abstract Get the deepest event that bears the specified type and matches the options.
	 @discussion If any of the top 4 bits of options is set (i.e. (options & 0xF0000000) != 0), the children of this event will not be checked. */
	IOHIDEventRef IOHIDEventGetEventWithOptions(IOHIDEventRef event, IOHIDEventType type, IOOptionBits options);
	/*! @function IOHIDEventGetEvent
	 @abstract Get the event that bears the specified type. 
	 @discussion Equivalent to IOHIDEventGetEventWithOptions(event, type, 0xF0000000); */
	IOHIDEventRef IOHIDEventGetEvent(IOHIDEventRef event, IOHIDEventType type);
	
	void IOHIDEventSetFloatValueWithOptions(IOHIDEventRef event, IOHIDEventField field, IOHIDFloat value, IOOptionBits options);
	void IOHIDEventSetFloatValue(IOHIDEventRef event, IOHIDEventField field, IOHIDFloat value);
	void IOHIDEventSetIntegerValueWithOptions(IOHIDEventRef event, IOHIDEventField field, int value, IOOptionBits options);
	void IOHIDEventSetIntegerValue(IOHIDEventRef event, IOHIDEventField field, int value);
	void IOHIDEventSetPositionWithOptions(IOHIDEventRef event, IOHIDEventField field, IOHID3DPoint position, IOOptionBits options);
	void IOHIDEventSetPosition(IOHIDEventRef event, IOHIDEventField field, IOHID3DPoint position);
	
	IOHIDFloat IOHIDEventGetFloatValueWithOptions(IOHIDEventRef event, IOHIDEventField field, IOOptionBits options);
	IOHIDFloat IOHIDEventGetFloatValue(IOHIDEventRef event, IOHIDEventField field);
	int IOHIDEventGetIntegerValueWithOptions(IOHIDEventRef event, IOHIDEventField field, IOOptionBits options);
	int IOHIDEventGetIntegerValue(IOHIDEventRef event, IOHIDEventField field);
	IOHID3DPoint IOHIDEventGetPositionWithOptions(IOHIDEventRef event, IOHIDEventField field, IOOptionBits options);
	IOHID3DPoint IOHIDEventGetPosition(IOHIDEventRef event, IOHIDEventField field);
	
	/*! @function IOHIDEventConformsToWithOptions
	 @abstract Returns if the event or any of its children bears the specified type and options.
	 @discussion If any of the top 4 bits of options is set (i.e. (options & 0xF0000000) != 0), the children of this event will not be checked. */
	Boolean IOHIDEventConformsToWithOptions(IOHIDEventRef event, IOHIDEventType type, IOOptionBits options);
	/*! @function IOHIDEventConformsTo
	 @abstract Returns if the event bears the specified type.
	 @discussion Equivalent to IOHIDEventConformsToWithOptions(event, type, 0xF0000000); */
	Boolean IOHIDEventConformsTo(IOHIDEventRef event, IOHIDEventType type);

	void IOHIDEventRemoveEvent(IOHIDEventRef event, IOHIDEventRef childEvent);
	void IOHIDEventAppendEvent(IOHIDEventRef event, IOHIDEventRef childEvent);

#if __cplusplus
}
#endif

#endif
