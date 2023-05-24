#ifndef __CIRCLE__HPP__
#define __CIRCLE__HPP__

#include <memory>
#include <string>

#include "ETypes.hpp"
#include "IObject.hpp"

namespace PowerPoint{

    	class Circle : public Shape {
    	public:
        	Circle(Color, Color, const size_t);
        	void PrintMe() const noexcept override;
    	private:

    	}; // Circle

}

#include "Circle.impl.cpp"

#endif // __CIRCLE__HPP__
