//
//  WKView.h
//
//  Copyright (C) 2005, 2006, 2007, 2008, Apple Inc.  All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>
#import <CoreGraphics/CGSRegion.h>
#import <GraphicsServices/GSEvent.h>
#import "WKUtilities.h"

#ifdef __cplusplus
extern "C" {
#endif

enum {
    NSViewNotSizable = 0,
    NSViewMinXMargin = 1,
    NSViewWidthSizable = 2,
    NSViewMaxXMargin = 4,
    NSViewMinYMargin = 8,
    NSViewHeightSizable = 16,
    NSViewMaxYMargin = 32
};    
    
typedef enum {
    WKViewNotificationViewDidMoveToWindow,
    WKViewNotificationViewFrameSizeChanged,
    WKViewNotificationViewDidScroll
} WKViewNotificationType;

typedef enum {
    WKViewResponderAcceptsFirstResponder,
    WKViewResponderBecomeFirstResponder,
    WKViewResponderResignFirstResponder,
} WKViewResponderCallbackType;

typedef void (*WKViewDrawCallback)(WKViewRef view, CGRect dirtyRect, void *userInfo); 
typedef bool (*WKViewEventCallback)(WKViewRef view, GSEventRef event, void *userInfo);
typedef void (*WKViewNotificationCallback)(WKViewRef view, WKViewNotificationType type, void *userInfo);
typedef void (*WKViewLayoutCallback)(WKViewRef view, void *userInfo, bool force);
typedef bool (*WKViewResponderCallback)(WKViewRef view, WKViewResponderCallbackType type, void *userInfo);
typedef WKViewRef (*WKViewHitTestCallback)(WKViewRef view, CGPoint point, void *userInfo);
typedef void (*WKViewWillRemoveSubviewCallback)(WKViewRef view, WKViewRef subview);
typedef void (*WKViewInvalidateGStateCallback)(WKViewRef view);

typedef struct _WKViewContext {
    WKViewDrawCallback drawCallback;
    void *drawUserInfo;
    WKViewEventCallback eventCallback;
    void *eventUserInfo;    
    WKViewNotificationCallback notificationCallback;
    void *notificationUserInfo;
    WKViewLayoutCallback layoutCallback;
    void *layoutUserInfo;
    WKViewResponderCallback responderCallback;
    void *responderUserInfo;
    WKViewHitTestCallback hitTestCallback;
    void *hitTestUserInfo;
    WKViewWillRemoveSubviewCallback willRemoveSubviewCallback;
    WKViewInvalidateGStateCallback invalidateGStateCallback;
} WKViewContext;

struct WKView {
    WKObject isa;
    
    WKViewContext *context;
    
    WKWindowRef window;

    WKViewRef superview;
    CFMutableArrayRef subviews;

    CGPoint origin;
    CGRect bounds;
    
    unsigned int isHidden:1;
    
    unsigned int autoresizingMask;
    
    float scale;
    
    bool drawsOwnDescendants;
};

WKViewRef WKViewGetFocusView (void);

extern WKClassInfo WKViewClassInfo;

WKViewRef WKViewCreateWithFrame (CGRect rect, WKViewContext *context);
void WKViewInitialize (WKViewRef view, CGRect rect, WKViewContext *context);

void WKViewSetViewContext (WKViewRef view, WKViewContext *context);
void WKViewGetViewContext (WKViewRef view, WKViewContext *context);

CGRect WKViewGetBounds (WKViewRef view);

void WKViewSetFrameOrigin (WKViewRef view, CGPoint newPoint);
void WKViewSetFrameSize (WKViewRef view, CGSize newSize);
void WKViewSetBoundsSize (WKViewRef view, CGSize newSize);

CGRect WKViewGetFrame (WKViewRef view);

void WKViewSetScale (WKViewRef view, float scale);
float WKViewGetScale (WKViewRef view);

WKWindowRef WKViewGetWindow (WKViewRef view);

CFArrayRef WKViewGetSubviews (WKViewRef view);

WKViewRef WKViewGetSuperview (WKViewRef view);

void WKViewAddSubview (WKViewRef view, WKViewRef subview);
void WKViewRemoveFromSuperview (WKViewRef view);

void WKViewSetNeedsDisplay (WKViewRef view);
void WKViewSetNeedsDisplayInRect (WKViewRef view, CGRect invalidRect);
void WKViewDisplay (WKViewRef view);
void WKViewDisplayRect (WKViewRef view, CGRect rectToDraw);

void WKViewLockFocus (WKViewRef view);
void WKViewUnlockFocus (WKViewRef view);

bool WKViewGetIsHidden (WKViewRef view);
void WKViewSetIsHidden (WKViewRef view, bool flag);

CGPoint WKViewConvertPointToSuperview (WKViewRef view, CGPoint aPoint);
CGPoint WKViewConvertPointFromSuperview (WKViewRef view, CGPoint aPoint);
CGPoint WKViewConvertPointToBase(WKViewRef view, CGPoint aPoint);
CGPoint WKViewConvertPointFromBase(WKViewRef view, CGPoint aPoint);

CGRect WKViewConvertRectToSuperview (WKViewRef view, CGRect aRect);
CGRect WKViewConvertRectFromSuperview (WKViewRef view, CGRect aRect);
CGRect WKViewConvertRectToBase (WKViewRef view, CGRect r);
CGRect WKViewConvertRectFromBase (WKViewRef view, CGRect aRect);

CGRect WKViewGetVisibleRect (WKViewRef view);

WKViewRef WKViewFirstChild (WKViewRef view);
WKViewRef WKViewNextSibling (WKViewRef view);
WKViewRef WKViewTraverseNext (WKViewRef view);

bool WKViewAcceptsFirstResponder (WKViewRef view);
bool WKViewBecomeFirstResponder (WKViewRef view);
bool WKViewResignFirstResponder (WKViewRef view);

unsigned int WKViewGetAutoresizingMask(WKViewRef view);
void WKViewSetAutoresizingMask (WKViewRef view, unsigned int mask);

WKViewRef WKViewHitTest(WKViewRef view, CGPoint superviewPoint);
void WKViewScrollToPoint(WKViewRef view, CGPoint point);
void WKViewScrollToRect(WKViewRef view, CGRect rect);

void WKViewLayout(WKViewRef view, bool force);

CGImageRef WKViewCreateImage(WKViewRef view);

#ifdef __cplusplus
}
#endif

