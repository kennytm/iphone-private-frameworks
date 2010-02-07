/*

FILE_NAME ... DESCRIPTION
 
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

#ifndef TEXTINPUT_KBWORDTRIE_HPP
#define TEXTINPUT_KBWORDTRIE_HPP

#include "KBVector.hpp"
#include "KBHashmap.hpp"
#include "KBString.hpp"
#include "KBDataFile.hpp"
#include <JavaScriptCore/wtf/Vector.h>

namespace KB {
	
#pragma mark -
#pragma mark Sort Key Byte Converter
	
	class SortKeyByteConverter {
		virtual ~SortKeyByteConverter();
		void clear();
		
		String cached_compute_sort_key_for_letter(unsigned character);
		
		/// Load sort key converter form table.
		/// The format is:
		///    <unsigned-int = Number Of Entries>
		///    <null-terminated-string = Sort Key 1> <utf32-char = Letter 1>
		///    <null-terminated-string = Sort Key 2> <utf32-char = Letter 2>  ...
		/// Returns true if the loading succeeded. Each sort key should be 3 bytes long.
		/// The file is usually the .idx file, and the offset is 0x80.
		bool loadCommonLetterFormTable(ReadOnlyDataFile* file, unsigned offset);
		Vector<Pair<String, unsigned> > sortedLetterMappingList();
		void removeDigraphSortKeys();
		bool setLetterFormMapping(const String&, unsigned character);
		void printLetterMapping();
		
		void appendCompressPrimarySortKeyLetter(String&, unsigned char&, const String&) const;
		unsigned commonLetterFormTrackLeadPrimary(unsigned char, unsigned char&) const;
		int look_backwards_for_lead_primary(const String&) const;
		unsigned lettersForSortKey(const String&) const;
		bool isDigraphSortKey() const;
		
	private:
		static size_t g_num_three_byte_primary_sort_keys;
		static Hashmap<unsigned, String> g_cached_sort_keys_for_letter_forms;
		
		unsigned m_single_primaries_to_letter[256];
		uint8_t m_is_known_lead_primary[256];
		Hashmap<String, unsigned> m_sort_keys_to_letter_forms;
	};
	
#pragma mark -
#pragma mark Word
	
	class Word {
	public:
		static float One, Zero;
		static Word& empty_word();	///< Return a shared instance of empty word.
		
		void set_custom_capitalization();
		void move_capitalization_to_bits();
		void parse_substitution_list(ReadOnlyDataFile& dat_file, unsigned offset, const String& string, unsigned sort_key_length);
		String capitalized_string() const;
		
		Word();	///< Create an empty word.
		Word(const String& str);	///< Create a word with string.
		
		/// Read a word from a data file.
		/// The format is like this:
		///   <byte = h> [if h & 4, <byte = a if not flag & 512, a * 255 else>] [if h & 32, <byte = c>. If c & 1, cap_mask is set to 1]
		///      [if h & 1, <unsigned = cap_mask>] [if h & 64, <unsigned = d>] [if not flag & 2048 or h & 8 or c & 48, <unsigned short = SSSSSS.....KKKKK> ]
		///      [if h & 16, <null-terminated-string = string>, else if not h & 8, string = lettersForSortKey(sort_key), else parse_substitution_list(dat_file, "offset", ?, sort_key_length) ]
		Word(ReadOnlyDataFile& dat_file, unsigned offset, const String& sort_key, const SortKeyByteConverter&, unsigned compilation_flag);
		
		const String& string() const { return m_string; }
		float probability() const { return word.probability; }
		void set_probability(float new_prob) { word.probability = new_prob; }
		
	private:
		String m_string;
		struct {
			float probability; // 20
			unsigned b; // 24 
			unsigned c; // 28
			unsigned d; // 2c
			unsigned capitalization_mask; // 30. The n-th bit is on <=> the n-th character is upper-case.
			unsigned f; // 34
			float g; // 38
			unsigned char h; // 3c
		} word;
		
		void debug(const char* prefix = NULL) const {
			size_t sl = prefix ? strlen(prefix) : 0;
			char* more_prefix = (char*)malloc(sl+2);
			if (prefix != NULL)
				memcpy(more_prefix, prefix, sl);
			more_prefix[sl] = '\t';
			more_prefix[sl+1] = '\0';
			
			printf("(KB::Word) {\n");
			printf("%sstring:  ", more_prefix);
			m_string.debug(more_prefix);
			printf("%sprob:    %g,\n", more_prefix, word.probability);
			printf("%sb:       0x%x,\n", more_prefix, word.b);
			printf("%sc:       0x%x,\n", more_prefix, word.c);
			printf("%sd:       0x%x,\n", more_prefix, word.d);
			printf("%scapmask: 0x%x,\n", more_prefix, word.capitalization_mask);
			printf("%sf:       0x%x,\n", more_prefix, word.f);
			printf("%sg:       %g,\n", more_prefix, word.g);
			printf("%sh:       0x%x,\n", more_prefix, word.h);
			printf("%s}\n", prefix ?: "");
			
			free(more_prefix);
		}
	};
	
#pragma mark -
#pragma mark Packed Trie Sibling
	
	struct PackedTrieSibling {
		union {
			unsigned whole;
			struct {
				unsigned child_offset : 24;
				unsigned patricia_key_size_1 : 2;	// 0100_0000
				unsigned has_child_offset_type : 2;	// 0400_0000
				unsigned has_word_termination_prob : 1;	// 1000_0000
				unsigned has_unigram_list_offset : 1;	// 2000_0000
				unsigned has_freq : 1;	// 4000_0000
				unsigned more_siblings : 1;	// 8000_0000
			} v2fields;
			struct {
				unsigned child_offset_byte0 : 8;
				unsigned child_offset_byte1 : 8;
				unsigned child_offset_byte2 : 8;
				unsigned flags_byte : 8;
			} v2bytes;
		} sortNchild;
		union {
			unsigned whole;
			struct {
				unsigned word_offset : 23;
				unsigned word_is_0freq : 1;
				unsigned compacted_freq : 8;
			} fields;
			struct {
				unsigned child_offset_byte0 : 8;
				unsigned child_offset_byte1 : 8;
				unsigned child_offset_byte2 : 8;
				unsigned flags_byte : 8;
			} v2bytes;
		} freqNword;
		unsigned char patricia_key_bytes[4];
		
	private:
		const char* parse_trie_sibling_binary(const char* child, const char* data)	// returns the address of the next sibling.
#if 0
		{
			int cur_child_offset = child - data;
			
			this->sortNchild.v2bytes.flags_byte = *child++;
			
			for (unsigned i = 0; i <= this->sortNchild.v2fields.patricia_key_size_1; ++ i) {
				this->patricia_key_bytes[i] = *child++;
			}
			
			switch (this->sortNchild.v2fields.has_child_offset_type) {
				case 1:
					this->sortNchild.v2fields.child_offset = cur_child_offset + (*child++);
					break;
				case 2:
					this->sortNchild.v2fields.child_offset = cur_child_offset + unsigned_short_at(child);
					child += 2;
					break;
				case 3:
					// note: no addition.
					this->sortNchild.v2fields.child_offset = (read 3 bytes from child);
					child += 3;
					break;
			}
			
			if (has_freq bit is cleared) {
				this->freqNword.v2fields.compacted_freq = 0xff;
			} else {
				this->freqNword.v2fields.compacted_freq = 1 + *child++;
			}
			
			if (has_unigram_list_offset bit is cleared) {
				if (has_word_termination_prob bit is set) {
					this->freqNword.fields.word_offset = 1 + **child++
				}
			} else {
				this->freqNword.fields.word_[offset,is_0freq] = (read 3 bytes from child);
				child += 3;
			}
			
			if (more_sibling bit is set) {
				return child;
			} else
				return NULL;			
		}
#endif
		;
		
		bool finishesWords() const
#if 0
		{
			if (sortNchild.v2fields.child_offset != 0 || freqNword.fields.compacted_freq == 0 || freqNword.fields.word_is_0freq)
				return sortNchild.v2fields.has_word_termination_prob || sortNchild.v2fields.has_unigram_list_offset;
			else
				return true;
		}
#endif
		;
	};	
	
#pragma mark -
#pragma mark Word Trie
	
	class WordTrieNode;
	class DynamicTrieNode;	
	enum DynamicEntryType {};
	class WordTrie;
	
	template<typename V, typename T>
	class TrieArrayCache {
	private:
		T m_loaded_for_parent;
		int m_num_tags;
		unsigned char m_tag_list[256];
		V m_values[256];
		char* m_base_addr;
	};
	
	template<typename C, typename T>
	struct TrieArrayCacheSet {
		C root;
		C deep;
	};
	
	
	enum TrieSearchType {
		TrieSearchTypeExact,
		TrieSearchTypeFuzzy
	};
	
	class WordTrieSearch {
	private:
		void clear();
		bool matches(const String&, TrieSearchType);
		WordTrieSearch();
		~WordTrieSearch();
		WordTrieSearch& operator=(const WordTrieSearch&);
		
		WTF::Vector<WTF::RefPtr<WordTrieNode>, 0> m_states;
		TrieSearchType m_type;
		String m_string;
		String m_sort_key;
	};
	
	class DictionaryCursors {
	public:
		bool set_static_cursor(const PackedTrieSibling&, int value);
		void set_dynamic_cursor(const WTF::RefPtr<DynamicTrieNode>&, int, DynamicEntryType, int);
		void set_dynamic_ab_cursor(const WTF::RefPtr<DynamicTrieNode>&, int);
		void advance_patricia_key_byte();
		void set_dynamic_custom_cursor(const WTF::RefPtr<DynamicTrieNode>&, int);
		void printCursorOffsets(const char*, const String&, int, float) const;
		float staticPartialProbability() const;
		float dynamicPartialProbability() const;
		float advanceStaticCursorToSortKey(DictionaryCursors&, const WordTrie&, const String&, int) const;
		void fillVectorWithStaticTrieChildren(Vector<DictionaryCursors>&, const WordTrie&) const;
		void mergeDynamicSiblingKeysIntoVector(Vector<DictionaryCursors>&, DynamicEntryType) const;
		float dynamicPartialProbabilityForUsageCount(int, int);
	private:
		char a, b;
		int c, d;
		char e, f, g, h;
		int i, j;
		short k;
		char l, m;
	};
	
	class WordTrieNode {
	private:
		WordTrieNode(ReadOnlyDataFile* data_file, const char*, TrieSearchType type);
		WordTrieNode(ReadOnlyDataFile* data_file, unsigned int root_offset);
		WordTrieNode();
		
		WordTrieNode advance(unsigned char input, TrieSearchType search_type) const;
#if 0
		{
			const char* child_addr = this->trie_addr(this->sibling.child_offset);
			RefPtr<WordTrieNode> child_b = NULL;
			RefPtr<WordTrieNode> child_refptr = NULL;
			
			// begin:
			for (; child_addr != NULL && r6 != 256; ++ r6, child_addr = next_child_addr ) {
				
				PackedTrieSibling sibling;
				next_child_addr = sibling.parse_trie_sibling_binary(child_addr, data_file->m_data);
				
				char first_pat_char = sibling.pat_key[0];
				bool matches;
				TrieSearchType child_search_type;
				
				if (search_type == Exact) {
					matches = (first_pat_char == input);
					child_search_type = search_type;
				} else if (search_type == Fuzzy) {
					child_search_type = this->trie_search_type;
					if (this->trie_search_type != Fuzzy && first_pat_char == input)
						matches = true;
					else {
						matches = keyboard_sort_key_match(first_pat_char, input);
						child_search_type = Fuzzy;
					}
				} else {
					assert(false);
				}
				
				if (match) {
					RefPtr<WordTrieNode> child_a = WordTrieNode::create(this->data_file, child_addr, child_search_type);
					if (child_b == NULL) {
						child_refptr = child_a;
						child_b = child_refptr;
					} else {
						child_refptr->m = child_a;
						child_refptr = child_a;
					}
					// deref child_a.
				}
			}
			if (child_b == NULL)
				child_b = new WordTrieNode;
			return child_b;
			// deref stuff.
		}
#endif
		
		static WordTrieNode* create(ReadOnlyDataFile* data_file, const char*, TrieSearchType type);	///< Just calls the constructor.
		static WordTrieNode* create(ReadOnlyDataFile* data_file, unsigned int offset);	///< Just calls the constructor.
		bool not_valid(void) const;
		const char* trie_addr(unsigned int child_offset) const;	// returns : data_file->m_data + child_offset.
		
	private:
		int one;
		char b;
		ReadOnlyDataFile* data_file;
		const char* data_ptr;
		int parse_result;
		TrieSearchType trie_search_type;
		PackedTrieSibling sibling;
		WTF::RefPtr<WordTrieNode> m;
	};
	
	class WordTrie {
	public:
		void set_search(const String& str, TrieSearchType type = TrieSearchTypeExact);	///< Set the word trie to search for the string given.
		void init_search();
		
		void save_search();		///< Push the current search to stack.
		void restore_search();	///< Pop the last search from stack as current.
		
		static const unsigned kWordTrieHeaderSize, kWordTrieMagicNumber, kWordTrieMinimumMinorVersion, kWordTrieRequiredMajorVersion;
		
		String perform_match_check_on_words();
		void recurse_returning_words_with_constraints(Vector<Word>&, WordTrieNode*, int, unsigned, double, double&);
		
		bool load(const String& dat_file_name);
		void unload();
		
		// larger the number, longer the string can be.
		Vector<Word> words(int level, TrieSearchType type = TrieSearchTypeExact);
		Vector<Word> words(int, unsigned count, double);
		Vector<Word> words();
		Word lookup(const String&, TrieSearchType);
		
		WordTrie(const String& dat_file_name);
		WordTrie();
		~WordTrie();
		
		bool valid() const { return m_valid; }
		void* trie_root_addr() const {
			assert(valid());
			return m_index->data() + m_trie_root_offset;
		}
		void* trie_addr(unsigned offset) const {
			assert(valid());
			return offset == 0 ? NULL : m_index->data() + offset;
		}
		
		bool magic_number_ok(const ReadOnlyDataFile* file) const;	///< Check if the magic number of the file is OK. The data file should start with the bytes 00-00-00-01.
		bool dictionary_versions_ok(const ReadOnlyDataFile* file) const;
		
		Vector<Word> words_for_offset(unsigned, const String&) const;
		String string_matches_search(const String&) const;
		
		Vector<Word> derive_words_at_cursor(const DictionaryCursors&, const String&, const SortKeyByteConverter&) const;
		
		float probability_sum_for_V2_words_at(unsigned) const;
		
		void recurse_matching_words_for_node(Vector<Word>& res, WordTrieNode* node, unsigned offset, int the_int, bool perform_match) const;
		void fill_vector_with_trie_children_at(unsigned, Vector<DictionaryCursors>&) const;
		bool advance_static_cursor_to_next_patricia_node(DictionaryCursors& cursors, unsigned char tag, unsigned address) const;
		
		Word word_at(unsigned offset, unsigned& res_offset, const String& sort_key) const;
		
		
	private:
		ReadOnlyDataFile* m_index;	// 0
		ReadOnlyDataFile* m_words;	// 4
		unsigned m_word_count;	// 8
		WTF::RefPtr<WordTrieNode> m_root;	// c
		WordTrieSearch m_search;	// 10 (sizeof = 50)
		WordTrieSearch m_saved_search;	// 60 (sizeof = 50)
		bool m_returns_words_shorter_than_search;	// b0
		bool m_valid;	// b1
		TrieArrayCacheSet<TrieArrayCache<PackedTrieSibling, const char*>, const char*> m_trie_array_cache_set;	// b4 (sizeof = 1a18)
		unsigned m_compilation_flags;	// 1acc
		unsigned m_unigram_payload_offset;	// 1ad0
		unsigned m_trie_root_offset;	// 1ad4
		float m_root_usage_sum;	// 1ad8
		SortKeyByteConverter m_sort_key_converter;	// 1adc (sizeof = 524)
	};	// sizeof = 2000.
}

#endif