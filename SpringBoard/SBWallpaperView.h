#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIView.h>
@class UIImage, SBGradientImageView, CAFilter;

@interface SBWallpaperView : UIView {
	UIImage* _wallpaper;
	CGRect _wallpaperContentsRect;
	SBGradientImageView* _topView;
	SBGradientImageView* _middleView;
	SBGradientImageView* _bottomView;
	float _unitTopHeight;
	float _unitMiddleHeight;
	float _unitBottomHeight;
	float _topViewMinColorIntensity;
	float _bottomViewMinColorIntensity;
	float _filterAlpha;
	CAFilter* _topFilter;
	CAFilter* _bottomFilter;
}
@property(readonly, assign, nonatomic) UIImage* image;
@property(readonly, assign, nonatomic) CGRect imageContentsRect;
// inherited: +(void)initialize;
+(void)noteWallpaperPreferencesChanged;
+(int)_desktopVariant;
+(NSString *)_nameForVariant:(int)variant;
+(UIImage *)_desktopImage;
+(BOOL)lockScreenAndHomeScreenShareWallpaper;
// inherited: -(id)initWithFrame:(CGRect)frame;
// inherited: -(void)dealloc;
-(void)_wallpaperChanged;
-(void)_updateGeometry;
-(void)setWallpaper:(UIImage *)wallpaper;
-(void)setFrame:(CGRect)frame;
-(CGFloat)alpha;
-(void)setAlpha:(CGFloat)alpha;
// inherited: -(BOOL)_shouldAnimatePropertyWithKey:(id)key;
-(id)gradientColorAtUnitOffset:(CGPoint)unitOffset nearestColorStop:(CGPoint*)stop;
@end

#endif
