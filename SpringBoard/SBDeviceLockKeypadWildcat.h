#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import "SBDeviceLockKeypad.h"
@class UIView;

@interface SBDeviceLockKeypadWildcat : SBDeviceLockKeypad {
	UIView* _glowView;
}
// inherited: +(id)keypadImage;
// inherited: +(id)pressedImage;
// inherited: -(id)initWithFrame:(CGRect)frame;
// inherited: -(void)dealloc;
// inherited: -(void)setHighlighted:(BOOL)highlighted;
// inherited: -(float)_yFudge;
// inherited: -(CGRect)_rectForKey:(int)key;
// inherited: -(BOOL)deleteKeyChar;
// inherited: -(BOOL)cancelKeyChar;
@end

#endif