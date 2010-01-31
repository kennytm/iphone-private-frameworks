#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <Foundation/NSObject.h>
#import "UIWebSelectControl.h"
#import <UIKit/UIPopoverController.h>

@class UIWebSelectTableViewController, UIKeyboard;

__attribute__((visibility("hidden")))
@interface UIWebSelectPopover : NSObject <UIWebSelectControl, UIPopoverControllerDelegate> {
@private
	UIWebSelectTableViewController* _tableViewController;
	UIPopoverController* _popoverController;
	UIKeyboard* _keyboard;
	float _popoverHeight;
	BOOL _isRotating;
}
@property(retain, nonatomic) UIWebSelectTableViewController* _tableViewController;
@property(retain, nonatomic) UIPopoverController* _popoverController;
-(id)initSelectPopover;
// inherited: -(void)dealloc;
// in a protocol: -(id)controlView;
// in a protocol: -(void)beginEditing;
// in a protocol: -(void)setUpDOMSelectNode:(id)node cachedItems:(id)items singleSelectionItem:(id)item singleSelectionIndex:(unsigned)index multipleSelection:(BOOL)selection;
-(void)done:(id)done;
// in a protocol: -(void)popoverControllerDidDismissPopover:(id)popoverController;
-(void)willRotate:(id)rotate;
-(void)didRotate:(id)rotate;
@end

#endif
