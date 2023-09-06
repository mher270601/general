#ifndef __RECTANGLE__HPP__
#define __RECTANGLE__HPP__

#include <memory>
#include <string>

#include "ETypes.hpp"
#include "IObject.hpp"

namespace PowerPoint{

    	class Rectangle : public Shape {
    	public:
    	    	Rectangle(const std::string& objectName, EColor, EColor, const size_t);
		Rectangle(const std::string& objectName);
    	    

		void SetSize(const size_t size) override;
        	void SetBorderSize(const size_t borderSize) override;
        	void SetColor(const EColor color) override;
        	void SetBackgroundColor(const EColor backgroundColor) override;
	    	void PrintMe() const noexcept override;
    		~Rectangle();
    	protected:
		//void generateIdentifier() override;
    	private:


    	}; // Rectangle

}

#include "Rectangle.impl.cpp"

#endif // __RECTANGLE__HPP__
