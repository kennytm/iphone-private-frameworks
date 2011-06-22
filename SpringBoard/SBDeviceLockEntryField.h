#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIKit.h>
#import <CoreFoundation/CoreFoundation.h>
@class UIPasscodeField, UITextInputTraits;

@interface SBDeviceLockEntryField : UIView <UIKeyInput> {
	int _style;
	int _interfaceOrientation;
	UIPasscodeField* _passcodeField;
	UITextInputTraits* _textInputTraits;
	CFCharacterSetRef _numericTrimmingSet;
	id _delegate;
}
@property(assign, nonatomic) UIInterfaceOrientation interfaceOrientation;
@property(assign, nonatomic) id delegate;
// in a protocol: @property(assign, nonatomic) int autocapitalizationType;
// in a protocol: @property(assign, nonatomic) int autocorrectionType;
// in a protocol: @property(assign, nonatomic) int keyboardType;
// in a protocol: @property(assign, nonatomic) int keyboardAppearance;
// in a protocol: @property(assign, nonatomic) int returnKeyType;
// in a protocol: @property(assign, nonatomic) BOOL enablesReturnKeyAutomatically;
// in a protocol: @property(assign, nonatomic, getter=isSecureTextEntry) BOOL secureTextEntry;
@property(assign, nonatomic, getter=isOkayButtonEnabled) BOOL okayButtonEnabled;
@property(copy, nonatomic) NSString* stringValue;
-(id)initWithStyle:(int)style interfaceOrientation:(UIInterfaceOrientation)orientation;
// inherited: -(void)dealloc;
// inherited: -(BOOL)canBecomeFirstResponder;
// inherited: -(BOOL)becomeFirstResponder;
-(UIPasscodeField *)passcodeField;
-(CGSize)_fieldSizeForCurrentDevice;
-(void)_layoutForCurrentDevice;
-(void)appendString:(NSString *)string;
-(void)deleteLastCharacter;
-(id)textInputTraits;
-(void)passcodeFieldTextDidChange:(UIPasscodeField *)passcodeField;
-(BOOL)passcodeField:(UIPasscodeField *)passcodeField shouldInsertText:(NSString *)text;
-(void)passcodeFieldDidAcceptEntry:(UIPasscodeField *)passcodeField;
-(NSString *)text;
-(void)setText:(NSString *)text;
// in a protocol: -(BOOL)hasText;
// in a protocol: -(void)insertText:(id)text;
// in a protocol: -(void)deleteBackward;
// inherited: -(void)forwardInvocation:(id)invocation;
@end

#endif
