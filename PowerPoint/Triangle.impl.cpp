#ifndef __TRIANGLE__IMPL__CPP__
#define __TRIANGLE__IMPL__CPP__

#include <memory>
#include <string>

#include "ETypes.hpp"

namespace PowerPoint{

	Triangle::Triangle(Color color, Color backgroundColor, const size_t size) :
		Shape(Shapes::Triangle, color, backgroundColor, size) {
	
	}
	
	void Triangle::PrintMe() const noexcept {
	
	}

}

#endif // __TRIANGLE__IMPL__CPP__
