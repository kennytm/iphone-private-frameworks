#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <Foundation/NSObject.h>

@class UITextPosition;

__attribute__((visibility("hidden")))
@interface UITextInputArrowKeyHistory : NSObject {
@private
	UITextPosition* startPosition;
	int anchor;
	int direction;
	UITextPosition* start;
	UITextPosition* end;
	UITextPosition* cursor;
}
@property(retain, nonatomic) UITextPosition* startPosition;
@property(assign, nonatomic) int anchor;
@property(assign, nonatomic) int direction;
@property(retain, nonatomic) UITextPosition* cursor;
@property(retain, nonatomic) UITextPosition* start;
@property(retain, nonatomic) UITextPosition* end;
// inherited: -(void)dealloc;
-(void)resetWithStart:(id)start direction:(int)direction;
-(BOOL)isCompatibleWithDirection:(int)direction;
@end


#endif
