#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIWebDocumentView.h>
#import "UIWebFormAccessoryDelegate.h"
#import "BrowserDocumentController.h"
@class UIWebFormAccessory, NSObject, DOMNode, UIWebTouchEventsGestureRecognizer, UIWebFormDelegate, NSMutableArray, WebPDFView, NSTimer;
@protocol UIFormPeripheral;

@interface UIWebBrowserView : UIWebDocumentView <UIWebFormAccessoryDelegate, BrowserDocumentController> {
	UIWebFormAccessory* _accessory;
	NSObject<UIFormPeripheral>* _input;
	DOMNode* _currentAssistedNode;
	CGRect _inputViewBounds;
	unsigned _accessoryEnabled : 1;
	unsigned _forceInputView : 1;
	unsigned _formIsAutoFilling : 1;
	UIWebTouchEventsGestureRecognizer* _webTouchEventsGestureRecognizer;
	UIWebFormDelegate* _formDelegate;
	struct {
		NSMutableArray* all;
		NSMutableArray* html;
		NSMutableArray* javascript;
		NSMutableArray* css;
		NSMutableArray* error;
		NSMutableArray* warning;
		NSMutableArray* tip;
		NSMutableArray* log;
	} _messages;
	struct {
		WebPDFView* view;
		NSTimer* timer;
	} _pdf;
}
@property(retain, nonatomic) UIWebFormAccessory* _accessory;
@property(retain, nonatomic) NSObject<UIFormPeripheral>* _input;
@property(retain, nonatomic) DOMNode* _currentAssistedNode;
@property(assign, nonatomic, getter=isAccessoryEnabled) BOOL accessoryEnabled;
@property(assign, nonatomic) CGRect inputViewBounds;
@property(assign, nonatomic, getter=isTwoFingerPanEnabled) BOOL twoFingerPanEnabled;
+(float)preferredScrollDecelerationFactor;
+(id)getUIWebBrowserViewForWebFrame:(id)webFrame;
+(BOOL)isAutoFillAllowed;
+(id)_PDFPageNumberLabel;
// inherited: -(id)initWithFrame:(CGRect)frame;
-(void)installGestureRecognizers;
-(BOOL)_requiresKeyboardWhenFirstResponder;
-(BOOL)_requiresKeyboardResetOnReload;
-(id)_keyboardResponder;
// inherited: -(void)dealloc;
// inherited: -(BOOL)resignFirstResponder;
-(id)inputAccessoryView;
-(id)inputView;
-(void)_startAssistingKeyboard;
-(void)_stopAssistingKeyboard;
-(void)_startAssistingSelectForNode:(id)node;
-(void)_stopAssistingSelectForNode:(id)node;
-(void)_keyboardWillShow:(id)_keyboard;
-(void)_keyboardWillHide:(id)_keyboard;
// inherited: -(void)assistFormNode:(id)node;
// in a protocol: -(void)accessoryDone;
// in a protocol: -(void)accessoryTab:(BOOL)tab;
// in a protocol: -(void)accessoryAutoFill;
-(void)_scrollCaretToVisible:(id)visible;
-(void)formDelegateHandleTextChangeWithAutoFillSuggestions:(BOOL)autoFillSuggestions;
-(BOOL)canAutoFill;
// inherited: -(id)formElement;
// inherited: -(void)_resetFormDataForFrame:(id)frame;
-(void)_autoFillFrame:(id)frame;
-(void)webView:(id)view willCloseFrame:(id)frame;
-(void)webView:(id)view didFinishDocumentLoadForFrame:(id)frame;
-(void)webView:(id)view didFirstLayoutInFrame:(id)frame;
-(void)acceptedAutoFillWord:(id)word;
-(void)autoFillWithElementValue;
-(BOOL)isAutoFillMode;
// in a protocol: -(BOOL)isAutoFilling;
// in a protocol: -(void)webViewFormEditedStatusHasChanged:(id)changed;
-(void)webView:(id)view formStateDidFocusNode:(id)formState;
-(void)webView:(id)view formStateDidBlurNode:(id)formState;
-(void)_webTouchEventsRecognized:(id)recognized;
-(CGPoint)_convertWindowPointToViewport:(CGPoint)viewport;
-(void)webViewDidPreventDefaultForEvent:(id)webView;
-(void)_zoomToNode:(id)node;
-(void)_zoomToRect:(CGRect)rect withScale:(float)scale;
-(void)webView:(id)view didReceiveMessage:(id)message;
-(id)messagesMatchingMask:(int)mask;
-(void)clearMessagesMatchingMask:(int)mask;
// inherited: -(void)_clearAllConsoleMessages;
// inherited: -(void)_setPDFView:(id)view;
// inherited: -(void)_updatePDFPageNumberLabelWithUserScrolling:(BOOL)userScrolling;
// inherited: -(void)_cleanUpPDF;
-(void)_hidePDFPageNumberLabel;
@end

#endif
