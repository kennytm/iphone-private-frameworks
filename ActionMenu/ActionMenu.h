#import <UIKit/UIKit.h>

typedef enum {
	AMMenuItemStyleDefault = 0,
		// Default display style (what the user has selected)
    AMMenuItemStyleText = 1,
    	// Always display text
    AMMenuItemStyleImage = 2,
    	// Display image where available, otherwise display text
} AMMenuItemStyle;

typedef enum {
	AMActionMenuBehaviorDefault = 0,
		// Default additional behaviors provided by Action Menu
	AMActionMenuBehaviorDisableMenu = (1 << 0),
		// Disable the popup menu that Action Menu has added
} AMActionMenuBehaviors;


#define kAMMenuItemPrioritySelect    100
#define kAMMenuItemPrioritySelectAll 200
#define kAMMenuItemPriorityCut       300
#define kAMMenuItemPriorityCopy      400
#define kAMMenuItemPriorityPaste     500
#define kAMMenuItemPriorityCorrect   900
#define kAMMenuItemPriorityDefault   1000

#define kAMMenuItemPriorityCopyAll   450
#define kAMMenuItemPriorityHistory   525
#define kAMMenuItemPriorityFavorites 550
#define kAMMenuItemPriorityDial      925
#define kAMMenuItemPriorityLookup    950
#define kAMMenuItemPriorityFind      975
#define kAMMenuItemPriorityTweet     1100
#define kAMMenuItemPriorityScroll    1200

#define kAMMenuItemPriorityBuiltins  510

@protocol AMMenuItem <NSObject>
@property (nonatomic, readonly) SEL action;
	// Selector that will be sent to the target when menu item is pressed
@property (nonatomic, readonly) SEL canPerform;
	// Selector that will be sent to the target to query whether menu item is valid
@property (nonatomic, copy) NSString *title;
	// Localized title of the menu item
@property (nonatomic, assign) UIImage *image;
	// Image that will be used to display the menu item
@property (nonatomic, assign) AMMenuItemStyle style;
	// Style of the menu item
@property (nonatomic) NSInteger priority;
	// Specify the priority of the item
@end

@interface UIMenuController (ActionMenu)
// Plugin Registration functions
- (id<AMMenuItem>)registerAction:(SEL)action title:(NSString *)title canPerform:(SEL)canPerform;
- (id<AMMenuItem>)registerAction:(SEL)action title:(NSString *)title canPerform:(SEL)canPerform forPlugin:(NSString *)pluginName;
	// action will be sent to the target when the menu item has been pressed
	// canPerform will be sent to the target when the menu is about to be shown and we need to know if the menu item is valid
	// title is the localized title of the menu item
	// pluginName is the unlocalized title of the plugin
@end

@interface UIResponder (ActionMenu)
- (NSString *)textualRepresentation;
	// Called by plugins to get the text of the object; implement manually for custom views
- (NSString *)selectedTextualRepresentation;
	// Returns only the selected text; if unimplemented, will call and return textualRepresentation
- (AMActionMenuBehaviors)actionMenuBehaviors;
	// Control which additional ActionMenu behaviors are valid on this target
- (BOOL)always;
	// Always returns YES (used by actions that are always valid)
@end

/*
	Notes:
	Plugins will be loaded lazily from /Libary/ActionMenu/Plugins when the menu is first shown; this is usually much later than one might expect.
	If the user disables a plugin after it has been loaded, the plugin will still be resident in memory, but its items will no longer show.
	If the user enables a plugin, it will be loaded the next time the menu becomes visible.
	
	Plugins may be either .dylibs or .bundles
	Dylib plugins get a ON/OFF switch in the preferences pane.
	Bundle plugins get their own subpane to do what they please with.
*/