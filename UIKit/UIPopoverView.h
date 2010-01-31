#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIView.h>
@class UIDimmingView, UIViewController, NSArray, UIWindow, UILayoutContainerView;

@interface UIPopoverView : UIView {
@private
	id _delegate;
	UIView* _contentView;
	UIView* _bgView;
	SEL _presentAnimationCompletedSelector;
	SEL _dismissAnimationCompletedSelector;
	UIDimmingView* _dimmingView;
	UIViewController* _viewController;
	int _direction;
	int _backgroundStyle;
	NSArray* _passthroughViews;
	float _offset;
	float _sizeAdjustmentForKeyboard;
	float _slideAdjustmentForKeyboard;
	CGRect _desiredPresentationRect;
	CGRect _preferredFrame;
	CGSize _contentSize;
	CGPoint _contentOrigin;
	UIView* _toolbarShineImage;
	UIWindow* _popoverHostingWindow;
	BOOL _fastMode;
	UILayoutContainerView* _roundedLayoutContainerView;
	CGRect _popoverTargetRect;
	CGRect _screenPreferredFrame;
	struct {
		unsigned disableTopSeparator : 1;
		unsigned disableBottomSeparator : 1;
		unsigned selected : 1;
	} _popoverFlags;
}
@property(assign, nonatomic) id delegate;
@property(readonly, retain, nonatomic) UIView* contentView;
@property(assign, nonatomic) SEL presentAnimationCompletedSelector;
@property(assign, nonatomic) SEL dismissAnimationCompletedSelector;
@property(assign) int backgroundStyle;
@property(retain, nonatomic) UIViewController* viewController;
@property(retain, nonatomic) NSArray* passthroughViews;
@property(assign, nonatomic) int arrowDirections;
@property(readonly, assign) UIDimmingView* dimmingView;
@property(assign, nonatomic) BOOL useFastMode;
@property(assign, nonatomic) UILayoutContainerView* roundedLayoutContainerView;
@property(assign, nonatomic) float offset;
@property(assign, nonatomic) CGRect popoverTargetRect;
@property(assign, nonatomic) BOOL useToolbarShine;
+(id)_viewWithFrame:(CGRect)frame resizingMask:(unsigned)mask contentsImage:(CGImageRef)image rect:(CGRect)rect center:(CGRect)center antialiasingMask:(unsigned)mask6;
+(CGSize)_popoverViewSizeForContentSize:(CGSize)contentSize arrowDirection:(int)direction;
+(BOOL)_shouldClampHorizontallyToCornerForContentSize:(CGSize)contentSize arrowOffset:(float)offset;
+(BOOL)_shouldClampVerticallyToTopCornerForPopoverSize:(CGSize)popoverSize arrowOffset:(float)offset;
+(BOOL)_shouldClampVerticallyToBottomCornerForPopoverSize:(CGSize)popoverSize arrowOffset:(float)offset;
+(id)_popoverBackgroundViewForContentSize:(CGSize)contentSize offset:(float)offset direction:(int)direction background:(int)background contentOrigin:(out CGPoint*)origin;
+(id)popoverViewContainingView:(id)view;
// inherited: -(id)initWithFrame:(CGRect)frame;
-(id)initWithContentSize:(CGSize)contentSize;
// inherited: -(void)dealloc;
-(id)_viewForModalPresentationOfViewController:(id)viewController;
-(void)_modalPresentationWillBeginForViewController:(id)_modalPresentation;
-(void)_modalPresentationDidBeginForViewController:(id)_modalPresentation;
-(void)_modalPresentationWillEndForViewController:(id)_modalPresentation;
-(void)_modalPresentationDidEndForViewController:(id)_modalPresentation;
-(void)_hostingWindowWillRotate:(id)_hostingWindow;
-(void)_hostingWindowDidRotate:(id)_hostingWindow;
-(void)setDesiredPresentationRect:(CGRect)rect;
-(CGRect)presentationRect;
-(void)constrainFrameToPresentationRectAnimated:(BOOL)presentationRectAnimated duration:(double)duration;
-(void)constrainFrameToPresentationRectAnimated:(BOOL)presentationRectAnimated;
-(CGPathRef)_shadowPathForFrame:(CGRect)frame direction:(int)direction andOffset:(float)offset;
-(int)positionFromRect:(CGRect)rect;
-(void)presentFromRect:(CGRect)rect inView:(id)view contentSize:(CGSize)size backgroundStyle:(int)style animated:(BOOL)animated;
-(void)cancelSheetView;
-(void)dismissAnimated:(BOOL)animated;
-(int)_style;
-(void)dimmingViewWasTapped:(id)tapped;
-(void)_resizeAnimationDidStop:(id)_resizeAnimation finished:(id)finished context:(void*)context;
-(void)_presentationAnimationDidStop:(id)_presentationAnimation finished:(id)finished context:(void*)context;
-(void)_dismissalAnimationDidStop:(id)_dismissalAnimation finished:(id)finished context:(void*)context;
-(void)adjustFrame:(CGRect)frame animated:(BOOL)animated duration:(double)duration;
-(void)_keyboardWillShow:(id)_keyboard;
-(void)_keyboardWillHide:(id)_keyboard;
-(void)disableAutomaticKeyboard:(id)keyboard;
-(void)_setIgnoreTapsInDimmingView:(BOOL)dimmingView;
-(void)adjustFrameForViewController:(id)viewController fromViewController:(id)viewController2 isPopoverView:(BOOL)view;
-(void)sheetViewShouldAnimateForNewContentSize:(id)sheetView;
-(void)_backgroundStyleAnimationDidStop:(id)_backgroundStyleAnimation finished:(id)finished context:(void*)context;
-(void)_setBackgroundStyle:(int)style animated:(BOOL)animated;
-(void)presentFromRect:(CGRect)rect inView:(id)view animated:(BOOL)animated;
-(void)didMoveToWindow;
@end

#endif
