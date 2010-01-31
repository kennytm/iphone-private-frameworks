#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIViewController.h>
@class UIWindow, UIView, UIImageView;

__attribute__((visibility("hidden")))
@interface UIStatusBarViewController : UIViewController {
@private
	UIWindow* _window;
	UIView* _statusBar;
	UIImageView* _statusBarBackgroundImage;
	UIWindow* _leftBottomCorner;
	UIWindow* _rightBottomCorner;
}
// inherited: -(id)init;
// inherited: -(void)dealloc;
-(BOOL)isClassicControlWindow:(id)window;
// inherited: -(void)loadView;
-(void)prepareToSetStatusBarModeWithOrientation:(int)orientation oldMode:(int)mode animation:(int)animation duration:(float)duration;
-(void)_prepareForZoom:(BOOL)zoom;
-(void)_zoom:(BOOL)zoom animated:(BOOL)animated;
-(void)_setStatusBarBackgroundImageForOrientation:(int)orientation;
-(void)_updateStatusBarGeometryWithOrientation:(int)orientation slideUp:(BOOL)up;
-(void)_updateStatusBarWithOrientation:(int)orientation isStatusBarHidden:(BOOL)hidden slideUp:(BOOL)up;
-(CGSize)statusBarSizeForOrientation:(int)orientation;
-(void)_statusBarModeAnimationFinished:(id)finished finished:(BOOL)finished2 context:(void*)context;
-(id)loadCorner:(BOOL)corner cornerImage:(id)image cornersFrame:(CGRect)frame;
-(void)_updateCornersWithOrientation:(int)orientation;
@end

#endif
