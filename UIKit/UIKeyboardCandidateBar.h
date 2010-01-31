#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIView.h>
#import "UIKeyboardCandidateList.h"
@class NSMutableArray;

__attribute__((visibility("hidden")))
@interface UIKeyboardCandidateBar : UIView <UIKeyboardCandidateList> {
@private
	NSObject* m_delegate;
	NSArray* m_candidates;
	NSString* m_inlineText;
	NSMutableArray* m_cells;
	void* m_pageIndex;
	unsigned m_currentOffset;
	unsigned m_currentLimit;
	unsigned m_currentCandidateIndex;
	int m_currentPage;
}
+(id)sharedInstanceWithFrame:(CGRect)frame;
+(id)sharedInstance;
// inherited: -(id)initWithFrame:(CGRect)frame;
-(void)drawRect:(CGRect)rect;
// inherited: -(void)dealloc;
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

@interface UIKeyboardCandidateBar (internal)
-(void)_clearCells;
-(void)_clearAll;
-(void)_cellSelected:(id)selected;
@end

#endif
