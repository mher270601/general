#ifndef __UNIQUE__ID__GENERATOR__HPP__
#define __UNIQUE__ID__GENERATOR__HPP__

#include <sstream>

class UniqueIdGenerator{
public:
	UniqueIdGenerator();
	static size_t GenerateId();
private:
	static size_t m_counter;
};

#include "UniqueIdGenerator.impl.cpp"

#endif // __UNIQUE__ID__GENERATOR__HPP__
