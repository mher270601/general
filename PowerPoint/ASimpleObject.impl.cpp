#ifndef __ASIMPLEOBJECT__IMPL__CPP__
#define __ASIMPLEOBJECT__IMPL__CPP__

#include <string>

#include "UniqueIdGenerator.hpp"

namespace PowerPoint{

	ASimpleObject::ASimpleObject(const std::string& objectName) : m_name(objectName), m_Identifier(UniqueIdGenerator::GenerateId()){
	}

	inline std::string ASimpleObject::getName() const noexcept{
		return m_name;
	}
	
	inline size_t ASimpleObject::GetId() const noexcept{
		return m_Identifier;
	}
	
	ASimpleObject::~ASimpleObject(){
	} // Defining dtor for define ISimpleObject as an abstract class

} // namespace PowerPoint

#endif // __ASIMPLEOBJECT__IMPL__CPP__
