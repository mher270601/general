#ifndef __READ__FROM__FILE__HPP__
#define __READ__FROM__FILE__HPP__

#include <cstring>
#include <fstream>

	std::string getLine(std::fstream& file) noexcept{
		std::string lExpr;
		std::getline(file, lExpr);
		return lExpr;
	}

#endif // __READ__FROM__FILE__HPP__
