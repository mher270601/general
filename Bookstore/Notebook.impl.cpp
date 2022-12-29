#ifndef __NOTEBOOK__IMPL__CPP__
#define __NOTEBOOK__IMPL__CPP__

#include "ETypes.hpp"
#include "Price.hpp"

Notebook::Notebook(const NotebookName& name, const Price& _price){
	m_notebookName = name.m_name;
	m_price = _price.price;	
} // Notebook

inline std::string Notebook::Type() const noexcept{
	return "Notebook";
} // Type

inline std::string Notebook::Name() const noexcept{
	return m_notebookName;
} // Name

inline size_t Notebook::getPrice() const noexcept{
	return m_price;
} // getPrice

#endif // __NOTEBOOK__IMPL__CPP__
