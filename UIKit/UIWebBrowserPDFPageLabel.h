#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIView.h>
@class UILabel, UIHighlightView;

__attribute__((visibility("hidden")))
@interface UIWebBrowserPDFPageLabel : UIView {
@private
	UILabel* _label;
	UIHighlightView* _highlight;
}
// inherited: -(id)initWithFrame:(CGRect)frame;
// -(void)sizeToFit;
-(void)setText:(id)text;
// inherited: -(void)dealloc;
@end


#endif
