#!/usr/bin/env python3.1
#
#	test-compiler.py ... Convenient file to test and ensure all headers are compilable by each SDK.
#	Copyright (C) 2010  KennyTM~ <kennytm@gmail.com>
#
#	This program is free software: you can redistribute it and/or modify
#	it under the terms of the GNU General Public License as published by
#	the Free Software Foundation, either version 3 of the License, or
#	(at your option) any later version.
#
#	This program is distributed in the hope that it will be useful,
#	but WITHOUT ANY WARRANTY; without even the implied warranty of
#	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#	GNU General Public License for more details.
#
#	You should have received a copy of the GNU General Public License
#	along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

from os import listdir, fdopen, system, remove, close
from os.path import isdir, exists, join
from subprocess import Popen, PIPE, STDOUT
import sys

if len(sys.argv) > 1:

	sdk = '/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS{0}.sdk'.format(sys.argv[1])
	if not isdir(sdk):
		print ("Error: {0} is not a valid directory.".format(sdk))
		
	else:
		content = []
		for dirname in listdir('.'):
			if dirname[0].isupper() and isdir(dirname):
				mainname = join(dirname, dirname + '.h')
				if exists(mainname):
					content.append('#import <{0}>'.format(mainname))
			elif dirname[-2:] == '.h':
				content.append('#import <{0}>'.format(dirname))
		content_string = "\n".join(content).encode()
	
		for language in ('objective-c', 'objective-c++'):
			args = ['/Developer/Platforms/iPhoneOS.platform/Developer/usr/bin/gcc-4.2',
				'-c',
				'-std=c99',
				'-isysroot',
				sdk,
				'-I/Developer/Platforms/iPhoneOS.platform/Developer/usr/include/gcc/darwin/default',
				'-I{0}/usr/lib/gcc/arm-apple-darwin9/4.2.1/include'.format(sdk),
				'-F{0}/System/Library/PrivateFrameworks/'.format(sdk),
				'-I.',
				'-I_fallback',
				'-Wall',
				'-Wextra',
				'-o',
				'-',
				'-miphoneos-version-min={0}'.format(sys.argv[1]),
				'-x',
				language,
				'-arch',
				'armv7',
				'-']
			
			print('Language:', language)
			print()
			
			p = Popen(args, stdin=PIPE, stderr=STDOUT, close_fds=True)
			p.communicate(input=content_string)
			if p.returncode:
				break
				
else:
	print ("Usage: {0} <sdk-ver>".format(sys.argv[0]))
