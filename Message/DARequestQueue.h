/**
 * This header is generated by class-dump-z 0.2-1.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: /System/Library/PrivateFrameworks/Message.framework/Message
 */

#import "RequestQueue.h"

@class DAMailAccount, NSString;

@interface DARequestQueue : RequestQueue {
	DAMailAccount* account;
	NSString* folderID;
	double _invalidSyncKeyTimestamp;
}
-(instancetype)initWithAccount:(id)account folderID:(id)anId;
-(id)filterRequests:(id)requests consumers:(id)consumers newConsumers:(id*)consumers3;
-(void)_processRequests:(id)requests withConsumers:(id)consumers;
// inherited: -(void)processRequests:(id)requests consumers:(id)consumers;
// inherited: -(void)dealloc;
@end

