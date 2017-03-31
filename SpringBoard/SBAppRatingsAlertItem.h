/**
 * This header is generated by class-dump-z 0.2-1.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "SBAlertItem.h"
#import "UIModalViewDelegate.h"

@class SBInstalledApplicationIcon, UIPushButton;

@interface SBAppRatingsAlertItem : SBAlertItem <UIModalViewDelegate> {
	SBInstalledApplicationIcon* _icon;
	UIPushButton* _rateButton;
	BOOL _uninstallOnDismiss;
}
-(instancetype)initWithIcon:(id)icon uninstallOnDismiss:(BOOL)dismiss;
// inherited: -(void)dealloc;
// inherited: -(Class)alertSheetClass;
-(void)alertSheet:(id)sheet buttonClicked:(int)clicked;
// inherited: -(void)configure:(BOOL)configure requirePasscodeForActions:(BOOL)actions;
-(void)_starsControlValueChanged:(id)changed;
// inherited: -(BOOL)shouldShowInLockScreen;
// inherited: -(BOOL)dismissOnLock;
@end

