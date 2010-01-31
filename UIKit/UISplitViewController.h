#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#include_next <UIKit/UISplitViewController.h>

@interface UISplitViewController()
-(void)_commonInit;
-(void)loadSubviews;
// inherited: -(void)unloadViewForced:(BOOL)forced;
-(BOOL)_masterViewShown;
-(CGRect)_masterViewFrame;
-(CGRect)_detailViewFrame;
-(CGContextRef)_createContextForCachingWithFrame:(CGRect)frame isOpaque:(BOOL)opaque;
-(void)_setupRoundedCorners;
-(void)_removeRoundedCorners;
-(void)_viewControllerHiding:(id)hiding;
-(BOOL)hidesMasterViewInPortrait;
-(void)setHidesMasterViewInPortrait:(BOOL)portrait;
-(float)masterColumnWidth;
-(void)setMasterColumnWidth:(float)width;
-(float)gutterWidth;
-(void)setGutterWidth:(float)width;
-(void)showMasterInPopover:(id)popover;
-(void)_layoutChildViewControllersForOrientation:(int)orientation includingMaster:(BOOL)master;
-(void)_layoutChildViewControllers;
@end

#endif
