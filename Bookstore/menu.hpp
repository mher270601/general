#ifndef __MENU__HPP__
#define __MENU__HPP__

#include <algorithm>
#include <exception>
#include <memory>
#include <fstream>
#include <vector>

#include "Bookstore.hpp"
#include "ETypes.hpp"
#include "fileManager.hpp"
#include "getFilePath.hpp"
#include "IBook.hpp"
#include "utility.hpp"

class Menu{
public:
	Menu() : m_line(1),
		 m_state(true){}
	void finish(){
		m_state = false;
	}
	bool getState(){
		return m_state;
	}
	void print(){
		std::cout << "\n\t\t\t" << m_bookStore << std::endl;
		std::cout << "\n\t\t\t" << m_books << std::endl;
		std::cout << "\n\t\t\t" << m_authors << std::endl;
		std::cout << "\n\t\t\t" << m_categories << std::endl;
		std::cout << "\n\t\t\t" << m_products << std::endl;
		std::cout << "\n\t\t\t" << m_addBook << std::endl;
		std::cout << "\n\t\t\t" << m_addProduct << std::endl;
		std::cout << "\n\t\t\t" << m_receiveBook << std::endl;
		std::cout << "\n\t\t\t" << m_receiveProduct << std::endl;
	}
	size_t getLine() const noexcept{
		return m_line;
	}
	void Top(){
		if(m_line > 1){
			--m_line;
			switch(m_line){
			case 1:
				m_bookStore = "\033[32m     BOOK STORE\u001b[0m\n";
				m_books = "\u001b[36m BOOKS\u001b[0m\n";
			break;
			case 2:
				m_books = "\033[32m     BOOKS\u001b[0m\n";
				m_authors = "\u001b[36m AUTHORS\u001b[0m\n";
			break;
			case 3:
				m_authors = "\033[32m     AUTHORS\u001b[0m\n";
				m_categories = "\u001b[36m CATEGORIES\u001b[0m\n";
			break;
			case 4:
				m_categories = "\033[32m     CATEGORIES\u001b[0m\n";
				m_products = "\u001b[36m PRODUCTS\u001b[0m\n";
			break;
			case 5:
				m_products = "\033[32m     PRODUCTS\u001b[0m\n";
				m_addBook = "\u001b[36m ADD BOOK\u001b[0m\n";
			break;
			case 6:
				m_addBook = "\033[32m     ADD BOOK\u001b[0m\n";
				m_addProduct = "\u001b[36m ADD PRODUCT\u001b[0m\n";
			break;
			case 7:
				m_addProduct = "\033[32m     ADD PRODUCT\u001b[0m\n";
				m_receiveBook = "\u001b[36m RECEIVE BOOK\u001b[0m\n";

			break;
			case 8:
				m_receiveBook = "\033[32m     RECEIVE BOOK\u001b[0m\n";
				m_receiveProduct = "\u001b[36m RECEIVE PRODUCT\u001b[0m\n";
			break;
			}
		}
		print();
	}
	void Down(){
		if(m_line < 9){
			++m_line;
			switch(m_line){
			case 2:
				m_bookStore = "\u001b[36m BOOK STORE\u001b[0m\n";
				m_books = "\033[32m     BOOKS\u001b[0m\n";
			break;
			case 3:
				m_books = "\u001b[36m BOOKS\u001b[0m\n";
				m_authors = "\033[32m     AUTHORS\u001b[0m\n";
			break;
			case 4:
				m_authors = "\u001b[36m AUTHORS\u001b[0m\n";
				m_categories = "\033[32m     CATEGORIES\u001b[0m\n";
			break;
			case 5:
				m_categories = "\u001b[36m CATEGORIES\u001b[0m\n";
				m_products = "\033[32m     PRODUCTS\u001b[0m\n";
			break;
			case 6:
				m_products = "\u001b[36m PRODUCTS\u001b[0m\n";
				m_addBook = "\033[32m     ADD BOOK\u001b[0m\n";
			break;
			case 7:
				m_addBook = "\u001b[36m ADD BOOK\u001b[0m\n";
				m_addProduct = "\033[32m     ADD PRODUCT\u001b[0m\n";
			break;
			case 8:
				m_addProduct = "\u001b[36m ADD PRODUCT\u001b[0m\n";
				m_receiveBook = "\033[32m     RECEIVE BOOK\u001b[0m\n";

			break;
			case 9:
				m_receiveBook = "\u001b[36m RECEIVE BOOK\u001b[0m\n";
				m_receiveProduct = "\033[32m     RECEIVE PRODUCT\u001b[0m\n";
			break;
			}
		}
		print();
	}
	void Enter(){
		BookStore& bs = BookStore::GetInstance();
		switch(m_line){
		case 1: // PRESENT ALL BOOKSTORE
			bs.PresentIn(EPresentIn::ALL);
		break;
		case 2: // PRESENT BOOKS
			bs.PresentIn(EPresentIn::BOOKS);
		break;
		case 3: // PRESENT AUTHORS
			bs.PresentIn(EPresentIn::AUTHORS);
		break;
		case 4: // PRESENT CATEGORIES
			bs.PresentIn(EPresentIn::CATEGORIES);
		break;
		case 5: // PRESENT PRODUCTS
			bs.PresentIn(EPresentIn::PRODUCTS);
		break;
		case 6: // ADD BOOK
		{	std::cout << BLUE << "INPUT AUTHOR NAME: " << RESET;
			std::string authorName;
			std::cin >> authorName;
			std::cout << std::endl;
			
			std::cout << BLUE << "INPUT BOOK NAME: " << RESET;
			std::string bookName;
			std::cin >> bookName;
			std::cout << std::endl;
			
			std::cout << BLUE << "INPUT CATEGORY: " << RESET;
			ECategory _category;
			std::string category; 
			std::cin >> category;
			std::cout << std::endl;
			_category = checkCategory(category);
			
			std::cout << BLUE << "INPUT PRICE: " << RESET;
			size_t price;
			std::cin >> price;	
			std::cout << std::endl;
			
			std::shared_ptr<IBook> book (new Book(BookName(bookName), AuthorName(authorName), ECategory(_category), price));
			bs.AddBookInStore(book);
			
		}
		break;
		case 7: // ADD PRODUCT
		{
			std::cout << BLUE << "INPUT PRODUCT TYPE: " << RESET;
			std::string type;
			std::cin >> type;
			std::cout << std::endl;
			std::transform(type.begin(), type.end(), type.begin(), ::toupper);

			std::cout << BLUE << "INPUT PRODUCT NAME: " << RESET;
			std::string productName;
			std::cin >> productName;
			std::cout << std::endl;

			std::cout << BLUE << "INPUT PRICE: " << RESET;
			size_t price;
			std::cin >> price;
			std::cout << std::endl;
			if(type == "PEN"){
				std::shared_ptr<IProduct> product (new Pen(PenName(productName), Price(price)));
				bs.AddProduct(product);
			}
			else if(type == "NOTEBOOK"){
				std::shared_ptr<IProduct> product (new Notebook(NotebookName(productName), Price(price)));
				bs.AddProduct(product);
			}
		}
		break;
		case 8: // RECEIVE BOOK
		{
			std::cout << BLUE << "INPUT BOOK NAME FOR RECEIVE: " << RESET;
			std::string bookName;
			std::cin >> bookName;
			std::cout << std::endl;
			bs.RemoveBookFromStore(bookName);
		}
		break;
		case 9: // RECEIVE PRODUCT
			std::cout << BLUE << "INPUT PRODUCT NAME FOR RECEIVE: " << RESET;
			std::string productName;
			std::cin >> productName;
			std::cout << std::endl;
			bs.RemoveProductFromStore(productName);
		break;
		}
	}
private:
	std::string m_bookStore = "\033[32m     BOOK STORE\u001b[0m\n";
	std::string m_books = "\u001b[36m BOOKS\u001b[0m\n";
	std::string m_authors = "\u001b[36m AUTHORS\u001b[0m\n";
	std::string m_categories = "\u001b[36m CATEGORIES\u001b[0m\n";
	std::string m_products = "\u001b[36m PRODUCTS\u001b[0m\n";
	std::string m_addBook = "\u001b[36m ADD BOOK\u001b[0m\n";
	std::string m_addProduct = "\u001b[36m ADD PRODUCT\u001b[0m\n";
	std::string m_receiveBook = "\u001b[36m RECEIVE BOOK\u001b[0m\n";
	std::string m_receiveProduct = "\u001b[36m RECEIVE PRODUCT\u001b[0m\n";
	size_t m_line;
	bool m_state;
};


#endif // __MENU__HPP__
