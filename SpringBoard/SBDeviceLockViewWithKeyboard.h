#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import "SBDeviceLockView.h"
@class UIKeyboard;

@interface SBDeviceLockViewWithKeyboard : SBDeviceLockView {
	UIKeyboard* _keyboard;
	BOOL _isAnimating;
}
// inherited: -(id)initWithStyle:(int)style interfaceOrientation:(int)orientation;
// inherited: -(id)protectedInitWithStyle:(int)style interfaceOrientation:(int)orientation;
// inherited: -(void)dealloc;
// inherited: -(id)keypadView;
// inherited: -(BOOL)isKeypadMinimized;
-(void)setMinimized:(BOOL)minimized;
-(void)minimize;
-(void)maximize;
-(void)returnKeyPressed:(id)pressed;
-(CGRect)keyboardFrameForInterfaceOrientation:(int)interfaceOrientation;
// inherited: -(void)setInterfaceOrientation:(int)orientation;
// inherited: -(void)willAnimateToInterfaceOrientation:(int)interfaceOrientation;
// inherited: -(void)animateToInterfaceInterfaceOrientation:(int)interfaceInterfaceOrientation;
// inherited: -(void)didAnimateToInterfaceOrientation:(int)interfaceOrientation;
@end

#endif
