#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#include_next <UIKit/UITextChecker.h>

@interface UITextChecker ()
+(int)uniqueSpellDocumentTag;
+(CFSetRef)createDictHashTable:(BOOL)table;
+(id)openUserDictionary:(id)dictionary;
+(id)dictionaryInfo:(id)info;
+(BOOL)_learnWord:(id)word inDictionary:(id)dictionary;
+(BOOL)_forgetWord:(id)word inDictionary:(id)dictionary;
+(BOOL)_isWord:(id)word inDictionary:(id)dictionary;
+(id)_wordsInDictionary:(id)dictionary;
+(void)_setWords:(id)words inDictionary:(id)dictionary;
-(id)_nameOfDictionaryForDocumentTag:(int)documentTag;
-(void)_setLanguageDictionaryName:(id)name;
-(void)_setDocumentDictionaryName:(id)name;
-(void)initUserAddressBook;
-(void)initUserDictionaries;
-(void)initGlobals;
// inherited: -(id)init;
-(id)_initWithAsynchronousLoading:(BOOL)asynchronousLoading;
-(BOOL)_doneLoading;
// inherited: -(void)dealloc;
-(id)_checker;
-(int)adjustOffsetToNextWordBoundaryInString:(id)string startingAt:(int)at;
-(NSRange)_chunkAndCheckGrammarInString:(id)string language:(id)language usingChecker:(id)checker details:(id*)details;
-(NSRange)_chunkAndFindMisspelledWordInString:(id)string language:(id)language learnedDictionaries:(id)dictionaries wordCount:(int*)count correction:(id*)correction usingChecker:(id)checker;
-(NSRange)checkSpellingOfString:(id)string startingAt:(int)at language:(id)language wrap:(BOOL)wrap correction:(id*)correction;
-(NSRange)checkGrammarOfString:(id)string startingAt:(int)at language:(id)language wrap:(BOOL)wrap details:(id*)details;
-(id)correctionForWordRange:(NSRange)wordRange inString:(id)string language:(id)language;
-(BOOL)isWordInUserDictionaries:(id)userDictionaries caseSensitive:(BOOL)sensitive;
@end

#endif
