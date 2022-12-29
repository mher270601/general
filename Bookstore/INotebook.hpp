#ifndef __INOTEBOOK__HPP__
#define __INOTEBOOK__HPP__

#include <string>

#include "IProduct.hpp"

class INotebook : public IProduct{
public:
	virtual std::string Type() const noexcept = 0;
	virtual size_t getPrice() const noexcept = 0;
private:

};
#endif // __INOTEBOOK__HPP__
