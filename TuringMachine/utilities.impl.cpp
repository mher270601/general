#ifndef __UTILITIES__IMPL__CPP__
#define __UTILITIES__IMPL__CPP__

#include <iostream>
#include <string>
#include <stdexcept>

namespace TuringMachine{

	size_t getRomanValueIndex(const char& value){
		switch(value){
		case 'I':
			return 0;
		break;
		case 'V':
			return 1;
		break;
		case 'X':
			return 2;
		break;
		case 'L':
			return 3;
		break;
		case 'C':
			return 4;
		break;
		case 'D':
			return 5;
		break;
		case 'M':
			return 6;
		break;
		default:
			std::string s = std::to_string(value - '0');
			throw std::invalid_argument("Invalid argument: " + s);
		break;
		}
		std::cout << "Error: should not reach here" << std::endl;
		return 9;
	}

	std::string getNextRomanValue(const char& value){
		switch(value){
		case 'I':
			return "V";
		break;
		case 'V':
			return "X";
		break;
		case 'X':
			return "L";
		break;
		case 'L':
			return "C";
		break;
		case 'C':
			return "D";
		break;
		case 'D':
			return "M";
		break;
		case 'M':
		default:
			std::string s = std::to_string(value - '0');
			throw std::invalid_argument("Invalid argument: " + s);
		break;
		}
		std::cout << "Error: should not reach here" << std::endl;
		return std::string("Invalid argument: overflow error: ") + __func__;
	}

} // namespace TuringMachine

#endif // __UTILITIES__IMPL__CPP__
