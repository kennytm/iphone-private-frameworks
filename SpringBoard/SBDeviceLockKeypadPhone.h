#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import "SBDeviceLockKeypad.h"
@class SBEmergencyCallButton, UIPushButton, UIImage;

@interface SBDeviceLockKeypadPhone : SBDeviceLockKeypad {
// Work around compiling with earlier deploymen target
#if __IPHONE_OS_VERSION_MIN_REQUIRED > __IPHONE_3_2
	SBEmergencyCallButton* _emergencyCallButton;
#endif
	UIPushButton* _poundButton;
#if __IPHONE_OS_VERSION_MIN_REQUIRED > __IPHONE_3_2
	UIImage* _deleteIcon;
#endif
}
// inherited: +(id)keypadImage;
// inherited: +(id)pressedImage;
// inherited: +(void)flushPressedImage;
// inherited: -(id)initWithFrame:(CGRect)frame;
// inherited: -(void)dealloc;
// inherited: -(float)_yFudge;
// inherited: -(BOOL)showsEmergencyCallButton;
// inherited: -(void)setShowsEmergencyCallButton:(BOOL)button;
// inherited: -(void)setDeleteEnabled:(BOOL)enabled;
// inherited: -(BOOL)deleteKeyChar;
// inherited: -(BOOL)cancelKeyChar;
// inherited: -(BOOL)emergencyKeyChar;
-(void)_updateCancelAndDeleteButtons;
@end

#endif
