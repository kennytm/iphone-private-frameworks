#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UITableViewController.h>
#import <UIKit/UITextInput.h>

@class DOMHTMLSelectElement, NSArray, UIWebSelectPopover;

__attribute__((visibility("hidden")))
@interface UIWebSelectTableViewController : UITableViewController <UIKeyInput> {
@private
	DOMHTMLSelectElement* _selectionNode;
	NSArray* _cachedItems;
	unsigned _singleSelectionIndex;
	BOOL _allowsMultipleSelection;
	float _popoverHeight;
	UIWebSelectPopover* _popover;
}
@property(retain, nonatomic) DOMHTMLSelectElement* _selectionNode;
@property(retain, nonatomic) NSArray* _cachedItems;
@property(assign, nonatomic) UIWebSelectPopover* _popover;
// in a protocol: @property(assign, nonatomic) int autocapitalizationType;
// in a protocol: @property(assign, nonatomic) int autocorrectionType;
// in a protocol: @property(assign, nonatomic) int keyboardType;
// in a protocol: @property(assign, nonatomic) int keyboardAppearance;
// in a protocol: @property(assign, nonatomic) int returnKeyType;
// in a protocol: @property(assign, nonatomic) BOOL enablesReturnKeyAutomatically;
// in a protocol: @property(assign, nonatomic, getter=isSecureTextEntry) BOOL secureTextEntry;
// inherited: -(void)dealloc;
-(void)setUpDOMSelectNode:(id)node cachedItems:(id)items singleSelectionIndex:(unsigned)index multipleSelection:(BOOL)selection popoverHeight:(float)height;
// inherited: -(void)viewWillAppear:(BOOL)view;
// inherited: -(CGSize)contentSizeForViewInPopoverView;
-(int)numberOfSectionsInTableView:(id)tableView;
// inherited: -(int)tableView:(id)view numberOfRowsInSection:(int)section;
// inherited: -(id)tableView:(id)view cellForRowAtIndexPath:(id)indexPath;
-(void)tableView:(id)view didSelectRowAtIndexPath:(id)indexPath;
// in a protocol: -(BOOL)hasText;
// in a protocol: -(void)insertText:(id)text;
// in a protocol: -(void)deleteBackward;
@end

#endif
