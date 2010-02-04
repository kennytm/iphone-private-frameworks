#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIView.h>

@interface SBRoundedMaskCornerView : UIView {
	float _cornerRadius;
	unsigned _corner;
}
-(id)initWithCorner:(unsigned)corner radius:(float)radius;
-(void)drawRect:(CGRect)rect;
@end

#endif
