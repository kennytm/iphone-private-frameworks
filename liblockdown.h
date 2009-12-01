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
	extern CFStringRef kLDErrorCheckinConnectionFailed
	extern CFStringRef kLDErrorCheckinOutOfMemory;
	extern CFStringRef kLDErrorCheckinReceiveFailed;
	extern CFStringRef kLDErrorCheckinResponseFailed;
	extern CFStringRef kLDErrorCheckinSendFailed;
	extern CFStringRef kLDErrorCheckinSetupFailed;
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_0
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
	
#pragma mark -
#pragma mark Misc.
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_2_2
	extern CFStringRef kLockdownProtocolVersion;	// "2"
	extern CFStringRef kLockdownPrefApplicationID;	// com.apple.mobile.lockdownd
	extern CFStringRef kLockdownMobileApplicationUsageMapDomain;	// com.apple.mobile.mobile_application_usage
	extern CFStringRef kLockdownThirdPartyTerminationMapDomain;	// com.apple.mobile.third_party_termination
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_0
	extern CFStringRef kLockdownIQAgentApplicationID;	// com.apple.iqagent
#endif
	
#pragma mark -
#pragma mark Keys
	extern CFStringRef kLockdownActivationInfoCompleteKey;
	extern CFStringRef kLockdownActivationInfoErrorsKey;
	extern CFStringRef kLockdownActivationInfoKey;
	extern CFStringRef kLockdownActivationRandomnessKey;
	extern CFStringRef kLockdownActivationStateKey;
	extern CFStringRef kLockdownActivationTicketKey;
	extern CFStringRef kLockdownAmountCameraAvailableKey;
	extern CFStringRef kLockdownAmountDataAvailableKey;
	extern CFStringRef kLockdownAmountDataReservedKey;
	extern CFStringRef kLockdownBasebandBootloaderVersionKey;
	extern CFStringRef kLockdownBasebandMasterKeyHashKey;
	extern CFStringRef kLockdownBasebandThumbprintKey;
	extern CFStringRef kLockdownBasebandVersionKey;
	extern CFStringRef kLockdownBluetoothAddressKey;
	extern CFStringRef kLockdownBrickStateKey;
	extern CFStringRef kLockdownBuildVersionKey;
	extern CFStringRef kLockdownCalendarUsageKey;
	extern CFStringRef kLockdownCameraUsageKey;
	extern CFStringRef kLockdownCarrierBundleInfoKey;
	extern CFStringRef kLockdownCheckpointDomainKey;
	extern CFStringRef kLockdownColorSyncProfileKey;
	extern CFStringRef kLockdownDataSyncDomainKey;
	extern CFStringRef kLockdownDebugDockPresentKey;
	extern CFStringRef kLockdownDebugDomainKey;
	extern CFStringRef kLockdownDeviceCertificateKey;
	extern CFStringRef kLockdownDeviceClassKey;
	extern CFStringRef kLockdownDeviceNameKey;
	extern CFStringRef kLockdownDevicePrivateKey;
	extern CFStringRef kLockdownDevicePublicKey;
	extern CFStringRef kLockdownDiskUsageDomainKey;
	extern CFStringRef kLockdownEnable8021XLogsKey;
	extern CFStringRef kLockdownEnableVPNLogsKey;
	extern CFStringRef kLockdownFairPlayCertificateKey;
	extern CFStringRef kLockdownFairPlayContextIDKey;
	extern CFStringRef kLockdownFairPlayDomainKey;
	extern CFStringRef kLockdownFairPlayGUIDKey;
	extern CFStringRef kLockdownFairPlayIDKey;
	extern CFStringRef kLockdownFairPlayKeyDataKey;
	extern CFStringRef kLockdownFirmwareVersionKey;
	extern CFStringRef kLockdownHostAttachedKey;
	extern CFStringRef kLockdownICCIDKey;
	extern CFStringRef kLockdownIMEIKey;
	extern CFStringRef kLockdownIMSIKey;
	extern CFStringRef kLockdownInternalDomainKey;
	extern CFStringRef kLockdownInternationalDomainKey;
	extern CFStringRef kLockdownInverseDeviceIDKey;
	extern CFStringRef kLockdownIsInternalKey;
	extern CFStringRef kLockdownKeyboardKey;
	extern CFStringRef kLockdownLanguageKey;
	extern CFStringRef kLockdownLocaleKey;
	extern CFStringRef kLockdownMediaCacheUsageKey;
	extern CFStringRef kLockdownModelNumberKey;
	extern CFStringRef kLockdownNANDInfoKey;
	extern CFStringRef kLockdownNotesUsageKey;
	extern CFStringRef kLockdownPasswordProtectedKey;
	extern CFStringRef kLockdownPhoneNumberKey;
	extern CFStringRef kLockdownPhotoUsageKey;
	extern CFStringRef kLockdownProductTypeKey;
	extern CFStringRef kLockdownProductVersionKey;
	extern CFStringRef kLockdownProhibitAppInstallKey;
	extern CFStringRef kLockdownProposedTicketKey;
	extern CFStringRef kLockdownProtocolVersionKey;
	extern CFStringRef kLockdownRegionInfoKey;
	extern CFStringRef kLockdownReleaseTypeKey;
	extern CFStringRef kLockdownRentalBagRequestKey;
	extern CFStringRef kLockdownRentalBagRequestVersionKey;
	extern CFStringRef kLockdownRentalBagResponseKey;
	extern CFStringRef kLockdownRentalCheckinAckRequestKey;
	extern CFStringRef kLockdownRentalCheckinAckResponseKey;
	extern CFStringRef kLockdownReservedBytesKey;
	extern CFStringRef kLockdownRestrictionDomainKey;
	extern CFStringRef kLockdownSIMGID1Key;
	extern CFStringRef kLockdownSIMGID2Key;
	extern CFStringRef kLockdownSIMStatusKey;
	extern CFStringRef kLockdownSerialNumberKey;
	extern CFStringRef kLockdownShutterClickKey;
	extern CFStringRef kLockdownSoftwareBehaviorDomainKey;
	extern CFStringRef kLockdownSoftwareBehaviorKey;
	extern CFStringRef kLockdownSomebodySetTimeZoneKey;
	extern CFStringRef kLockdownStoreDomainKey;
	extern CFStringRef kLockdownSupportedKeyboardsKey;
	extern CFStringRef kLockdownSupportedLanguagesKey;
	extern CFStringRef kLockdownSupportedLocalesKey;
	extern CFStringRef kLockdownSupportsAccessibilityKey;
	extern CFStringRef kLockdownSyncDataClassDomainKey;
	extern CFStringRef kLockdownSyncSupportsCalDAV;
	extern CFStringRef kLockdownTimeIntervalSince1970Key;
	extern CFStringRef kLockdownTimeZoneKey;
	extern CFStringRef kLockdownTimeZoneOffsetFromUTCKey;
	extern CFStringRef kLockdownTotalDataAvailableKey;
	extern CFStringRef kLockdownTotalDataCapacityKey;
	extern CFStringRef kLockdownTotalDiskCapacityKey;
	extern CFStringRef kLockdownTotalSystemAvailableKey;
	extern CFStringRef kLockdownTotalSystemCapacityKey;
	extern CFStringRef kLockdownTrustedHostAttachedKey;
	extern CFStringRef kLockdownUniqueChipIDKey;
	extern CFStringRef kLockdownUniqueDeviceIDKey;
	extern CFStringRef kLockdownUnlockCodeKey;
	extern CFStringRef kLockdownUses24HourClockKey;
	extern CFStringRef kLockdownVoicemailUsageKey;
	extern CFStringRef kLockdownVoidWarrantyKey;
	extern CFStringRef kLockdownVolumeLimitKey;
	extern CFStringRef kLockdownWebAppCacheUsageKey;
	extern CFStringRef kLockdownWifiAddressKey;
	extern CFStringRef kLockdownWildcardTicketKey;
	extern CFStringRef kLockdowniTunesHasConnectedKey;
	extern CFStringRef kLockownSQLMusicLibraryPostProcessCommandsDomainKey;
	extern CFStringRef kLockdownBatteryCurrentCapacity;
	extern CFStringRef kLockdownBatteryIsCharging;
	extern CFStringRef kLockdownDeviceHandlesDefaultCalendar;
	extern CFStringRef kLockdownFairPlayRentalClockBias;
	extern CFStringRef kLockdownRemoveWiFiManagerLogs;
	extern CFStringRef kLockdownSupportsEncryptedBackups;	
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_2_1
	extern CFStringRef kLockdownActivationStateAcknowledgedKey;
	extern CFStringRef kLockdownDBVersionKey;
	extern CFStringRef kLockdownFamilyIDKey;
	extern CFStringRef kLockdownMinimumiTunesVersionKey;
	extern CFStringRef kLockdownMobileApplicationUsageKey;
	extern CFStringRef kLockdownSupportsCarrierBundleInstallKey;
	extern CFStringRef kLockdownUserPreferencesDomainKey;
	extern CFStringRef kLockdownUserSetLanguageKey;
	extern CFStringRef kLockdownUserSetLocaleKey;	
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_2_2
	extern CFStringRef kLockdownEnableLockdownExtendedLoggingKey;
	extern CFStringRef kLockdownEnableLockdownLogToDiskKey;
	extern CFStringRef kLockdownExtendedLoggingPrefKey;
	extern CFStringRef kLockdownLogToDiskPrefKey;
	extern CFStringRef kLockdownRemove8021XLogs;
	extern CFStringRef kLockdownRemoveLockdownLog;
	extern CFStringRef kLockdownRemoveVPNLogs;	
#else
	extern CFStringRef kLockdownCaptureSyslogKey;
	extern CFStringRef kLockdownLogToDiskKey;
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_0
	extern CFStringRef kLockdownAccessibilityLanguagesKey;
	extern CFStringRef kLockdownActivationPrivateKey;
	extern CFStringRef kLockdownActivationPublicKey;
	extern CFStringRef kLockdownAmountCameraUsageChangedKey;
	extern CFStringRef kLockdownBackupDomainKey;
	extern CFStringRef kLockdownBackupWillEncrypt;
	extern CFStringRef kLockdownBehaviorsValidKey;
	extern CFStringRef kLockdownCPUArchitectureKey;
	extern CFStringRef kLockdownChinaBrickKey;
	extern CFStringRef kLockdownDSPersonIDKey;
	extern CFStringRef kLockdownDiagnosticsAllowedKey;
	extern CFStringRef kLockdownEnableWiFiManagerLogsKey;
	extern CFStringRef kLockdownGoogleMailKey;
	extern CFStringRef kLockdownHardwareModelKey;
	extern CFStringRef kLockdownMLBSerialNumberKey;
	extern CFStringRef kLockdownNTSCKey;
	extern CFStringRef kLockdownNVRAMKey;
	extern CFStringRef kLockdownNoWiFiKey;	
	extern CFStringRef kLockdownProductionSOCKey;
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_1
	extern CFStringRef kLockdownAMRKey;
	extern CFStringRef kLockdownAudioCodecsKey;
	extern CFStringRef kLockdownDeviceSupportsClearingDataKey;
	extern CFStringRef kLockdownEnableLockdownNetworkConnectKey;
	extern CFStringRef kLockdownH263Key;
	extern CFStringRef kLockdownH264HKey;
	extern CFStringRef kLockdownH264MKey;
	extern CFStringRef kLockdownSNUMKey;
	extern CFStringRef kLockdownServiceToken;
	extern CFStringRef kLockdownVideoCodecsKey;
#else
	extern CFStringRef kLockdownAmountCameraReservedKey;
	extern CFStringRef kLockdownAmountSongsReservedKey;
#endif
	
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
	
	typedef void(*LockdownServiceCallback)(LcokdownServiceRef service, CFSocketCallBackType cbType, void* info);
	
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