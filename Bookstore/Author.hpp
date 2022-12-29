#ifndef __AUTHOR__HPP__
#define __AUTHOR__HPP__

#include <string>

#include "Price.hpp"
#include "IBook.hpp"
#include "ETypes.hpp"

class Author : public IAuthor{
public:
	Author(const AuthorName&, const BookName&);
	std::string Name() const noexcept override;
	void PrintBooks() const noexcept override;
	void AddBook(const std::shared_ptr<IBook>&) override;
	void CheckAndRemoveBook(const std::string&) override;
private:
	std::string m_authorName{""};
	std::vector<BookName> m_books;
};

#include "Author.impl.cpp"

#endif // __AUTHOR__HPP__
