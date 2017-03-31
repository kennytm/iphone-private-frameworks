/**
 * This header is generated by class-dump-z 0.1-11o.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 */

#import "NSCoding.h"
#import <Foundation/NSObject.h>

@class NSString;

@interface UIKBAttribute : NSObject <NSCoding> {
	NSString* m_name;
	id m_value;
}
@property(copy, nonatomic) NSString* name;
@property(copy, nonatomic) id value;
+(id)attributeWithName:(id)name value:(id)value;
-(instancetype)initWithName:(id)name value:(id)value;
-(void)dealloc;
-(nullable instancetype)initWithCoder:(NSCoder *)coder;
-(void)encodeWithCoder:(id)coder;
@end

