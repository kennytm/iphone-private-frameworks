#import <UIKit/UIView.h>

typedef enum {
    HPHapticFeedbackTypePressed,
    HPHapticFeedbackTypeReleased,
    HPHapticFeedbackTypeRepeated,
} HPHapticFeedbackType;

typedef enum {
    HPHapticFeedbackSourceKeyboard,
    HPHapticFeedbackSourceButton,
    HPHapticFeedbackSourceTableCell,
    HPHapticFeedbackSourceWebLink,
    HPHapticFeedbackSourceAny = -1,
} HPHapticFeedbackSource;

@interface UIView (HapticPro)
- (void)performHapticFeedback:(HPHapticFeedbackType)feedbackType;
@end

@interface HPHapticManager : NSObject
+ (void)performHapticFeedback:(HPHapticFeedbackType)feedbackType;
+ (void)performHapticFeedback:(HPHapticFeedbackType)feedbackType fromSource:(HPHapticFeedbackSource)feedbackSource;
@end

#define HPPerformHapticFeedbackOn(view, feedbackType) \
	[(([view respondsToSelector:@selector(performHapticFeedback:)])?view:nil) performHapticFeedback:feedbackType]
#define HPPerformHapticFeedback(feedbackType) \
	[objc_getClass("HPHapticManager") performHapticFeedback:feedbackType]
