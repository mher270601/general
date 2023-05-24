#ifndef __SHAPE__IMPL__CPP__
#define __SHAPE__IMPL__CPP__

#include <string>
#include <memory>

#include "ETypes.hpp"

namespace PowerPoint{
	
	// Shape
	Shape::Shape(const Shapes& shape, Color color, Color backgroundColor, const size_t size) :
		m_shape{ shape },
		m_data(color, backgroundColor, size)
	{
	}
	
	void Shape::SetSize(const size_t size) {
		m_data.size = size;
	}
	
	//inline size_t Shape::GetSize() noexcept {
	//	return m_data.size;
	//}
	
	void Shape::SetBorderSize(const size_t size) {
		m_data.borderSize = size;
	}
	
	//inline size_t Shape::GetBorderSize() noexcept {
	//	return m_data.borderSize;
	//}
	
	void Shape::SetColor(const Color color) {
		m_data.color = color;
	}
	
	//inline Color Shape::GetColor() noexcept {
	//	return m_data.color;
	//}
	
	void Shape::SetBackgroundColor(const Color color) {
		m_data.backgroundColor = color;
	}
	
	//inline Color Shape::GetBackgroundColor() noexcept {
	//	return m_data.backgroundColor;
	//}
	
	void Shape::PrintMe() const noexcept {
	
	}
	
	Shape::~Shape() {
	}
}

#endif // __SHAPE__IMPL__CPP__
