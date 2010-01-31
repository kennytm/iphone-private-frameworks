#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIView.h>

@interface UIMultiColumnsNavigationTransitionView : UIView <NSCoding> {
@private
	id _delegate;
	int _transition;
	UIView* _firstResponderViewToRestore;
	unsigned _isTransitioning : 1;
	float _columnWidth;
	int _columnCount;
	NSArray* _fromViews;
	NSArray* _toViews;
	NSArray* _viewsToRemove;
	NSArray* _viewsToAdd;
	NSArray* _displayedViews;
	CFDictionaryRef _dividerViews;
	CFDictionaryRef _containerViews;
	UIColor* _dividersColor;
	float _dividersWidth;
}
@property(assign, nonatomic) id delegate;
@property(assign, nonatomic) float columnWidth;
@property(assign, nonatomic) int columnCount;
+(double)defaultDurationForTransition:(int)transition;
// inherited: -(id)initWithFrame:(CGRect)frame;
// in a protocol: -(id)initWithCoder:(id)coder;
// in a protocol: -(void)encodeWithCoder:(id)coder;
// inherited: -(void)dealloc;
-(BOOL)transition:(int)transition toViews:(id)views;
-(BOOL)transition:(int)transition fromViews:(id)views toViews:(id)views3;
-(BOOL)isTransitioning;
-(void)_navigationTransitionDidStop;
-(id)_dividerViewForView:(id)view;
-(void)_removeDividerViewForView:(id)view;
-(id)_containerViewForView:(id)view;
-(void)_removeContainerViewForView:(id)view;
@end

#endif
