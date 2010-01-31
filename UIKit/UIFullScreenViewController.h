#import <Availability2.h>
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2
#import <UIKit/UIViewController.h>

__attribute__((visibility("hidden")))
@interface UIFullScreenViewController : UIViewController {
}
// inherited: -(BOOL)shouldAutorotateToInterfaceOrientation:(int)interfaceOrientation;
@end

#endif
