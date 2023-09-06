#ifndef __TRIANGLE__IMPL__CPP__
#define __TRIANGLE__IMPL__CPP__

#include <iostream>
#include <memory>
#include <string>

#include "ETypes.hpp"

namespace PowerPoint{

	Triangle::Triangle(const std::string& objectName, EColor color, EColor backgroundColor, const size_t size) :
		Shape(objectName, EShape::Triangle, color, backgroundColor, size) {
	
	}

	Triangle::Triangle(const std::string& objectName) : Shape(objectName, EShape::Triangle, EColor::BLACK, EColor::WHITE, 12){
	}
	
	void Triangle::SetSize(const size_t size) {
		m_data.m_size = size;
	}

	void Triangle::SetBorderSize(const size_t borderSize) {
		m_data.m_borderSize = borderSize;
	}

	void Triangle::SetColor(const EColor color) {
		m_data.m_color = color;
	}

	void Triangle::SetBackgroundColor(const EColor backgroundColor) {
		m_data.m_backgroundColor = backgroundColor;
	}
	
	void Triangle::PrintMe() const noexcept {
		std::cout << "Id = " << GetId() << std::endl;
		std::cout << "Size = " << m_data.m_size << std::endl;
		std::cout << "Name = " << getName() << std::endl;
		std::cout << "X = " << m_data.m_coords.x << std::endl;
		std::cout << "Y = " << m_data.m_coords.y << std::endl;
	}

	Triangle::~Triangle(){
		
	}

}

#endif // __TRIANGLE__IMPL__CPP__
