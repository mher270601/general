#ifndef __TRIANGLE__HPP__
#define __TRIANGLE__HPP__

#include <memory>
#include <string>

#include "ETypes.hpp"
#include "IObject.hpp"

namespace PowerPoint{
    
	class Triangle : public Shape {
    	public:
        	Triangle(const std::string& objectName, EColor, EColor, const size_t);
		Triangle(const std::string& objectName);

		void SetSize(const size_t size) override;
        	void SetBorderSize(const size_t borderSize) override;
        	void SetColor(const EColor color) override;
        	void SetBackgroundColor(const EColor backgroundColor) override;

        	void PrintMe() const noexcept override;
		~Triangle();
	protected:
		//void generateIdentifier() override;
    	private:


    	}; // Triangle
	
}

#include "Triangle.impl.cpp"

#endif // __TRIANGLE__HPP__
