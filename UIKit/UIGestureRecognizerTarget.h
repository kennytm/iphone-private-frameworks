#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >=__IPHONE_3_2

#import <Foundation/NSObject.h>

__attribute__((visibility("hidden")))
@interface UIGestureRecognizerTarget : NSObject {
@private
	id _target;
	SEL _action;
}
// inherited: -(id)description;
@end


#endif
