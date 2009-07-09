//
//  WKUtilities.h
//
//  Copyright (C) 2005, 2006, 2007, Apple Inc.  All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>

#import "WKTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

extern const CFArrayCallBacks WKCollectionArrayCallBacks;
extern const CFSetCallBacks WKCollectionSetCallBacks;


typedef void(*WKDeallocCallback)(WKObjectRef object);

typedef struct _WKClassInfo WKClassInfo;

struct _WKClassInfo
{
    const WKClassInfo *parent;
    const char *name;
    WKDeallocCallback dealloc;
};

extern WKClassInfo WKObjectClass;

struct _WKObject
{
    unsigned referenceCount;
    WKClassInfo *classInfo;
};

const void *WKCreateObjectWithSize (size_t size, WKClassInfo *info);
const void *WKRetain(const void *object);
void WKRelease(const void *object);

const void *WKCollectionRetain (CFAllocatorRef allocator, const void *value);
void WKCollectionRelease (CFAllocatorRef allocator, const void *value);

void WKReportError(const char *file, int line, const char *function, const char *format, ...);
#define WKError(formatAndArgs...) WKReportError(__FILE__, __LINE__, __PRETTY_FUNCTION__, formatAndArgs)

CFIndex WKArrayIndexOfValue (CFArrayRef array, const void *value);

WKClassInfo *WKGetClassInfo (WKObjectRef object);

#ifdef __cplusplus
}
#endif
