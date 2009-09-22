/*
 
FILE_NAME ... FILE_DESCRIPTION

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

#ifndef CPCITY_H
#define CPCITY_H

#include <CoreFoundation/CoreFoundation.h>

#if __cplusplus
extern "C" {
#endif
	/*! A "city" is in fact an array with 11 strings. The content are, in order:
	 0. latitude [i.e. N/S]
	 1. longitude [i.e. E/W]
	 2. <?>
	 3. time zone
	 4. country code, if any
	 5. localized city name
	 6. localized country name
	 7. city name
	 8. country name
	 9. identifier
	 10. an empty array?
	 */

	typedef CFArrayRef CPCityRef;
	
	/// Get the array of all recognized cities. There are 324 cities in iPhoneOS 3.1. This list can be copied from AppSupport.framework/all_cities_adj.plist
	CFArrayRef CPGetCityList();
	
	/// Check if the city object is valid.
	Boolean CPIsArrayValidCity(CPCityRef city);
	
	/// Get the identifier of a city. The identifier is a string like "Yaounde, Cameroon". 
	CFStringRef CPCityGetIdentifier(CPCityRef city);
	
	/// Get the timezone of a city. The timezone is a string like "Africa/Douala". This string can be passed to CFTimeZoneCreateWithName.
	CFStringRef CPCityGetTimeZoneFile(CPCityRef city);
	
	/// Get the localized country name, e.g. "Cameroun" (the current localization is French).
	CFStringRef CPCityGetLocalizedCountryName(CPCityRef city);
	
	/// Get the localized city name, e.g. "Yaoundé".
	CFStringRef CPCityGetLocalizedCityName(CPCityRef city);
	
	/// Copy the name of the city that can represent the locale, e.g. the city for "fr_FR" is Paris. The correspondance is given by AppSupport.framework/DefaultCities.plist.
	CFStringRef CPCopyCityNameForLocale(CFLocaleRef locale);
	
	/// Create a timezone object of the city.
	CFTimeZoneRef CPCreateTimeZoneForCityArray(CPCityRef city);
	
	/// Get the dictionary that maps a timezone string to a representing city. This list can be copied from AppSupport.framework/timezoneToCity.plist
	CFDictionaryRef CPGetTimezoneToCityDictionary();
	
	/// Find the city that matches the identifier exactly.
	CPCityRef CPCopyCityForIdentifier(CFStringRef identifier);
	
	/// Find a city that have the specified name.
	CPCityRef CPCopyFirstCityWithName(CFStringRef name);
	
	/// Returns an array of cities matching the specified term, e.g. matching for "Y" gives New York, Yakutsk, Yamoussoukro, Yaounde, Yekaterinburg & Yerevan.
	CFArrayRef CPCopyCitiesMatching(CFStringRef match);
	
	/// Copy the representing city of the timezone object.
	CPCityRef CPCopyCityForTimeZone(CFTimeZoneRef timezone);
	
#if __cplusplus
}
#endif

#endif