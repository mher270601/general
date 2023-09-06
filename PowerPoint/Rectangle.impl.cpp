#ifndef __RECTANGLE__IMPL__CPP__
#define __RECTANGLE__IMPL__CPP__

#include <memory>
#include <string>

#include "ETypes.hpp"

namespace PowerPoint{

	Rectangle::Rectangle(const std::string& objectName, EColor color, EColor backgroundColor, const size_t size) :
		Shape(objectName, EShape::Rectangle, color, backgroundColor, size) {
	
	}

	Rectangle::Rectangle(const std::string& objectName) : Shape(objectName, EShape::Rectangle, EColor::BLACK, EColor::WHITE, 12){
	}

	void Rectangle::SetSize(const size_t size) {
		m_data.m_size = size;
	}

	void Rectangle::SetBorderSize(const size_t borderSize) {
		m_data.m_borderSize = borderSize;
	}

	void Rectangle::SetColor(const EColor color) {
		m_data.m_color = color;
	}

	void Rectangle::SetBackgroundColor(const EColor backgroundColor) {
		m_data.m_backgroundColor = backgroundColor;
	}

	//void Set

	void Rectangle::PrintMe() const noexcept {
		std::cout << "Id = " << GetId() << std::endl;
		std::cout << "Size = " << m_data.m_size << std::endl;
		std::cout << "Name = " << getName() << std::endl;
		std::cout << "X = " << m_data.m_coords.x << std::endl;
		std::cout << "Y = " << m_data.m_coords.y << std::endl;
	}
	
	Rectangle::~Rectangle(){
		
	}

}

#endif // __RECTANGLE__IMPL__CPP__
