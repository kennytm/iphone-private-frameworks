#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIViewController.h>
@class NSMutableArray, UIScrollView, UIPageControl;
@protocol UIPageControllerDelegate;

@interface UIPageController : UIViewController {
	NSMutableArray* _viewControllers;
	UIViewController* _disappearingViewController;
	UIView* _wrapperViews[3];
	UIScrollView* _scrollView;
	UIPageControl* _pageControl;
	id<UIPageControllerDelegate> _delegate;
	int _pageSpacing;
	int _visibleIndex;
	int _pageCount;
	struct {
		unsigned _firstTouchForView : 1;
		unsigned _isTap : 1;
		unsigned _isWarped : 1;
		unsigned _isDelayed : 1;
		unsigned _sentTouchesEnded : 1;
	} _pageControllerFlags;
}
@property(assign, nonatomic) id<UIPageControllerDelegate> delegate;
@property(assign, nonatomic) int visibleIndex;
@property(assign, nonatomic) int pageCount;
@property(readonly, retain, nonatomic) UIViewController* visibleViewController;
@property(assign, nonatomic) BOOL displaysPageControl;
@property(assign, nonatomic) float pageSpacing;
// inherited: -(void)dealloc;
// inherited: -(void)loadView;
// inherited: -(void)viewDidUnload;
-(id)_scrollView;
-(void)_setPreviousViewController:(id)controller;
-(void)_setVisibleViewController:(id)controller;
-(void)_setNextViewController:(id)controller;
-(BOOL)_needToLoadPrevious;
-(BOOL)_needToLoadVisible;
-(BOOL)_needToLoadNext;
-(id)_loadPreviousViewController;
-(id)_loadVisibleViewControllerAndNotify:(BOOL)notify;
-(id)_loadNextViewController;
-(id)_previousViewController;
-(id)_visibleViewController;
-(id)_nextViewController;
-(BOOL)_hasPreviousViewController;
-(BOOL)_hasVisibleViewController;
-(BOOL)_hasNextViewController;
-(void)_scrollViewWillBeginPaging;
-(void)_scrollViewDidEndPaging;
-(void)_adjustScrollViewContentInsets;
-(void)_scrollView:(id)view boundsDidChangeToSize:(CGSize)bounds;
-(void)_scrollViewDidScroll:(id)_scrollView;
-(void)_sendDidAppearDisappear;
-(void)setVisibleIndex:(int)index animated:(BOOL)animated;
-(void)_pageChanged:(id)changed;
-(void)_createPageControl;
-(int)indexOfViewController:(id)viewController;
// inherited: -(BOOL)_allowsAutorotation;
-(BOOL)_doesVisibleViewControllerSupportInterfaceOrientation:(int)orientation;
// inherited: -(BOOL)shouldAutorotateToInterfaceOrientation:(int)interfaceOrientation;
// inherited: -(BOOL)_isSupportedInterfaceOrientation:(int)orientation;
// inherited: -(id)rotatingHeaderView;
// inherited: -(id)rotatingFooterView;
// inherited: -(BOOL)_shouldUseOnePartRotation;
// inherited: -(void)_getRotationContentSettings:(XXStruct_Nw9VXC*)settings;
// inherited: -(void)willRotateToInterfaceOrientation:(int)interfaceOrientation duration:(double)duration;
// inherited: -(void)willAnimateRotationToInterfaceOrientation:(int)interfaceOrientation duration:(double)duration;
// inherited: -(void)willAnimateFirstHalfOfRotationToInterfaceOrientation:(int)interfaceOrientation duration:(double)duration;
// inherited: -(void)didAnimateFirstHalfOfRotationToInterfaceOrientation:(int)interfaceOrientation;
// inherited: -(void)willAnimateSecondHalfOfRotationFromInterfaceOrientation:(int)interfaceOrientation duration:(double)duration;
// inherited: -(void)didRotateFromInterfaceOrientation:(int)interfaceOrientation;
// inherited: -(void)viewWillAppear:(BOOL)view;
// inherited: -(void)viewDidAppear:(BOOL)view;
// inherited: -(void)viewWillDisappear:(BOOL)view;
// inherited: -(void)viewDidDisappear:(BOOL)view;
@end


#endif
