#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import "SBDataPlanAccountAlertItem.h"

@interface SBDataPlanActivationAlertItem : SBDataPlanAccountAlertItem {
	BOOL _newAccount;
}
@property(assign, nonatomic, getter=isNewAccount) BOOL newAccount;
-(id)initWithAccountURL:(NSURL *)accountURL newAccount:(BOOL)account;
// inherited: -(void)configure:(BOOL)configure requirePasscodeForActions:(BOOL)actions;
@end

#endif
