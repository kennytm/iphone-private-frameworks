#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import "SBDeviceLockViewWithKeypad.h"
@class UIView;

@interface SBDeviceLockViewWithKeypadWildcat : SBDeviceLockViewWithKeypad {
	UIView* _bottomContainer;
}
// inherited: -(id)initWithStyle:(int)style interfaceOrientation:(int)orientation;
// inherited: -(void)dealloc;
// inherited: -(id)keypadView;
@end

#endif
