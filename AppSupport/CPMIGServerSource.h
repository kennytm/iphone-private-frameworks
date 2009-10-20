/*
 
CPMIGServerSource.h ... Convenient function to receive Mach MIG messages.

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

#ifndef APPSUPPORT_CPMIGSERVERSOURCE_H
#define APPSUPPORT_CPMIGSERVERSOURCE_H

#if __cplusplus
extern "C" {
#endif

#include <CoreFoundation/CoreFoundation.h>
#include <Availability.h>	// for __OSX_AVAILABLE_STARTING.
#include <mach/mig.h>
	
	typedef CFRunLoopSourceRef CPMIGServerSourceRef;
	
	CPMIGServerSourceRef CPCreateMIGServerSource(mig_subsystem_t subsystem, mach_port_t receivePort, CFIndex order);
	CPMIGServerSourceRef CPCreateMIGServerSourceWithContext(mig_subsystem_t subsystem, mach_port_t receivePort, CFIndex order, void* context) __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_2_1);
	
	mach_port_t CPGetMachPortForMIGServerSource(CPMIGServerSourceRef source);
	void* CPGetContextForCalloutCurrentMIGServerSource(CPMIGServerSourceRef source) __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_2_1);	///< BUG: The context source is shared among the whole thread.
	
	CPMIGServerSourceRef CPSHCreateMIGServerSource(void* unused1, CFIndex order, mig_subsystem_t subsystem, void* unused2, mach_port_t receivePort) __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_NA, __MAC_NA, __IPHONE_2_0, __IPHONE_3_0);	
	
#if __cplusplus
}
#endif

#endif