#ifndef __BOOK__HPP__
#define __BOOK__HPP__

#include <string>

#include "Price.hpp"
#include "IBook.hpp"
#include "ETypes.hpp"

class Book : public IBook{
public:
	Book(const BookName&, const AuthorName&, const ECategory&i, const Price&);
	std::string Name() const noexcept override;
	std::string authorName() const noexcept;
	ECategory category() const noexcept override;
	size_t getPrice() const noexcept;
private:
	std::string m_bookName{""};
	std::string m_authorName{""};
	ECategory m_category;
	Price m_price;
};
#include "Book.impl.cpp"
#endif // __BOOK__HPP__
