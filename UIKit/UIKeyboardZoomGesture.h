#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIGestureRecognizer.h>

__attribute__((visibility("hidden")))
@interface UIKeyboardZoomGesture : UIGestureRecognizer {
@private
	BOOL _waiting;
	int _zoomType;
	float _initialDistance;
	double _maximumWaitForMultitouch;
	double _maximumWaitForMovement;
}
@property(assign, nonatomic) int zoomType;
@property(assign, nonatomic) double maximumWaitForMultitouch;
@property(assign, nonatomic) double maximumWaitForMovement;
// inherited: -(id)initWithTarget:(id)target action:(SEL)action;
// inherited: -(void)reset;
// inherited: -(void)touchesBegan:(id)began withEvent:(id)event;
// inherited: -(void)touchesMoved:(id)moved withEvent:(id)event;
// inherited: -(void)touchesEnded:(id)ended withEvent:(id)event;
// inherited: -(void)touchesCancelled:(id)cancelled withEvent:(id)event;
-(void)tooSlow:(id)slow;
-(void)clearTimers;
-(void)failAfterDelay:(double)delay;
-(CGPoint)centroidForTouches:(id)touches;
-(float)averageDistanceForTouches:(id)touches;
@end

#endif
