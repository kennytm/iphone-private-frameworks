#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <GraphicsServices/GSEvent.h>

@interface SBBrightnessController : NSObject {
	BOOL _debounce;
}
+(SBBrightnessController *)sharedBrightnessController;
-(CGFloat)_calcButtonRepeatDelay;
-(void)adjustBacklightLevel:(BOOL)level;
-(void)increaseBrightnessAndRepeat;
-(void)decreaseBrightnessAndRepeat;
-(void)handleBrightnessEvent:(GSEventRef)event;
@end

#endif
