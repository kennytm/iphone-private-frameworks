#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#include_next <UIKit/UIScreenMode.h>

@interface UIScreenMode ()
+(id)screenModeForDisplayMode:(id)displayMode;
-(id)initWithDisplayMode:(id)displayMode;
-(id)_displayMode;
@end

#endif
