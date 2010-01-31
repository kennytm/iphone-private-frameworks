#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UITableViewController.h>

@class UISearchDisplayController;

__attribute__((visibility("hidden")))
@interface UISearchDisplayTableViewController : UITableViewController {
@private
	UISearchDisplayController* _linkedSearchDisplayController;
}
-(id)initWithStyle:(int)style searchDisplayController:(id)controller;
// inherited: -(void)viewDidDisappear:(BOOL)view;
// inherited: -(float)heightForViewInPopoverView;
@end

#endif
