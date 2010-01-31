#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UITableView.h>

__attribute__((visibility("hidden")))
@interface UIInputSwitcherView : UIView <UITableViewDataSource, UITableViewDelegate> {
@private
	UITableView* m_table;
	UIView* m_shadowView;
	UIView* m_selExtraView;
	int m_mode;
	CGRect m_referenceRect;
	float m_pointerOffset;
	NSIndexPath* m_currentInputModeIndexPath;
}
@property(readonly, assign, nonatomic) int mode;
+(id)sharedInstance;
// inherited: -(id)initWithFrame:(CGRect)frame;
// inherited: -(void)dealloc;
-(void)applicationWillSuspend:(id)application;
-(id)font;
-(void)setFrame:(CGRect)frame;
-(BOOL)isVisible;
-(void)show;
-(void)showAsHUD;
-(void)showAsPopupFromRect:(CGRect)rect inView:(id)view;
-(void)fade;
-(void)fadeWithDelay:(double)delay;
-(void)removeFromSuperview;
-(void)hide;
-(void)fadeAnimationDidStop:(id)fadeAnimation finished:(id)finished context:(void*)context;
-(void)updateSelectionWithPoint:(CGPoint)point;
-(id)selectedInputMode;
-(void)selectCurrentInputMode;
-(void)selectRowForInputMode:(id)inputMode;
-(void)selectInputMode:(id)mode;
-(id)nextInputMode;
-(void)selectNextInputMode;
-(id)previousInputMode;
-(void)selectPreviousInputMode;
-(int)indexForIndexPath:(id)indexPath;
// in a protocol: -(int)tableView:(id)view numberOfRowsInSection:(int)section;
// in a protocol: -(id)tableView:(id)view cellForRowAtIndexPath:(id)indexPath;
// in a protocol: -(float)tableView:(id)view heightForRowAtIndexPath:(id)indexPath;
// in a protocol: -(void)tableView:(id)view didSelectRowAtIndexPath:(id)indexPath;
@end

#endif
