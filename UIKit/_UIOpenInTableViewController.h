#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2
#import <UIKit/UITableViewController.h>
@class UIDocumentInteractionController;

__attribute__((visibility("hidden")))
@interface _UIOpenInTableViewController : UITableViewController {
@private
	UIDocumentInteractionController* _documentInteractionController;
}
-(id)initWithDocumentInteractionController:(id)documentInteractionController;
// inherited: -(int)tableView:(id)view numberOfRowsInSection:(int)section;
// inherited: -(id)tableView:(id)view cellForRowAtIndexPath:(id)indexPath;
// -(void)tableView:(id)view didSelectRowAtIndexPath:(id)indexPath;
@end

#endif
