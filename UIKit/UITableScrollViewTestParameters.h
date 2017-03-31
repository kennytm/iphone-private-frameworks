/*
 
UITableScrollViewTestParamters.h ... Table Scroll View Test-parameters.

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

__attribute__((visibility("hidden")))
@interface UITableViewScrollTestParameters : NSObject {
@private
	int _iterations;
	int _yDelta;
	int _scrollLength;
	NSString* _currentTest;
}
@property(assign, nonatomic) int iterations;
@property(retain, nonatomic) NSString* currentTest;
@property(assign, nonatomic) int yDelta;
@property(assign, nonatomic) int scrollLength;
-(instancetype)initWithName:(id)name iterations:(int)iterations delta:(int)delta length:(int)length;
// inherited: -(void)dealloc;
@end

#endif
