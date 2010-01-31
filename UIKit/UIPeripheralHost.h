#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <Foundation/NSObject.h>
@class UIView, UIKeyboardAutomatic, UIPeripheralHostState;

@interface UIPeripheralHost : NSObject {
	UIView* m_peripheralToolbar;
	UIView* m_peripheral;
	UIView* m_hostView;
	UIKeyboardAutomatic* m_automaticKeyboard;
	BOOL m_automaticAppearanceEnabled;
	BOOL m_automaticAppearanceEnabledForMail;
	BOOL m_automaticAppearanceEnabledInternal;
	BOOL m_automaticKeyboardAnimatingIn;
	BOOL m_automaticKeyboardPreparedForRotation;
	int m_automaticKeyboardState;
	BOOL m_ignoresReloadInputViews;
	BOOL m_useHideNotificationsWhenNotVisible;
	int m_automaticKeyboardOrientation;
	int m_nextAutomaticOrderInDirection;
	double m_nextAutomaticOrderInDuration;
	double m_lastAutomaticKeyboardDuration;
	UIPeripheralHostState* m_targetState;
}
@property(assign, nonatomic) BOOL automaticAppearanceEnabled;
@property(retain, nonatomic) UIPeripheralHostState* targetState;
@property(readonly, assign, nonatomic) BOOL automaticAppearanceReallyEnabled;
@property(readonly, assign, nonatomic) UIKeyboard* peripheralKeyboard;
@property(retain, nonatomic) UIView* alternatePeripheral;
@property(retain, nonatomic) UIView* peripheralToolbar;
+(id)sharedInstance;
// inherited: -(id)init;
// inherited: -(void)dealloc;
-(void)createHostViewIfNeeded;
-(BOOL)isOnScreen;
-(BOOL)isOffScreen;
-(void)manualKeyboardWasOrderedIn:(id)anIn;
-(void)orderInAutomatic;
-(void)orderInAutomaticSkippingAnimation;
-(void)orderInAutomaticFromDirection:(int)direction withDuration:(double)duration;
-(void)orderOutAutomatic;
-(void)orderOutAutomaticSkippingAnimation;
-(void)orderOutAutomaticToDirection:(int)direction withDuration:(double)duration;
-(void)prepareForRotationToOrientation:(int)orientation;
-(void)rotateToOrientation:(int)orientation;
-(void)finishRotation;
-(void)prepareForRotationOfKeyboard:(id)keyboard toOrientation:(int)orientation;
-(void)rotateKeyboard:(id)keyboard toOrientation:(int)orientation;
-(void)finishRotationOfKeyboard:(id)keyboard;
@end

@interface UIPeripheralHost (AutomaticAppearance)
-(void)setAutomaticAppearanceEnabledForMail:(BOOL)mail;
-(void)forceOrderInAutomatic;
-(void)forceOrderOutAutomatic;
-(void)forceOrderInAutomaticAnimated:(BOOL)automaticAnimated;
-(void)forceOrderOutAutomaticAnimated:(BOOL)animated;
-(void)forceOrderInAutomaticFromDirection:(int)direction withDuration:(double)duration;
-(void)forceOrderOutAutomaticToDirection:(int)direction withDuration:(double)duration;
-(id)containerWindow;
-(id)automaticKeyboard;
-(BOOL)hasCustomInputView;
-(BOOL)isHostingActiveImpl;
-(void)setPeripheralToolbarFrameForHostWidth:(float)hostWidth;
-(void)setPeripheralFrameForHostBounds:(CGRect)hostBounds;
-(CGSize)totalPeripheralSizeForOrientation:(int)orientation;
-(UIPeripheralAnimationGeometry)calculateAnimationGeometryForOrientation:(int)orientation outDirection:(int)direction forMinimize:(BOOL)minimize;
-(void)postWillHideNotificationForGeometry:(UIPeripheralAnimationGeometry)post duration:(double)duration;
-(void)postDidHideNotificationForGeometry:(UIPeripheralAnimationGeometry)post;
-(void)orderInWithAnimation:(BOOL)animation;
-(void)orderInWithAnimation:(BOOL)animation fromDirection:(int)direction duration:(double)duration;
-(void)orderOutWithAnimation:(BOOL)animation;
-(void)syncToExistingAnimations;
-(void)resetOrderOutDuration:(double)duration;
-(void)resetOrderOutDuration:(double)duration toCenter:(CGPoint)center;
-(BOOL)_isSuppressedByManualKeyboard;
-(void)orderOutWithAnimation:(BOOL)animation toDirection:(int)direction duration:(double)duration;
-(void)keyboardAutomaticWillOrderIn:(id)keyboardAutomatic context:(void*)context;
-(void)keyboardAutomaticOrderIn:(id)anIn finished:(id)finished;
-(void)keyboardAutomaticOrderOut:(id)anOut finished:(id)finished;
@end

#endif
