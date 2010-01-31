#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import "UIKeyboardCandidate.h"
@class NSString;

@interface UIKeyboardCandidateSingle : UIKeyboardCandidate {
	NSString* _candidate;
}
-(id)initWithCandidate:(id)candidate;
// inherited: -(void)dealloc;
// inherited: -(id)candidate;
// inherited: -(id)copyWithZone:(NSZone*)zone;
@end

#endif
