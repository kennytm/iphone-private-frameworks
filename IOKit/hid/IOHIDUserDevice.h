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

#ifndef _IOKIT_HID_IOHIDUSERDEVICE_USER_H
#define _IOKIT_HID_IOHIDUSERDEVICE_USER_H

#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/IOKitLib.h>

__BEGIN_DECLS

typedef struct __IOHIDUserDevice * IOHIDUserDeviceRef;

/*!
	@function   IOHIDUserDeviceGetTypeID
	@abstract   Returns the type identifier of all IOHIDUserDevice instances.
*/
CF_EXPORT
CFTypeID IOHIDUserDeviceGetTypeID(void);

/*!
	@function   IOHIDUserDeviceCreate
	@abstract   Creates an virtual IOHIDDevice in the kernel.
    @discussion The io_service_t passed in this method must reference an object 
                in the kernel of type IOHIDUserDevice.
    @param      allocator Allocator to be used during creation.
    @param      properties CFDictionaryRef containing device properties index by keys defined in IOHIDKeys.h.
    @result     Returns a new IOHIDUserDeviceRef.
*/
CF_EXPORT
IOHIDUserDeviceRef IOHIDUserDeviceCreate(
                                CFAllocatorRef                  allocator, 
                                CFDictionaryRef                 properties);


/*!
	@function   IOHIDUserDeviceHandleReport
	@abstract   Dispatch a report to the IOHIDUserDevice.
*/
CF_EXPORT
IOReturn IOHIDUserDeviceHandleReport(
                                IOHIDUserDeviceRef              device, 
                                uint8_t *                       report, 
                                CFIndex                         reportLength);

__END_DECLS

#endif /* _IOKIT_HID_IOHIDUSERDEVICE_USER_H */
