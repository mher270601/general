#ifndef __FILE__MANAGER__HPP__
#define __FILE__MANAGER__HPP__

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

class IBaseComponents{
public:
	virtual void addBook(const std::shared_ptr<IBook>&) = 0;
	virtual void addProduct(const std::shared_ptr<IProduct>&) = 0;
	virtual void receiveBook(const std::string&) = 0;
	virtual void receiveProduct(std::string&) = 0;
	virtual std::vector<std::shared_ptr<IObject>> readParseLines() = 0;
	virtual ~IBaseComponents() = default;
protected:
}; // IBaseComponents

class Administrator : public IBaseComponents{
public:
	void addBook(const std::shared_ptr<IBook>& book);
	void addProduct(const std::shared_ptr<IProduct>& product);
	void receiveBook(const std::string& bookName);
	void receiveProduct(std::string& productName);
	static Administrator* GetInstance(const std::string& path);
	Administrator& operator=(const Administrator& rhs) = delete;
	Administrator(const Administrator& rhs) = delete;
	virtual ~Administrator() = default;
	std::vector<std::shared_ptr<IObject>> readParseLines();
private:
	Administrator(const std::string& path);
	Administrator() = default;
private: // HELPERS
	std::shared_ptr<IObject> parser(std::stringstream& currentLine);
	bool parseType(std::istream& expr); // product is book -> return true : return false
private:
	const std::string m_FPath;
	std::fstream file;
}; // Class Administrator

#include "fileManager.impl.cpp"

#endif // __FILE__MANAGER__HPP__
