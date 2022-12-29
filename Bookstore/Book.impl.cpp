#ifndef __BOOK__IMPL__CPP__
#define __BOOK__IMPL__CPP__

#include <string>

#include "Price.hpp"
#include "ETypes.hpp"

// Book
Book::Book(const BookName& bookName, const AuthorName& authorName, const ECategory& category, const Price& price) : m_bookName(bookName.m_name),
	  m_authorName(authorName.m_name),
  	  m_category(category),
	  m_price(price)
{
		
} // Book

inline std::string Book::Name() const noexcept{
	return m_bookName;
} // Name

inline std::string Book::authorName() const noexcept{
	return m_authorName;
} // authorName

inline ECategory Book::category() const noexcept{
	return m_category;
} // category

inline size_t Book::getPrice() const noexcept{
	return m_price.price;
} // getPrice
#endif // __BOOK__IMPL__CPP__
