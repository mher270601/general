#ifndef __IPRODUCT__HPP__
#define __IPRODUCT__HPP__

#include <string>

#include "IObject.hpp"

class IProduct : public IObject{
public:
	virtual std::string Type() const noexcept = 0;
	virtual size_t getPrice() const noexcept = 0;
};

#endif // __IPRODUCT__HPP__
