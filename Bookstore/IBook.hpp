#ifndef __IBOOK__HPP__
#define __IBOOK__HPP__

#include "IObject.hpp"

class IBook : public IObject{
public:
	virtual std::string authorName() const noexcept = 0;
	virtual ECategory category() const noexcept = 0;
	virtual size_t getPrice() const noexcept = 0;
private:

};
#endif // __IBOOK__HPP__
