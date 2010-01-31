#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import "UIKeyboard.h"

__attribute__((visibility("hidden")))
@interface UIKeyboardAutomatic : UIKeyboard {
}
// inherited: -(id)initWithFrame:(CGRect)frame;
// inherited: -(void)dealloc;
// inherited: -(void)minimize;
// inherited: -(void)maximize;
// inherited: -(UIPeripheralAnimationGeometry)geometryForImplHeightDelta:(float)implHeightDelta;
// inherited: -(void)prepareForImplBoundsHeightChange:(float)implBoundsHeightChange suppressNotification:(BOOL)notification;
// inherited: -(void)implBoundsHeightChangeDone:(float)done suppressNotification:(BOOL)notification;
-(void)didResume:(id)resume;
-(BOOL)_isAutomaticKeyboard;
@end

#endif
