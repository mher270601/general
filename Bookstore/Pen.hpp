#ifndef __PEN__HPP__
#define __PEN__HPP__

#include <string>

#include "Price.hpp"
#include "IPen.hpp"
#include "ETypes.hpp"

class Pen : public IPen{
public:
	Pen(const PenName&, const Price&);
	std::string Type() const noexcept override;
	std::string Name() const noexcept override;
	size_t getPrice() const noexcept;
private:
	std::string m_penName;
	size_t m_price;
};

#include "Pen.impl.cpp"

#endif // __PEN__HPP__
