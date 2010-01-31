#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import "UIKit-Structs.h"
#import <Foundation/NSObject.h>

__attribute__((visibility("hidden")))
@interface UIPeripheralHostState : NSObject {
@private
	UIPeripheralAnimationGeometry _geometry;
}
@property(assign, nonatomic) UIPeripheralAnimationGeometry geometry;
+(id)stateWithGeometry:(UIPeripheralAnimationGeometry)geometry;
@end

#endif
