#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import "SBDeviceLockTitle.h"
@class TPLCDView;

@interface SBDeviceLockTitlePhone : SBDeviceLockTitle {
	BOOL _highlighted;
	TPLCDView* _lcdView;
}
// inherited: -(id)_protectedInitWithStyle:(int)style interfaceOrientation:(int)orientation;
// inherited: -(void)dealloc;
// inherited: -(BOOL)isHighlighted;
// inherited: -(void)setHighlighted:(BOOL)highlighted;
// inherited: -(id)title;
// inherited: -(void)setTitle:(id)title;
// inherited: -(id)subtitle;
// inherited: -(void)setSubtitle:(id)subtitle;
// inherited: -(void)blinkSubtitle;
@end

#endif
