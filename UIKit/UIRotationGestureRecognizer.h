#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#include_next <UIKit/UIRotationGestureRecognizer.h>

@interface UIRotationGestureRecognizer()
-(CGPoint)anchorPoint;
@end

#endif
