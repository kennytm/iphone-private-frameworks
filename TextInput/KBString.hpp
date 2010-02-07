/*

KBString.hpp ... Header for KB::String
 
Copyright (c) 2009, KennyTM~
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

#ifndef TEXTINPUT_KBSTRING_HPP
#define TEXTINPUT_KBSTRING_HPP

#include "KBVector.hpp"
#include <CoreFoundation/CoreFoundation.h>
#if __OBJC__
@class NSString;
#else
struct NSString;
#endif
#include <cstdio>
#include <stdint.h>

namespace KB {
	
	class String {
	public:
		enum StringBufferType {
			External,
			Internal
		};
		
		static uint16_t NotAnIndex;	///< The value returned when a search operation failed. Equivalent to 65535.
		
		String();	///< Create an empty string (with capacity = 16).
		String(const char* str);	///< Create a string from UTF-8 string.
		String(const char* str, uint16_t len);	///< Create a string from UTF-8 string with maximum length. Note: len must not be greater than strlen(str).
		String(const char* str, uint16_t len, uint16_t pos);	///< Create a string from UTF-8 string with maximum length starting from an offset.
		String(const String&);	///< Copy a string.
		String(unsigned character);	///< Create a string with the specific UTF-32 character.
		~String();	///< Destructor.
		
		/// Create a string with external/internal buffer.
		String(StringBufferType buffer_type, const char* data_file, uint16_t size, uint16_t length, uint16_t sort_key_length);
		
		/// Assignment operators.
		String& operator=(const char* str);
		String& operator=(const String& str);
		String& operator=(char character);
		
		/// Get the byte array starting from the specified position.
		char* operator[](uint16_t pos);
		const char* operator[](uint16_t pos) const;
		
		unsigned character_at(uint16_t pos) const;	/// Find the n-th Unicode character. Linear complexity.
		unsigned at(uint16_t) const;	///< Get the n-th code point.
		
		void append_byte(char);	///< Append a UTF-8 code point to the end of the string.
		void append_float(float);	///< Append a floating point number to the end of the string, formatted as %.2f.
		void append(const char* str);	///< Append a UTF-8 string to the end of the string.
		void append(const char* str, uint16_t len);	///< Append a UTF-8 string to the end of the string with a maximum length.
		void append(const String&);	///< Append another string to the end of this string.
		void append(unsigned character);	///< Append a UTF-32 character to the end of this string.
		
		/// Append a string.
		String& operator+=(const char* str);
		String& operator+=(const String& str);
		String& operator+=(unsigned character);
		
		/// Create a string by concatenate two strings together.
		String operator+(const char* str) const;
		String operator+(const String&) const;
		String operator+(unsigned character) const;
		
		void in_place_swap(char from, char to);	///< Change any code points "from" to that of "to".
		
		/// Compute the length of the string.
		/// Because the string is UTF-8 encoded, computing the length is has linear complexity.
		void compute_length();
		void compute_sort_key_length();	///< Compute the sort key length. See KB::compute_sort_key() for how the sort key is defined.
		uint16_t size_for_length(uint16_t len) const; ///< Compute the code point index corresponding to the n-th character.
		
		/// Ensure the string is enough to hold a string of size "min_size".
		/// If not, extra bytes will be reserved.
		void ensure_capacity(uint16_t min_size);
		
		/// Copy an external buffer.
		/// By internalizing, the UTF-8 buffer refered by this string will be free()-ed on the string's destruction.
		void internalize_buffer();
		
		void clear();	///< Clear the string.
		void resize(uint16_t new_len, char code_point = ' ');	///< Resize the string, pad with the specified code point.
		void reserve(uint16_t new_capacity);	///< Reserve bytes for at least the specified capacity.
		
		bool starts_with(const String& prefix, bool case_sensitive = true) const;	///< Test if the string starts with the specified prefix.
		bool ends_with(const String& suffix, bool case_sensitive = true) const;	///< Test if the string ends with the suffix.
		bool contains(const String& target) const;	///< Check if the string containts the target.
		
		int compare(const String&) const;	///< Compare with another string using strcmp().
		bool equal(const String&, bool case_sensitive = true) const;	///< Compare if two strings are equal
		
		uint16_t find_last_of(const String& target, uint16_t from = NotAnIndex) const;	///< Find the last code point index that at least one code point in the target appears, before the specified index.
		uint16_t find_first_of(const String& target, uint16_t from = 0) const;	///< Find the first code point index that that at least one code point in target appears, after the specified index.
		uint16_t find_last_not_of(const String& target, uint16_t from = NotAnIndex) const;	///< Find the last code point index that all code points in the target do not appear, before the specified index.
		uint16_t find_first_not_of(const String& target, uint16_t from = 0) const;	///< Find the first code point index that all code points in the target do not appear, before the specified index.
		
		String substr_to_pos(uint16_t pos) const;	///< Extract a subtring to the specified code point index.
		String substr_chopped(uint16_t len) const;	///< Extract a substring such that the last n code points are removed.
		String substr_from_pos(uint16_t pos) const;	///< Extract a subtring from the specified code point index.
		String substr(uint16_t pos, uint16_t len) const;	///< Extract a substring.
		
		String trim(const String& target) const;	///< Trim the string by removing all code points appearing in the target.
		
		/// Remove appearance of all code points in the target.
		/// Do not use this function on a string containing non-ASCII characters.
		String remove(const String& target) const;
		
		const char* buffer() const { return m_buffer ? m_buffer : m_static_buffer; }
		bool data_in_allocated_internal_buffer() const { return m_buffer_type == Internal && m_buffer != NULL; }
		uint16_t size() const { return m_size; }
		
	private:
		void initialize(const char* str, uint16_t pos, uint16_t len);	///< Initialize an allocated string to store a UTF-8 string with an offset and a maximal length.
		
		uint16_t m_size;	// Number of UTF-8 code points occupied by the string
		uint16_t m_capacity;	// Code point capacity of the string.
		uint16_t m_length;	// Length of the string (with unicode characters).
		uint16_t m_sort_key_length;	// 6
		uint8_t m_buffer_type;	// 8
		char* m_buffer;	// c
		char m_static_buffer[16];	// 10
		
		inline void debug(const char* prefix = "") const {
			printf("(KB::String) {\n");
			printf("%s\tm_size:            %u,\n", prefix, m_size);
			printf("%s\tm_capacity:        %u,\n", prefix, m_capacity);
			printf("%s\tm_length:          %u,\n", prefix, m_length);
			printf("%s\tm_sort_key_length: %u,\n", prefix, m_sort_key_length);
			printf("%s\tm_buffer_type:     %u,\n", prefix, m_buffer_type);
			printf("%s\tm_buffer:          \"%s\", // %p\n", prefix, m_buffer, m_buffer);
			printf("%s\tm_static_buffer:   \"%s\"\n", prefix, m_static_buffer);
			printf("%s}\n", prefix);
		}
		friend class Word;
	};
	
	/// Compute the sort key.
	/// The sort key is a string that can be sorted literally using memcmp().
	/// The sorting is variant-insensitive. For example, A, a, Â, ª all maps to the same key, and Æ is mapped to sort_key(A) + sort_key(E).
	/// This function only consider all alphanumeric symbols (0 - 9, A - Z, etc.) and currency symbols ($, ¢, etc.)
	/// The backend of this function is ICU's ucol_getSortKey().
	String compute_sort_key(const String&);
	
	CFStringRef cf_string(const String&);	///< Convert a KB string into a CFString. Follows Create rule.
	NSString* ns_string(const String&);	///< Convert a KB string into an NSString. The string is autoreleased.
	
	String string_join(const Vector<String>& components, const String& separator);	///< Join strings together.
	
#pragma mark String extensions
	
	/// The UTF8Iterator class can be used to traverse a String at amortized constant time, bidirectionally.
	class UTF8Iterator {
	public:
		unsigned next();	///< Get the next Unicode character. Returns 0 when the end is reached.
		unsigned prev();	///< Get the previous Unicode character. Returns 0 when the begin is reached.
		void reset();	///< Restart from the beginning.
		UTF8Iterator(const String& str);	///< Initiate a UTF-8 iterator by a _copy_ of the string.
	private:
		String m_string;
		uint16_t m_code_point_index;
		uint16_t m_character_index;
	};
	
	bool equal_utf8(const String& a, const String& b, bool case_sensitive = true);	///< Compare if two strings are equal using UTF8Iterator and ICU's u_tolower.
	bool starts_with_utf8(const String& str, const String& prefix, bool case_sensitive = true);
	bool prefixes_equal_utf8(const String& a, const String& b, int prefix_length, bool case_sensitive = true);	///< Check if two strings are equal up to a specific length.
	int string_compare_utf8(const String& a, const String& b);	///< Compare two strings.
	bool suffixes_equal_utf8(const String& a, int a_start_index, const String& b, int b_start_index);	///< Check if a.substr(a_start_index) == b.substr(b_start_index).
	
	size_t count_character_UTF8(const String& str, unsigned character);	///< Count number of appearance of a character in a string.
	size_t count_characters_UTF8(const String& str, unsigned offset, unsigned char1, unsigned char2);
	
	String format_url_if_needed(const String& str);
	
	unsigned atomize_stem(const String& str);
	
	String lower_string(const String&);	///< Get lower-case string.
	String upper_string(const String&);	///< Get upper-case string.
	String to_hex_string(const String&);	///< Convert to a hex string representing the UTF-8 code points.
	
	/// Returns true if each corresponding character in the string are neighbors on the QWERTY keyboard.
	/// For example, keyboard_match("ftyhvcb", "ggggggg") == true.
	bool keyboard_match(const String&, const String&);
	
	char convert_to_ascii(unsigned character);	///< Convert a Unicode character to ASCII. Can only deal with characters from 0xC0 (À) to 0x21b (ț). The rest will be treated as \0.
	bool character_is_digraph(unsigned character);	///< Check if a Unicode character is a digraph (only checks for œ, Œ, æ, Æ, ß, å, Å)
	String convert_to_ascii(String);	///< Convert a Unicode string to ASCII string.
	bool string_has_digraphs(const String&);	///< Check if a string contains any digraphs.
	bool strings_have_same_digraphs(const String& a, const String& b);
	
	size_t count_acute_accented_letters(const String& str);
	size_t count_caron_accented_letters(const String& str);
	bool string_has_separated_diacritics(const String& str);
	size_t count_precomposed_diacritic_letters(const String& str);
	bool string_has_precomposed_diacritic_letters(const String& str);
	bool strings_have_diacritics_in_same_positions(const String& a, const String& b);
	bool strings_have_same_precomposed_diacritic_letters(const String& a, const String& b);
	
	/// Split the string to a list, using any character in "seperator_list" as a separator.
	Vector<String> sbs_string_tokenize(const String& str, const String& seperator_list);

}

#endif