/*

KBHashmap.hpp ... Reverse engineering KB::Hashmap
 
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

#ifndef TEXTINPUT_KBHASHMAP_HPP
#define TEXTINPUT_KBHASHMAP_HPP

namespace KB {
	
	class String;
	
	/// A bucket.
	template<typename K, typename V>
	struct Bucket {
		K m_key;
		V m_value;
		Bucket<K,V>* m_next;
		
		Bucket(const K& key, const V& value) : m_key(key), m_value(value), m_next(NULL) {}
		~Bucket() {}
	};
	
	/// Compute hash.
	struct HashFunctions {
		static size_t hash(const char*);
		static size_t hash(const void*);
		static size_t hash(const String&);
		static size_t hash(int);
		static size_t hash(unsigned);
	};
	
	/// A pair of values.
	template<typename T1, typename T2>
	struct Pair {
		T1 first;
		T2 second;
		Pair(const T1& a, const T2& b) : first(a), second(b) {}
		~Pair() {}
	};
	
	/// A token for iterating the hash table.
	struct IteratorToken {
		size_t index;
		bool main;
		bool operator!=(const IteratorToken& other) const { return index != other.index || main != other.main; }
	};
	
	/// A hash table.
	/// The hash table stores values using linear probing. Table size is of the form 2^n * 1.25, starting from n = 7. (no, not prime numbers.)
	template<typename K, typename V>
	class Hashmap {
	private:
		static V& empty_value() {
			static V empty_value;
			return empty_value;
		}
		static K& empty_key() {
			static K empty_key;
			return empty_key;
		}
		
		/// Check if a bucket is filled.
		bool is_bucket_filled(Bucket<K,V>* bucket) const {
			static bool init = false;
			static char nil_bucket[sizeof(Bucket<K,V>)];
			if (!init) {
				std::memset(nil_bucket, 0, sizeof(Bucket<K,V>));
				init = true;
			}
			if (bucket == NULL)
				return false;
			return std::memcmp(nil_bucket, bucket, sizeof(Bucket<K,V>)) != 0;
		}
		
		/// Get a bucket from the extra table.
		Bucket<K,V>* take_extra() {
			for (int i = 0; i < std::min(m_extra_size, (size_t)7); ++ i) {
				int j = i + m_extra_index;
				while (j >= m_extra_size)
					j -= m_extra_size;
				
				Bucket<K,V>* extra = m_extra + j;
				if (!is_bucket_filled(extra)) {
					j = m_extra_index + 1;
					while (j >= m_extra_size)
						j -= m_extra_size;
					m_extra_index = j;
					return extra;
				}
			}
			return NULL;
		}
		
		/// Allocate N empty buckets.
		static Bucket<K,V>* allocate_fill(size_t count) {
			Bucket<K,V>* buckets = reinterpret_cast<Bucket<K,V>*>(std::malloc(count * sizeof(Bucket<K,V>)));
			std::memset(buckets, 0, count * sizeof(Bucket<K,V>));
			/*			for (int i = 0; i < s; ++ i) {
			 buckets[i].m_key = K();
			 buckets[i].m_value = V();
			 buckets[i].m_next = NULL;
			 } */
			return buckets;
		}
		
	public:
		/// Get a value from a key.
		V& get(const K& key) {
			static V value;
			Bucket<K,V>* bucket = m_table + (HashFunctions::hash(key) & (m_table_size - 1));
			while (is_bucket_filled(bucket)) {
				if (key == bucket->m_key)
					return bucket->m_value;
				else
					bucket = bucket->m_next;
			}
			return value;
		}
		
		/// Set a value for a key.
		void set(const K& key, const V& value) {
		set_again:
			Bucket<K,V>* bucket = m_table + (HashFunctions::hash(key) & (m_table_size - 1));
			if (!is_bucket_filled(bucket)) {
				if (bucket != NULL) {
					bucket->m_key = key;
					bucket->m_value = value;
					bucket->m_next = NULL;
				}
				++ m_size;
			} else {
				if (bucket->m_key == key)
					bucket->m_value = value;
				else {
					Bucket<K,V>* next_bucket = bucket->m_next, *prev_bucket = bucket;
					while (is_bucket_filled(next_bucket)) {
						if (bucket->m_key == key) {
							bucket->m_value = value;
							return;
						} else {
							prev_bucket = next_bucket;
							next_bucket = next_bucket->m_next;
						}
					}
					Bucket<K,V>* extra = take_extra();
					if (extra != NULL) {
						extra->m_key = key;
						extra->m_value = value;
						extra->m_next = NULL;
						prev_bucket->m_next = extra;
						++ m_size;
					} else {
						if (!m_rehashing) {
							rehash();
							goto set_again;
						}
						
						size_t old_extra_size = m_extra_size;
						m_extra_size *= 2;
						m_extra = reinterpret_cast<Bucket<K,V>*>(std::realloc(m_extra, m_extra_size * sizeof(Bucket<K,V>)));
						std::memset(m_extra + old_extra_size, 0, sizeof(Bucket<K,V>)*old_extra_size);
						/*						for (int i = old_extra_size; i < m_extra_size; ++ i) {
						 m_extra[i].m_key = K();
						 m_extra[i].m_value = V();
						 m_extra[i].m_next = NULL;
						 } */
						
						m_extra_index = old_extra_size + 1;
						m_extra[old_extra_size].m_key = key;
						m_extra[old_extra_size].m_value = value;
						m_extra[old_extra_size].m_next = NULL;
						prev_bucket->m_next = m_extra + old_extra_size;
						++ m_size;
					}
				}
			}
		}
		
	private:
		void set_sizes(size_t size) {
			m_table_size = size;
			m_extra_size = size / 4;
		}
		
	public:
		/// Default constructor.
		Hashmap() : m_size(0), m_capacity(128), m_table_size(0), m_extra_size(0), m_extra_index(0), m_rehashing(false), m_table(NULL), m_extra(NULL) {
			set_sizes(128);
			m_table = allocate_fill(m_table_size);
			m_extra = allocate_fill(m_extra_size);
		}
		
		/// Empty the hash table.
		void clear() {
			for (int i = 0; i < m_table_size; ++ i) {
				Bucket<K,V>* bucket = m_table + i;
				if (is_bucket_filled(bucket))
					bucket->~Bucket<K,V>();	// ??!
				std::memset(bucket, 0, sizeof(Bucket<K,V>));
			}
			for (int i = 0; i < m_extra_size; ++ i) {
				Bucket<K,V>* bucket = m_extra + i;
				if (is_bucket_filled(bucket))
					bucket->~Bucket<K,V>();
				std::memset(bucket, 0, sizeof(Bucket<K,V>));
			}
			m_extra_index = 0;
			m_size = 0;
		}
		
		/// Destructor.
		~Hashmap() {
			clear();
			if (m_table != NULL)
				std::free(m_table);
			if (m_extra != NULL)
				std::free(m_extra);
		}
		
		/// Rebuild the hash table.
		void rehash() {
			assert(!m_rehashing);
			m_rehashing = true;
			
			Bucket<K,V>* old_table = m_table;
			Bucket<K,V>* old_extra = m_extra;
			size_t old_table_size = m_table_size;
			size_t old_extra_size = m_extra_size;
			
			m_capacity *= 2;
			set_sizes(m_capacity);
			m_table = allocate_fill(m_table_size);
			m_extra = allocate_fill(m_extra_size);
			m_size = 0;
			m_extra_index = 0;
			
			for (int i = 0; i < old_table_size; ++ i) {
				Bucket<K,V>* bucket = old_table + i;
				if (is_bucket_filled(bucket))
					set(bucket->m_key, bucket->m_value);
			}
			for (int i = 0; i < old_extra_size; ++ i) {
				Bucket<K,V>* bucket = old_extra + i;
				if (is_bucket_filled(bucket))
					set(bucket->m_key, bucket->m_value);
			}
			std::free(old_table);
			std::free(old_extra);
			m_rehashing = false;
		}
		
		/// Remove a key from the hash table.
		void remove(const K& key) {
			Bucket<K,V>* bucket = m_table + (HashFunctions::hash(key) & (m_table_size - 1));
			Bucket<K,V>* first_bucket = bucket, *prev_bucket;
			
			while (is_bucket_filled(bucket)) {
				if (key == bucket->m_key) {
					if (bucket == first_bucket) {
						Bucket<K,V>* next_bucket = bucket->m_next;
						if (is_bucket_filled(next_bucket)) {
							*bucket = *next_bucket;
							next_bucket->~Bucket<K,V>();
							std::memset(next_bucket, 0, sizeof(Bucket<K,V>));
						} else {
							bucket->~Bucket<K,V>();
							std::memset(bucket, 0, sizeof(Bucket<K,V>));
						}
					} else {
						prev_bucket->m_next = bucket->m_next;
						bucket->~Bucket<K,V>();
						std::memset(bucket, 0, sizeof(Bucket<K,V>));
					}
					
					-- m_size;
					return;					
				} else {
					prev_bucket = bucket;
					bucket = bucket->m_next;
				}
			}
		}
		
		IteratorToken next_token(IteratorToken cur) const {
			IteratorToken retval;
			if (cur.main) {
				for (int i = cur.index+1; i < m_table_size; ++ i) {
					if (is_bucket_filled(m_table + i)) {
						retval.index = i;
						retval.main = true;
						return retval;
					}
				}
				if (is_bucket_filled(m_extra)) {
					retval.index = 0;
					retval.main = false;
					return retval;
				} else
					cur.index = 0;
			}
			int i;
			for (i = cur.index + 1; i < m_extra_size; ++ i)
				if (is_bucket_filled(m_extra + i))
					break;
			retval.index = i;
			retval.main = false;
			return retval;
		}
		
		IteratorToken begin_token() const {
			IteratorToken retval;
			retval.index = 0;
			retval.main = true;
			if (!is_bucket_filled(m_table))
				retval = next_token(retval);
			return retval;
		}
		
		Pair<K,V> entry_for_token(IteratorToken cur) const {
			Bucket<K,V>* bucket;
			if (cur.main)
				bucket = m_table + cur.index;
			else {
				if (cur.index >= m_extra_size)
					return Pair<K,V>(empty_key(), empty_value());
				else
					bucket = m_extra + cur.index;
			}
			return Pair<K,V>(bucket->m_key, bucket->m_value);
		}
		
		IteratorToken end_token() const {
			IteratorToken retval;
			retval.index = m_extra_size;
			retval.main = false;
			return retval;
		}
		
		
	private:
		size_t m_size;	// 0
		size_t m_capacity;	// 4
		size_t m_table_size;	// 8
		size_t m_extra_size;	// c
		size_t m_extra_index;	// 10
		bool m_rehashing;	// 14
		char m_traits;	// 15
		Bucket<K,V>* m_table;	// 18
		Bucket<K,V>* m_extra;	// 1c
	};

}

#endif