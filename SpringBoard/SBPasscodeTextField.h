#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UITextField.h>
@class UILabel;

@interface SBPasscodeTextField : UITextField {
	float _letterSpacing;
	BOOL _usesLargeClearButton;
	UILabel* _hiddenLabel;
}
@property(assign, nonatomic) float letterSpacing;
@property(assign, nonatomic) BOOL usesLargeClearButton;
// inherited: -(void)dealloc;
// inherited: -(CGRect)clearButtonRectForBounds:(CGRect)bounds;
// inherited: -(id)createTextLabelWithTextColor:(id)textColor;
// inherited: -(void)attachFieldEditor:(id)editor;
// inherited: -(void)_endedEditing;
// inherited: -(id)_style;
@end

#endif
