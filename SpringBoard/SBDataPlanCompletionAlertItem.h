#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import "SBDataPlanAlertItem.h"
@class NSString;

@interface SBDataPlanCompletionAlertItem : SBDataPlanAlertItem {
	NSString* _carrierName;
	BOOL _newAccount;
}
@property(copy, nonatomic) NSString* carrierName;
@property(assign, nonatomic, getter=isNewAccount) BOOL newAccount;
-(id)initWithCarrierName:(id)carrierName newAccount:(BOOL)account;
// inherited: -(void)dealloc;
// inherited: -(void)configure:(BOOL)configure requirePasscodeForActions:(BOOL)actions;
-(void)alertSheet:(id)sheet buttonClicked:(int)clicked;
@end

#endif
