#ifndef SPRINGBOARDSERVICES_H
#define SPRINGBOARDSERVICES_H

#if __cplusplus
extern "C" {
#endif
	
#if __OBJC__
	@class NSString;
	
	NSString* SBSCopyIconImagePathForDisplayIdentifier(NSString* dispIden);
	NSString* SBSCopyLocalizedApplicationNameForDisplayIdentifier(NSString* dispIden);
	
#else	
#include <CoreFoundation/CoreFoundation.h>
	
	CFStringRef SBSCopyIconImagePathForDisplayIdentifier(CFStringRef dispIden);
	CFStringRef SBSCopyLocalizedApplicationNameForDisplayIdentifier(CFStringRef dispIden);
	
#endif
	
#if __cplusplus
}
#endif

#endif