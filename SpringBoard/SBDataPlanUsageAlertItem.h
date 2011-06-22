#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import "SBDataPlanAccountAlertItem.h"
@class NSNumber;

@interface SBDataPlanUsageAlertItem : SBDataPlanAccountAlertItem {
	NSNumber* _remainingPortion;
}
@property(retain, nonatomic) NSNumber* remainingPortion;
-(id)initWithAccountURL:(NSURL *)accountURL usage:(id)usage;
// inherited: -(void)dealloc;
// inherited: -(void)configure:(BOOL)configure requirePasscodeForActions:(BOOL)actions;
@end

#endif
