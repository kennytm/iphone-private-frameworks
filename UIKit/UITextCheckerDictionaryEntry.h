#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <Foundation/NSObject.h>
#import <CoreFoundation/CoreFoundation.h>
@class NSData;

__attribute__((visibility("hidden")))
@interface UITextCheckerDictionaryEntry : NSObject {
@private
	CFSetRef dictionary;
	NSData* data;
	int size;
	int mtime;
}
// inherited: -(void)dealloc;
@end

#endif
