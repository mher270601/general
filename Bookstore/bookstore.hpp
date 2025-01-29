#ifndef __BOOKSTORE__HPP__
#define __BOOKSTORE__HPP__

#include <cassert>
#include <map>
#include <memory>
#include <vector>
#include <string>
#include <string.h>

#include "ETypes.hpp"
#include "fileManager.hpp"
#include "getFilePath.hpp"
#include "IBookStore.hpp"
#include "Book.hpp"
#include "Author.hpp"
#include "Pen.hpp"
#include "Notebook.hpp"

class BookStore : public IBookStore{
public:	
	void AddBookInStore(const std::shared_ptr<IBook>&, const bool) override;
	void RemoveBookFromStore(std::string) override;
	void RemoveProductFromStore(std::string) override;
	void AddProduct(const std::shared_ptr<IProduct>&, const bool) override;
	void PresentIn(const EPresentIn&) const noexcept override;
	void PresentCategory(const ECategory&) const noexcept;
public:
	BookStore(const BookStore&) = delete;
	BookStore& operator=(const BookStore&) = delete;
	static BookStore& GetInstance();
private: // HELPERS
	void ReadFromFile();
	bool CheckAuthor(const std::shared_ptr<IAuthor>&) const noexcept override;
	bool CheckBook(const std::shared_ptr<IBook>&) const noexcept override;
	void AddBookInAuthor(const std::shared_ptr<IBook>&);
	void presentCategories() const noexcept;
	void presentAll() const noexcept;
	void presentAuthors() const noexcept;
	void presentBooks() const noexcept;
	void presentProducts() const noexcept;
	std::string getCategoryName(const ECategory&) const noexcept;
private:
	BookStore(const std::string& filePath);
	BookStore();
	virtual ~BookStore();
	std::vector<std::shared_ptr<IBook>> m_books; // All Books
	std::vector<std::shared_ptr<IAuthor>> m_authors; // Authors
	std::vector<std::pair<ECategory, std::vector<std::shared_ptr<IBook>>>> m_categories; // Categories	
	std::vector<std::shared_ptr<IProduct>> m_products; // Products
	IBaseComponents* m_admin = Administrator::GetInstance(getFilePath()); // Administrator for file handling
	std::string m_filePath;
}; // Class BookStore

#include "Bookstore.impl.hpp"

#endif // __BOOKSTORE__HPP__
