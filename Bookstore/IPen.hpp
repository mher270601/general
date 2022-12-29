#ifndef __IPEN__HPP__
#define __IPEN__HPP__

#include <string>

#include "IProduct.hpp"

class IPen : public IProduct{
public:
	virtual std::string Type() const noexcept = 0;
	virtual size_t getPrice() const noexcept = 0;
private:

};
#endif // __IPEN__HPP__
