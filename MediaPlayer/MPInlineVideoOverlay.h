/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: /System/Library/Frameworks/MediaPlayer.framework/MediaPlayer
 */

#import "MPWildcatVideoOverlay.h"
#import "MediaPlayer-Structs.h"

@class MPInlineTransportControls;

@interface MPInlineVideoOverlay : MPWildcatVideoOverlay {
@private
	MPInlineTransportControls* _transportControls;
}
-(instancetype)initWithFrame:(CGRect)frame;
-(void)dealloc;
-(void)layoutSubviews;
-(void)setItem:(id)item;
-(void)setDesiredParts:(unsigned)parts animate:(BOOL)animate;
-(void)setVisibleParts:(unsigned)parts animate:(BOOL)animate;
-(void)setDisabledParts:(unsigned)parts;
-(void)_availableRoutesDidChangeNotification:(id)_availableRoutes;
-(unsigned)_convertedPartsMask:(unsigned)mask;
@end

