#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIView.h>

__attribute__((visibility("hidden")))
@interface UISnapshotView : UIView {
@private
	UIEdgeInsets _edgePadding;
	UIColor* _edgePaddingColor;
	UIView* _imageView;
	unsigned _disableEdgeAntialiasing : 1;
	unsigned _disableSubviewLayout : 1;
}
@property(assign, nonatomic) UIEdgeInsets edgePadding;
@property(retain, nonatomic) UIColor* edgePaddingColor;
@property(assign, nonatomic, getter=isSubviewLayoutEnabled) BOOL subviewLayoutEnabled;
@property(assign, nonatomic, getter=isEdgeAntialiasingEnabled) BOOL edgeAntialiasingEnabled;
// inherited: -(id)initWithFrame:(CGRect)frame;
// inherited: -(void)dealloc;
-(void)setFrame:(CGRect)frame;
-(void)setBounds:(CGRect)bounds;
-(void)_positionImageView;
-(void)layoutSubviews;
-(UIEdgeInsets)_edgePadding;
-(void)_drawEdges:(UIEdgeInsets)edges inRect:(CGRect)rect;
-(void)_snapshotView:(id)view usingIOSurface:(BOOL)surface;
@end

#endif
