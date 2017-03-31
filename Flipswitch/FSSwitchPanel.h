#import <UIKit/UIKit.h>
#import "FSSwitchState.h"

@interface FSSwitchPanel : NSObject

+ (FSSwitchPanel *)sharedPanel;

@property (nonatomic, readonly, copy) NSArray *switchIdentifiers;
// Returns a list of identifying all switches installed on the device

- (NSString *)titleForSwitchIdentifier:(NSString *)switchIdentifier;
// Returns the localized title for a specific switch

- (UIButton *)buttonForSwitchIdentifier:(NSString *)switchIdentifier usingTemplate:(NSBundle *)templateBundle;
// Returns a UIButton for a specific switch
// The button automatically updates its style based on the user interaction and switch state changes, applies the standard action when pressed, and applies the alternate action when held

- (UIImage *)imageOfSwitchState:(FSSwitchState)state controlState:(UIControlState)controlState forSwitchIdentifier:(NSString *)switchIdentifier usingTemplate:(NSBundle *)templateBundle;
- (UIImage *)imageOfSwitchState:(FSSwitchState)state controlState:(UIControlState)controlState scale:(CGFloat)scale forSwitchIdentifier:(NSString *)switchIdentifier usingTemplate:(NSBundle *)templateBundle;
// Returns an image representing how a specific switch would look in a particular state when styled with the provided template

- (BOOL)hasCachedImageOfSwitchState:(FSSwitchState)state controlState:(UIControlState)controlState forSwitchIdentifier:(NSString *)switchIdentifier usingTemplate:(NSBundle *)templateBundle;
- (BOOL)hasCachedImageOfSwitchState:(FSSwitchState)state controlState:(UIControlState)controlState scale:(CGFloat)scale forSwitchIdentifier:(NSString *)switchIdentifier usingTemplate:(NSBundle *)templateBundle;
// Returns YES if an image representing the state is loaded

- (FSSwitchState)stateForSwitchIdentifier:(NSString *)switchIdentifier;
// Returns the current state of a particualr switch
- (void)setState:(FSSwitchState)state forSwitchIdentifier:(NSString *)switchIdentifier;
// Updates the state of a particular switch. If the switch accepts the change it will send a state change
- (void)applyActionForSwitchIdentifier:(NSString *)switchIdentifier;
// Applies the default action of a particular switch

- (BOOL)hasAlternateActionForSwitchIdentifier:(NSString *)switchIdentifier;
// Queries whether a switch supports an alternate action. This is often triggered by a hold gesture
- (void)applyAlternateActionForSwitchIdentifier:(NSString *)switchIdentifier;
// Apply the alternate action of a particular switch

- (void)openURLAsAlternateAction:(NSURL *)url;
// Helper method to open a particular URL as if it were launched from an alternate action

- (BOOL)switchWithIdentifierIsEnabled:(NSString *)switchIdentifier;
// Returns YES if the switch is enabled (1.0.1 or later)

@end

@protocol FSSwitchDataSource;

@interface FSSwitchPanel (SpringBoard)
- (void)registerDataSource:(id<FSSwitchDataSource>)dataSource forSwitchIdentifier:(NSString *)switchIdentifier;
// Registers a switch implementation for a specific identifier. Bundlee in /Library/Switches will have their principal class automatically loaded
- (void)unregisterSwitchIdentifier:(NSString *)switchIdentifier;
// Unregisters a switch
- (void)stateDidChangeForSwitchIdentifier:(NSString *)switchIdentifier;
// Informs the system when a switch changes its state. This will trigger any switch buttons to update their style
@end

extern NSString * const FSSwitchPanelSwitchesChangedNotification;

extern NSString * const FSSwitchPanelSwitchStateChangedNotification;
extern NSString * const FSSwitchPanelSwitchIdentifierKey;

extern NSString * const FSSwitchPanelSwitchWillOpenURLNotification;
