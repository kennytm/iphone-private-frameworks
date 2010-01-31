#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <Foundation/NSObject.h>
#import "UIFormPeripheral.h"

@class DOMHTMLSelectElement;
@protocol UIWebSelectControl;

__attribute__((visibility("hidden")))
@interface UIWebSelectPeripheral : NSObject <UIFormPeripheral> {
@private
	DOMHTMLSelectElement* _selectionNode;
	id<UIWebSelectControl> _selectControl;
}
@property(retain, nonatomic) DOMHTMLSelectElement* _selectionNode;
@property(retain, nonatomic) id<UIWebSelectControl> _selectControl;
+(id)createPeripheral;
-(id)initFormPeripheral;
// inherited: -(void)dealloc;
// in a protocol: -(id)assistantView;
// in a protocol: -(void)beginEditing;
// in a protocol: -(void)endEditing;
// in a protocol: -(void)setPeripheralFormNode:(id)node;
@end

#endif
