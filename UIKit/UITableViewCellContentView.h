#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIView.h>
@class CALayer;

__attribute__((visibility("hidden")))
@interface UITableViewCellContentView : UIView {
@private
	CALayer* _mask;
}
@property(retain, nonatomic) CALayer* mask;
-(id)_cell;
//-(void)didAddSubview:(id)subview;
//-(void)willRemoveSubview:(id)subview;
//-(void)setFrame:(CGRect)frame;
//-(void)setBounds:(CGRect)bounds;
// inherited: -(void)dealloc;
@end

#endif
