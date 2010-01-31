#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <Foundation/NSObject.h>
#import <CoreGraphics/CGGeometry.h>
@class UITouch;

__attribute__((visibility("hidden")))
@interface UIGestureContext : NSObject {
@private
	CGPoint _startLocation;
	float _startTimestamp;
	CGPoint _currentLocation;
	UITouch* _touch;
	int _state;
}
@property(assign, nonatomic) CGPoint startLocation;
@property(assign, nonatomic) CGPoint currentLocation;
@property(retain, nonatomic) UITouch* touch;
@property(assign, nonatomic) int state;
@property(assign, nonatomic) float startTimestamp;
-(id)initWithTouch:(id)touch inView:(id)view;
@end

#endif
