#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2
#import <UIKit/UIKit.h>

@class SBIcon;

@interface SBIconRotationContainer : UIView {
	UIView* _startSnapshot;
	UIView* _endSnapshot;
	SBIcon* _icon;
	BOOL _shouldCrossfade;
}
@property(retain, nonatomic) SBIcon* icon;
// inherited: -(void)dealloc;
-(void)setStartIcon:(id)icon endIcon:(id)icon2;
-(void)setOrigin:(CGPoint)origin;
-(void)prepareToCrossfade;
-(void)crossfadeWithDuration:(NSTimeInterval)duration;
-(id)createSnapshot:(id)snapshot includingShadows:(BOOL)shadows;
@end

#endif
