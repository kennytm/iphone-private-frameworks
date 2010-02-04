#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2
#import <UIKit/UIView.h>

@class UILabel, UIImageView, UIImage, NSString;

@interface SBHUDView : UIView {
	int _level;
	UILabel* _titleLabel;
	UILabel* _subtitleLabel;
	UIImageView* _imageView;
	BOOL _showsProgress;
	float _progress;
}
@property(assign, nonatomic) int level;
@property(assign, nonatomic) BOOL showsProgress;
@property(assign, nonatomic) float progress;
@property(retain, nonatomic) UIImage* image;
@property(retain, nonatomic) NSString* subtitle;
@property(retain, nonatomic) NSString* title;
+(int)numberOfProgressIndicatorSteps;
+(float)progressIndicatorStep;
-(id)initWithHUDViewLevel:(int)hudviewLevel;
// inherited: -(void)dealloc;
-(BOOL)displaysLabel;
-(void)layoutSubviews;
-(void)drawRect:(CGRect)rect;
@end

#endif
