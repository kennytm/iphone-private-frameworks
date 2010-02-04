#import <Availability2.h>
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2
#import <UIKit/UIImageView.h>
@class UIImage;

@interface TPLCDBar : UIImageView {
	UIImage* _barBackground;
}
@property(retain, nonatomic) UIImage* barBackground;
+(void)preloadImages;
+(id)backgroundImage;
+(float)defaultHeight;
+(float)defaultHeightForOrientation:(int)orientation;
+(id)backgroundImageName;
-(id)initWithDefaultSizeForOrientation:(int)orientation;
-(id)initWithDefaultSize;
// inherited: -(id)initWithFrame:(CGRect)frame;
// inherited: -(void)dealloc;
-(void)setOrientation:(int)orientation;
-(CGRect)contentStretchRect;
@end

#endif
