#ifndef __IOBJECT__HPP__
#define __IOBJECT__HPP__

#include <memory>
#include <string>

#include "ETypes.hpp"
#include "ASimpleObject.hpp"

namespace PowerPoint{
        
    
	class IObject : public ASimpleObject { // Interface - abstract class
    	public:
        	//using IObjectPtr = std::shared_ptr<IObject>;
    	public:
		IObject(const std::string& objectName);
        	//IObject() = default;
        	virtual ~IObject() = default;
		// virtual std::string getTypeName() const = 0;
		// virtual IObjectPtr getObject()
        	virtual void SetSize(const size_t) = 0;
        	virtual void SetBorderSize(const size_t) = 0;
        	virtual void SetColor(const EColor) = 0;
        	virtual void SetBackgroundColor(const EColor) = 0;
		// std::string getName() const noexcept;
		virtual void PrintMe() const noexcept = 0;
        	virtual void MoveRight(const size_t plusX); // Group must be override
        	virtual void MoveLeft(const size_t minusX);
        	virtual void MoveTop(const size_t plusY);
        	virtual void MoveBottom(const size_t minusY);
		//size_t GetIdentifier() const noexcept;
	protected:
		ItemData m_data;
		//std::string m_name;
		//size_t m_Identifier{0};
    	private:

    	}; // IObject
	
	using IObjectPtr = std::shared_ptr<IObject>;

}

#include "IObject.impl.cpp"

#endif // __IOBJECT__HPP__
