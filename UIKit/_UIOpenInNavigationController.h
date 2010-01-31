#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2
#import <UIKit/UINavigationController.h>

__attribute__((visibility("hidden")))
@interface _UIOpenInNavigationController : UINavigationController {
}
-(id)initWithDocumentInteractionController:(id)documentInteractionController;
@end

#endif
