#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIView.h>
@class UIBookViewController;

__attribute__((visibility("hidden")))
@interface _UIBookViewControllerView : UIView {
@private
	UIBookViewController* _bookViewController;
}
-(id)initWithBookViewController:(id)bookViewController withView:(id)view;
// inherited: -(void)touchesEnded:(id)ended withEvent:(id)event;
// -(void)layoutSubviews;
@end

#endif
