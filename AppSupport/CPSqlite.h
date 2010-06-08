/*
 
CPSqlite.h ... Sqlite interface in AppSupport.

Copyright (c) 2010  KennyTM~ <kennytm@gmail.com>
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice, 
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.
* Neither the name of the KennyTM~ nor the names of its contributors may be
  used to endorse or promote products derived from this software without
  specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef APPSUPPORT_CPSQLITE_H_opf8964u57
#define APPSUPPORT_CPSQLITE_H_opf8964u57

#import <CoreFoundation/CoreFoundation.h>
#import <sqlite3.h>
#include <stdbool.h>
#include <stdint.h>

/* Relevant environment variables:
 
 CPSQLDEBUG
 CPSQLEXPLAIN

*/

#if __cplusplus
extern "C" {
#endif
		
	struct CPSqliteConnection;
	struct CPSqliteDatabase;
	struct CPSqliteStatement;
	
	typedef void (*CPSqliteConnectionProgressHandlerCallback)(struct CPSqliteConnection* connection, void* context);

	typedef struct CPSqliteConnection {
		struct CPSqliteDatabase* database;
		sqlite3* connection;
		CFDictionaryRef statementCache;
		void* deallocatorContext;
		void (*deallocator)(void* context);
		CPSqliteConnectionProgressHandlerCallback progressHandler;
		void* progressHandlerContext;
	} CPSqliteConnection;
	
	typedef void (*CPSqliteDatabaseCorruptionHandler)(struct CPSqliteDatabase* database);
	typedef void (*CPSqliteDatabaseConnectionInitializer)(struct CPSqliteDatabase* database, CPSqliteConnection* connection);
	typedef int (*CPSqliteDatabaseExternalConversionChecker)(struct CPSqliteDatabase* database, CPSqliteConnection* connection);
	typedef int (*CPSqliteDatabaseMigrationHandler)(struct CPSqliteDatabase* database, CPSqliteConnection* connection, int clientVersion, void* context);
	typedef int (*CPSqliteDatabaseCommitHookCallback)(struct CPSqliteDatabase* database);
	typedef void (*CPSqliteDatabaseUpdateHookCallback)(struct CPSqliteDatabase* database, const char* databaseName);
	
	typedef struct CPSqliteDatabase {
		CFStringRef path;
		CPSqliteConnection* connection;
		/*function-pointer*/ void* setupHandler;
		/*function-pointer*/ void* databaseInitializer;
		CPSqliteDatabaseConnectionInitializer connectionInitializer;
		void* setupHandlerContext;
		CPSqliteDatabaseMigrationHandler migrationHandlerBefore;
		CPSqliteDatabaseMigrationHandler migrationHandlerAfter;
		CPSqliteDatabaseCorruptionHandler corruptionHandler;
		bool shouldNotMigrateInProcess;
		void* migrationContext;
		int version;
		struct {
			unsigned checkVersion : 1;	// 1
			unsigned checkedJournalPermissions : 1;	// 2
			unsigned propertiesDisabled : 1;	// 4
			unsigned threadSafety : 1;	// 8
			unsigned shouldNotify : 1;	// 16
			unsigned shouldYield : 1;	// 32
			unsigned notifyRegisterAttempted : 1;	// 64
			unsigned notifyRegisterSucceeded : 1;	// 128
			unsigned postedRequest : 1;	// 1
			unsigned receivedRequest : 1;	// 2
		} flags;
		pthread_mutex_t mutex;
		int _field15;
		CPSqliteDatabaseCommitHookCallback commitHookCallback;
		CPSqliteDatabaseUpdateHookCallback updateHookCallback;
		CPSqliteDatabaseExternalConversionChecker externalConversionChecker;
		int (*busyHandler)(void* context, int count);
		void* busyHandlerContext;
		int unlockRequestToken;
		CFStringRef vfsModuleName;
	} CPSqliteDatabase;
	
	typedef struct CPSqliteStatement {
		CPSqliteConnection* connection;
		sqlite3_stmt* statement;
	} CPSqliteStatement;
	
#pragma mark -
	
	typedef enum CPSqliteStatementValueType {
		CPSqliteStatementValueType_Integer,
		CPSqliteStatementValueType_Integer64,
		CPSqliteStatementValueType_CFString,
		CPSqliteStatementValueType_RawString,
		CPSqliteStatementValueType_CFData,
		CPSqliteStatementValueType_Blob,
		CPSqliteStatementValueType_FloatingPoint,
		CPSqliteStatementValueType_CFNumber
	} CPSqliteStatementValueType;
	
	typedef union CPSqliteStatementContent {
		int integer;
		int64_t integer64;
		CFStringRef string;
		const uint8_t* rawString;
		CFDataRef data;
		const void* blob;
		float floatingPoint;
		CFNumberRef number;
	} CPSqliteStatementContent;
	
	typedef struct CPSqliteStatementValue {
		const char* name;
		CPSqliteStatementValueType type;
		CPSqliteStatementContent value;
	} CPSqliteStatementValue;
	
	typedef struct CPSqliteStatementApplyCallback {
		int column;
		CPSqliteStatementValueType type;
		bool (*apply)(void* context, void* column_context, CPSqliteStatementContent content);
		void* column_context;
	} CPSqliteStatementApplyCallback;	
	
	typedef enum CPSqliteConnectionTransactionType {
		CPSqliteConnectionTransactionType_Begin,
		CPSqliteConnectionTransactionType_BeginImmediate,
		CPSqliteConnectionTransactionType_BeginExclusive
	} CPSqliteConnectionTransactionType;
	
#pragma mark -
	
	CPSqliteDatabase* CPSqliteDatabaseCreateWithPath(CFStringRef path);	// release with free().
	
	void CPSqliteDatabaseSetVersion(CPSqliteDatabase* database, int version);	// also set the checkVersion flag.
	void CPSqliteDatabaseSetShouldMigrateInProcess(CPSqliteDatabase* database, bool shouldMigrateInProcess);
	void CPSqliteDatabaseSetPropertiesEnabled(CPSqliteDatabase* database, bool propertiesEnabled);
	void CPSqliteDatabaseSetShouldRequestUnlock(CPSqliteDatabase* database, bool shouldNotify);

	void CPSqliteDatabaseSetSetupHandler(CPSqliteDatabase* database, void* handler, void* context);
	void CPSqliteDatabaseSetDatabaseInitializer(CPSqliteDatabase* database, void* initializer);
	void CPSqliteDatabaseSetConnectionInitializer(CPSqliteDatabase* database, CPSqliteDatabaseConnectionInitializer initializer);
	void CPSqliteDatabaseSetCommitHookCallback(CPSqliteDatabase* database, CPSqliteDatabaseCommitHookCallback callback);
	void CPSqliteDatabaseSetUpdateHookCallback(CPSqliteDatabase* database, CPSqliteDatabaseUpdateHookCallback callback);
	void CPSqliteDatabaseSetExternalConversionChecker(CPSqliteDatabase* database, CPSqliteDatabaseExternalConversionChecker checker);
	void CPSqliteDatabaseSetMigrationHandlers(CPSqliteDatabase* database, CPSqliteDatabaseMigrationHandler handlerBefore, void* handlerAfter, void* context);
	void CPSqliteDatabaseSetCorruptionHandler(CPSqliteDatabase* database, CPSqliteDatabaseCorruptionHandler handler);
	void CPSqliteDatabaseSetBusyHandler(CPSqliteDatabase* database, int(*busyHandler)(void* context, int count), void* busyHandlerContext);
	
	CFStringRef CPSqliteDatabasePath(CPSqliteDatabase* database);
	char* CPSqliteDatabaseCopyPath(CPSqliteDatabase* database);	// remember to free().
	void CPSqliteDatabaseSetVFSModuleName(CPSqliteDatabase* database, CFStringRef vfsModuleName);
	
	void CPSqliteDatabaseCloseAllConnections(CPSqliteDatabase* database);
	void CPSqliteDatabaseClose(CPSqliteDatabase* database);
	
	void CPSqliteDatabaseRequestUnlock(CPSqliteDatabase* database);
	bool CPSqliteDatabaseUnlockRequested(CPSqliteDatabase* database);
	void CPSqliteDatabaseSetShouldYieldWhenRequested(CPSqliteDatabase* database, bool shouldYield);
	
	CPSqliteConnection* CPSqliteDatabaseConnectionForReading(CPSqliteDatabase* database, bool debug);
	CPSqliteConnection* CPSqliteDatabaseConnectionForWriting(CPSqliteDatabase* database);
	CPSqliteStatement* CPSqliteDatabaseStatementForReading(CPSqliteDatabase* database, CFStringRef sql);
	CPSqliteStatement* CPSqliteDatabaseStatementForWriting(CPSqliteDatabase* database, CFStringRef sql);
	
	CFStringRef CPSqliteDatabaseCopyValueForProperty(CPSqliteDatabase* database, CFStringRef property);
	CFStringRef CPSqliteDatabaseCopyUniqueIdentifier(CPSqliteDatabase* database);
	int CPSqliteDatabaseSetValueForProperty(CPSqliteDatabase* database, CFStringRef property, CFStringRef value);
	
	// See http://www.sqlite.org/c3ref/create_function.html for what these arguments mean.
	int CPSqliteDatabaseRegisterFunction(CPSqliteDatabase* database, const char* zFunctionName, void (*xFunc)(sqlite3_context*,int,sqlite3_value**), int nArg, void* pApp);
	
	void CPSqliteDatabaseSetThreadSafeEnabled(CPSqliteDatabase* database);

	void CPSqliteDatabaseDefaultSetupHandler(void);	// no-op.
	
#pragma mark -
	
	void CPSqliteConnectionClose(CPSqliteConnection* connection);
	void CPSqliteConnectionFlushStatementCache(CPSqliteConnection* connection);
	bool CPSqliteConnectionCheckNoConnectionError(CPSqliteConnection* connection, int errcode, const char* location);
	
	void CPSqliteConnectionDisableProgressHandlerCallback(CPSqliteConnection* connection);
	void CPSqliteConnectionEnableProgressHandlerCallback(CPSqliteConnection* connection, CPSqliteConnectionProgressHandlerCallback callback, void* context);
	
	sqlite_int64 CPSqliteConnectionRowidOfLastInsert(CPSqliteConnection* connection);
	
	sqlite3_stmt* CPSqlitePreparedStatement(sqlite3* db, const char* sql, bool ignore_warning);
	CPSqliteStatement* CPSqliteConnectionStatementForSQL(CPSqliteConnection* connection, CFStringRef sql);
	// CPSqliteStatement* CPSqliteConnectionStatementForSQLAndIgnoreErrors(CPSqliteConnection* connection, CFStringRef sql, bool ignore_warning);	
	
	// Do stuff with the "_SqliteDatabaseProperties" table.
	int CPSqliteConnectionSetIntegerForProperty(CPSqliteConnection* connection, CFStringRef key, int value);
	int CPSqliteConnectionSetDatabaseVersion(CPSqliteConnection* connection, int version); // equivalent to CPSqliteConnectionSetIntegerForProperty with key "_ClientVersion"
	int CPSqliteConnectionSetValueForProperty(CPSqliteConnection* connection, CFStringRef key, CFStringRef value);
	
	int CPSqliteConnectionIntegerForPropertyWithDefaultValue(CPSqliteConnection* connection, CFStringRef property, int defaultValue);
	int CPSqliteConnectionIntegerForProperty(CPSqliteConnection* connection, CFStringRef property);	// default value is 0.
	int CPSqliteConnectionDatabaseVersion(CPSqliteConnection* connection);	// equivalent to CPSqliteConnectionIntegerForProperty(connection, @"_ClientVersion");
	void CPSqliteConnectionCopyValuesForPropertiesLike(CPSqliteConnection* connection, CFStringRef pattern, CFMutableArrayRef* keys, CFMutableArrayRef* values);
	CFStringRef CPSqliteConnectionCopyValueForProperty(CPSqliteConnection* connection, CFStringRef key);
	
	int CPSqliteConnectionUpdateRecord(CPSqliteConnection* connection, CFStringRef table, sqlite_int64 rowid, const CPSqliteStatementValue values[], int count);
	int CPSqliteConnectionAddRecordWithRowid(CPSqliteConnection* connection, CFStringRef table, sqlite_int64 rowid, const CPSqliteStatementValue values[], int count);
	int CPSqliteConnectionAddRecord(CPSqliteConnection* connection, CFStringRef table, const CPSqliteStatementValue values[], int count);	// rowid == -1.
	
	int CPSqliteConnectionRollback(CPSqliteConnection* connection);
	int CPSqliteConnectionCommit(CPSqliteConnection* connection);
	int CPSqliteConnectionPerformSQL(CPSqliteConnection* connection, CFStringRef sql);
	int CPSqliteConnectionBeginTranscationType(CPSqliteConnection* connection, CPSqliteConnectionTransactionType type);
	int CPSqliteConnectionBegin(CPSqliteConnection* connection);	// equivalent to CPSqliteConnectionBeginTranscationType(connection, 0);
	
	int CPSqliteDatabaseReleaseSqliteConnection(CPSqliteConnection* connection);
	
#pragma mark -
		
	void CPSqliteStatementBindValuesForColumns(CPSqliteStatement* statement, const CPSqliteStatementValue records[], int count, int start_index);

	void CPSqliteStatementApplyValuesFromRecordWithNullValue(CPSqliteStatement* statement, const CPSqliteStatementApplyCallback columns[], int count, void* context, CPSqliteStatementContent nullValue);
	void CPSqliteStatementApplyValuesFromRecord(CPSqliteStatement* statement, const CPSqliteStatementApplyCallback columns[], int count, void* context);
	
	CFStringRef CPSqliteStatementCopyStringResult(CPSqliteStatement* statement);	
	int64_t CPSqliteStatementInteger64Result(CPSqliteStatement* statement, int* errcode);
	int CPSqliteStatementIntegerResult(CPSqliteStatement* statement, int* errcode);
	
	int CPSqliteStatementPerform(CPSqliteStatement* statement);
	int CPSqliteStatementReset(CPSqliteStatement* statement);
	
	void CPSqliteStatementFinalize(CPSqliteStatement* statement);
	
	int CPSqliteStatementSendResults(CPSqliteStatement* statement, int(*action)(CPSqliteStatement* statement, void* context), void* context);
	
	void CPSqliteDatabaseReleaseSqliteStatement(CPSqliteStatement* statement);
	
	int CPSqliteStatementProcessPhoneQuery(void*, CFStringRef, void*, void*, void*);	// ???
	
#pragma mark -
	
	// Perform a 'SELECT value FROM _SqliteDatabaseProperties WHERE key = "_ClientVersion"' query on the database.
	int CPSqliteUtilitiesGetSchemaVersionAtPath(CFStringRef filename);
	
	bool CPSqliteCompareSortKeyPrefixes(const char* r0, const char* r1);
	
	// unary functions:
	void CPSqliteNormalizePhoneNumber(sqlite3_context* context, int count, sqlite3_value* const values[]);
	void CPSqlitePhoneNumberContainsAlphaCharacters(sqlite3_context* context, int count, sqlite3_value* const values[]);
	// binary functions:
	void CPSqliteHasSortKeyPrefix(sqlite3_context* context, int count, sqlite3_value* const values[]);
	void CPSqliteComparePhoneNumbers(sqlite3_context* context, int count, sqlite3_value* const values[]);
	
#if __cplusplus
}
#endif

#endif
