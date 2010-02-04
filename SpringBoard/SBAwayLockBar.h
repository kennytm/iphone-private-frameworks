#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <TelephonyUI/TPBottomLockBar.h>
@class UIButton, NSMutableDictionary;

@interface SBAwayLockBar : TPBottomLockBar {
	UIButton* _bluetoothButton;
	UIButton* _slideshowButton;
	NSMutableDictionary* _orientationToButtonImages;
}
// inherited: -(void)dealloc;
-(void)setShowsBluetoothButton:(BOOL)button animated:(BOOL)animated;
-(void)setShowsSlideshowButton:(BOOL)button;
-(void)setSlideshowButtonSelected:(BOOL)selected;
// inherited: -(void)setOrientation:(int)orientation;
// inherited: -(id)hitTest:(CGPoint)test withEvent:(id)event;
-(id)_newButtonWithAction:(SEL)action tag:(int)tag;
-(id)_unselectedImageForButtonTag:(int)buttonTag interfaceOrientation:(int)orientation;
-(id)_selectedImageForButtonTag:(int)buttonTag interfaceOrientation:(int)orientation;
-(void)_setImagesForButton:(id)button orientation:(int)orientation;
-(void)_setShowsButton:(BOOL)button button:(id*)button2 buttonTag:(int)tag action:(SEL)action animated:(BOOL)animated;
-(void)_bluetoothButtonActivated:(id)activated;
-(void)_slideshowButtonActivated:(id)activated;
@end

#endif
