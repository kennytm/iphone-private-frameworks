#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

__attribute__((visibility("hidden")))
@interface UIZoomButtonWindow : UIWindow {
}
// inherited: -(BOOL)_allowsContextHosting;
@end

#endif
