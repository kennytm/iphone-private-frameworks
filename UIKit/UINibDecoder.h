/*
 
UINibDecoder.h ... .nib Decoder

Copyright (c) 2009  KennyTM~ <kennytm@gmail.com>
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice, 
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.
* Neither the name of the KennyTM~ nor the names of its contributors may be
  used to endorse or promote products derived from this software without
  specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_1

#import <Foundation/NSCoder.h>
#import "UIKit-Structs.h"

@class NSString, UINibStringIDTable;

__attribute__((visibility("hidden")))
@interface UINibDecoder : NSCoder {
@private
	Class arrayClass;
	Class setClass;
	Class dictionaryClass;
	Class* classes;
	NSString** missingClasses;
	UINibDecoderObjectEntry* objects;
	UINibDecoderValue* values;
	char* valueTypes;
	void* valueData;
	unsigned valueDataSize;
	UINibDecoderHeader header;
	id* objectsByObjectID;
	unsigned* longObjectClassIDs;
	char* shortObjectClassIDs;
	unsigned* keyMasks;
	int inlinedValueKey;
	UINibDecoderRecursiveState recursiveState;
	UINibStringIDTable* keyIDTable;
	id delegate;
	UIKeyToKeyIDCache keyIDCache;
	UIKeyAndScopeToValueCache valueCache;
	int lookupRounds;
	int maxPossibleLookupRounds;
	int failedByKeyMask;
	int savedByKeyMask;
}
@property(assign) id delegate;
+(id)unarchiveObjectWithData:(id)data;
+(id)unarchiveObjectWithFile:(id)file;
-(id)initForReadingWithData:(id)data error:(id*)error;
-(id)initForReadingWithData:(id)data;
-(void)dealloc;
-(BOOL)validateAndIndexData:(id)data error:(id*)error;
-(BOOL)validateAndIndexClasses:(const void*)classes length:(unsigned long)length;
-(BOOL)validateAndIndexObjects:(const void*)objects length:(unsigned long)length;
-(BOOL)validateAndIndexValues:(const void*)values length:(unsigned long)length;
-(BOOL)validateAndIndexKeys:(const void*)keys length:(unsigned long)length;
-(id)nextGenericKey;
-(void)replaceObject:(id)object withObject:(id)object2;
// inherited: -(BOOL)allowsKeyedCoding;
// inherited: -(BOOL)containsValueForKey:(id)key;
// inherited: -(id)decodeObjectForKey:(id)key;
// inherited: -(const char*)decodeBytesForKey:(id)key returnedLength:(unsigned*)length;
// inherited: -(BOOL)decodeBoolForKey:(id)key;
// inherited: -(float)decodeFloatForKey:(id)key;
// inherited: -(double)decodeDoubleForKey:(id)key;
// inherited: -(long long)decodeInt64ForKey:(id)key;
// inherited: -(int)decodeIntegerForKey:(id)key;
// inherited: -(int)decodeIntForKey:(id)key;
// inherited: -(int)decodeInt32ForKey:(id)key;
-(BOOL)decodeArrayOfFloats:(float*)floats count:(int)count forKey:(id)key;
-(BOOL)decodeArrayOfDoubles:(double*)doubles count:(int)count forKey:(id)key;
-(BOOL)decodeArrayOfCGFloats:(float*)cgfloats count:(int)count forKey:(id)key;
-(CGPoint)decodeCGPointForKey:(id)key;
-(CGSize)decodeCGSizeForKey:(id)key;
-(CGRect)decodeCGRectForKey:(id)key;
-(CGAffineTransform)decodeCGAffineTransformForKey:(id)key;
-(UIEdgeInsets)decodeUIEdgeInsetsForKey:(id)key;
// inherited: -(void)decodeValueOfObjCType:(const char*)objCType at:(void*)at;
-(id)decodeNXObject;
// inherited: -(id)decodeDataObject;
// inherited: -(id)decodeObject;
-(id)decodePropertyList;
// inherited: -(void)decodeValuesOfObjCTypes:(const char*)objCTypes;
// inherited: -(void)decodeArrayOfObjCType:(const char*)objCType count:(unsigned)count at:(void*)at;
// inherited: -(void*)decodeBytesWithReturnedLength:(unsigned*)returnedLength;
// inherited: -(unsigned)systemVersion;
// inherited: -(int)versionForClassName:(id)className;
-(void)finishDecoding;
@end

#endif
