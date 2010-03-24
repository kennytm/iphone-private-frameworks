#import <UIKit/UIKit.h>

// libactivator
// Centralized gestures and button management for iPhone OS

// Events

@interface LAEvent : NSObject<NSCoding> {
@private
	NSString *_name;
	NSString *_mode;
	BOOL _handled;
}
+ (id)eventWithName:(NSString *)name;
+ (id)eventWithName:(NSString *)name mode:(NSString *)mode;
- (id)initWithName:(NSString *)name;
- (id)initWithName:(NSString *)name mode:(NSString *)mode;

@property (nonatomic, readonly) NSString *name;
@property (nonatomic, readonly) NSString *mode;
@property (nonatomic, getter=isHandled) BOOL handled;

@end

// Activator

@protocol LAListener;

@interface LAActivator : NSObject {
@private
	NSMutableDictionary *_listeners;
	NSMutableDictionary *_preferences;
	NSUInteger _suppressReload;
	NSMutableDictionary *_eventData;
	NSBundle *_mainBundle;
	NSDictionary *_cachedAndSortedListeners;
	NSMutableDictionary *_cachedListenerTitles;
	NSMutableDictionary *_cachedListenerGroups;
}
+ (LAActivator *)sharedInstance;

@property (nonatomic, readonly) NSString *settingsFilePath;

- (id<LAListener>)listenerForEvent:(LAEvent *)event;
- (void)sendEventToListener:(LAEvent *)event;
- (void)sendAbortToListener:(LAEvent *)event;
- (void)sendDeactivateEventToListeners:(LAEvent *)event;

- (id<LAListener>)listenerForName:(NSString *)name;
- (void)registerListener:(id<LAListener>)listener forName:(NSString *)name; // Only available in SpringBoard
- (void)unregisterListenerWithName:(NSString *)name; // Only available in SpringBoard

- (BOOL)hasSeenListenerWithName:(NSString *)name;

- (void)assignEvent:(LAEvent *)event toListenerWithName:(NSString *)listenerName;
- (void)unassignEvent:(LAEvent *)event;
- (NSString *)assignedListenerNameForEvent:(LAEvent *)event;
- (NSArray *)eventsAssignedToListenerWithName:(NSString *)listenerName;

@property (nonatomic, readonly) NSArray *availableEventNames;
- (BOOL)eventWithNameIsHidden:(NSString *)name;
- (NSArray *)compatibleModesForEventWithName:(NSString *)name;
- (BOOL)eventWithName:(NSString *)eventName isCompatibleWithMode:(NSString *)eventMode;

@property (nonatomic, readonly) NSArray *availableListenerNames;
- (id)infoDictionaryValueOfKey:(NSString *)key forListenerWithName:(NSString *)name;
- (BOOL)listenerWithNameRequiresAssignment:(NSString *)name;
- (NSArray *)compatibleEventModesForListenerWithName:(NSString *)name;
- (BOOL)listenerWithName:(NSString *)listenerName isCompatibleWithMode:(NSString *)eventMode;
- (BOOL)listenerWithName:(NSString *)listenerName isCompatibleWithEventName:(NSString *)eventName;
- (UIImage *)iconForListenerName:(NSString *)listenerName;
- (UIImage *)smallIconForListenerName:(NSString *)listenerName;

@property (nonatomic, readonly) NSArray *availableEventModes;
- (NSString *)currentEventMode;

@end

extern LAActivator *LASharedActivator;

@interface LAActivator (Localization)
- (NSString *)localizedStringForKey:(NSString *)key value:(NSString *)value;

- (NSString *)localizedTitleForEventMode:(NSString *)eventMode;
- (NSString *)localizedTitleForEventName:(NSString *)eventName;
- (NSString *)localizedTitleForListenerName:(NSString *)listenerName;

- (NSString *)localizedGroupForEventName:(NSString *)eventName;
- (NSString *)localizedGroupForListenerName:(NSString *)listenerName;

- (NSString *)localizedDescriptionForEventMode:(NSString *)eventMode;
- (NSString *)localizedDescriptionForEventName:(NSString *)eventName;
- (NSString *)localizedDescriptionForListenerName:(NSString *)listenerName;
@end

// Listeners

@protocol LAListener <NSObject>
@optional

- (void)activator:(LAActivator *)activator didChangeToEventMode:(NSString *)eventMode;

// Incoming events
- (void)activator:(LAActivator *)activator receiveEvent:(LAEvent *)event forListenerName:(NSString *)listenerName;
- (void)activator:(LAActivator *)activator abortEvent:(LAEvent *)event forListenerName:(NSString *)listenerName;
- (void)activator:(LAActivator *)activator otherListenerDidHandleEvent:(LAEvent *)event forListenerName:(NSString *)listenerName;
- (void)activator:(LAActivator *)activator receiveDeactivateEvent:(LAEvent *)event forListenerName:(NSString *)listenerName;

// Simpler versions
- (void)activator:(LAActivator *)activator receiveEvent:(LAEvent *)event;
- (void)activator:(LAActivator *)activator abortEvent:(LAEvent *)event;
- (void)activator:(LAActivator *)activator otherListenerDidHandleEvent:(LAEvent *)event;
- (void)activator:(LAActivator *)activator receiveDeactivateEvent:(LAEvent *)event;

// Metadata (may be cached)
- (NSString *)activator:(LAActivator *)activator requiresLocalizedTitleForListenerName:(NSString *)listenerName;
- (NSString *)activator:(LAActivator *)activator requiresLocalizedDescriptionForListenerName:(NSString *)listenerName;
- (NSString *)activator:(LAActivator *)activator requiresLocalizedGroupForListenerName:(NSString *)listenerName;
- (NSNumber *)activator:(LAActivator *)activator requiresRequiresAssignmentForListenerName:(NSString *)listenerName;
- (NSArray *)activator:(LAActivator *)activator requiresCompatibleEventModesForListenerWithName:(NSString *)listenerName;
- (NSData *)activator:(LAActivator *)activator requiresIconDataForListenerName:(NSString *)listenerName;
- (NSData *)activator:(LAActivator *)activator requiresSmallIconDataForListenerName:(NSString *)listenerName;
- (NSNumber *)activator:(LAActivator *)activator requiresIsCompatibleWithEventName:(NSString *)eventName listenerName:(NSString *)listenerName;
- (id)activator:(LAActivator *)activator requiresInfoDictionaryValueOfKey:(NSString *)key forListenerWithName:(NSString *)listenerName;

@end

// Settings Controller

@interface LAListenerSettingsViewController : UIViewController {
@private
	NSString *_listenerName;
	NSString *_eventMode;
	NSMutableDictionary *_events;
	NSMutableDictionary *_compatibleEvents;
	NSArray *_groups;
}

- (id)init;
@property (nonatomic, copy) NSString *listenerName;

@end

extern NSString * const LAEventModeSpringBoard;
extern NSString * const LAEventModeApplication;
extern NSString * const LAEventModeLockScreen;


extern NSString * const LAEventNameMenuPressSingle;
extern NSString * const LAEventNameMenuPressDouble;
extern NSString * const LAEventNameMenuHoldShort;

extern NSString * const LAEventNameLockHoldShort;
extern NSString * const LAEventNameLockPressDouble;

extern NSString * const LAEventNameSpringBoardPinch;
extern NSString * const LAEventNameSpringBoardSpread;

extern NSString * const LAEventNameStatusBarSwipeRight;
extern NSString * const LAEventNameStatusBarSwipeLeft;
extern NSString * const LAEventNameStatusBarSwipeDown;
extern NSString * const LAEventNameStatusBarTapDouble;
extern NSString * const LAEventNameStatusBarHold;

extern NSString * const LAEventNameVolumeDownUp;
extern NSString * const LAEventNameVolumeUpDown;
extern NSString * const LAEventNameVolumeDisplayTap;

extern NSString * const LAEventNameSlideInFromBottom;
extern NSString * const LAEventNameSlideInFromBottomLeft;
extern NSString * const LAEventNameSlideInFromBottomRight;

extern NSString * const LAEventNameMotionShake;

@interface LASimpleListener : NSObject<LAListener> {
}
+ (LASimpleListener *)sharedInstance;

// System
- (BOOL)homeButton;
- (BOOL)sleepButton;
- (BOOL)respring;
- (BOOL)reboot;
- (BOOL)powerDown;
- (BOOL)spotlight;
- (BOOL)takeScreenshot;
- (BOOL)voiceControl;

// Lock Screen
- (BOOL)showLockScreen;
- (BOOL)dismissLockScreen;
- (BOOL)toggleLockScreen;

// iPod
- (BOOL)togglePlayback;
- (BOOL)previousTrack;
- (BOOL)nextTrack;
- (BOOL)musicControls;

@end
