#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIWindow.h>

@interface SBHUDWindow : UIWindow {
}
// inherited: -(BOOL)_ignoresHitTest;
@end

#endif
