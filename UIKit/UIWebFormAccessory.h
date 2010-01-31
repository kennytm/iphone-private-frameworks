#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIImageView.h>
@class UIButton, UISegmentedControl;
@protocol UIWebFormAccessoryDelegate;

__attribute__((visibility("hidden")))
@interface UIWebFormAccessory : UIImageView {
@private
	UIButton* _done;
	UISegmentedControl* _tab;
	UIButton* _autofill;
	id<UIWebFormAccessoryDelegate> delegate;
}
@property(retain, nonatomic) UIButton* _done;
@property(retain, nonatomic) UISegmentedControl* _tab;
@property(retain, nonatomic) UIButton* _autofill;
@property(assign, nonatomic) id<UIWebFormAccessoryDelegate> delegate;
// inherited: -(id)init;
// inherited: -(void)dealloc;
-(void)done:(id)done;
-(void)tab:(id)tab;
-(void)autoFill:(id)fill;
-(void)enableAutoFill:(BOOL)fill;
-(void)enableNext:(BOOL)next enablePrevious:(BOOL)previous;
-(void)layoutSubviews;
@end

#endif
