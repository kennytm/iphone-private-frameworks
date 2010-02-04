#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIView.h>
@class SBDeviceLockTitle, SBDeviceLockEntryField;

@interface SBDeviceLockView : UIView {
	int _style;
	int _interfaceOrientation;
	SBDeviceLockTitle* _statusView;
	SBDeviceLockEntryField* _entryView;
	id _delegate;
}
@property(readonly, assign, nonatomic) int style;
@property(assign, nonatomic) int interfaceOrientation;
@property(assign, nonatomic) id delegate;
@property(readonly, assign, nonatomic, getter=isKeypadMinimized) BOOL keypadMinimized;
@property(assign, nonatomic) BOOL showsEmergencyCallButton;
@property(assign, nonatomic) BOOL playsKeyboardClicks;
@property(retain, nonatomic) NSString* passcode;
@property(assign, nonatomic, getter=isShowingStatusWarning) BOOL showingStatusWarning;
@property(retain, nonatomic) NSString* statusSubtitle;
@property(retain, nonatomic) NSString* statusTitle;
@property(readonly, assign, nonatomic) UIView* keypadView;
@property(readonly, assign, nonatomic) UIView* entryView;
@property(readonly, assign, nonatomic) UIView* statusView;
-(id)initWithStyle:(int)style interfaceOrientation:(int)orientation;
-(id)protectedInitWithStyle:(int)style interfaceOrientation:(int)orientation;
// inherited: -(void)dealloc;
// inherited: -(void)setUserInteractionEnabled:(BOOL)enabled;
-(void)blinkStatusView;
-(void)deviceLockEntryFieldDidAcceptEntry:(id)deviceLockEntryField;
-(void)deviceLockEntryFieldDidCancelEntry:(id)deviceLockEntryField;
-(BOOL)deviceLockEntryField:(id)field shouldInsertText:(id)text;
-(void)deviceLockEntryFieldTextDidChange:(id)deviceLockEntryFieldText;
-(void)notifyDelegateThatPasscodeDidChange;
-(void)notifyDelegateThatPasscodeWasEntered;
-(void)notifyDelegateThatCancelButtonWasPressed;
-(void)notifyDelegateThatEmergencyCallButtonWasPressed;
-(void)willAnimateToInterfaceOrientation:(int)interfaceOrientation;
-(void)animateToInterfaceInterfaceOrientation:(int)interfaceInterfaceOrientation;
-(void)didAnimateToInterfaceOrientation:(int)interfaceOrientation;
@end

#endif
