/*

KBDataFile.hpp ... Header for KB::DataFile
 
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

#ifndef TEXTINPUT_KBDATAFILE_HPP
#define TEXTINPUT_KBDATAFILE_HPP

#include <fcntl.h>
#include "KBString.hpp"

namespace KB {
	
	class DataFile {
	public:
		DataFile();
		DataFile(const char* filename, int oflag, int mode = 0);	///< Open a data file. This constructor is just a front-end of POSIX's open().
		~DataFile();
		
		bool valid() { return m_file_opened; }
		
	protected:
		int m_oflag;			// 0
		int m_mode;		// 4
		bool m_file_opened;	// 8
		int m_file_handle;		// c
		const char* m_filename;	// 10
	};
	
	class WritableDataFile : public DataFile {
	public:
		enum Flags {
			NonBlocking = O_NONBLOCK,
			Append = O_APPEND,
			Create = O_CREAT,
			Truncate = O_TRUNC,
			Excl = O_EXCL,
			SharedLock = O_SHLOCK,
			ExclusiveLock = O_EXLOCK,
			NoFollow = O_NOFOLLOW,
			Symlink = O_SYMLINK
		};
		
		WritableDataFile();
		WritableDataFile(const char* filename, Flags flags);
		~WritableDataFile();
		
		void write_data(const char* data, int length);	///< Write unformatted data.
		void write_unsigned_char(unsigned char);	///< Write a byte.
		void write_unsigned_short(unsigned short);	///< Write an unsigned short interger as Big Endian.
		void write_unsigned_int(unsigned int);	///< Write an unsigned integer as Big Endian.
		void write_unsigned_float(float);	///< Write a floating point number in machine encoding.
		void write_string(const String&, bool appendNull = false);	///< Write a string.
		void write_string(const char*, bool appendNull = false);	///< Write a UTF-8 string.
	};
	
	class MappedDataFile : public DataFile {
	public:
		MappedDataFile();
		MappedDataFile(const char* filename, int oflag, mode_t mode, int protection_mode);	///< Open a file and map to memory with mmap().
		~MappedDataFile();
		
		void sync();	///< Synchronize the mapped memory region to the file.
		void map(void*);	///< Remap the file to the specified memory address.
		bool resize(int);	///< Resize the mapped region.
		
		const char* data() const { return m_data; }
		char* data() { return m_data; }
		
	protected:
		size_t m_length;		// 14
		size_t m_map_size;		// 18
		int m_protection_mode;	// 1c
		bool m_need_sync;		// 20
		char* m_data;			// 24
	};
	
	class ReadOnlyDataFile;
	void null_parser(const ReadOnlyDataFile&, Vector<char*>&);	///< A parser that does nothing.
	
	class ReadOnlyDataFile : public MappedDataFile {
	public:
		ReadOnlyDataFile();
		ReadOnlyDataFile(const char* filename, void(*parser)(const ReadOnlyDataFile&, Vector<char*>&) = NULL);
		~ReadOnlyDataFile();
		
		float read_float(unsigned offset);	///< Read a float at offset.
		unsigned read_unsigned_int(unsigned offset);	///< Read an unsigned integer at offset.
		unsigned char read_unsigned_char(unsigned offset);	///< Read an unsigned char at offset.
		unsigned short read_unsigned_short(unsigned offset);	///< Read an unsigned short at offset.
		String read_null_terminated_string(unsigned offset);	///< Read a NULL-terminated string at offset.
	protected:
		void (*m_parser)(const ReadOnlyDataFile&, Vector<char*>&);	// 28
		int m_parsed_data_capacity;	// 2c
		char** m_parsed_data;		// 30		
	};	
}

#endif