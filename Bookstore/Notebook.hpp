#ifndef __NOTEBOOK__HPP__
#define __NOTEBOOK__HPP__

#include <string>

#include "Price.hpp"
#include "INotebook.hpp"
#include "ETypes.hpp"

class Notebook : public INotebook{
public:
	Notebook(const NotebookName&, const Price&);
	std::string Type() const noexcept override;
	std::string Name() const noexcept override;
	size_t getPrice() const noexcept;
private:
	std::string m_notebookName;
	size_t m_price;
};

#include "Notebook.impl.cpp"

#endif // __NOTEBOOK__HPP__
