#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <Foundation/NSObject.h>
#import <CoreGraphics/CGGeometry.h>
@class UITouch, UIKBKey, UIKBKeyplane, UIKBKey;

__attribute__((visibility("hidden")))
@interface UIKeyboardTouchInfo : NSObject {
@private
	UITouch* _touch;
	UIKBKey* _key;
	UIKBKeyplane* _keyplane;
	UIKBKey* _slidOffKey;
	CGPoint _initialPoint;
}
@property(retain, nonatomic) UITouch* touch;
@property(retain, nonatomic) UIKBKey* key;
@property(retain, nonatomic) UIKBKeyplane* keyplane;
@property(retain, nonatomic) UIKBKey* slidOffKey;
@property(assign, nonatomic) CGPoint initialPoint;
// inherited: -(void)dealloc;
@end

#endif
