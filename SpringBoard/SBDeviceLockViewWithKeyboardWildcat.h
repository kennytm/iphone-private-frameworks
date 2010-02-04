#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import "SBDeviceLockViewWithKeyboard.h"

@interface SBDeviceLockViewWithKeyboardWildcat : SBDeviceLockViewWithKeyboard {
}
-(void)_centerStatusView;
-(void)_layoutForCurrentOrientation;
// inherited: -(id)initWithStyle:(int)style interfaceOrientation:(int)orientation;
// inherited: -(void)setMinimized:(BOOL)minimized;
// inherited: -(void)setInterfaceOrientation:(int)orientation;
// inherited: -(void)returnKeyPressed:(id)pressed;
@end

#endif
