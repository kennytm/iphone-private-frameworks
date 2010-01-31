#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIPickerView.h>
#import "UIWebSelectControl.h"

@class NSArray;
@protocol UIWebSelectedItemPrivate;

__attribute__((visibility("hidden")))
@interface UIWebSelectPicker : UIPickerView <UIWebSelectControl, UIPickerViewDataSource, UIPickerViewDelegate> {
@private
	NSArray* _cachedItems;
	id<UIWebSelectedItemPrivate> _singleSelectionItem;
	unsigned _singleSelectionIndex;
}
@property(retain, nonatomic) NSArray* _cachedItems;
@property(retain, nonatomic) id<UIWebSelectedItemPrivate> _singleSelectionItem;
-(id)initSelectPicker;
// inherited: -(void)dealloc;
// in a protocol: -(id)controlView;
// in a protocol: -(void)beginEditing;
// in a protocol: -(void)setUpDOMSelectNode:(id)node cachedItems:(id)items singleSelectionItem:(id)item singleSelectionIndex:(unsigned)index multipleSelection:(BOOL)selection;
-(void)pickerViewLoaded:(id)loaded;
// in a protocol: -(id)pickerView:(id)view viewForRow:(int)row forComponent:(int)component reusingView:(id)view4;
// in a protocol: -(int)numberOfComponentsInPickerView:(id)pickerView;
// in a protocol: -(int)pickerView:(id)view numberOfRowsInComponent:(int)component;
-(void)pickerView:(id)view row:(int)row column:(int)column checked:(BOOL)checked;
// in a protocol: -(float)pickerView:(id)view widthForComponent:(int)component;
@end

#endif
