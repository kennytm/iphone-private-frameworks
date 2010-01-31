#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UITextInput.h>

@class DOMRange;

__attribute__((visibility("hidden")))
@interface UITextRangeImpl : UITextRange {
@private
	DOMRange* _domRange;
}
@property(retain, nonatomic) DOMRange* domRange;
+(id)wrapDOMRange:(id)range;
// inherited: -(id)description;
// inherited: -(void)dealloc;
// inherited: -(id)start;
// inherited: -(id)end;
// inherited: -(BOOL)isEmpty;
// inherited: -(BOOL)isEqual:(id)equal;
@end

#endif
