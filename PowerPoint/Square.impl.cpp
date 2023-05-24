#ifndef __SQUARE__IMPL__CPP__
#define __SQUARE__IMPL__CPP__

#include <memory>
#include <string>

#include "ETypes.hpp"

namespace PowerPoint{
	
	Square::Square(Color color, Color backgroundColor, const size_t size) :
		Shape(Shapes::Square, color, backgroundColor, size) {
	
	}
	
	void Square::PrintMe() const noexcept {
	
	}
	
}

#endif // __SQUARE__IMPL__CPP__
