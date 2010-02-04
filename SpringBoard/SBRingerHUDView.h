#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2
#import "SBHUDView.h"

@interface SBRingerHUDView : SBHUDView {
	BOOL _silent;
}
@property(assign, nonatomic, getter=isSilent) BOOL silent;
-(void)_updateSilentImage;
// inherited: -(id)init;
@end

#endif
