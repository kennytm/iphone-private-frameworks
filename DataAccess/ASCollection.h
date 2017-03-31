/**
 * This header is generated by class-dump-z 0.2-1.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: /System/Library/PrivateFrameworks/DataAccess.framework/DataAccess
 */

#import "ASItem.h"

@class ASFolderItemsSyncResponse, NSArray, NSNumber, NSString;

@interface ASCollection : ASItem {
	int _collectionClassType;
	NSString* _syncKey;
	NSString* _collectionId;
	NSNumber* _status;
	NSNumber* _moreAvailable;
	NSArray* _changedItems;
	NSArray* _responseItems;
	ASFolderItemsSyncResponse* _parentResponse;
	int _sniffableType;
	BOOL _checkedShouldSniffInvites;
}
// inherited: +(BOOL)acceptsTopLevelLeaves;
// inherited: +(BOOL)parsingLeafNode;
// inherited: +(BOOL)parsingWithSubItems;
// inherited: +(BOOL)frontingBasicTypes;
// inherited: -(instancetype)init;
// inherited: -(void)dealloc;
-(void)setParentResponse:(id)response;
-(int)collectionClassType;
-(void)setCollectionClassTypeString:(id)string;
-(id)changedItems;
-(void)setChangedItems:(id)items;
-(id)responseItems;
-(void)setResponseItems:(id)items;
// inherited: -(id)asParseRules;
// inherited: -(void)parseASParseContext:(id)context root:(id)root parent:(id)parent callbackDict:(id)dict streamCallbackDict:(id)dict5 account:(id)account;
-(int)sniffableTypeForAccount:(id)account;
-(id)syncKey;
-(void)setSyncKey:(id)key;
-(id)collectionId;
-(void)setCollectionId:(id)anId;
-(id)status;
-(void)setStatus:(id)status;
-(id)moreAvailable;
-(void)setMoreAvailable:(id)available;
// inherited: -(id)description;
@end

