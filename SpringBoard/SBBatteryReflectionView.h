#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIView.h>
@class UIImage;

@interface SBBatteryReflectionView : UIView {
	UIImage* _image;
	UIImage* _maskImage;
	float _bottomMargin;
}
-(id)initWithImage:(id)image bottomMargin:(float)margin;
// inherited: -(void)dealloc;
-(void)setImage:(id)image;
-(void)drawRect:(CGRect)rect;
@end

#endif
