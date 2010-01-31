#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIGestureRecognizer.h>
@class NSMutableArray;

__attribute__((visibility("hidden")))
@interface UIWebTouchEventsGestureRecognizer : UIGestureRecognizer {
@private
	id _touchTarget;
	SEL _touchAction;
	unsigned _passedHitTest : 1;
	unsigned _defaultPrevented : 1;
	float _originalGestureDistance;
	float _originalGestureAngle;
	int _type;
	CGPoint _locationInWindow;
	NSMutableArray* _touchLocations;
	NSMutableArray* _touchIdentifiers;
	float _scale;
	float _rotation;
}
@property(assign, nonatomic, getter=isDefaultPrevented) BOOL defaultPrevented;
@property(readonly, assign, nonatomic) int type;
@property(readonly, assign, nonatomic) CGPoint locationInWindow;
@property(retain, nonatomic) NSMutableArray* touchLocations;
@property(retain, nonatomic) NSMutableArray* touchIdentifiers;
@property(readonly, assign, nonatomic) float scale;
@property(readonly, assign, nonatomic) float rotation;
// inherited: -(id)initWithTarget:(id)target action:(SEL)action;
// inherited: -(void)dealloc;
-(id)_typeDescription;
-(id)_locationsDescription;
-(id)_identifiersDescription;
// inherited: -(id)description;
// inherited: -(void)reset;
-(BOOL)_hitTestTouches:(id)touches;
-(void)_recordTouches:(id)touches type:(int)type;
-(void)_processTouches:(id)touches withEvent:(id)event type:(int)type;
// inherited: -(BOOL)canBePreventedByGestureRecognizer:(id)recognizer;
// inherited: -(void)touchesBegan:(id)began withEvent:(id)event;
// inherited: -(void)touchesMoved:(id)moved withEvent:(id)event;
// inherited: -(void)touchesEnded:(id)ended withEvent:(id)event;
// inherited: -(void)touchesCancelled:(id)cancelled withEvent:(id)event;
@end

#endif
