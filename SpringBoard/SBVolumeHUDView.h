#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2
#import "SBHUDView.h"

@interface SBVolumeHUDView : SBHUDView {
	int _mode;
	BOOL _headphonesPresent;
}
@property(assign, nonatomic) int mode;
@property(assign, nonatomic) BOOL headphonesPresent;
-(void)_updateImage;
-(void)_updateLabels;
// inherited: -(id)init;
// inherited: -(void)setProgress:(float)progress;
@end

#endif
