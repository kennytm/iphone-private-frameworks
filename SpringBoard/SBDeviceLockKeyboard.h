#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIKeyboard.h>
@class SBDeviceLockViewWithKeyboard;

@interface SBDeviceLockKeyboard : UIKeyboard {
	SBDeviceLockViewWithKeyboard* _deviceLockView;
}
-(id)initWithFrame:(CGRect)frame deviceLockView:(SBDeviceLockViewWithKeyboard *)view;
// inherited: -(BOOL)canDismiss;
// inherited: -(void)minimize;
// inherited: -(void)maximize;
@end

#endif
