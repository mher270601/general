#ifndef __IAUTHOR__HPP__
#define __IAUTHOR__HPP__

#include <string>

#include "IObject.hpp"

class IAuthor : public IObject{
public:
	virtual void PrintBooks() const noexcept = 0;
	virtual void AddBook(const std::shared_ptr<IBook>&) = 0;
	virtual void CheckAndRemoveBook(const std::string&) = 0;
private:

};
#endif // __IAUTHOR__HPP__
