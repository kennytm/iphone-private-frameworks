#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIViewController.h>
@class UIWindow, UIButton;

__attribute__((visibility("hidden")))
@interface UIZoomViewController : UIViewController {
@private
	UIWindow* _window;
	UIButton* _zoomButton;
}
// inherited: -(id)init;
// inherited: -(void)dealloc;
-(BOOL)isClassicControlWindow:(id)window;
-(id)_zoomText:(BOOL)text;
-(void)_changeZoom:(id)zoom;
-(void)_startZoomAnimation:(BOOL)animation;
-(void)_setupPositioningAndRotationForInterfaceOrientation:(int)interfaceOrientation offscreen:(BOOL)offscreen;
// inherited: -(void)loadView;
-(void)_zoomOrientationChange:(id)change;
-(void)_zoomOrientationAnimationFinished:(id)finished finished:(BOOL)finished2 context:(void*)context;
-(void)_applicationDidFinishLaunching:(id)_application;
-(void)_suspendAnimationStarted:(id)started;
-(void)_getRotationContentSettings:(XXStruct_Nw9VXC*)settings forWindow:(id)window;
@end

#endif
