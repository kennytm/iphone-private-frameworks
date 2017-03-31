/**
 * This header is generated by class-dump-z 0.2-1.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "SpringBoard-Structs.h"
#import "SBStatusBarContentView.h"

@class UIProgressIndicator;

@interface SBStatusBarProgressView : SBStatusBarContentView {
	UIProgressIndicator* _progressIndicator;
	BOOL _wasLastUsingASlowConnection;
	BOOL _showProgressView;
	BOOL _showOnLeft;
}
// inherited: -(instancetype)init;
// inherited: -(void)dealloc;
-(void)dataConnectionTypeChanged;
// inherited: -(void)start;
// inherited: -(void)stop;
-(void)progressChanged;
// inherited: -(int)priority;
// inherited: -(void)setVisible:(BOOL)visible;
// inherited: -(BOOL)isVisible;
// inherited: -(BOOL)showOnLeft;
// inherited: -(void)setShowOnLeft:(BOOL)left;
// inherited: -(float)padding;
@end

