#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <UIKit/UIView.h>

__attribute__((visibility("hidden")))
@interface UIDropShadowView : UIView {
@private
	float _shadowRadius;
	float _shadowOpacity;
	float _cornerRadius;
}
@property(assign) float shadowRadius;
@property(assign) float shadowOpacity;
@property(assign) float cornerRadius;
-(id)initWithView:(id)view;
-(void)animateShadow;
//-(void)setFrame:(CGRect)frame;
//-(void)setBounds:(CGRect)bounds;
@end

#endif
