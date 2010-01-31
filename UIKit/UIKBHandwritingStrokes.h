#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <Foundation/NSObject.h>
#import "UIKit-Structs.h"

@interface UIKBHandwritingStrokes : NSObject <NSCopying> {
	KBStrokeList* _strokes;
}
-(id)initWithStrokes:(KBStrokeList*)strokes;
// inherited: -(void)dealloc;
-(const KBStrokeList*)strokes;
// in a protocol: -(id)copyWithZone:(NSZone*)zone;
@end

#endif
