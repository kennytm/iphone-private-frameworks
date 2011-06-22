#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import "SBDataPlanAccountAlertItem.h"

@interface SBDataPlanFailureAlertItem : SBDataPlanAccountAlertItem {
	NSString* _carrierName;
	BOOL _newAccount;
}
@property(copy, nonatomic) NSString* carrierName;
@property(assign, nonatomic, getter=isNewAccount) BOOL newAccount;
// inherited: +(id)laterButtonTitle;
// inherited: +(id)nowButtonTitle;
-(id)initWithAccountURL:(NSURL *)accountURL carrierName:(NSString *)name newAccount:(BOOL)account;
// inherited: -(void)dealloc;
// inherited: -(void)configure:(BOOL)configure requirePasscodeForActions:(BOOL)actions;
@end

#endif
