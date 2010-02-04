#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIView.h>
@class SBWallpaperClipView, SBRoundedMaskCornerView;

@interface SBRoundedCornersView : UIView {
	CGFloat _cornerRadius;
	SBWallpaperClipView* _topLeftCorner;
	SBWallpaperClipView* _topRightCorner;
	SBWallpaperClipView* _bottomLeftCorner;
	SBWallpaperClipView* _bottomRightCorner;
	SBRoundedMaskCornerView* _topLeftCornerMask;
	SBRoundedMaskCornerView* _topRightCornerMask;
	SBRoundedMaskCornerView* _bottomLeftCornerMask;
	SBRoundedMaskCornerView* _bottomRightCornerMask;
}
-(id)initWithFrame:(CGRect)frame cornerRadius:(CGFloat)radius;
-(void)layoutSubviews;
// inherited: -(void)dealloc;
@end

#endif
