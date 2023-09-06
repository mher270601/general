#ifndef __CIRCLE__IMPL__CPP__
#define __CIRCLE__IMPL__CPP__

#include <memory>
#include <string>

#include "ETypes.hpp"

namespace PowerPoint{

	Circle::Circle(const std::string& objectName, EColor color, EColor backgroundColor, const size_t size) :
		Shape(objectName, EShape::Circle, color, backgroundColor, size) {
	
	}

	Circle::Circle(const std::string& objectName) : Shape(objectName, EShape::Circle, EColor::BLACK, EColor::WHITE, 12){
	}
	
	void Circle::SetSize(const size_t size) {
		m_data.m_size = size;
	}

	void Circle::SetBorderSize(const size_t borderSize) {
		m_data.m_borderSize = borderSize;
	}

	void Circle::SetColor(const EColor color) {
		m_data.m_color = color;
	}

	void Circle::SetBackgroundColor(const EColor backgroundColor) {
		m_data.m_backgroundColor = backgroundColor;
	}
	
	void Circle::PrintMe() const noexcept {
		std::cout << "Id = " << GetId() << std::endl;
		std::cout << "Size = " << m_data.m_size << std::endl;
		std::cout << "Name = " << getName() << std::endl;
		std::cout << "X = " << m_data.m_coords.x << std::endl;
		std::cout << "Y = " << m_data.m_coords.y << std::endl;
	
	}

	Circle::~Circle(){
	}
}

#endif // __CIRCLE__IMPL__CPP__
