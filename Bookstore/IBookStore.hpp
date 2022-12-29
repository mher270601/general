#ifndef __IBOOKSTORE__HPP__
#define __IBOOKSTORE__HPP__

#include <string>

#include "IBook.hpp"
#include "IAuthor.hpp"

class IBookStore{
public:

	virtual void AddBookInStore(const std::shared_ptr<IBook>&, const bool) = 0;
	virtual void AddProduct(const std::shared_ptr<IProduct>&, const bool) = 0;
	virtual void RemoveBookFromStore(std::string) = 0;
	virtual void RemoveProductFromStore(std::string) = 0;
	virtual void PresentIn(const EPresentIn&) const noexcept = 0;
	virtual ~IBookStore() = default;
protected:
	// HELPERS
	virtual bool CheckAuthor(const std::shared_ptr<IAuthor>&) const noexcept = 0;
	virtual bool CheckBook(const std::shared_ptr<IBook>&) const noexcept = 0;
private:
}; // Interface IBookStore (IObserver)
#endif // __IBOOKSTORE__HPP__
