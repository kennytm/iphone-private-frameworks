/*
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * Copyright (c) 1999-2003 Apple Computer, Inc.  All Rights Reserved.
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

#ifndef _IOKIT_HID_IOHIDEVENTDATA_H
#define _IOKIT_HID_IOHIDEVENTDATA_H

#include <IOKit/IOTypes.h>
#include <IOKit/hid/IOHIDEventTypes.h>

#ifdef KERNEL
    #include <IOKit/IOLib.h>

    #define IOHIDEventRef IOHIDEvent *
#else
    #include <IOKit/hid/IOHIDEvent.h>

    typedef struct IOHIDEventData IOHIDEventData;
#endif

//==============================================================================
// IOHIDEventData Declarations
//==============================================================================

#define IOHIDEVENT_BASE         \
    uint32_t        size;       \
    IOHIDEventType  type;       \
    uint64_t        timestamp;  \
    uint32_t        options;

/*!
    @typedef    IOHIDEventData
    @abstract   
    @discussion 
    @field      size        Size, in bytes, of the memory detailing this
                            particular event
    @field      type        Type of this particular event
    @field      options     Event specific options
*/

struct IOHIDEventData{
    IOHIDEVENT_BASE;
};

typedef struct _IOHIDVendorDefinedEventData {
    IOHIDEVENT_BASE;
    uint16_t        usagePage;
    uint16_t        usage;
    uint32_t        version;
    uint32_t        length;
    uint8_t         data[0];
} IOHIDVendorDefinedEventData;

enum {
    kIOHIDKeyboardIsRepeat      = 0x00010000
};

typedef struct _IOHIDKeyboardEventData {
    IOHIDEVENT_BASE;                            // options = kHIDKeyboardRepeat
    uint16_t        usagePage;
    uint16_t        usage;
    boolean_t       down;
} IOHIDKeyboardEventData;

enum {
    kIOHIDEventOptionIgnore     = 0xf0000000
};

enum {
    kIOHIDTransducerRange       = 0x00010000,
    kIOHIDTransducerTouch       = 0x00020000,
    kIOHIDTransducerInvert      = 0x00040000,
};

enum {
    kIOHIDDigitizerOrientationTypeTilt = 0,
    kIOHIDDigitizerOrientationTypePolar,
    kIOHIDDigitizerOrientationTypeQuality
};
typedef uint8_t IOHIDDigitizerOrientationType;

#define IOHIDAXISEVENT_BASE     \
    struct {                    \
        IOFixed x;              \
        IOFixed y;              \
        IOFixed z;              \
    } position;

typedef struct _IOHIDAxisEventData {
    IOHIDEVENT_BASE;                            // options = kHIDAxisRelative
    IOHIDAXISEVENT_BASE;
} IOHIDAxisEventData, IOHIDTranslationData, IOHIDRotationEventData, IOHIDScrollEventData, IOHIDScaleEventData, IOHIDVelocityData, IOHIDOrientationEventData;

typedef struct _IOHIDAccelerometerEventData {
    IOHIDEVENT_BASE;                            // options = kHIDAxisRelative
    IOHIDAXISEVENT_BASE;
    uint32_t        acclType;
} IOHIDAccelerometerEventData;

typedef struct _IOHIDAmbientLightSensorEventData {
    IOHIDEVENT_BASE;                            // options = kHIDAxisRelative
    uint32_t        level;
    uint32_t        ch0;
    uint32_t        ch1;
    Boolean         brightnessChanged;
} IOHIDAmbientLightSensorEventData;

typedef struct _IOHIDTemperatureEventData {
    IOHIDEVENT_BASE;                            
    IOFixed        level;
} IOHIDTemperatureEventData;

typedef struct _IOHIDProximityEventData {
    IOHIDEVENT_BASE;                            
    uint32_t        detectionMask;
} IOHIDProximityEventData;

typedef struct _IOHIDProgressEventData {
    IOHIDEVENT_BASE;
    uint32_t        eventType;
    IOFixed         level;
} IOHIDProgressEventData;


#define IOHIDBUTTONEVENT_BASE           \
    struct {                            \
        uint32_t        buttonMask;     \
        IOFixed         pressure;       \
        uint8_t         buttonNumber;   \
        uint8_t         clickState;     \
    } button;

typedef struct _IOHIDButtonEventData {
    IOHIDEVENT_BASE;
    IOHIDBUTTONEVENT_BASE;
} IOHIDButtonEventData;

typedef struct _IOHIDMouseEventData {
    IOHIDEVENT_BASE;
    IOHIDAXISEVENT_BASE;
    IOHIDBUTTONEVENT_BASE;
} IOHIDMouseEventData;


typedef struct _IOHIDDigitizerEventData {
    IOHIDEVENT_BASE;                            // options = kIOHIDTransducerRange, kHIDTransducerTouch, kHIDTransducerInvert
    IOHIDAXISEVENT_BASE;						// 3c, 40, 44

    uint32_t        transducerIndex;   
    uint32_t        transducerType;				// could overload this to include that both the hand and finger id.
    uint32_t        identity;                   // Specifies a unique ID of the current transducer action.
    uint32_t        eventMask;                  // the type of event that has occurred: range, touch, position
    uint32_t        childEventMask;             // CHILD: the type of event that has occurred: range, touch, position
    
    uint32_t        buttonMask;                 // Bit field representing the current button state
                                                // Pressure field are assumed to be scaled from 0.0 to 1.0
    IOFixed         tipPressure;                // Force exerted against the digitizer surface by the transducer.
    IOFixed         barrelPressure;             // Force exerted directly by the user on a transducer sensor.
    
    IOFixed         twist;                      // Specifies the clockwise rotation of the cursor around its own major axis.  Unsure it the device should declare units via properties or event.  My first inclination is force degrees as the is the unit already expected by AppKit, Carbon and OpenGL.
    uint32_t        orientationType;            // Specifies the orientation type used by the transducer.
    union {
        struct {                                // X Tilt and Y Tilt are used together to specify the tilt away from normal of a digitizer transducer. In its normal position, the values of X Tilt and Y Tilt for a transducer are both zero.
            IOFixed     x;                      // This quantity is used in conjunction with Y Tilt to represent the tilt away from normal of a transducer, such as a stylus. The X Tilt value represents the plane angle between the Y-Z plane and the plane containing the transducer axis and the Y axis. A positive X Tilt is to the right. 
            IOFixed     y;                      // This value represents the angle between the X-Z and transducer-X planes. A positive Y Tilt is toward the user.
        } tilt;
        struct {                                // X Tilt and Y Tilt are used together to specify the tilt away from normal of a digitizer transducer. In its normal position, the values of X Tilt and Y Tilt for a transducer are both zero.
            IOFixed  altitude;                  //The angle with the X-Y plane though a signed, semicicular range.  Positive values specify an angle downward and toward the positive Z axis. 
            IOFixed  azimuth;                   // Specifies the counter clockwise rotation of the cursor around the Z axis though a full circular range.
        } polar;
        struct {
            IOFixed  quality;                    // If set, indicates that the transducer is sensed to be in a relatively noise-free region of digitizing.
            IOFixed  density;
            IOFixed  irregularity;
            IOFixed  majorRadius;                // units in mm
            IOFixed  minorRadius;                // units in mm
        } quality;
    }orientation;
} IOHIDDigitizerEventData;

typedef struct _IOHIDSwipeEventData {
    IOHIDEVENT_BASE;                            
    IOHIDSwipeMask swipeMask;
} IOHIDSwipeEventData;


/*!
    @typedef    IOHIDSystemQueueElement
    @abstract   Memory structure defining the layout of each event queue element
    @discussion The IOHIDEventQueueElement represents a portion of mememory in the
                new IOHIDEventQueue.  It is possible that a event queue element
                can contain multiple interpretations of a given event.  The first
                event is always considered the primary event.
    @field      version     Version of the event queue element
    @field      size        Size, in bytes, of this particular event queue element
    @field      timeStamp   Time at which event was dispatched
    @field      deviceID    ID of the sending device
    @field      options     Options for further developement
    @field      eventCount  The number of events contained in this transaction
    @field      events      Begining offset of contiguous mememory that contains the
                            pertinent event data
*/
typedef struct _IOHIDSystemQueueElement {
    uint64_t        timeStamp;
    uint64_t        deviceID;
    uint32_t        options;
    uint32_t        eventCount;
    IOHIDEventData  events[];
} IOHIDSystemQueueElement; 

//******************************************************************************
// MACROS
//******************************************************************************

#define IOHIDEventFieldEventType(field) ((field >> 16) & 0xffff)
#define IOHIDEventFieldOffset(field) (field & 0xffff)
#define IOHIDEventGetSize(type,size)    \
{                                       \
    switch ( type ) {                   \
        case kIOHIDEventTypeNULL:       \
            size = sizeof(IOHIDEventData);\
            break;                      \
        case kIOHIDEventTypeVendorDefined:\
            size = sizeof(IOHIDVendorDefinedEventData);\
            break;                      \
        case kIOHIDEventTypeKeyboard:   \
            size = sizeof(IOHIDKeyboardEventData);\
            break;                      \
        case kIOHIDEventTypeTranslation:\
        case kIOHIDEventTypeRotation:   \
        case kIOHIDEventTypeScroll:     \
        case kIOHIDEventTypeScale:      \
        case kIOHIDEventTypeVelocity:   \
        case kIOHIDEventTypeOrientation:\
            size = sizeof(IOHIDAxisEventData);\
            break;                      \
        case kIOHIDEventTypeAccelerometer:\
            size = sizeof(IOHIDAccelerometerEventData);\
            break;\
        case kIOHIDEventTypeAmbientLightSensor:\
            size = sizeof(IOHIDAmbientLightSensorEventData);\
            break;                      \
        case kIOHIDEventTypeProximity:  \
            size = sizeof(IOHIDProximityEventData);\
            break;                      \
        case kIOHIDEventTypeButton:     \
            size = sizeof(IOHIDButtonEventData);\
            break;                      \
        case kIOHIDEventTypeDigitizer:  \
            size = sizeof(IOHIDDigitizerEventData);\
            break;                      \
        case kIOHIDEventTypeTemperature:\
            size = sizeof(IOHIDTemperatureEventData);\
            break;                      \
        case kIOHIDEventTypeSwipe:\
            size = sizeof(IOHIDSwipeEventData);\
            break;                      \
        case kIOHIDEventTypeMouse:\
            size = sizeof(IOHIDMouseEventData);\
            break;                      \
        case kIOHIDEventTypeProgress:\
            size = sizeof(IOHIDProgressEventData);\
            break;                      \
        default:                        \
            size = 0;                   \
            break;                      \
    }                                   \
}
#define IOHIDEventGetQueueElementSize(type,size)\
{                                               \
    IOHIDEventGetSize(type,size);               \
    size += sizeof(IOHIDSystemQueueElement);    \
}

#ifdef KERNEL
    #ifdef HIDEVENTFIXED        
        #define IOHIDEventValueFloat(value) (value)
        #define IOHIDEventValueFixed(value) (value)
    #else
        #define IOHIDEventValueFloat(value) (value >> 16)
        #define IOHIDEventValueFixed(value) (value << 16)
    #endif
    #define IOHIDEventGetEventWithOptions(event, type, options) event->getEvent(type, options)
    #define GET_EVENTDATA(event) event->_data
#else
    #define IOHIDEventValueFloat(value) (value / 65536.0)
    #define IOHIDEventValueFixed(value) (value * 65536)
    #define GET_EVENTDATA(event) event->eventData
#endif

//==============================================================================
// IOHIDEventGetValue MACRO
//==============================================================================
#define GET_EVENTDATA_VALUE(eventData, fieldEvType, fieldOffset, value)\
{                                                       \
    switch ( fieldEvType ) {                            \
        case kIOHIDEventTypeNULL:                       \
            switch ( fieldOffset ) {                    \
                case IOHIDEventFieldOffset(kIOHIDEventFieldIsRelative): \
                    value = (eventData->options & kIOHIDEventOptionIsAbsolute) == 0; \
                    break;                              \
                case IOHIDEventFieldOffset(kIOHIDEventFieldIsCollection): \
                    value = (eventData->options & kIOHIDEventOptionIsCollection) != 0; \
                    break;                              \
            }; break;                                   \
        case kIOHIDEventTypeVendorDefined:              \
            {                                           \
                IOHIDVendorDefinedEventData * sysDef = (IOHIDVendorDefinedEventData*)eventData; \
                switch ( fieldOffset ) {                \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldVendorDefinedUsagePage): \
                        value = sysDef->usagePage;      \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldVendorDefinedUsage): \
                        value = sysDef->usage;          \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldVendorDefinedVersion): \
                        value = sysDef->version;        \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldVendorDefinedDataLength): \
                        value = sysDef->length;         \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldVendorDefinedData): \
                        if (sysDef->data)               \
                            value = *((typeof(value)*) sysDef->data); \
                        break;                          \
                };                                      \
            }                                           \
            break;                                      \
        case kIOHIDEventTypeProgress:                     \
            {                                           \
                IOHIDProgressEventData * progress = (IOHIDProgressEventData*)eventData; \
                switch ( fieldOffset ) {                \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldProgressEventType): \
                        value = progress->eventType;    \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldProgressLevel): \
                        value = IOHIDEventValueFloat(progress->level); \
                        break;                          \
                };                                      \
            }                                           \
            break;                                      \
        case kIOHIDEventTypeButton:                     \
            {                                           \
                IOHIDButtonEventData * button = (IOHIDButtonEventData*)eventData; \
                switch ( fieldOffset ) {                \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldButtonMask): \
                        value = button->button.buttonMask;     \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldButtonNumber): \
                        value = button->button.buttonNumber;   \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldButtonClickCount): \
                        value = button->button.clickState;     \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldButtonPressure): \
                        value = IOHIDEventValueFloat(button->button.pressure); \
                        break;                          \
                };                                      \
            }                                           \
            break;                                      \
        case kIOHIDEventTypeAccelerometer:                     \
            {                                           \
                IOHIDAccelerometerEventData * accl = (IOHIDAccelerometerEventData*)eventData; \
                switch ( fieldOffset ) {                \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldAccelerometerX): \
                        value = IOHIDEventValueFloat(accl->position.x); \
                        break;                              \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldAccelerometerY): \
                        value = IOHIDEventValueFloat(accl->position.y); \
                        break;                              \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldAccelerometerZ): \
                        value = IOHIDEventValueFloat(accl->position.z); \
                        break;                              \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldAccelerometerType): \
                        value = accl->acclType;     \
                        break;                          \
                };                                      \
            }                                           \
            break;                                      \
        case kIOHIDEventTypeMouse:                     \
            {                                           \
                IOHIDMouseEventData * mouse = (IOHIDMouseEventData*)eventData; \
                switch ( fieldOffset ) {                \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldMouseX): \
                        value = IOHIDEventValueFloat(mouse->position.x); \
                        break;                              \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldMouseY): \
                        value = IOHIDEventValueFloat(mouse->position.y); \
                        break;                              \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldMouseZ): \
                        value = IOHIDEventValueFloat(mouse->position.z); \
                        break;                              \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldMouseButtonMask): \
                        value = mouse->button.buttonMask;     \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldMouseNumber): \
                        value = mouse->button.buttonNumber;   \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldMouseClickCount): \
                        value = mouse->button.clickState;     \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldMousePressure): \
                        value = IOHIDEventValueFloat(mouse->button.pressure); \
                        break;                          \
                };                                      \
            }                                           \
            break;                                      \
        case kIOHIDEventTypeSwipe:                      \
            {                                           \
                IOHIDSwipeEventData * swipe = (IOHIDSwipeEventData *)eventData; \
                switch ( fieldOffset ) {                \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldSwipeMask):       \
                        value = swipe->swipeMask;       \
                        break;                          \
                };                                      \
            }                                           \
            break;                                      \
        case kIOHIDEventTypeTemperature:                \
            {                                           \
                IOHIDTemperatureEventData * temp = (IOHIDTemperatureEventData *)eventData; \
                switch ( fieldOffset ) {                    \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldTemperatureLevel):       \
                        value = IOHIDEventValueFloat(temp->level);\
                        break;                          \
                };                                      \
            }                                           \
            break;                                      \
        case kIOHIDEventTypeTranslation:                \
        case kIOHIDEventTypeRotation:                   \
        case kIOHIDEventTypeScroll:                     \
        case kIOHIDEventTypeScale:                      \
        case kIOHIDEventTypeVelocity:                   \
        case kIOHIDEventTypeOrientation:                \
            {                                           \
                IOHIDAxisEventData * axis = (IOHIDAxisEventData *)eventData; \
                switch ( fieldOffset ) {                    \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldTranslationX):       \
                    /*                                                              \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldRotationX):          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldScrollX):            \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldScaleX):             \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldVelocityX):          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerX);         \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldOrientationRadius):  \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldAccelerometerX): \
                    */                                                              \
                        value = IOHIDEventValueFloat(axis->position.x); \
                        break;                              \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldTranslationY):       \
                    /*                                                              \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldRotationY):          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldScrollY):            \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldScaleY):             \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldVelocityY):          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerY);         \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldOrientationAzimuth): \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldAccelerometerY): \
                    */                                                              \
                        value = IOHIDEventValueFloat(axis->position.y); \
                        break;                              \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldTranslationZ):       \
                    /*                                                              \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldRotationZ):          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldScrollZ):            \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldScaleZ):             \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldVelocityZ):          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerZ);         \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldOrientationAltitude):\
                    case IOHIDEventFieldOffset(kIOHIDEventFieldAccelerometerZ): \
                    */                                                              \
                        value = IOHIDEventValueFloat(axis->position.z); \
                        break;                              \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldScrollIsPixels):         \
                        value = ((axis->options & kIOHIDEventOptionPixelUnits) != 0);\
                        break;                              \
                };                                          \
            }                                           \
            break;                                      \
        case kIOHIDEventTypeAmbientLightSensor:         \
            {                                           \
                IOHIDAmbientLightSensorEventData * alsEvent = (IOHIDAmbientLightSensorEventData *)eventData;\
                switch ( fieldOffset ) {                \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldAmbientLightSensorLevel): \
                        value = alsEvent->level;        \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldAmbientLightSensorRawChannel0): \
                        value = alsEvent->ch0;          \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldAmbientLightSensorRawChannel1): \
                        value = alsEvent->ch1;          \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldAmbientLightDisplayBrightnessChanged): \
                        value = alsEvent->brightnessChanged; \
                        break;                          \
                };                                      \
            }                                           \
            break;                                      \
        case kIOHIDEventTypeProximity:                  \
            {                                           \
                IOHIDProximityEventData * proxEvent = (IOHIDProximityEventData *)eventData;\
                switch ( fieldOffset ) {                \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldProximityDetectionMask): \
                        value = proxEvent->detectionMask; \
                        break;                          \
                };                                      \
            }                                           \
            break;                                      \
        case kIOHIDEventTypeKeyboard:                   \
            {                                           \
                IOHIDKeyboardEventData * keyEvent = (IOHIDKeyboardEventData *)eventData;\
                switch ( fieldOffset ) {                \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldKeyboardUsagePage): \
                        value = keyEvent->usagePage;    \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldKeyboardUsage):     \
                        value = keyEvent->usage;        \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldKeyboardDown):    \
                        value = keyEvent->down;         \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldKeyboardRepeat):  \
                        value = (keyEvent->options & kIOHIDKeyboardIsRepeat);\
                        break;                          \
                };                                      \
            }                                           \
            break;                                      \
        case kIOHIDEventTypeDigitizer:                  \
            {                                           \
                IOHIDDigitizerEventData * digEvent = (IOHIDDigitizerEventData *)eventData; \
                switch ( fieldOffset ) {                \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerX): \
                        value = IOHIDEventValueFloat(digEvent->position.x);   \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerY): \
                        value = IOHIDEventValueFloat(digEvent->position.y);   \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerZ): \
                        value = IOHIDEventValueFloat(digEvent->position.z);   \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerButtonMask): \
                        value = digEvent->buttonMask;   \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerIndex): \
                        value = digEvent->transducerIndex; \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerIdentity): \
                        value = digEvent->identity;     \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerEventMask): \
                        value = digEvent->eventMask;    \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerChildEventMask): \
                        value = digEvent->childEventMask; \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerRange): \
                        value = (digEvent->options & kIOHIDTransducerRange) != 0;\
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerTouch): \
                        value = (digEvent->options & kIOHIDTransducerTouch) != 0;\
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerCollection): \
                        value = (digEvent->options & kIOHIDEventOptionIsCollection) != 0;\
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerPressure): \
                        value = IOHIDEventValueFloat(digEvent->tipPressure); \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerBarrelPressure): \
                        value = IOHIDEventValueFloat(digEvent->barrelPressure);   \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerTwist): \
                        value = IOHIDEventValueFloat(digEvent->twist);        \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerTiltX): \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerTiltY): \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerQuality): \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerDensity): \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerIrregularity): \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerMajorRadius): \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerMinorRadius): \
                        switch ( digEvent->orientationType ) {\
                            case kIOHIDDigitizerOrientationTypeTilt:\
                                switch ( fieldOffset ) {\
                                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerTiltX): \
                                        value = IOHIDEventValueFloat(digEvent->orientation.tilt.x); \
                                        break;          \
                                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerTiltY): \
                                        value = IOHIDEventValueFloat(digEvent->orientation.tilt.y); \
                                        break;          \
                                };                      \
                                break;                  \
                            case kIOHIDDigitizerOrientationTypePolar:\
                                switch ( fieldOffset ) {\
                                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerAltitude): \
                                        value = IOHIDEventValueFloat(digEvent->orientation.polar.altitude); \
                                        break;          \
                                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerAzimuth): \
                                        value = IOHIDEventValueFloat(digEvent->orientation.polar.azimuth); \
                                        break;          \
                                };                      \
                                break;                  \
                            case kIOHIDDigitizerOrientationTypeQuality:\
                                switch ( fieldOffset ) {\
                                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerQuality): \
                                        value = IOHIDEventValueFloat(digEvent->orientation.quality.quality); \
                                        break;          \
                                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerDensity): \
                                        value = IOHIDEventValueFloat(digEvent->orientation.quality.density); \
                                        break;          \
                                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerIrregularity): \
                                        value = IOHIDEventValueFloat(digEvent->orientation.quality.irregularity); \
                                        break;          \
                                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerMajorRadius): \
                                        value = IOHIDEventValueFloat(digEvent->orientation.quality.majorRadius); \
                                        break;          \
                                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerMinorRadius): \
                                        value = IOHIDEventValueFloat(digEvent->orientation.quality.minorRadius); \
                                        break;          \
                                };                      \
                                break;                  \
                        };                              \
                        break;                          \
                };                                      \
            }                                           \
            break;                                      \
    };                                                  \
}

#define GET_EVENT_VALUE(event, field, value, options) \
{   IOHIDEventType  fieldEvType = IOHIDEventFieldEventType(field);  \
    uint32_t        fieldOffset = IOHIDEventFieldOffset(field);     \
    IOHIDEventRef   ev          = NULL;                             \
    if ( (ev = IOHIDEventGetEventWithOptions(event, fieldEvType, options)) ) {\
        GET_EVENTDATA_VALUE(GET_EVENTDATA(ev),fieldEvType,fieldOffset,value);\
    }                                                               \
}

//==============================================================================
// IOHIDEventSetValue MACRO
//==============================================================================
#define SET_EVENTDATA_VALUE(eventData, fieldEvType, fieldOffset, value) \
{   switch ( fieldEvType ) {                            \
        case kIOHIDEventTypeNULL:                       \
            switch ( fieldOffset ) {                    \
                case IOHIDEventFieldOffset(kIOHIDEventFieldIsRelative): \
                    if ( value )                        \
                        eventData->options &= ~kIOHIDEventOptionIsAbsolute; \
                    else                                \
                        eventData->options |= kIOHIDEventOptionIsAbsolute; \
                    break;                              \
                case IOHIDEventFieldOffset(kIOHIDEventFieldIsCollection): \
                    if ( value )                        \
                        eventData->options |= kIOHIDEventOptionIsCollection; \
                    else                                \
                        eventData->options &= ~kIOHIDEventOptionIsCollection; \
                    break;                              \
            }; break;                                   \
        case kIOHIDEventTypeVendorDefined:              \
            {                                           \
                IOHIDVendorDefinedEventData * sysDef = (IOHIDVendorDefinedEventData*)eventData; \
                switch ( fieldOffset ) {                \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldVendorDefinedUsagePage): \
                        sysDef->usagePage = value;      \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldVendorDefinedUsage): \
                        sysDef->usage = value;          \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldVendorDefinedVersion): \
                        sysDef->version = value;        \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldVendorDefinedData): \
                        if (sysDef->data)               \
                            *((typeof(value)*) sysDef->data) = value; \
                        break;                          \
                };                                      \
            }                                           \
            break;                                      \
        case kIOHIDEventTypeProgress:                     \
            {                                           \
                IOHIDProgressEventData * progress = (IOHIDProgressEventData*)eventData; \
                switch ( fieldOffset ) {                \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldProgressEventType): \
                        progress->eventType = value;    \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldProgressLevel): \
                        progress->level = IOHIDEventValueFixed(value); \
                        break;                          \
                };                                      \
            }                                           \
            break;                                      \
        case kIOHIDEventTypeButton:                     \
            {                                           \
                IOHIDButtonEventData * button = (IOHIDButtonEventData*)eventData; \
                switch ( fieldOffset ) {                \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldButtonMask): \
                        button->button.buttonMask = value;     \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldButtonNumber): \
                        button->button.buttonNumber = value;   \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldButtonClickCount): \
                        button->button.clickState = value;     \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldButtonPressure): \
                        button->button.pressure = IOHIDEventValueFixed(value); \
                        break;                          \
                };                                      \
            }                                           \
            break;                                      \
        case kIOHIDEventTypeAccelerometer:              \
            {                                           \
                IOHIDAccelerometerEventData * accl = (IOHIDAccelerometerEventData*)eventData; \
                switch ( fieldOffset ) {                \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldAccelerometerX): \
                        accl->position.x = IOHIDEventValueFixed(value); \
                        break;                              \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldAccelerometerY): \
                        accl->position.y = IOHIDEventValueFixed(value); \
                        break;                              \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldAccelerometerZ): \
                        accl->position.z = IOHIDEventValueFixed(value); \
                        break;                              \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldAccelerometerType): \
                        accl->acclType = value;     \
                        break;                          \
                };                                      \
            }                                           \
            break;                                      \
        case kIOHIDEventTypeMouse:                     \
            {                                           \
                IOHIDMouseEventData * mouse = (IOHIDMouseEventData*)eventData; \
                switch ( fieldOffset ) {                \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldMouseX): \
                        mouse->position.x = IOHIDEventValueFixed(value); \
                        break;                              \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldMouseY): \
                        mouse->position.y = IOHIDEventValueFixed(value); \
                        break;                              \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldMouseZ): \
                        mouse->position.z = IOHIDEventValueFixed(value); \
                        break;                              \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldMouseButtonMask): \
                        mouse->button.buttonMask = value;     \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldMouseNumber): \
                        mouse->button.buttonNumber = value;   \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldMouseClickCount): \
                        mouse->button.clickState = value;     \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldMousePressure): \
                        mouse->button.pressure = IOHIDEventValueFixed(value); \
                        break;                          \
                };                                      \
            }                                           \
            break;                                      \
        case kIOHIDEventTypeSwipe:                      \
            {                                           \
                IOHIDSwipeEventData * swipe = (IOHIDSwipeEventData *)eventData; \
                switch ( fieldOffset ) {                    \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldSwipeMask):       \
                        swipe->swipeMask = value;\
                        break;                          \
                };                                      \
            }                                           \
            break;                                      \
        case kIOHIDEventTypeTemperature:                \
            {                                           \
                IOHIDTemperatureEventData * temp = (IOHIDTemperatureEventData *)eventData; \
                switch ( fieldOffset ) {                    \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldTemperatureLevel):       \
                        temp->level = IOHIDEventValueFixed(value);\
                        break;                          \
                };                                      \
            }                                           \
            break;                                      \
        case kIOHIDEventTypeTranslation:                \
        case kIOHIDEventTypeRotation:                   \
        case kIOHIDEventTypeScroll:                     \
        case kIOHIDEventTypeScale:                      \
        case kIOHIDEventTypeVelocity:                   \
        case kIOHIDEventTypeOrientation:                \
            {                                           \
                IOHIDAxisEventData * axis = (IOHIDAxisEventData *)eventData;    \
                switch ( fieldOffset ) {                    \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldTranslationX):       \
                    /*                                                              \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldRotationX):          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldScrollX):            \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldScaleX):             \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldVelocityX):          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerX);         \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldOrientationRadius):  \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldAccelerometerX):     \
                    */                                                              \
                        axis->position.x = IOHIDEventValueFixed(value);             \
                        break;                              \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldTranslationY):       \
                    /*                                                              \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldRotationY):          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldScrollY):            \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldScaleY):             \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldVelocityY):          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerY);         \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldOrientationAzimuth): \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldAccelerometerY):     \
                    */                                                              \
                        axis->position.y = IOHIDEventValueFixed(value);             \
                        break;                              \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldTranslationZ):       \
                    /*                                                              \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldRotationZ):          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldScrollZ):            \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldScaleZ):             \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldVelocityZ):          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerZ);         \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldOrientationAltitude):\
                    case IOHIDEventFieldOffset(kIOHIDEventFieldAccelerometerZ):     \
                    */                                                              \
                        axis->position.z = IOHIDEventValueFixed(value);             \
                        break;                              \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldScrollIsPixels):         \
                        if ( value )                        \
                            axis->options |= kIOHIDEventOptionPixelUnits;           \
                        else                                \
                            axis->options &= ~kIOHIDEventOptionPixelUnits;           \
                        break;                              \
                };                                          \
            }                                               \
            break;                                          \
        case kIOHIDEventTypeAmbientLightSensor:             \
            {                                               \
                IOHIDAmbientLightSensorEventData * alsEvent = (IOHIDAmbientLightSensorEventData *)eventData;\
                switch ( fieldOffset ) {                \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldAmbientLightSensorLevel): \
                        alsEvent->level = value;        \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldAmbientLightSensorRawChannel0): \
                        alsEvent->ch0 = value;          \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldAmbientLightSensorRawChannel1): \
                        alsEvent->ch1 = value;          \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldAmbientLightDisplayBrightnessChanged): \
                        alsEvent->brightnessChanged = value; \
                        break;                          \
                };                                      \
            }                                           \
            break;                                      \
        case kIOHIDEventTypeProximity:                  \
            {                                           \
                IOHIDProximityEventData * proxEvent = (IOHIDProximityEventData *)eventData;\
                switch ( fieldOffset ) {                \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldProximityDetectionMask): \
                        proxEvent->detectionMask = value; \
                        break;                          \
                };                                      \
            }                                           \
            break;                                      \
        case kIOHIDEventTypeKeyboard:                       \
            {                                               \
                IOHIDKeyboardEventData * keyEvent = (IOHIDKeyboardEventData *)eventData;\
                switch ( fieldOffset ) {                \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldKeyboardUsagePage): \
                        keyEvent->usagePage = value;    \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldKeyboardUsage):     \
                        keyEvent->usage = value;        \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldKeyboardDown):    \
                        keyEvent->down = value;         \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldKeyboardRepeat):  \
                        if ( value )                        \
                            keyEvent->options |= kIOHIDKeyboardIsRepeat;            \
                        else                                \
                            keyEvent->options &= ~kIOHIDKeyboardIsRepeat;           \
                        break;                              \
                };                                      \
            }                                           \
            break;                                      \
        case kIOHIDEventTypeDigitizer:                  \
            {                                           \
                IOHIDDigitizerEventData * digEvent = (IOHIDDigitizerEventData *)eventData; \
                switch ( fieldOffset ) {                \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerX): \
                        digEvent->position.x = IOHIDEventValueFixed(value);   \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerY): \
                        digEvent->position.y = IOHIDEventValueFixed(value);   \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerZ): \
                        digEvent->position.z = IOHIDEventValueFixed(value);   \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerButtonMask): \
                        digEvent->buttonMask = value;   \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerIndex): \
                        digEvent->transducerIndex = value; \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerIdentity): \
                        digEvent->identity = value;     \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerEventMask): \
                        digEvent->eventMask = value;    \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerChildEventMask): \
                        digEvent->childEventMask = value; \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerRange): \
                        if ( value )                        \
                            digEvent->options |= kIOHIDTransducerRange;         \
                        else                                \
                            digEvent->options &= ~kIOHIDTransducerRange;        \
                        break;                              \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerTouch): \
                        if ( value )                        \
                            digEvent->options |= kIOHIDTransducerTouch;         \
                        else                                \
                            digEvent->options &= ~kIOHIDTransducerTouch;        \
                        break;                              \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerCollection): \
                        if ( value )                        \
                            digEvent->options |= kIOHIDEventOptionIsCollection;         \
                        else                                \
                            digEvent->options &= ~kIOHIDEventOptionIsCollection;        \
                        break;                              \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerPressure): \
                        digEvent->tipPressure = IOHIDEventValueFixed(value);  \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerBarrelPressure): \
                        digEvent->barrelPressure = IOHIDEventValueFixed(value);   \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerTwist): \
                        digEvent->twist = IOHIDEventValueFixed(value);        \
                        break;                          \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerTiltX): \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerTiltY): \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerQuality): \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerDensity): \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerIrregularity): \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerMajorRadius): \
                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerMinorRadius): \
                        switch ( digEvent->orientationType ) {\
                            case kIOHIDDigitizerOrientationTypeTilt:\
                                switch ( fieldOffset ) {\
                                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerTiltX): \
                                        digEvent->orientation.tilt.x = IOHIDEventValueFixed(value); \
                                        break;          \
                                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerTiltY): \
                                        digEvent->orientation.tilt.y = IOHIDEventValueFixed(value); \
                                        break;          \
                                };                      \
                                break;                  \
                            case kIOHIDDigitizerOrientationTypePolar:\
                                switch ( fieldOffset ) {\
                                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerAltitude): \
                                        digEvent->orientation.polar.altitude = IOHIDEventValueFixed(value); \
                                        break;          \
                                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerAzimuth): \
                                        digEvent->orientation.polar.azimuth = IOHIDEventValueFixed(value); \
                                        break;          \
                                };                      \
                                break;                  \
                            case kIOHIDDigitizerOrientationTypeQuality:\
                                switch ( fieldOffset ) {\
                                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerQuality): \
                                        digEvent->orientation.quality.quality = IOHIDEventValueFixed(value); \
                                        break;          \
                                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerDensity): \
                                        digEvent->orientation.quality.density = IOHIDEventValueFixed(value); \
                                        break;          \
                                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerIrregularity): \
                                        digEvent->orientation.quality.irregularity = IOHIDEventValueFixed(value); \
                                        break;          \
                                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerMajorRadius): \
                                        digEvent->orientation.quality.majorRadius = IOHIDEventValueFixed(value); \
                                        break;          \
                                    case IOHIDEventFieldOffset(kIOHIDEventFieldDigitizerMinorRadius): \
                                        digEvent->orientation.quality.minorRadius = IOHIDEventValueFixed(value); \
                                        break;          \
                                };                      \
                                break;                  \
                        };                              \
                        break;                          \
                };                                      \
            }                                           \
            break;                                      \
    };                                                  \
}

#define SET_EVENT_VALUE(event, field, value, options)               \
{   IOHIDEventType  fieldEvType = IOHIDEventFieldEventType(field);  \
    uint32_t        fieldOffset = IOHIDEventFieldOffset(field);     \
    IOHIDEventRef   ev          = NULL;                             \
    if ( (ev = IOHIDEventGetEventWithOptions(event, fieldEvType, options)) ) {\
        SET_EVENTDATA_VALUE(GET_EVENTDATA(ev),fieldEvType,fieldOffset,value);\
    }                                                               \
}

#endif /* _IOKIT_HID_IOHIDEVENTDATA_H */
