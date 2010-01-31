#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <Foundation/NSObject.h>
#import "UIKit-Structs.h"

__attribute__((visibility("hidden")))
@interface UIKeyboardCacheEntry : NSObject {
@private
	UIImage* image;
	XXStruct_0aX3CD onDiskInfo;
	NSString* key;
}
@property(retain, nonatomic) UIImage* image;
@property(retain, nonatomic) NSString* key;
@property(assign, nonatomic) XXStruct_0aX3CD onDiskInfo;
// inherited: -(void)dealloc;
-(int)keyCompare:(id)compare;
-(int)onDiskCompare:(id)compare;
@end

#endif
