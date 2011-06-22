#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <Foundation/NSObject.h>
#import <UIKit/UIKit.h>

@class SBCornerView, SBCornerWindow;

@interface SBCornerViewFactory : NSObject {
}
+(SBCornerView *)createCornerViewForCorner:(int)corner cornersFrame:(CGRect)frame;
+(SBCornerWindow *)createCornerWindowForCorner:(int)corner windowLevel:(UIWindowLevel)level cornersFrame:(CGRect)frame;
@end

#endif
