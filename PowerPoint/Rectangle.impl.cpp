#ifndef __RECTANGLE__IMPL__CPP__
#define __RECTANGLE__IMPL__CPP__

#include <memory>
#include <string>

#include "ETypes.hpp"

namespace PowerPoint{

	Rectangle::Rectangle(Color color, Color backgroundColor, const size_t size) :
		Shape(Shapes::Rectangle, color, backgroundColor, size) {
	
	}
	
	void Rectangle::PrintMe() const noexcept {
	
	}
	
	Rectangle::~Rectangle(){
		
	}

}

#endif // __RECTANGLE__IMPL__CPP__
