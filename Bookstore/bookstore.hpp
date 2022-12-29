#ifndef __BOOKSTORE__HPP__
#define __BOOKSTORE__HPP__

#include <cassert>
#include <map>
#include <memory>
#include <vector>
#include <string>
#include <string.h>

#include "ETypes.hpp"
//#include "IObservable.hpp"
//#include "IObject.hpp"
//#include "IBook.hpp"
//#include "IAuthor.hpp"
#include "IBookStore.hpp"
#include "Book.hpp"
#include "Author.hpp"
#include "fileManager.hpp"

//sql::mysql::MySQL_Driver *driver;
//sql::Connection *con;
//sql::ConnectOptionsMap connection_properties;
//
//// Create a connection
//driver = sql::mysql::MySQL_Driver::get_mysql_driver_instance();
//con = driver->connect();

//template <typename T>
//class IObservable{
//public:
//	//virtual void FieldChanged(const T&, const std::string&);
//private:
//};

//class IObject : public IObservable<IObject>{
//public:
//	virtual std::string Name() const noexcept = 0;
//	//virtual std::string authorName() const noexcept = 0;
//protected:
//	//std::string m_authorName{""};
//};

//class IBook : public IObject{
//public:
//	virtual std::string authorName() const noexcept = 0;
//	virtual ECategory category() const noexcept = 0;
//private:
//
//};

//class IAuthor : public IObject{
//public:	 // TODO
//	virtual void PrintBooks() const noexcept = 0;
//	virtual void AddBook(const std::shared_ptr<IBook>&) = 0;
//	//virtual void print() = 0;
//private:
//
//};

/*template <typename T>*/
//class IBookStore{
//public:
//
//	virtual void AddBookInStore(const std::shared_ptr<IBook>& /*book*/) = 0;
//
//	virtual void RemoveBookFromStore(const std::shared_ptr<IBook>& /*book*/) = 0;
//	virtual void PresentIn(const EPresentIn&) const noexcept = 0;
//protected:
//	// HELPERS
//	virtual bool CheckAuthor(const std::shared_ptr<IAuthor>&) const noexcept = 0;
//	virtual bool CheckBook(const std::shared_ptr<IBook>&) const noexcept = 0;
////private:
//}; // Interface IBookStore (IObserver)

//class IBookStore : public IObserver/*<IObject>*/{
//public:
//	void AddBookInStore(const std::shared_ptr<IBook>& /*book*/) override;
//	void AddAuthorInStore(const std::shared_ptr<IAuthor>& /*author*/) override;
//	void RemoveBookFromStore(const std::shared_ptr<IBook>& /*book*/) override;
//	//void FieldChanged(const IObject&, const std::string&);
//protected:
//	bool CheckAuthor(const std::shared_ptr<IAuthor>&);
//	bool CheckBook(std::shared_ptr<IBook>&);
//
//private:
//	std::map<std::shared_ptr<IAuthor>, std::vector<std::string>> m_data;
//	std::vector<std::shared_ptr<IBook>> m_books;
//	std::vector<std::shared_ptr<IAuthor>> m_authors;
//};


class BookStore : public IBookStore{
public:	
	void AddBookInStore(const std::shared_ptr<IBook>& /*book*/) override;
	void RemoveBookFromStore(const std::shared_ptr<IBook>& /*book*/) override;
	void PresentIn(const EPresentIn&) const noexcept override;
	void PresentCategory(const ECategory&) const noexcept;
public:
	BookStore(const BookStore&) = delete;
	BookStore& operator=(const BookStore&) = delete;
	static BookStore& GetInstance(const int argc, char** argv);
private: // HELPERS
	bool CheckAuthor(const std::shared_ptr<IAuthor>&) const noexcept override;
	bool CheckBook(const std::shared_ptr<IBook>&) const noexcept override;
	void AddBookInAuthor(const std::shared_ptr<IBook>& /*author*/);
	//void presentAll() const noexcept;
	void presentCategories() const noexcept;
	void presentAuthors() const noexcept;
	void presentBooks() const noexcept;
	//void presentProducts() const noexcept;
	std::string getCategoryName(const ECategory&) const noexcept;
private:
	BookStore() = default;
private:
	std::vector<std::pair<std::shared_ptr<IAuthor>, std::vector<std::string>>> m_data; // BookStore
	std::vector<std::shared_ptr<IProduct>> m_products; // Products, such as a pen, notebook...
	std::vector<std::shared_ptr<IBook>> m_books; // All Books
	std::vector<std::shared_ptr<IAuthor>> m_authors; // Authors
	std::vector<std::pair<ECategory, std::vector<std::shared_ptr<IBook>>>> m_categories; // Categories
	std::shared_ptr<IBaseComponents> m_data{new Administrator::GetInstance(m_filePath)};
	std::string m_filePath;
	//IBaseComponents* m_data {new Administrator(new Writable)};
}; // Class BookStore

//class Book : public IBook /*IObject*/{
//public:
//	Book(const BookName&, const AuthorName&, const ECategory&);
//	std::string Name() const noexcept override;
//	std::string authorName() const noexcept;
//	ECategory category() const noexcept override;
//	//Book(const Book&) = delete;
//	//Book& operator=(const Book&) = delete;
//private:
//	std::string m_bookName{""};
//	std::string m_authorName{""};
//	ECategory m_category;
//};

//class Author : public IAuthor/*IObject*/{
//public:
//	Author(const AuthorName&, const BookName&);
//	std::string Name() const noexcept override;
//	void PrintBooks() const noexcept override;
//	void AddBook(const std::shared_ptr<IBook>&) override;
//	//Author(const Author&) = delete;
//	//Author& operator=(const Author&) = delete;
//private:
//	std::string m_authorName{""};
//	std::vector<BookName> m_books;
//};

#include "Bookstore.impl.hpp"

#endif // __BOOKSTORE__HPP__
