#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <Foundation/Foundation.h>
@class UIWindow, UIView, SBHUDView;

@interface SBHUDController : NSObject {
	UIWindow* _hudWindow;
	UIView* _hudContentView;
	SBHUDView* _hudView;
}
+(SBHUDController *)sharedHUDController;
// inherited: -(void)dealloc;
-(void)_recenterHUDView;
-(void)reorientHUDIfNeeded:(BOOL)needed;
-(void)_createUI;
-(void)_tearDown;
-(void)animationDidStop:(id)animation finished:(id)finished context:(void*)context;
-(void)_orderWindowOut:(id)anOut;
-(void)presentHUDView:(SBHUDView *)view;
-(void)presentHUDView:(SBHUDView *)view autoDismissWithDelay:(NSTimeInterval)delay;
-(SBHUDView *)visibleHUDView;
-(void)hideHUDView;
@end

#endif
