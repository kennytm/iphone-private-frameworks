#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UITextInput.h>

@class WebVisiblePosition;

__attribute__((visibility("hidden")))
@interface UITextPositionImpl : UITextPosition {
@private
	WebVisiblePosition* _webVisiblePosition;
}
@property(retain, nonatomic) WebVisiblePosition* webVisiblePosition;
+(id)wrapWebVisiblePosition:(id)position;
// inherited: -(void)dealloc;
// inherited: -(BOOL)isEqual:(id)equal;
// inherited: -(id)description;
@end

#endif
