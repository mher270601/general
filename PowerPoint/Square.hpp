#ifndef __SQUARE__HPP__
#define __SQUARE__HPP__

#include <memory>
#include <string>

#include "ETypes.hpp"
#include "IObject.hpp"

namespace PowerPoint{
    
	class Square : public Shape {
    	public:
        	Square(Color, Color, const size_t);
        	void PrintMe() const noexcept override;
    	private:

    	}; // Square
	
}

#include "Square.impl.cpp"

#endif // __SQUARE__HPP__
