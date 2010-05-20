
@protocol UIKeyboardImplGeometryDelegate
@property(assign, nonatomic, getter=isMinimized) BOOL minimized;
-(void)prepareForImplBoundsHeightChange:(float)implBoundsHeightChange suppressNotification:(BOOL)notification;
-(void)implBoundsHeightChangeDone:(float)done suppressNotification:(BOOL)notification;
-(BOOL)canDismiss;
-(BOOL)isActive;
@end
