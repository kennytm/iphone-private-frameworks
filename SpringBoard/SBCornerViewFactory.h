#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <Foundation/NSObject.h>

@interface SBCornerViewFactory : NSObject {
}
+(id)createCornerViewForCorner:(int)corner cornersFrame:(CGRect)frame;
+(id)createCornerWindowForCorner:(int)corner windowLevel:(float)level cornersFrame:(CGRect)frame;
@end

#endif
