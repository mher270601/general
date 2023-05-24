#ifndef __CIRCLE__IMPL__CPP__
#define __CIRCLE__IMPL__CPP__

#include <memory>
#include <string>

#include "ETypes.hpp"

namespace PowerPoint{

	Circle::Circle(Color color, Color backgroundColor, const size_t size) :
		Shape(Shapes::Circle, color, backgroundColor, size) {
	
	}
	
	void Circle::PrintMe() const noexcept {
	
	}

}

#endif // __CIRCLE__IMPL__CPP__
