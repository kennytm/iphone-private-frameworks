#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import "SBDeviceLockKeypad.h"
@class SBEmergencyCallButton, UIPushButton, UIImage;

@interface SBDeviceLockKeypadPhone : SBDeviceLockKeypad {
	SBEmergencyCallButton* _emergencyCallButton;
	UIPushButton* _poundButton;
	UIImage* _deleteIcon;
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
