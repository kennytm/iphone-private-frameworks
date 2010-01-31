#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIWindow.h>

__attribute__((visibility("hidden")))
@interface UIStatusDimmingWindow : UIWindow {
}
// inherited: -(BOOL)_ignoresHitTest;
@end

#endif
