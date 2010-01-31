#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#import <Foundation/NSObject.h>
#import "UIKit-Structs.h"
@class NSMutableDictionary, NSTimer;

__attribute__((visibility("hidden")))
@interface UIKeyboardCache : NSObject {
@private
	NSMutableDictionary* _keyToEntryMap;
	NSString* _nextKey;
	long _currentWeight;
	long _maxWeight;
	NSMutableArray* _recentlyUsed;
	NSMutableArray* _inProgress;
	int _mappedDataFd;
	char* _mappedData;
	unsigned _mappedDataLength;
	XXStruct_iXKIAB _header;
	NSTimer* _writeTimer;
	BOOL _diskFull;
	BOOL _canWrite;
}
+(id)sharedCache;
+(id)compoundKeyFromKeys:(id)keys;
+(id)cacheDataPath;
+(id)cacheIndexPath;
+(void)clearDiskCache;
+(BOOL)cachingEnabled;
// inherited: -(id)init;
// inherited: -(void)dealloc;
-(id)imageForKey:(id)key;
-(void)evictAsNeeded;
-(void)beginImageForKey:(id)key size:(CGSize)size;
-(id)commitImage;
-(id)copyBitmapDataFromImage:(id)image;
-(unsigned)sizeOfImageForInfo:(XXStruct_0aX3CD)info;
-(id)imageFromInfo:(XXStruct_0aX3CD)info;
-(BOOL)ensureOpenCacheDataFile:(BOOL)file;
-(BOOL)ensureFilesExistAndAreOpenForWriting:(id*)writing;
-(id)writeImageData;
-(void)setHeader:(XXStruct_iXKIAB)header forIndex:(id)index;
-(BOOL)getHeader:(XXStruct_iXKIAB*)header forIndex:(id)index;
-(void)appendEntries:(id)entries toIndex:(id)index;
-(void)updateFromIndex:(id)index;
-(void)writeToDisk;
-(void)readFromDisk;
-(void)preheatDataFile;
-(void)preheatImages;
-(void)adviseImages;
-(BOOL)shouldCreateCacheImageForKey:(id)key;
-(id)allOnDiskEntries;
-(void)sanityCheckIndex;
-(void)closeDiskCache;
-(void)clearDiskCache;
@end

#endif
