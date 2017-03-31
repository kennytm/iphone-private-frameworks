#import <UIKit/UIKit.h>
#import "FSSwitchState.h"

@protocol FSSwitchDataSource <NSObject>
@optional

- (FSSwitchState)stateForSwitchIdentifier:(NSString *)switchIdentifier;
// Gets the current state of the switch.
// Must override if building a settings-like switch.
// Return FSSwitchStateIndeterminate if switch is loading
// By default returns FSSwitchStateIndeterminate

- (void)applyState:(FSSwitchState)newState forSwitchIdentifier:(NSString *)switchIdentifier;
// Sets the new state of the switch
// Must override if building a settings-like switch.
// By default calls through to applyActionForSwitchIdentifier: if newState is different from the current state

- (void)applyActionForSwitchIdentifier:(NSString *)switchIdentifier;
// Runs the default action for the switch.
// Must override if building an action-like switch.
// By default calls through to applyState:forSwitchIdentifier: if state is not indeterminate

- (NSString *)titleForSwitchIdentifier:(NSString *)switchIdentifier;
// Returns the localized title for the switch.
// By default reads the CFBundleDisplayName out of the switch's bundle.

- (id)glyphImageDescriptorOfState:(FSSwitchState)switchState size:(CGFloat)size scale:(CGFloat)scale forSwitchIdentifier:(NSString *)switchIdentifier;
// Provide an image descriptor that best displays at the requested size and scale
// By default looks through the bundle to find a glyph image

- (NSBundle *)bundleForSwitchIdentifier:(NSString *)switchIdentifier;
// Provides a bundle to look for localizations/images in
// By default returns the bundle for the current class

- (void)switchWasRegisteredForIdentifier:(NSString *)switchIdentifier;
// Called when switch is first registered

- (void)switchWasUnregisteredForIdentifier:(NSString *)switchIdentifier;
// Called when switch is unregistered

- (BOOL)hasAlternateActionForSwitchIdentifier:(NSString *)switchIdentifier;
// Gets whether the switch supports an alternate or "hold" action
// By default queries if switch responds to applyAlternateActionForSwitchIdentifier: or if it has a "alternate-action-url" key set

- (void)applyAlternateActionForSwitchIdentifier:(NSString *)switchIdentifier;
// Applies the alternate or "hold" action
// By default launches the URL stored in the "alternate-action-url" key of the switch's bundle

- (BOOL)switchWithIdentifierIsEnabled:(NSString *)switchIdentifier;
// Gets whether or not the switch is enabled
// Must override if switch can be disabled
// By default returns YES

@end