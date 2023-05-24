#ifndef __TRIANGLE__HPP__
#define __TRIANGLE__HPP__

#include <memory>
#include <string>

#include "ETypes.hpp"
#include "IObject.hpp"

namespace PowerPoint{
    
	class Triangle : public Shape {
    	public:
        	Triangle(Color, Color, const size_t);
        	void PrintMe() const noexcept override;
    	private:

    	}; // Triangle
	
}

#include "Triangle.impl.cpp"

#endif // __TRIANGLE__HPP__
