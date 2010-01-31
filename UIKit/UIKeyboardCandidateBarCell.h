#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIView.h>

__attribute__((visibility("hidden")))
@interface UIKeyboardCandidateBarCell : UIView {
@private
	NSString* m_candidate;
	id m_target;
	SEL m_action;
	CGSize m_textSize;
	BOOL m_highlighted;
	BOOL m_special;
	BOOL m_arrow;
}
@property(readonly, assign, nonatomic) CGSize stringSize;
@property(readonly, assign, nonatomic) BOOL isArrow;
@property(assign, nonatomic) BOOL highlighted;
+(id)font;
-(id)initWithCandidate:(id)candidate tag:(int)tag target:(id)target action:(SEL)action;
// inherited: -(void)dealloc;
// -(void)drawRect:(CGRect)rect;
// inherited: -(void)touchesBegan:(id)began withEvent:(id)event;
// inherited: -(void)touchesMoved:(id)moved withEvent:(id)event;
// inherited: -(void)touchesEnded:(id)ended withEvent:(id)event;
// inherited: -(void)touchesCancelled:(id)cancelled withEvent:(id)event;
@end

#endif
