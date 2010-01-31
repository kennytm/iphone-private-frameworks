#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import "UIKBKeyView.h"
#import "UIKit-Structs.h"
#import <CoreGraphics/CoreGraphics.h>
@class UIKBKeyboard;
@protocol UIKBHandwritingDelegateProtocol;

__attribute__((visibility("hidden")))
@interface UIKBHandwritingView : UIKBKeyView {
@private
	KBStrokeList* _strokes;
	id<UIKBHandwritingDelegateProtocol> _delegate;
	CGColorRef _inkColor;
	UIKBKeyboard* _keyboard;
	CGPoint _last;
	int _down;
	BOOL _stroked;
	BOOL _captureEnabled;
	BOOL _inGesture;
}
// inherited: -(id)initWithFrame:(CGRect)frame keyboard:(id)keyboard key:(id)key state:(int)state;
// inherited: -(void)dealloc;
-(void)updateKeyboard:(id)keyboard key:(id)key;
-(BOOL)clear;
-(void)setDelegate:(id)delegate;
-(void)send;
// inherited: -(void)drawRect:(CGRect)rect;
// inherited: -(void)touchesBegan:(id)began withEvent:(id)event;
// inherited: -(void)touchesMoved:(id)moved withEvent:(id)event;
// inherited: -(void)touchesEnded:(id)ended withEvent:(id)event;
// inherited: -(void)touchesCancelled:(id)cancelled withEvent:(id)event;
// inherited: -(BOOL)cancelTouchTracking;
@end


#endif
