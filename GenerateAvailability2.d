/*

GenerateAvailability2.d ... Generate <Availability2.h>
Copyright (C) 2009  KennyTM~ <kennytm@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

import std.stdio;
import std.algorithm;
import std.string;
import std.array;
import std.conv;

int versToInt(string vers) {
	auto s = vers.split(".");
	auto major = to!int(s[0]), minor = to!int(s[1]);
	return major * 10000 + minor * 100;
}

void main (string[] argv) {
	if (argv.length == 1) {
		writeln("Usage: GenerateAvailability2 2.0 2.1 2.2 3.0 3.1 4.0 ...");
	} else {
		auto args = argv[1..$];
		sort(args);
		auto vers = map!(`"__IPHONE_" ~ replace(a, ".", "_")`, versToInt)(args);
		
		writeln("#ifndef AVAILABILITY2_H\n#define AVAILABILITY2_H\n#include <Availability.h>\n");
		
		auto isFirst2 = true;
		foreach (v; vers) {
			if (isFirst2) {
				isFirst2 = false;
				continue;
			}
			
			auto vs = v.field[0];
			
			writeln("#ifndef ", vs);
			writeln(" #define ", vs, " ", v.field[1]);
			writeln(" #define __AVAILABILITY_INTERNAL", vs, " __AVAILABILITY_INTERNAL_UNAVAILABLE");
			writeln(" #define __AVAILABILITY_INTERNAL", vs, "_DEP__IPHONE_NA __AVAILABILITY_INTERNAL", vs);
			
			auto isElsif = false, isFirst = true;
			foreach (v2; vers) {
				if (isFirst) {
					isFirst = false;
					continue;
				}
				auto v2s = v2.field[0];
				writeln(isElsif?" #elif":" #if", " __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE", v2s);
				isElsif = true;
				foreach (v3; vers)
					writeln("  #define __AVAILABILITY_INTERNAL", v3.field[0], "_DEP", vs, v3.field[1] < v2.field[1] ? "" : " __AVAILABILITY_INTERNAL_WEAK_IMPORT");
				if (v.field[1] <= v2.field[1])
					break;
			}
			writeln(" #else");
			foreach (v3; vers)
				writeln("  #define __AVAILABILITY_INTERNAL", v3.field[0], "_DEP", vs, " __AVAILABILITY_INTERNAL_DEPRECATED");
			writeln(" #endif");
			writeln("#endif");
		}
		
		writeln("\n#endif");
	}
}