#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIKit.h>

@interface SBBatteryReflectionView : UIView {
	UIImage* _image;
	UIImage* _maskImage;
	CGFloat _bottomMargin;
}
-(id)initWithImage:(UIImage *)image bottomMargin:(CGFloat)margin;
// inherited: -(void)dealloc;
-(void)setImage:(UIImage *)image;
-(void)drawRect:(CGRect)rect;
@end

#endif
