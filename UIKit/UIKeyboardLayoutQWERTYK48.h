#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import "UIKeyboardLayoutRoman.h"

@interface UIKeyboardLayoutQWERTYLandscapeK48 : UIKeyboardLayoutRoman {
}
@end

@interface UIKeyboardLayoutQWERTYK48 : UIKeyboardLayoutRoman {
}
@end

@interface UIKeyboardLayoutQWERTYK48 (UI_QWERTY_NumbersAndPunctuationK48)
// inherited: -(id)buildUIKeyboardLayoutNumbers;
@end

@interface UIKeyboardLayoutQWERTYLandscapeK48 (UI_QWERTYLandscapeK48_Alphabet)
// inherited: -(id)buildUIKeyboardLayoutAlphabet;
@end

@interface UIKeyboardLayoutQWERTYK48 (UI_QWERTYK48_Alphabet)
// inherited: -(id)buildUIKeyboardLayoutAlphabet;
@end

@interface UIKeyboardLayoutQWERTYLandscapeK48 (UI_QWERTYLandscape_NumbersAndPunctuationK48)
// inherited: -(id)buildUIKeyboardLayoutNumbers;
@end

#endif
