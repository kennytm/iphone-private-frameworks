#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIView.h>
@class SBWallpaperView;

@interface SBWallpaperClipView : UIView {
	SBWallpaperView* _wallpaperView;
	CGPoint _contentOffset;
	CGPoint _unitContentOffset;
	CGSize _unitContentSize;
}
@property(retain, nonatomic) SBWallpaperView* wallpaperView;
@property(assign, nonatomic) CGPoint contentOffset;
-(id)initWithFrame:(CGRect)frame wallpaperView:(SBWallpaperView *)view;
// inherited: -(void)dealloc;
-(void)setFrame:(CGRect)frame;
-(void)setWallpaperView:(SBWallpaperView *)view force:(BOOL)force;
-(void)_setWallpaperAlpha:(CGFloat)alpha;
-(void)_wallpaperImageChanged:(id)changed;
-(void)_wallpaperFrameChanged:(id)changed;
-(void)_wallpaperAlphaChanged:(id)changed;
-(void)_updateWallpaperImage;
-(void)_recomputeGeometry;
-(void)_recomputeGradient;
@end

#endif
