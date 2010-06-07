#import <Foundation/Foundation.h>
#import "UIKit-Structs.h"

@class UIStatusBarServer;

@protocol UIStatusBarServerClient
@required
- (void)statusBarServer:(UIStatusBarServer *)server didReceiveStatusBarData:(UIStatusBarData *)data withActions:(int)actions;
- (void)statusBarServer:(UIStatusBarServer *)server didReceiveStyleOverrides:(int)overrides;
- (void)statusBarServer:(UIStatusBarServer *)server didReceiveGlowAnimationState:(BOOL)state forStyle:(int)style;
- (void)statusBarServer:(UIStatusBarServer *)server didReceiveDoubleHeightStatusString:(NSString *)statusString forStyle:(int)style;
@end
