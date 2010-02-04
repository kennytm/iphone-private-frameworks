#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import "SBDeviceLockView.h"
@class SBDeviceLockKeypad;

@interface SBDeviceLockViewWithKeypad : SBDeviceLockView {
	SBDeviceLockKeypad* _keypad;
}
// inherited: -(id)initWithStyle:(int)style interfaceOrientation:(int)orientation;
// inherited: -(id)protectedInitWithStyle:(int)style interfaceOrientation:(int)orientation;
// inherited: -(void)dealloc;
// inherited: -(id)keypadView;
// inherited: -(void)setPasscode:(id)passcode;
// inherited: -(BOOL)playsKeyboardClicks;
// inherited: -(void)setPlaysKeyboardClicks:(BOOL)clicks;
// inherited: -(BOOL)showsEmergencyCallButton;
// inherited: -(void)setShowsEmergencyCallButton:(BOOL)button;
-(void)phonePad:(id)pad keyDown:(BOOL)down;
-(void)phonePad:(id)pad keyUp:(BOOL)up;
@end

#endif
