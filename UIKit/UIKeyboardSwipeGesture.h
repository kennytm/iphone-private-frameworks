#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIGestureRecognizer.h>
@class NSMutableArray;

__attribute__((visibility("hidden")))
@interface UIKeyboardSwipeGesture : UIGestureRecognizer {
@private
	double _maximumDuration;
	float _verticalScale;
	float _horizontalScale;
	float _minimumHorizontalMovement;
	float _maximumHorizontalMovement;
	float _minimumVerticalMovement;
	float _maximumVerticalMovement;
	double _startTime;
	int _numberOfFingers;
	NSMutableArray* _activeTouches;
	unsigned _timerOn : 1;
}
@property(assign, nonatomic) int numberOfFingers;
@property(assign, nonatomic) float minimumVerticalMovement;
// inherited: -(id)initWithTarget:(id)target action:(SEL)action;
-(float)minimumVerticalMovementForTimeInterval:(double)timeInterval;
-(float)minimumHorizontalMovementForTimeInterval:(double)timeInterval;
-(float)maximumVerticalMovementForTimeInterval:(double)timeInterval;
-(float)maximumHorizontalMovementForTimeInterval:(double)timeInterval;
-(void)clearTimer;
// inherited: -(void)dealloc;
// inherited: -(void)reset;
-(void)startTimer:(double)timer;
-(void)tooSlow:(id)slow;
-(void)tooManyFingers;
-(id)infoForTouch:(id)touch;
-(BOOL)mergeTouches:(id)touches;
// inherited: -(void)touchesBegan:(id)began withEvent:(id)event;
-(int)determineStateForTouch:(id)touch atTimeInterval:(double)timeInterval;
-(int)overallState;
// inherited: -(void)touchesMoved:(id)moved withEvent:(id)event;
// inherited: -(void)touchesEnded:(id)ended withEvent:(id)event;
// inherited: -(void)touchesCancelled:(id)cancelled withEvent:(id)event;
// inherited: -(void)setState:(int)state;
@end

#endif
