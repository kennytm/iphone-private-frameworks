#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <Foundation/NSObject.h>

@interface UIKeyboardCandidate : NSObject <NSCopying> {
}
-(id)candidate;
-(id)input;
-(id)insertion;
-(unsigned)wordOriginFeedbackID;
-(unsigned)deleteCount;
// in a protocol: -(id)copyWithZone:(NSZone*)zone;
// inherited: -(BOOL)isEqual:(id)equal;
// inherited: -(unsigned)hash;
@end

#endif
