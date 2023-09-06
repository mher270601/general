#ifndef __SQUARE__HPP__
#define __SQUARE__HPP__

#include <memory>
#include <string>

#include "ETypes.hpp"
#include "IObject.hpp"

namespace PowerPoint{
    
	class Square : public Shape {
    	public:
        	Square(const std::string& objectName, EColor, EColor, const size_t);
		Square(const std::string& objectName);
		
		void SetSize(const size_t size) override;
        	void SetBorderSize(const size_t borderSize) override;
        	void SetColor(const EColor color) override;
        	void SetBackgroundColor(const EColor backgroundColor) override;
        	
		void PrintMe() const noexcept override;
		~Square();
    	private:

    	}; // Square
	
}

#include "Square.impl.cpp"

#endif // __SQUARE__HPP__
