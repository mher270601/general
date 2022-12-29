#ifndef __BOOKSTORE__IMPL__
#define __BOOKSTORE__IMPL__

#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <thread>
#include <vector>

#include "utility.hpp"
#include "IBook.hpp"
#include "IProduct.hpp"
#include "getFilePath.hpp"
#include "name.hpp"
#include "utility.hpp"

// BookStore
bool BookStore::CheckAuthor(const std::shared_ptr<IAuthor>& author) const noexcept{
	for(const auto& _author : m_authors){
		if (_author->Name() == author->Name()){
			return true;
		}
	}
	return false;
} // CheckAuthor

bool BookStore::CheckBook(const std::shared_ptr<IBook>& book) const noexcept{
	for(const auto& _book : m_books){
		if(_book->Name() == book->Name() && _book->authorName() == book->authorName()){
			return true;
		}
	}
	return false;
} // CheckBook

void BookStore::AddBookInStore(const std::shared_ptr<IBook>& book, const bool admin = true){
	assert(book != nullptr);
	if(CheckBook(book)){
		return;
	}
	if(admin){
		m_admin->addBook(book);
	}
	m_books.push_back(book);
	std::shared_ptr<IAuthor> author(new Author(AuthorName(book->authorName()), BookName(book->Name())));
	AddBookInAuthor(book);

	std::vector<std::shared_ptr<IBook>> curVec;
	for(auto& category : m_categories){
		if(book->category() == category.first){
			curVec = category.second;
			curVec.push_back(book);
			category.second = curVec;
			return;
		}
	}
	std::vector<std::shared_ptr<IBook>> curBook {book};
	m_categories.push_back(std::make_pair(book->category(), curBook));
} // AddBookInStore

void BookStore::AddProduct(const std::shared_ptr<IProduct>& product, const bool admin = true){
	assert(product != nullptr);
	m_products.push_back(product);
	if(admin){
		m_admin->addProduct(product);
	}
} // AddProduct

void BookStore::AddBookInAuthor(const std::shared_ptr<IBook>& book){
	assert(book != nullptr);
	for(auto& _author : m_authors){
		if(_author->Name() == book->authorName()){
			_author->AddBook(book);
			return;
		}
	}
	std::shared_ptr<IAuthor> author(new Author(AuthorName(book->authorName()), BookName(book->Name())));
	m_authors.push_back(author);
} // AddBookInAuthor

void BookStore::RemoveBookFromStore(std::string _bookName){
	std::transform(_bookName.begin(), _bookName.end(), _bookName.begin(), ::toupper);
	for(size_t i = 0; i < m_books.size(); ++i){
		std::string BName = m_books[i]->Name();
		std::transform(BName.begin(), BName.end(), BName.begin(), ::toupper);
		if(_bookName == BName){
			m_books.erase(m_books.begin() + i);
		}
	}
	for(size_t i = 0; i < m_categories.size(); ++i){
		for(size_t j = 0; j < m_categories[i].second.size(); ++j){
			std::string BName = m_categories[i].second[j]->Name();
			std::transform(BName.begin(), BName.end(), BName.begin(), ::toupper);
			if(_bookName == BName){
				m_categories[i].second.erase(m_categories[i].second.begin() + j);
			}
		}
	}
	for(auto& author : m_authors){
		author->CheckAndRemoveBook(_bookName);
	}
	m_admin->receiveBook(_bookName);
} // RemoveBookFromStore

void BookStore::RemoveProductFromStore(/*const std::shared_ptr<IBook>& book*/ std::string _productName){
	std::transform(_productName.begin(), _productName.end(), _productName.begin(), ::toupper);
	
	for(size_t i = 0; i < m_products.size(); ++i){
		std::string curPrdName = m_products[i]->Name();
		std::transform(curPrdName.begin(), curPrdName.end(), curPrdName.begin(), ::toupper);
		if(curPrdName == _productName){
			m_products.erase(m_products.begin() + i);
		}
	}	
	m_admin->receiveProduct(_productName);
} // RemoveProductFromStore

void BookStore::PresentCategory(const ECategory& category) const noexcept{
	for(const auto& _category : m_categories){
		if(_category.first == category){
			std::cout << getCategory(category) << std::endl;
			for(const auto& book : _category.second){
				std::cout << book->authorName() << " - " << book->Name() << " - " << book->getPrice() << std::endl;
			}
		}
	}
} // PresentCategory

void BookStore::presentCategories() const noexcept{
	BCName();
	for(const auto& category : m_categories){
		std::cout << MAGENTA << "\t" << getCategory(category.first) << RESET << std::endl;
		for(const auto& book : category.second){
			std::cout << YELLOW << book->authorName() << RESET << " - " << BLUE << book->Name() << RESET << " - " << CYAN << book->getPrice() << RESET << std::endl;
		}
		std::cout << std::endl;	
	}
} // presentCategories

void BookStore::presentAuthors() const noexcept{
	AName();
	for(const auto& author : m_authors){
		author->PrintBooks();
	}	
} // presentAuthors

void BookStore::presentBooks() const noexcept{
	BName();
	for(const auto& book : m_books){
		std::cout << YELLOW << book->authorName() << RESET << " - " << BLUE << book->Name() << RESET << " - " << CYAN << book->getPrice() << RESET << std::endl;
	}
} // presentBooks

void BookStore::presentAll() const noexcept{
	presentBooks();
	presentProducts();
} // presentAll

void BookStore::presentProducts() const noexcept{
	PName();
	for(const auto& product : m_products){
		std::cout << BLUE << product->Name() << RESET << " - " << CYAN << product->getPrice() << RESET << std::endl;
	}
} // presentProducts

void BookStore::PresentIn(const EPresentIn& present_in) const noexcept{
	switch(present_in){
	case EPresentIn::CATEGORIES:
		system("clear");
		BSName();
		presentCategories();
	break;
	case EPresentIn::AUTHORS:
		system("clear");
		BSName();
		presentAuthors();
	break;
	case EPresentIn::BOOKS:
		system("clear");
		BSName();
		presentBooks();
	break;
	case EPresentIn::PRODUCTS:
		system("clear");
		BSName();
		presentProducts();
	break;
	case EPresentIn::ALL:
		system("clear");
		BSName();
		presentAll();
	break;
	}	
} // PresentIn

void BookStore::ReadFromFile(){
	auto data = m_admin->readParseLines();
	for(const auto& item : data){
		if(dynamic_cast<IBook*>(item.get())){
			std::shared_ptr<IBook> book = std::dynamic_pointer_cast<IBook>(item);
			AddBookInStore(book, false);	
		}
		else if(dynamic_cast<IProduct*>(item.get())){
			std::shared_ptr<IProduct> product = std::dynamic_pointer_cast<IProduct>(item);
			AddProduct(product, false);
		}
	}
} // ReadFromFile

BookStore::BookStore(const std::string& filePath) : m_filePath(filePath){
} // BookStore

BookStore& BookStore::GetInstance() {
	static BookStore ob;
	return ob;
} // GetInstance

BookStore::BookStore(){
	ReadFromFile();
} // BookStore

BookStore::~BookStore(){
	delete m_admin;
} // ~BookStore

#endif // __BOOKSTORE__IMPL__
