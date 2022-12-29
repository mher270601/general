#ifndef __PEN__IMPL__CPP__
#define __PEN__IMPL__CPP__

#include "ETypes.hpp"
#include "Price.hpp"

Pen::Pen(const PenName& name, const Price& _price){
	m_penName = name.m_name;
	m_price = _price.price;	
} // Pen

inline std::string Pen::Type() const noexcept{
	return "Pen";
} // Type

inline std::string Pen::Name() const noexcept{
	return m_penName;
} // Name

inline size_t Pen::getPrice() const noexcept{
	return m_price;
} // getPrice

#endif // __PEN__IMPL__CPP__
