#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <Foundation/NSObject.h>
@class UIDelayedAction, UIInputSwitcherView, NSString;

__attribute__((visibility("hidden")))
@interface UIInputSwitcher : NSObject {
@private
	UIDelayedAction* m_switcherDelay;
	int m_state;
	UIInputSwitcherView* m_switcherView;
	NSString* _newMode;
}
@property(copy, nonatomic) NSString* newMode;
+(id)sharedInstance;
// inherited: -(id)init;
// inherited: -(void)dealloc;
-(void)hideSwitcher;
-(void)showSwitcher;
-(void)touchSwitcherTimer;
-(void)cancelSwitcherTimer;
-(void)clearSwitcherTimer;
-(BOOL)isVisible;
-(BOOL)handleSwitchCommand:(BOOL)command;
-(BOOL)switchMode:(id)mode withDelay:(BOOL)delay;
-(BOOL)handleModifiersChangedEvent:(GSEventRef)event;
@end

#endif
