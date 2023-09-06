#ifndef __SQUARE__IMPL__CPP__
#define __SQUARE__IMPL__CPP__

#include <memory>
#include <string>

#include "ETypes.hpp"

namespace PowerPoint{
	
	Square::Square(const std::string& objectName, EColor color, EColor backgroundColor, const size_t size) :
		Shape(objectName, EShape::Square, color, backgroundColor, size) {
	
	}

	Square::Square(const std::string& objectName) : Shape(objectName, EShape::Square, EColor::BLACK, EColor::WHITE, 12){
	}
	
	void Square::SetSize(const size_t size) {
		m_data.m_size = size;
	}

	void Square::SetBorderSize(const size_t borderSize) {
		m_data.m_borderSize = borderSize;
	}

	void Square::SetColor(const EColor color) {
		m_data.m_color = color;
	}

	void Square::SetBackgroundColor(const EColor backgroundColor) {
		m_data.m_backgroundColor = backgroundColor;
	}

	void Square::PrintMe() const noexcept {
	
	}

	Square::~Square(){
	}
	
}

#endif // __SQUARE__IMPL__CPP__
