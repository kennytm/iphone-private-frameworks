#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#include_next <UIKit/UIPopoverController.h>

@interface UIPopoverController ()
-(void)_disableAutomaticKeyboard:(id)keyboard;
-(void)_adjustPopoverForNewContentSize:(id)newContentSize;
-(id)popoverView;
-(void)_setupIncomingViewController:(id)controller presenting:(BOOL)presenting animated:(BOOL)animated;
-(void)_teardownOutgoingViewController:(id)controller animated:(BOOL)animated;
//-(void)setContentViewController:(UIViewContorller*)controller animated:(BOOL)animated;
-(void)setPopoverFrame:(CGRect)frame animated:(BOOL)animated;
-(BOOL)_popoverShouldBeDismissed:(id)_popover;
-(void)_popoverDidDismiss:(id)_popover;
-(void)_popoverPresentAnimationCompleted;
-(void)_popoverDismissAnimationCompleted;
-(void)_setPopoverRasterizesLayer:(BOOL)layer;
-(BOOL)_popoverRasterizesLayer;
-(void)_setPopoverBackgroundStyle:(int)style;
-(int)_popoverBackgroundStyle;
-(void)_setContentViewController:(id)controller backgroundStyle:(int)style animated:(BOOL)animated;
-(BOOL)isPresentingOrDismissing;
@end

#endif
