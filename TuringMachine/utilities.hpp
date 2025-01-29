#ifndef __UTILITIES__HPP__
#define __UTILITIES__HPP__

#include <iostream>
#include <string>

namespace TuringMachine{

	size_t getRomanValueIndex(const char& value);
	std::string getNextRomanValue(const char& value);

} // namespace TuringMachine

#include "utilities.impl.cpp"

#endif // __UTILITIES__HPP__
