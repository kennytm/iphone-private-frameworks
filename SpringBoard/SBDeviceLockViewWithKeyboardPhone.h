#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import "SBDeviceLockViewWithKeyboard.h"

@interface SBDeviceLockViewWithKeyboardPhone : SBDeviceLockViewWithKeyboard {
}
// inherited: -(id)initWithStyle:(int)style interfaceOrientation:(int)orientation;
// inherited: -(BOOL)showsEmergencyCallButton;
// inherited: -(void)setShowsEmergencyCallButton:(BOOL)button;
// inherited: -(void)returnKeyPressed:(id)pressed;
@end

#endif
