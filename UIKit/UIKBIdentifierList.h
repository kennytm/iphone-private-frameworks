#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <Foundation/NSObject.h>
@class NSMutableArray;

@interface UIKBIdentifierList : NSObject <NSCoding, NSCopying> {
	NSString* m_name;
	NSMutableArray* m_list;
	BOOL m_explicit;
}
@property(copy, nonatomic) NSString* name;
@property(readonly, assign, nonatomic) NSArray* list;
//@property(assign, nonatomic) BOOL explicit;
@property(readonly, assign, nonatomic) unsigned count;
// inherited: -(instancetype)init;
// inherited: -(void)dealloc;
// in a protocol: -(nullable instancetype)initWithCoder:(NSCoder *)coder;
// in a protocol: -(void)encodeWithCoder:(id)coder;
// in a protocol: -(id)copyWithZone:(NSZone*)zone;
// inherited: -(id)description;
-(void)addIdentifier:(id)identifier;
@end

#endif
