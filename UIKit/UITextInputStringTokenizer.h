#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <Foundation/NSObject.h>
#import <Foundation/NSRange.h>
#import <UIKit/UITextInput.h>

@class UIResponder;

@interface UITextInputStringTokenizer ()
-(NSRange)_getClosestTokenRangeForPosition:(id)position granularity:(int)granularity downstream:(BOOL)downstream;
// in a protocol: -(BOOL)isPosition:(id)position atBoundary:(int)boundary inDirection:(int)direction;
// in a protocol: -(id)positionFromPosition:(id)position toBoundary:(int)boundary inDirection:(int)direction;
// in a protocol: -(BOOL)isPosition:(id)position withinTextUnit:(int)unit inDirection:(int)direction;
// in a protocol: -(id)rangeEnclosingPosition:(id)position withGranularity:(int)granularity inDirection:(int)direction;
@end


#endif
