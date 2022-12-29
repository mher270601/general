#ifndef __ENUM__TYPES__
#define __ENUM__TYPES__

#include <string>

struct BookName{
	BookName(std::string name) : m_name(name){}
	std::string m_name{""};	
};

struct PenName{
	PenName(std::string name) : m_name(name){}
	PenName() = default;
	PenName(const PenName& rhs){
		m_name = rhs.m_name;
	}
	std::string m_name{""};	
};

struct NotebookName{
	NotebookName(std::string name) : m_name(name){}
	NotebookName() = default;
	NotebookName(const NotebookName& rhs){
		m_name = rhs.m_name;
	}
	std::string m_name{""};	
};

struct AuthorName{
	AuthorName(std::string name) : m_name(name){}
	std::string m_name{""};	
};

enum class EPresentIn{
	CATEGORIES,
	AUTHORS,
	BOOKS,
	PRODUCTS,
	ALL
};

enum class ECategory{
	BUSINESS,
	FANTASTIC,
	STUDYING,
	DETECTIVE,
	HISTORY,
	ROMANTIC,
	HUMOR,
	SPORT,
	MOTIVATION,
	CHILDRENS,
	MILITANTS
};

#endif // __ENUM__TYPES__
