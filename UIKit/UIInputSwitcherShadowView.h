#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIView.h>

__attribute__((visibility("hidden")))
@interface UIInputSwitcherTableCellBackgroundView : UIView {
@private
	BOOL m_first;
	BOOL m_last;
	BOOL m_selected;
}
@property(assign, nonatomic) BOOL first;
@property(assign, nonatomic) BOOL last;
@property(assign, nonatomic) BOOL selected;
// -(void)drawRect:(CGRect)rect;
@end

#endif
