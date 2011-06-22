#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import "SBDataPlanAlertItem.h"
@class NSURL;

@interface SBDataPlanAccountAlertItem : SBDataPlanAlertItem {
	NSURL* _accountURL;
}
@property(copy, nonatomic) NSURL* accountURL;
+(NSString *)laterButtonTitle;
+(NSString *)nowButtonTitle;
-(id)initWithAccountURL:(NSURL *)accountURL;
// inherited: -(void)dealloc;
// inherited: -(void)configure:(BOOL)configure requirePasscodeForActions:(BOOL)actions;
-(void)alertSheet:(id)sheet buttonClicked:(int)clicked;
@end

#endif
