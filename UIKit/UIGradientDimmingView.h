#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import "UIDimmingView.h"
#import <CoreGraphics/CoreGraphics.h>

__attribute__((visibility("hidden")))
@interface UIGradientDimmingView : UIDimmingView {
@private
	CGGradientRef _gradient;
}
// inherited: -(id)initWithFrame:(CGRect)frame;
// inherited: -(void)dealloc;
-(void)drawRect:(CGRect)rect;
@end

#endif
