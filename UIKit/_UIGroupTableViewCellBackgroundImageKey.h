/*
 
_UIGroupTableViewCellBackgroundImageKey.h ... ???

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

#import <Foundation/NSObject.h>
#import <CoreGraphics/CoreGraphics.h>

@class UIColor;

__attribute__((visibility("hidden")))
@interface _UIGroupTableViewCellBackgroundImageKey : NSObject <NSCopying> {
@private
	BOOL _opaque;
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2
	BOOL _selected;
#endif
	CGSize _size;
	UIColor* _backgroundColor;
	UIColor* _borderColor;
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2
	UIColor* _topShadowColor;
	UIColor* _bottomShadowColor;
#endif
	UIColor* _fillColor;
	float _leftPhase;
	float _rightPhase;
	int _sectionLocation;
}
@property(assign, nonatomic) BOOL opaque;
@property(assign, nonatomic) CGSize size;
@property(retain, nonatomic) UIColor* backgroundColor;
@property(retain, nonatomic) UIColor* borderColor;
@property(retain, nonatomic) UIColor* fillColor;
@property(assign, nonatomic) float leftPhase;
@property(assign, nonatomic) float rightPhase;
@property(assign, nonatomic) int sectionLocation;
// inherited: -(void)dealloc;
// inherited: -(BOOL)isEqual:(id)equal;
// inherited: -(unsigned)hash;
// in a protocol: -(id)copyWithZone:(NSZone*)zone;
// inherited: -(id)description;
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2
@property(assign, nonatomic) BOOL selected;
@property(retain, nonatomic) UIColor* topShadowColor;
@property(retain, nonatomic) UIColor* bottomShadowColor;
#endif
@end

#endif
