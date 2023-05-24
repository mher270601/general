#ifndef __IOBJECT__HPP__
#define __IOBJECT__HPP__

#include <memory>

#include "ETypes.hpp"

namespace PowerPoint{
    
	class IObject { // Interface - abstract class
    	public:
        	using IObjectPtr = std::shared_ptr<IObject>;
    	public:
        	IObject() = default;
        	virtual ~IObject() = default;
		//virtual std::string getTypeName() const = 0;
        	virtual void SetSize(const size_t) = 0;
        	virtual void SetBorderSize(const size_t) = 0;
        	virtual void SetColor(const Color) = 0;
        	virtual void SetBackgroundColor(const Color) = 0;
        	virtual void PrintMe() const noexcept = 0;
    	private:

    	}; // IObject
	
}

#endif // __IOBJECT__HPP__
