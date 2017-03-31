/**
 * This header is generated by class-dump-z 0.2-1.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: /System/Library/PrivateFrameworks/DataAccess.framework/DataAccess
 */

#import <DAVKit/AYOperation.h>
#import "CalDAVCollectionRefreshOperation.h"

@class MobileCalDAVCalendar, MobileCalDAVAccount, CalDAVCacheManager;

@interface CalDAVCollectionRefreshOperation : AYOperation {
	MobileCalDAVAccount* _account;
	MobileCalDAVCalendar* _calendar;
	CalDAVCacheManager* _cache;
	id _delegate;
}
+(id)propertiesForCollection;
-(instancetype)initWithAccount:(id)account calendar:(id)calendar delegate:(id)delegate;
-(void)refresh;
-(BOOL)validate:(id)validate error:(id*)error;
-(id)account;
-(id)path;
-(BOOL)useMultiGet;
-(id)cache;
// inherited: -(void)dealloc;
@end

@interface CalDAVCollectionRefreshOperation (PrivateMethods)
+(id)propertiesForResources;
-(id)listing:(id*)listing;
-(id)reconcile:(id)reconcile;
-(BOOL)download:(id)download error:(id*)error;
-(BOOL)_multiget:(id)multiget error:(id*)error;
-(BOOL)_gets:(id)gets error:(id*)error;
@end

@interface CalDAVCollectionRefreshOperation (DelegateMethods)
-(void)_delegateDeleteResourcesWithFilenames:(id)filenames;
-(void)_delegateDidAbortRefresh;
-(void)_delegateDidCompleteRefresh;
-(void)_delegateProcessError:(id)error;
-(void)_delegateProcessResources:(id)resources;
-(BOOL)_delegateShouldContinueProcessingResources;
-(BOOL)_delegateShouldAcceptEntryModification:(id)_delegate isDeleted:(BOOL)deleted;
@end

