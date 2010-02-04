#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIView.h>

@interface SBDeviceLockTitle : UIView {
	int _style;
	int _interfaceOrientation;
}
@property(assign, nonatomic) int interfaceOrientation;
@property(retain, nonatomic) NSString* subtitle;
@property(retain, nonatomic) NSString* title;
@property(assign, nonatomic, getter=isHighlighted) BOOL highlighted;
-(id)initWithStyle:(int)style interfaceOrientation:(int)orientation;
-(id)_protectedInitWithStyle:(int)style interfaceOrientation:(int)orientation;
-(void)blinkSubtitle;
@end

#endif
