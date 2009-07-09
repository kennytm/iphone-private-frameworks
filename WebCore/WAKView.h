//
//  WAKView.h
//
//  Copyright (C) 2005, 2006, 2007, 2008, Apple Inc.  All rights reserved.
//
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

#import "WAKResponder.h"
#import "WKView.h"

#ifndef NSRect
#define NSRect CGRect
#endif
#define NSPoint CGPoint
#define NSSize CGSize

extern NSString *WAKViewFrameSizeDidChangeNotification;
extern NSString *WAKViewDidScrollNotification;

@class WAKWindow;

@interface WAKView : WAKResponder
{
    WKViewContext viewContext;
    WKViewRef viewRef;
    
    NSMutableSet *subviewReferences;    // This array is only used to keep WAKViews alive.
                                        // The actual subviews are maintained by the WKView.
}

+ (WAKView *)focusView;

- (id)initWithFrame:(CGRect)rect;

- (WAKWindow *)window;

- (NSRect)bounds;
- (NSRect)frame;

- (void)setFrame:(NSRect)frameRect;
- (void)setFrameSize:(NSSize)newSize;
- (void)setBoundsSize:(NSSize)size;
- (void)frameSizeChanged;

- (NSArray *)subviews;
- (WAKView *)superview;
- (void)addSubview:(WAKView *)subview;
- (void)willRemoveSubview:(WAKView *)subview;
- (void)removeFromSuperview;
- (BOOL)isDescendantOf:(WAKView *)aView;
- (WAKView *)lastScrollableAncestor;

- (void)viewDidMoveToWindow;

- (void)lockFocus;
- (void)unlockFocus;

- (void)setNeedsDisplay:(BOOL)flag;
- (void)setNeedsDisplayInRect:(CGRect)invalidRect;
- (BOOL)needsDisplay;
- (void)display;
- (void)displayIfNeeded;
- (void)displayRect:(NSRect)rect;
- (void)displayRectIgnoringOpacity:(NSRect)rect;
- (void)drawRect:(CGRect)rect;
- (void)viewWillDraw;

- (WAKView *)hitTest:(NSPoint)point;
- (NSPoint)convertPoint:(NSPoint)point fromView:(WAKView *)aView;
- (NSPoint)convertPoint:(NSPoint)point toView:(WAKView *)aView;
- (NSSize)convertSize:(NSSize)size toView:(WAKView *)aView;
- (NSRect)convertRect:(NSRect)rect fromView:(WAKView *)aView;
- (NSRect)convertRect:(NSRect)rect toView:(WAKView *)aView;

- (BOOL)needsPanelToBecomeKey;

- (BOOL)scrollRectToVisible:(NSRect)aRect;
- (void)scrollPoint:(NSPoint)aPoint;
- (NSRect)visibleRect;

- (void)setHidden:(BOOL)flag;

- (void)setNextKeyView:(WAKView *)aView;
- (WAKView *)nextKeyView;
- (WAKView *)nextValidKeyView;
- (WAKView *)previousKeyView;
- (WAKView *)previousValidKeyView;

- (void)invalidateGState;
- (void)releaseGState;

- (void)setAutoresizingMask:(unsigned int)mask;
- (unsigned int)autoresizingMask;
- (BOOL)inLiveResize;

- (BOOL)mouse:(NSPoint)aPoint inRect:(NSRect)aRect;

- (void)setNeedsLayout:(BOOL)flag;
- (void)layout;
- (void)layoutIfNeeded;

- (void)setScale:(float)scale;
- (float)scale;

- (void)_setDrawsOwnDescendants:(BOOL)draw;

@end
