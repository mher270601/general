#ifndef __FILE__MANAGER__CPP__
#define __FILE__MANAGER__CPP__

#include <algorithm>
#include <cstdio>
#include <exception>
#include <iostream>
#include <memory>
#include <sstream>
#include <thread>
#include <fstream>

#include "Bookstore.hpp"
#include "ETypes.hpp"
#include "fileExcep.hpp"
#include "readFromFile.hpp"
#include "IObject.hpp"
#include "IBook.hpp"
#include "IProduct.hpp"
#include "Book.hpp"
#include "Pen.hpp"
#include "Notebook.hpp"
#include "utility.hpp"

void Administrator::addBook(const std::shared_ptr<IBook>& book){
	std::string category = getCategory(book->category());
	std::string currentLine = "Book , ";
       	currentLine += book->authorName();
       	currentLine += " , ";
       	currentLine += book->Name();
        currentLine += " , ";
       	currentLine += category;
        currentLine += " , ";
       	currentLine += std::to_string(book->getPrice());
	currentLine += "\n";
	file.open(m_FPath, std::ios::app | std::ios::out); // Append book
	if(!file.is_open()){
		throw FileOpen_Error("File can not open, check a permissions !");
	}
	std::cout << GREEN << "BOOK SUCCESSFULLY ADDED )" << RESET << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	file << currentLine;
	file.close();
} // addBook
void Administrator::addProduct(const std::shared_ptr<IProduct>& product){
	std::string currentLine = product->Type();
	currentLine += " , ";
	currentLine += product->Name();
	currentLine += " , ";
	currentLine += std::to_string(product->getPrice());
	currentLine += "\n";
	file.open(m_FPath, std::ios::app | std::ios::out); // Append product
	if(!file.is_open()){
		throw FileOpen_Error("File can not open, check a permissions !");
	}
	std::cout << GREEN << "PRODUCT SUCCESSFULLY ADDED )" << RESET << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	file << currentLine;
	file.close();
} // addProduct
void Administrator::receiveBook(const std::string& bookName){
	std::string line;
	file.open(m_FPath, std::ios::in);
	std::ofstream temp;
	temp.open("temp.txt");
		
	do{
		std::stringstream currLine(getLine(file));
		line = currLine.str();
		std::string type;
		std::string threshold;
		currLine >> type;
		std::transform(type.begin(), type.end(), type.begin(), ::toupper);
		currLine >> threshold;
		currLine >> threshold;
		currLine >> threshold;
		std::string BName;
		currLine >> BName;
		std::transform(BName.begin(), BName.end(), BName.begin(), ::toupper);
		std::string myus;
		currLine >> myus;
		if(type != "BOOK" || BName != bookName){
			temp << line << std::endl;
		}
	}while(!file.eof());
	temp.close();
	file.close();

	const char* c = m_FPath.c_str();
	std::remove(c);
	std::rename("temp.txt", c);
	std::cout << GREEN << "BOOK SUCCESSFULLY RECEIVED )" << RESET << std::endl;
} // receiveBook
void Administrator::receiveProduct(std::string& productName){
	std::string line;
	file.open(m_FPath, std::ios::in); // READ MODE
	std::ofstream temp;
	temp.open("temp.txt");
		
	do{
		std::stringstream currLine(getLine(file));
		line = currLine.str();
		std::string type;
		std::string threshold;
		currLine >> type;
		std::transform(type.begin(), type.end(), type.begin(), ::toupper);
		currLine >> threshold;
		std::string PName;
		currLine >> PName;
		std::transform(PName.begin(), PName.end(), PName.begin(), ::toupper);
		std::string myus;
		currLine >> myus;
		if(type == "BOOK" || PName != productName){
			temp << line << std::endl;
		}
	}while(!file.eof());
	temp.close();
	file.close();

	const char* c = m_FPath.c_str();
	std::remove(c);
	std::rename("temp.txt", c);
	std::cout << GREEN << "PRODUCT SUCCESSFULLY RECEIVED )" << RESET << std::endl;
} // receiveProduct

Administrator* Administrator::GetInstance(const std::string& path){
	static Administrator* ptr = new Administrator(path);
	return ptr;
} // GetInstance

std::vector<std::shared_ptr<IObject>> Administrator::readParseLines() /*-> decltype(5 < 6 ? 5 : 7.6)*/ {
	file.open(m_FPath,std::ios::in); // Read product
	if(!file.is_open()){
		throw FileOpen_Error("File can not open, check a permissions !");
	}
	std::vector<std::shared_ptr<IObject>> data;
	do{
		std::stringstream line(getLine(file));
		if(line.str() != ""){
			data.push_back(parser(line));
		}
	}while(!file.eof());
	file.close();
	return data;
} // readParseLines
	
Administrator::Administrator(/*const BookStore& bookStore, */const std::string& path) : 
									m_FPath(path)
{
} // Administrator
	
std::shared_ptr<IObject> Administrator::parser(std::stringstream& currentLine){
	if(parseType(currentLine)){
		std::string _authorName, cur;
		do{
			currentLine >> cur;
			_authorName += cur + " ";
		}while(cur != ",");
		cur = "";
		_authorName.pop_back();
		_authorName.pop_back();
		
		std::string _bookName;
		do{
			currentLine >> cur;
			_bookName += cur + " ";
		}while(cur != ",");
		cur = "";
		_bookName.pop_back();
		_bookName.pop_back();
		
		ECategory _category;
		currentLine >> cur;
		_category = checkCategory(cur);
		currentLine >> cur;
		
		cur = "";
		size_t _price;
		currentLine >> cur;
		_price = std::stoi(cur);
		
		std::shared_ptr<IBook> book(new Book(BookName(_bookName), AuthorName(_authorName), ECategory(_category), _price));
		return book;
	}
	std::string _prdName, cur;
	do{
		currentLine >> cur;
		_prdName += cur + " ";
	}while(cur != ",");
	cur = "";
	_prdName.pop_back();
	_prdName.pop_back();
	
	currentLine >> cur;
	size_t _price = std::stoi(cur);
	
	std::shared_ptr<IProduct> product(new Pen(PenName(_prdName), Price(_price)));
	return product;
} // parser
	
bool Administrator::parseType(std::istream& expr){ // product is book -> return true : return false
	std::string prdType;
	expr >> prdType;
	
	std::string cur;
	expr >> cur;
	std::transform(prdType.begin(), prdType.end(), prdType.begin(), ::toupper);
	if(prdType == "BOOK"){
		return true;
	}
	return false;
} // parseType
#endif // __FILE__MANAGER__CPP__
