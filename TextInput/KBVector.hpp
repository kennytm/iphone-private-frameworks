/*

KBVector.hpp ... Reverse engineered version of KB::Vector
 
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

#ifndef TEXTINPUT_KBVECTOR_HPP
#define TEXTINPUT_KBVECTOR_HPP

#include <algorithm>
#include <cassert>

namespace KB {

	template<typename T>
	class Vector {
	private:
		/// Return the value representing the NULL of type T.
		static T& null_value() {
			static T __null_value = T();
			return __null_value;
		}
		
	public:
		/// Return the number of elements of the vector.
		size_t size() const { return m_size; }
		
	private:
		/// Fill a range with null value.
		void fill(size_t start, size_t length) {
			memset(m_elements+start, 0, length*sizeof(*m_elements));
			for (size_t i = 0; i < length; ++ i)
				m_elements[start + i] = null_value();
		}
		
		/// Ensure the vector has enough capacity. Enlarge if not.
		void ensure_capacity(size_t capacity) {
			if (m_capacity < 6)
				m_capacity = 6;	// o_O Why 6
			if (m_elements != NULL && m_capacity >= capacity)
				return;
			
			while (m_capacity < capacity)
				m_capacity *= 2;
			
			size_t elements_to_fill, offset_to_fill; 
			if (m_elements != NULL) {
				m_elements = reinterpret_cast<T*>(std::realloc(m_elements, m_capacity * sizeof(T)));
				offset_to_fill = m_size;
				elements_to_fill = m_capacity - m_size;
			} else {
				m_elements = reinterpret_cast<T*>(std::malloc(m_capacity * sizeof(T)));
				offset_to_fill = 0;
				elements_to_fill = m_capacity;
			}
			fill(offset_to_fill, elements_to_fill);
		}
		
	public:
		/// Reserve enough elements for the vector.
		void reserve(size_t capacity) { ensure_capacity(capacity); }
		
		/// Empty the vector.
		void clear() {
			if (m_elements != NULL) {
				for (size_t i = 0; i < m_size; ++ i)
					m_elements[i] = null_value();
				m_size = 0;
			} else {
				assert(m_size == 0);
			}
		}
		
		/// Push an element to the end of vector.
		void push_back(const T& elem) {
			ensure_capacity(m_size + 1);
			m_elements[m_size] = elem;
			++ m_size;
		}
		
		/// Create a vector with some capacity.
		Vector(size_t capacity = 32) : m_size(0), m_capacity(0), m_elements(NULL) {
			reserve(capacity);
		}
		
		/// Destructor.
		~Vector() {
			clear();
			if (m_elements != NULL)
				std::free(m_elements);
			m_elements = NULL;
		}
		
		/// Get the i-th element.
		T& operator[](size_t i) { return (i >= m_size) ? null_value() : m_elements[i]; }
		const T& at(size_t i) const { return (i >= m_size) ? null_value() : m_elements[i]; }
		const T& operator[](size_t i) const { return at(i); }
		
		/// Insert an element after a specific index. Resize if necessary.
		void insert_at(size_t i, const T& element) {
			ensure_capacity(m_size + 1);
			if (i > m_size)
				m_size = i+1;
			else {
				size_t elements_to_move = m_size - i;
				if (elements_to_move != 0) {
					std::memmove(m_elements + i + 1, m_elements + i, elements_to_move*sizeof(T));
					std::memset(m_elements + i, 0, sizeof(T));
				}
				++ m_size;
			}
			m_elements[i] = element;
		}
		
		/// Remove an element.
		void remove_at(size_t i) {
			if (i >= m_size) return;
			size_t elements_to_move = m_size - i - 1;
			if (elements_to_move != 0) {
				std::memcpy(m_elements + i, m_elements + i + 1, elements_to_move * sizeof(T));
				std::memset(m_elements + m_size, 0, sizeof(T));
			} else
				m_elements[i] = null_value();
			-- m_size;
		}
		
	private:
		size_t quick_sort_partition(T* elements, size_t low, size_t high, size_t pivot, int(*compare)(const T&, const T&)) {
			// Note: I don't know wtf is Apple doing in quick_sort_partition, there's too much code. So I just copy the partition algorithm from Wikipedia.
			T pivot_value = elements[pivot];
			std::swap(elements[pivot], elements[high]);
			size_t new_pivot = low;
			for (size_t i = low; i < high; ++ i)
				if (compare(elements[i], pivot_value) < 0) {
					std::swap(elements[i], elements[new_pivot]);
					++ new_pivot;
				}
			std::swap(elements[new_pivot], elements[high]);
			return new_pivot;
		}
		
		void quick_sort(T* elements, size_t low, size_t high, int(*compare)(const T&, const T&)) {
			while (true) {
				if (low >= high)
					return;
				
				size_t new_pivot = quick_sort_partition(elements, low, high, (low+high)/2, compare);
				
				if (new_pivot != 0)
					quick_sort(elements, low, new_pivot-1, compare);
				
				if (new_pivot >= m_size-1)
					low = new_pivot + 1;
				else
					break;
			}
		}
		
	public:
		/// Sort the vector using Quick Sort.
		void sort(int(*compare)(const T&, const T&)) {
			if (m_size > 1)
				quick_sort(m_elements, 0, m_size-1, compare);
		}
		
		/// Turn all elements with index >= from to null.
		void trim(size_t from) {
			for (size_t i = from; i < m_size; ++ i)
				m_elements[i] = null_value();
		}
		
		/// Append another vector to the end of this vector.
		void concat(const Vector<T>& other) {
			for (size_t i = 0; i < other.m_size; ++ i)
				push_back(other[i]);
		}
		
		/// Resize the vector (cannot increase the size).
		void resize(size_t new_size) {
			if (new_size == m_size)
				return;
			else if (new_size < m_size) {
				m_size = new_size;
				return;
			} else {
				ensure_capacity(new_size);
			}
		}
		
		/// Set at element at index, enlarge the vector if necessary.
		void set_at(size_t i, const T& element) {
			if (i >= m_size) {
				ensure_capacity(i + 1);	
				m_size = i + 1;
			}
			m_elements[i] = element;
		}
		
		/// Copy from a raw array. Assume count <= m_size.
		void copy_from(T* raw, size_t count) {
			fill(0, m_size);
			for (size_t i = 0; i != count; ++ i)
				m_elements[i] = raw[i];
		}
		
		/// Copy constructor.
		Vector(const Vector<T>& other) : m_size(other.m_size), m_capacity(0), m_elements(NULL) {
			ensure_capacity(other.m_capacity);
			if (m_size == 0)
				return;
			copy_from(other.m_elements, m_size);
		}
		
		/// Assignment operator.
		Vector<T>& operator=(const Vector<T>& other) {
			if (this != &other) {
				clear();
				m_size = other.m_size;
				ensure_capacity(other.m_capacity);
				if (m_size != NULL)
					copy_from(other.m_elements, m_size);
			}
			return *this;
		}
		
		/// Remove the last element.
		void pop_back() {
			if (m_size == 0)
				return;
			-- m_size;
			m_elements[m_size] = null_value();
		}
		
		// Vector<T> subvector(size_t start, size_t count) const;
		
		/// Copy the last element.
		T back() const {
			return T(m_size != 0 ? m_elements[m_size-1] : null_value());
		}
		
		typedef const T* const_iterator;
		typedef T* iterator;
		
		const_iterator begin() const { return m_elements; }
		const_iterator end() const { return m_elements + m_size; }
		const_iterator cbegin() const { return m_elements; }
		const_iterator cend() const { return m_elements + m_size; }
		iterator begin() { return m_elements; }
		iterator end() { return m_elements + m_size; }
		
	private:
		size_t m_size;	// 0
		size_t m_capacity;	// 4
		T* m_elements;	// 8
	};

}

#endif