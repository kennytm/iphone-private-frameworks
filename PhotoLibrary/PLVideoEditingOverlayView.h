/**
 * This header is generated by class-dump-z 0.2-0.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: /System/Library/PrivateFrameworks/PhotoLibrary.framework/PhotoLibrary
 */

#import <UIKit/UIView.h>
#import "PhotoLibrary-Structs.h"

@class UILabel;

@interface PLVideoEditingOverlayView : UIView {
	UILabel* _titleLabel;
	UILabel* _bodyLabel;
}
// inherited: -(instancetype)initWithFrame:(CGRect)frame;
-(void)drawRect:(CGRect)rect;
-(void)setTitle:(id)title;
-(void)setBody:(id)body;
-(void)layoutSubviews;
@end

