#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIView.h>

__attribute__((visibility("hidden")))
@interface UIPeripheralHostView : UIView {
}
// inherited: -(id)initWithFrame:(CGRect)frame;
-(int)textEffectsVisibilityLevel;
-(BOOL)pointInside:(CGPoint)inside withEvent:(id)event;
@end

#endif
