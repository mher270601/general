#ifndef __CIRCLE__HPP__
#define __CIRCLE__HPP__

#include <memory>
#include <string>

#include "ETypes.hpp"
#include "IObject.hpp"

namespace PowerPoint{

    	class Circle : public Shape {
    	public:
        	Circle(const std::string& objectName, EColor, EColor, const size_t);
		Circle(const std::string& objectName);
        	
		void SetSize(const size_t size) override;
        	void SetBorderSize(const size_t borderSize) override;
        	void SetColor(const EColor color) override;
        	void SetBackgroundColor(const EColor backgroundColor) override;
		void PrintMe() const noexcept override;
		~Circle();
    	private:

    	}; // Circle

}

#include "Circle.impl.cpp"

#endif // __CIRCLE__HPP__
