/*
 *  WebCoreThread.h
 *  WebCore
 *
 *  Copyright (C) 2006, 2007, Apple Inc.  All rights reserved.
 *
 */

#import <GraphicsServices/GSEvent.h>

#ifndef WebCoreThread_h
#define WebCoreThread_h

#if defined(__cplusplus)
extern "C" {
#endif    
	
	typedef struct {
		CFRunLoopRef runLoop;
		CFRunLoopTimerRef sharedTimer;
		void *timers;
		GSEventRef event;
		void * DOMWrapperCache;
		void * RGBWrapperCache;
		void * DOMMouseWheelEventListeners;
		void * DOMMouseMoveEventListeners;
		void * DOMMouseClickEventListeners;
		void * observedContentModifiers;
	} WebThreadContext;
	
	typedef enum {
		WebThreadStateBitIsStopping = 1,
		WebThreadStateBitIsSuspended
	} WebThreadStateBit;
	
	void WebThreadLock(void);
	void WebThreadUnlock(void);
	bool WebTryThreadLock(void);
	bool WebThreadIsLocked(void);
	bool WebThreadIsLockedOrDisabled(void);
	
	void WebThreadEnable(void);
	bool WebThreadIsEnabled(void);
	bool WebThreadIsCurrent(void);
	bool WebThreadNotCurrent(void);
	
	bool WebThreadStateBitIsSet(char *state, WebThreadStateBit bit);
	bool WebThreadIsSuspended(void);
	
	WebThreadContext *WebThreadCurrentContext(void);
	bool WebThreadContextIsCurrent(void);
	
	void WebThreadPrepareForDrawing(void);
	
#if defined(__cplusplus)
}
#endif

#endif // WebCoreThread_h
