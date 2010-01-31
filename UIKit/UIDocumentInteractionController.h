#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#include_next <UIKit/UIDocumentInteractionController.h>

@interface UIDocumentInteractionController()
@property(retain, nonatomic) NSString* uniqueIdentifier;
@property(readonly, assign, nonatomic) NSArray* gestureRecognizers;
@property(readonly, assign, nonatomic) NSArray* icons;
@property(copy, nonatomic) NSString* name;
// inherited: +(void)initialize;
-(id)initWithURL:(id)url;
// inherited: -(void)dealloc;
-(void)updatePopoverContentSizeForPresentationOfTableViewHack;
@end

#endif
