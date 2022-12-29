#ifndef __AUTHOR__IMPL__CPP__
#define __AUTHOR__IMPL__CPP__

#include <algorithm>
#include <string>

#include "utility.hpp"
#include "Price.hpp"

// Author
Author::Author(const AuthorName& authorName, const BookName& bookName) : 
			m_authorName (authorName.m_name)
{
	m_books.push_back(bookName);
} // Author

inline std::string Author::Name() const noexcept{
	return m_authorName;
} // Name

inline void Author::AddBook(const std::shared_ptr<IBook>& book){
	m_books.push_back(BookName(book->Name()));
} // AddBook

void Author::CheckAndRemoveBook(const std::string& _bookName){
	for(size_t i = 0; i < m_books.size(); ++i){
		std::string BName = m_books[i].m_name;
		std::transform(BName.begin(), BName.end(), BName.begin(), ::toupper);
		if(_bookName == BName){
			m_books.erase(m_books.begin() + i);
		}	
	}
} // CheckAndRemoveBook

void Author::PrintBooks() const noexcept{
	std::cout << YELLOW << "\t" << m_authorName << RESET << std::endl;
	for(const auto& book : m_books){
		std::cout << BLUE << book.m_name << RESET << std::endl;
	}
} // PrintBooks
#endif // __AUTHOR__IMPL__CPP__
