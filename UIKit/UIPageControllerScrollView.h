#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIScrollView.h>
@class UIPageController;

@interface UIPageControllerScrollView : UIScrollView {
	UIPageController* _pageController;
}
@property(assign, nonatomic) UIPageController* pageController;
// inherited: -(void)setBounds:(CGRect)bounds;
// inherited: -(void)setFrame:(CGRect)frame;
// inherited: -(void)layoutSubviews;
// inherited: -(void)_scrollViewWillBeginDragging;
-(void)_scrollViewDidEndDraggingWithDeceleration:(BOOL)_scrollView;
// inherited: -(void)_scrollViewDidEndDecelerating;
@end

#endif
