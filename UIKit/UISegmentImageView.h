#import <Availability2.h>
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2
#import <UIKit/UIImageView.h>

__attribute__((visibility("hidden")))
@interface UISegmentImageView : UIImageView {
}
-(BOOL)useBlockyMagnificationInClassic;
@end

#endif
