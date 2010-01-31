#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import "UIKBKeyView.h"
#import "UIKeyboardCandidateList.h"
#import <CoreGraphics/CGColor.h>
@class NSArray, NSMutableArray, NSObject, UIColor;

__attribute__((visibility("hidden")))
@interface UIKBCandidateView : UIKBKeyView <UIKeyboardCandidateList> {
@private
	NSArray* m_candidates;
	NSMutableArray* m_buttons;
	NSObject* m_delegate;
	int m_columns;
	int m_candidatesPerColumn;
	int m_candidatesPerPage;
	int m_current;
	int m_firstShown;
	int m_firstComposition;
	int m_candidateCount;
	UIColor* m_textColor;
	CGColorRef m_highlightColor;
	BOOL m_respondsToSelect;
	BOOL m_respondsToAccept;
}
// inherited: -(id)initWithFrame:(CGRect)frame keyboard:(id)keyboard key:(id)key state:(int)state;
// inherited: -(void)dealloc;
-(void)updateKeyboard:(id)keyboard key:(id)key;
-(id)candidateList;
-(void)nextCandidatesAction;
// in a protocol: -(void)setCandidates:(id)candidates inlineText:(id)text inlineRect:(CGRect)rect maxX:(float)x layout:(BOOL)layout;
// in a protocol: -(void)layout;
// in a protocol: -(void)setUIKeyboardCandidateListDelegate:(id)delegate;
// in a protocol: -(void)showCandidateAtIndex:(unsigned)index;
// in a protocol: -(void)showNextCandidate;
// in a protocol: -(void)showPreviousCandidate;
// in a protocol: -(void)showPageAtIndex:(unsigned)index;
// in a protocol: -(void)showNextPage;
// in a protocol: -(void)showPreviousPage;
// in a protocol: -(id)currentCandidate;
// in a protocol: -(unsigned)currentIndex;
// in a protocol: -(id)candidateAtIndex:(unsigned)index;
// in a protocol: -(void)candidateAcceptedAtIndex:(unsigned)index;
// in a protocol: -(unsigned)count;
// in a protocol: -(void)configureKeyboard:(id)keyboard;
@end

#endif
