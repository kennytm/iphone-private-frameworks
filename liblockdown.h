/*
 
liblockdown.h ... Header for liblockdown.

Copyright (c) 2009  KennyTM~ <kennytm@gmail.com>
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

#ifndef LIBLOCKDOWN_H
#define LIBLOCKDOWN_H

#if __cplusplus
extern "C" {
#endif
	
#include <CoreFoundation/CoreFoundation.h>
#include <Security/Security.h>
#include <Availability2.h>
	
#pragma mark -
#pragma mark Error messages
	extern CFStringRef kLDErrorCheckinTimeout;
	extern CFStringRef kLDErrorGetProhibited;
	extern CFStringRef kLDErrorImmutableValue;
	extern CFStringRef kLDErrorInvalidActivationRecord;
	extern CFStringRef kLDErrorInvalidCheckin;
	extern CFStringRef kLDErrorInvalidHostID;
	extern CFStringRef kLDErrorInvalidPairRecord;
	extern CFStringRef kLDErrorInvalidResponse;
	extern CFStringRef kLDErrorInvalidService;
	extern CFStringRef kLDErrorInvalidSessionID;
	extern CFStringRef kLDErrorMissingActivationRecord;
	extern CFStringRef kLDErrorMissingHostID;
	extern CFStringRef kLDErrorMissingKey;
	extern CFStringRef kLDErrorMissingPairRecord;
	extern CFStringRef kLDErrorMissingService;
	extern CFStringRef kLDErrorMissingSessionID;
	extern CFStringRef kLDErrorMissingValue;
	extern CFStringRef kLDErrorPasswordProtected;
	extern CFStringRef kLDErrorRemoveProhibited;
	extern CFStringRef kLDErrorServiceLimit;
	extern CFStringRef kLDErrorServiceProhibited;
	extern CFStringRef kLDErrorSessionActive;
	extern CFStringRef kLDErrorSessionInactive;
	extern CFStringRef kLDErrorSetProhibited;
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_2_2
	extern CFStringRef kLDErrorCheckinConnectionFailed;
	extern CFStringRef kLDErrorCheckinOutOfMemory;
	extern CFStringRef kLDErrorCheckinReceiveFailed;
	extern CFStringRef kLDErrorCheckinResponseFailed;
	extern CFStringRef kLDErrorCheckinSendFailed;
	extern CFStringRef kLDErrorCheckinSetupFailed;
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_4_0
	extern CFStringRef kLDErrorSavePairRecordFailed;
#elif __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_0
	extern CFStringRef kLLDErrorSavePairRecordFailed;
#endif
	
#pragma mark -
#pragma mark Notifications
	extern CFStringRef kLockdownNotificationActivationStateChanged;
	extern CFStringRef kLockdownNotificationBrickStateChanged;
	extern CFStringRef kLockdownNotificationDataSyncDomainChanged;
	extern CFStringRef kLockdownNotificationDeveloperImageMounted;
	extern CFStringRef kLockdownNotificationDeviceNameChanged;
	extern CFStringRef kLockdownNotificationHostAttached;
	extern CFStringRef kLockdownNotificationHostDetached;
	extern CFStringRef kLockdownNotificationPhoneNumberChanged;
	extern CFStringRef kLockdownNotificationRegistrationFailed;
	extern CFStringRef kLockdownNotificationTrustedHostAttached;
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_2_1
	extern CFStringRef kLockdownNotificationApplicationInstalled;
	extern CFStringRef kLockdownNotificationApplicationUninstalled;
	extern CFStringRef kLockdownNotificationThirdPartyApplicationQuit;
	extern CFStringRef kLockdownNotificationTimezoneChanged;
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_0
	extern CFStringRef kLockdownNotificationBackupDomainChanged;
	extern CFStringRef kLockdownNotificationIQAgentAllowedChanged;
	extern CFStringRef kLockdownNotificationiTunesAccountChanged;
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_4_0
	extern CFStringRef kLockdownNotificationPowerChange;
	extern CFStringRef kLockdownNotificationSBLockChange;
	extern CFStringRef kLockdownNotificationSyncAllowChanged;	
#endif
	
#pragma mark -
#pragma mark Domains
	extern CFStringRef kLockdownDiskUsageDomainKey;	// com.apple.disk_usage
	extern CFStringRef kLockdownCheckpointDomainKey;	// com.apple.mobile.iTunes
	extern CFStringRef kLockdownDataSyncDomainKey;	// com.apple.data_sync
	extern CFStringRef kLockdownDebugDomainKey;	// com.apple.mobile.debug
	extern CFStringRef kLockdownFairPlayDomainKey;	// com.apple.fairplay
	extern CFStringRef kLockdownInternalDomainKey;	// com.apple.mobile.internal
	extern CFStringRef kLockdownInternationalDomainKey;	// com.apple.international
	extern CFStringRef kLockdownRestrictionDomainKey;	// com.apple.mobile.restriction
	extern CFStringRef kLockdownSoftwareBehaviorDomainKey;	// com.apple.mobile.software_behavior
	extern CFStringRef kLockdownStoreDomainKey;	// com.apple.mobile.iTunes.store
	extern CFStringRef kLockdownSyncDataClassDomainKey;	// com.apple.mobile.sync_data_class
	extern CFStringRef kLockownSQLMusicLibraryPostProcessCommandsDomainKey;	// com.apple.mobile.iTunes.SQLMusicLibraryPostProcessCommands
	static const CFStringRef kLockdowniTunesDomainKey = CFSTR("com.apple.iTunes");
	static const CFStringRef kLockdowniTunesStoredDomainKey = CFSTR("com.apple.itunesstored");
	static const CFStringRef kLockdownXcodeDeveloperDomainKey = CFSTR("com.apple.xcode.developerdomain");
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_2_1
	extern CFStringRef kLockdownUserPreferencesDomainKey;	// com.apple.mobile.user_preferences
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_2_2
	extern CFStringRef kLockdownProtocolVersion;	// "2"
	extern CFStringRef kLockdownPrefApplicationID;	// com.apple.mobile.lockdownd
	extern CFStringRef kLockdownMobileApplicationUsageMapDomain;	// com.apple.mobile.mobile_application_usage
#if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_4_0
	extern CFStringRef kLockdownThirdPartyTerminationMapDomain;	// com.apple.mobile.third_party_termination
#else
	extern CFStringRef kLockdownHostPairingsDomainKey;
#endif
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_0
	extern CFStringRef kLockdownBackupDomainKey;	// com.apple.mobile.backup
	extern CFStringRef kLockdownIQAgentApplicationID;	// com.apple.iqagent
#endif
	
#pragma mark -
#pragma mark : (nil-Domain Keys)
	extern CFStringRef kLockdownActivationInfoKey;
	extern CFStringRef kLockdownActivationRandomnessKey;
	extern CFStringRef kLockdownActivationStateKey;
	extern CFStringRef kLockdownBuildVersionKey;
	extern CFStringRef kLockdownBrickStateKey;
	extern CFStringRef kLockdownDeviceCertificateKey;
	extern CFStringRef kLockdownDeviceClassKey;
	extern CFStringRef kLockdownDeviceNameKey;
	extern CFStringRef kLockdownDevicePrivateKey;
	extern CFStringRef kLockdownDevicePublicKey;
	extern CFStringRef kLockdownFirmwareVersionKey;
	extern CFStringRef kLockdownHostAttachedKey;
	extern CFStringRef kLockdownInverseDeviceIDKey;
	extern CFStringRef kLockdownModelNumberKey;
	extern CFStringRef kLockdownPasswordProtectedKey;
	extern CFStringRef kLockdownProductTypeKey;
	extern CFStringRef kLockdownProductVersionKey;
	extern CFStringRef kLockdownProtocolVersionKey;
	extern CFStringRef kLockdownRegionInfoKey;
	extern CFStringRef kLockdownSIMGID1Key;	// ?
	extern CFStringRef kLockdownSIMGID2Key;	// ?
	extern CFStringRef kLockdownSIMStatusKey;
	extern CFStringRef kLockdownSerialNumberKey;
	extern CFStringRef kLockdownSoftwareBehaviorKey;
	extern CFStringRef kLockdownSomebodySetTimeZoneKey;
	extern CFStringRef kLockdownTimeIntervalSince1970Key;
	extern CFStringRef kLockdownTimeZoneKey;
	extern CFStringRef kLockdownTimeZoneOffsetFromUTCKey;
	extern CFStringRef kLockdownTrustedHostAttachedKey;
	extern CFStringRef kLockdownUniqueChipIDKey;
	extern CFStringRef kLockdownUniqueDeviceIDKey;
	extern CFStringRef kLockdownUses24HourClockKey;
	extern CFStringRef kLockdownWifiAddressKey;
	extern CFStringRef kLockdowniTunesHasConnectedKey;
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_2_1
	extern CFStringRef kLockdownActivationStateAcknowledgedKey;
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_0
	extern CFStringRef kLockdownActivationPrivateKey;
	extern CFStringRef kLockdownActivationPublicKey;
	extern CFStringRef kLockdownCPUArchitectureKey;
	extern CFStringRef kLockdownHardwareModelKey;
	extern CFStringRef kLockdownMLBSerialNumberKey;
	extern CFStringRef kLockdownProductionSOCKey;
#endif
	
#pragma mark : (Unknown domain Keys)
	extern CFStringRef kLockdownActivationInfoCompleteKey;
	extern CFStringRef kLockdownActivationInfoErrorsKey;
	extern CFStringRef kLockdownActivationTicketKey;
	extern CFStringRef kLockdownBasebandBootloaderVersionKey;
	extern CFStringRef kLockdownBasebandMasterKeyHashKey;
	extern CFStringRef kLockdownBasebandThumbprintKey;
	extern CFStringRef kLockdownBasebandVersionKey;	
	extern CFStringRef kLockdownBluetoothAddressKey;
	extern CFStringRef kLockdownCarrierBundleInfoKey;
	extern CFStringRef kLockdownICCIDKey;	// IntegratedCircuitCardIdentity
	extern CFStringRef kLockdownIMEIKey;	// InternationalMobileEquipmentIdentity
	extern CFStringRef kLockdownIMSIKey;	// InternationalMobileSubscriberIdentity
	extern CFStringRef kLockdownIsInternalKey;
	extern CFStringRef kLockdownPhoneNumberKey;
	extern CFStringRef kLockdownProposedTicketKey;
	extern CFStringRef kLockdownReleaseTypeKey;
	extern CFStringRef kLockdownReservedBytesKey;
	extern CFStringRef kLockdownShutterClickKey;
	extern CFStringRef kLockdownUnlockCodeKey;
	extern CFStringRef kLockdownVolumeLimitKey;
	extern CFStringRef kLockdownWildcardTicketKey;
	extern CFStringRef kLockdownBatteryCurrentCapacity;
	extern CFStringRef kLockdownBatteryIsCharging;
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_2_1
	extern CFStringRef kLockdownSupportsCarrierBundleInstallKey;
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_2_2
	extern CFStringRef kLockdownExtendedLoggingPrefKey;
	extern CFStringRef kLockdownLogToDiskPrefKey;
#else
	extern CFStringRef kLockdownCaptureSyslogKey;
	extern CFStringRef kLockdownLogToDiskKey;
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_0
	extern CFStringRef kLockdownAccessibilityLanguagesKey;
	extern CFStringRef kLockdownChinaBrickKey;
	extern CFStringRef kLockdownGoogleMailKey;
	extern CFStringRef kLockdownNTSCKey;
	extern CFStringRef kLockdownNVRAMKey;
	extern CFStringRef kLockdownNoWiFiKey;	
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_1
	extern CFStringRef kLockdownAMRKey;
	extern CFStringRef kLockdownH263Key;
	extern CFStringRef kLockdownH264HKey;
	extern CFStringRef kLockdownH264MKey;
	extern CFStringRef kLockdownSNUMKey;
	extern CFStringRef kLockdownServiceToken;
#if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_4_0
	extern CFStringRef kLockdownEnableLockdownNetworkConnectKey;
#else
	extern CFStringRef kLockdownBackupVersionKey;
	extern CFStringRef kLockdownBuddyHostNameKey;
	extern CFStringRef kLockdownBuddyServiceNameKey;
	extern CFStringRef kLockdownBuddyServicePortKey;
	extern CFStringRef kLockdownCallsInProgressKey;
	extern CFStringRef kLockdownChapterImageSpecs;
	extern CFStringRef kLockdownCheckinHostIDkey;
	extern CFStringRef kLockdownCheckinVersionKey;
	extern CFStringRef kLockdownCurrentlyBrowsingKey;
	extern CFStringRef kLockdownDevToolsAvailableKey;
	extern CFStringRef kLockdownEscrowBagKey;
	extern CFStringRef kLockdownExternalChargeCapableKey;
	extern CFStringRef kLockdownExternalConnectedKey;
	extern CFStringRef kLockdownFullyChargedKey;
	extern CFStringRef kLockdownInternalKey;
	extern CFStringRef kLockdownMCCKey;
	extern CFStringRef kLockdownMNCKey;
	extern CFStringRef kLockdownMachineHackKey;
	extern CFStringRef kLockdownNoneKey;
	extern CFStringRef kLockdownPartitionTypeKey;
	extern CFStringRef kLockdownPluggedInKey;
	extern CFStringRef kLockdownSBLockedKey;
	extern CFStringRef kLockdownSortSectionsKey;
	extern CFStringRef kLockdownStandardKey;
	extern CFStringRef kLockdownSyncAllowedKey;
	extern CFStringRef kLockdownWakingBuddyKey;
	extern CFStringRef kLockdownWirelessBuddyFriendlyNameKey;
	extern CFStringRef kLockdownWirelessBuddyIDKey;
	extern CFStringRef kLockdownWirelessEchoServicePortNumberKey;
	extern CFStringRef kLockdownWirelessEnableWifiConnections;
	extern CFStringRef kLockdownWirelessSupportsWifi;
	extern CFStringRef kLockdownWokeBuddySincePluggedKey;
#endif
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED == __IPHONE_3_2
	extern CFStringRef kLockdownPlaylistFoldersSupportedKey;
#endif
	
	
#pragma mark : Disk Usage Domain Keys
	extern CFStringRef kLockdownAmountCameraAvailableKey;
	extern CFStringRef kLockdownAmountDataAvailableKey;
	extern CFStringRef kLockdownAmountDataReservedKey;
	extern CFStringRef kLockdownCalendarUsageKey;
	extern CFStringRef kLockdownCameraUsageKey;
	extern CFStringRef kLockdownMediaCacheUsageKey;
	extern CFStringRef kLockdownNANDInfoKey;
	extern CFStringRef kLockdownNotesUsageKey;
	extern CFStringRef kLockdownPhotoUsageKey;
	extern CFStringRef kLockdownTotalDataAvailableKey;
	extern CFStringRef kLockdownTotalDataCapacityKey;
	extern CFStringRef kLockdownTotalDiskCapacityKey;
	extern CFStringRef kLockdownTotalSystemAvailableKey;
	extern CFStringRef kLockdownTotalSystemCapacityKey;
	extern CFStringRef kLockdownVoicemailUsageKey;
	extern CFStringRef kLockdownWebAppCacheUsageKey;
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_2_1
	extern CFStringRef kLockdownMobileApplicationUsageKey;
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_0
	extern CFStringRef kLockdownAmountCameraUsageChangedKey;
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_3_1
	extern CFStringRef kLockdownAmountCameraReservedKey;
	extern CFStringRef kLockdownAmountSongsReservedKey;
#endif

#pragma mark : Checkpoint Domain Keys
	extern CFStringRef kLockdownColorSyncProfileKey;
	extern CFStringRef kLockdownFairPlayCertificateKey;
	extern CFStringRef kLockdownFairPlayGUIDKey;
	extern CFStringRef kLockdownFairPlayIDKey;
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_2_1
	extern CFStringRef kLockdownDBVersionKey;
	extern CFStringRef kLockdownFamilyIDKey;
	extern CFStringRef kLockdownMinimumiTunesVersionKey;
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_1
	extern CFStringRef kLockdownAudioCodecsKey;
	extern CFStringRef kLockdownVideoCodecsKey;
#endif
	
#pragma mark : Debug Domain Keys
	extern CFStringRef kLockdownDebugDockPresentKey;
	extern CFStringRef kLockdownEnableVPNLogsKey;
	extern CFStringRef kLockdownRemoveWiFiManagerLogs;	
	extern CFStringRef kLockdownEnable8021XLogsKey;
	static const CFStringRef kLockdownStoreIdentityCookieKey = CFSTR("StoreIdentityCookie");
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_2_2
	extern CFStringRef kLockdownRemoveVPNLogs;
	extern CFStringRef kLockdownRemove8021XLogs;
	extern CFStringRef kLockdownEnableLockdownLogToDiskKey;	
	extern CFStringRef kLockdownEnableLockdownExtendedLoggingKey;
	extern CFStringRef kLockdownRemoveLockdownLog;
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_0
	extern CFStringRef kLockdownEnableWiFiManagerLogsKey;
#endif
	

#pragma mark : FairPlay Domain Keys
	extern CFStringRef kLockdownFairPlayContextIDKey;
	extern CFStringRef kLockdownFairPlayKeyDataKey;	// ?
	extern CFStringRef kLockdownRentalBagRequestKey;
	extern CFStringRef kLockdownRentalBagRequestVersionKey;
	extern CFStringRef kLockdownRentalBagResponseKey;
	extern CFStringRef kLockdownRentalCheckinAckRequestKey;
	extern CFStringRef kLockdownRentalCheckinAckResponseKey;	// ?
	extern CFStringRef kLockdownFairPlayRentalClockBias;

#pragma mark : International Domain Keys
	extern CFStringRef kLockdownKeyboardKey;	// CFString.
	extern CFStringRef kLockdownLanguageKey;	// CFString.
	extern CFStringRef kLockdownLocaleKey;	// CFString.
	extern CFStringRef kLockdownSupportedKeyboardsKey;
	extern CFStringRef kLockdownSupportedLanguagesKey;
	extern CFStringRef kLockdownSupportedLocalesKey;
	extern CFStringRef kLockdownSupportsAccessibilityKey;	

#pragma mark : Restriction Domain Keys
	extern CFStringRef kLockdownProhibitAppInstallKey;
	
#pragma mark : Data Sync Domain Keys
	extern CFStringRef kLockdownSyncSupportsCalDAV;
	extern CFStringRef kLockdownDeviceHandlesDefaultCalendar;
	extern CFStringRef kLockdownSupportsEncryptedBackups;
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_1
	extern CFStringRef kLockdownDeviceSupportsClearingDataKey;
#endif

#pragma mark : iTunes Keys
	static const CFStringRef kLockdownLibraryApplicationsKey = CFSTR("LibraryApplications");
	static const CFStringRef kLockdownSyncedApplicationsKey = CFSTR("SyncedApplications");

#pragma mark : itunesstored Keys
	static const CFStringRef kLockdownSoftwareCUIDKey = CFSTR("SoftwareCUID");
	
	
#pragma mark : User Preferences Domain Keys
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_2_1
	extern CFStringRef kLockdownUserSetLanguageKey;
	extern CFStringRef kLockdownUserSetLocaleKey;	// ?
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_0
	extern CFStringRef kLockdownDiagnosticsAllowedKey;
#endif
	
#pragma mark : Backup Domain Keys
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_0
	extern CFStringRef kLockdownBackupWillEncrypt;	// ?
#endif
	
#pragma mark : Software Behavior Domain Keys
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_0
	extern CFStringRef kLockdownBehaviorsValidKey;
#endif
	
#pragma mark : Store Domain Keys
	static const CFStringRef kLockdownAccountKindKey = CFSTR("AccountKind");
	static const CFStringRef kLockdownAppleIDKey = CFSTR("AppleID");
	static const CFStringRef kLockdownCreditDisplayStringKey = CFSTR("CreditDisplayString");
	static const CFStringRef kLockdownKnownAccountsKey = CFSTR("KnownAccounts");	
	static const CFStringRef kLockdownPreferHQTracksKey = CFSTR("PreferHQTracks");	
	static const CFStringRef kLockdownPurchaseTypesKey = CFSTR("PurchaseTypes");	
	static const CFStringRef kLockdownStorefrontKey = CFSTR("Storefront");	
	static const CFStringRef kLockdownUserNameKey = CFSTR("UserName");	
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_0
	extern CFStringRef kLockdownDSPersonIDKey;
#endif
	
#pragma mark : Internal Domain Keys
	extern CFStringRef kLockdownVoidWarrantyKey;
	
#pragma mark : Xcode Developer Domain Keys
	static const CFStringRef kLockdownDeveloperStatusKey = CFSTR("DeveloperStatus");
	
#pragma mark -
#pragma mark Functions
	typedef void* LockdownConnectionRef;
	
	typedef enum {
		kLockdownErrorSuccess,
		kLockdownErrorInvalidResponse,
		kLockdownErrorMissingKey,
		kLockdownErrorMissingValue,
		kLockdownErrorGetProhibited,
		kLockdownErrorSetProhibited,
		kLockdownErrorRemoveProhibited,
		kLockdownErrorImmutableValue,
		kLockdownErrorInvalidCheckin,
		kLockdownErrorCheckinTimeout
	} LockdownError;
		
	CFSocketNativeHandle lockdown_checkin();	// returns -1 on error, a socket fildes on success.
		
	LockdownConnectionRef lockdown_connect();
	void lockdown_disconnect(LockdownConnectionRef connection);
	
	SecIdentityRef lockdown_copy_identity(LockdownConnectionRef connection);
	CFPropertyListRef lockdown_copy_value(LockdownConnectionRef connection, CFStringRef domain, CFStringRef key);
	LockdownError lockdown_remove_value(LockdownConnectionRef connection, CFStringRef domain, CFStringRef key);
	LockdownError lockdown_set_value(LockdownConnectionRef connection, CFStringRef domain, CFStringRef key, CFPropertyListRef newValue);
	
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_4_0
	/* XXX Todo:
	lockdown_get_securecontext
	lockdown_get_socket
	lockdown_receive_message
	lockdown_recv
	lockdown_secure_checkin
	lockdown_send
	lockdown_send_message
	secure_lockdown_checkin	
	 */
#endif
	
	/*
	 dlfun("lockdown_connect", "^v");
	 dlfun("lockdown_disconnect", "v^v");
	 dlfun("lockdown_copy_value", "@^v@@");
	 dlfun("lockdown_remove_value", "i^v@@");
	 dlfun("lockdown_set_value", "i^v@@@");
	 */
	
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_1
#pragma mark -
#pragma mark Lockdown Service functions
	typedef struct __LockdownService /*{
		CFRuntimeBase _base;
		CFRunLoopRef runloop;
		CFStringRef runloopMode;
		CFSocketRef socket;
		CFRunLoopSourceRef source;
		CFSocketNativeHandle fd;
		CFErrorRef error;
		LockdownServiceCallback callback;
		void* info;
	}*/* LockdownServiceRef;
	
	typedef void(*LockdownServiceCallback)(LockdownServiceRef service, CFSocketCallBackType cbType, void* info);
	
	CFTypeID LockdownServiceGetTypeID();
	
	CFSocketRef LockdownServiceGetSocket(LockdownServiceRef service);
	CFErrorRef LockdownServiceGetError(LockdownServiceRef service);
	void LockdownServiceSetError(LockdownServiceRef service, CFErrorRef error);
	bool LockdownServiceIsValid(LockdownServiceRef service);
	void LockdownServiceInvalidate(LockdownServiceRef service);
	bool LockdownServiceScheduleWithRunLoop(LockdownServiceRef service, CFRunLoopRef runloop, CFStringRef mode, CFErrorRef* pError);
	LockdownServiceRef LockdownServiceCreate(CFAllocatorRef allocator, LockdownServiceCallback callback, void* info, CFErrorRef* pError);
	void LockdownServiceSendMessage(LockdownServiceRef service, CFPropertyListRef message, CFErrorRef* pError);
#endif
	
#if __cplusplus
}
#endif

#endif