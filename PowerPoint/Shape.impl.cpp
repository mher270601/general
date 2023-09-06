#ifndef __SHAPE__IMPL__CPP__
#define __SHAPE__IMPL__CPP__

#include <string>
#include <memory>

#include "ETypes.hpp"

namespace PowerPoint{
	
	// Shape
	Shape::Shape(const std::string& objectName, const EShape& shape, EColor color, EColor backgroundColor, const size_t size) : IObject(objectName)/*, m_data(color, backgroundColor, size, EObjectType::SHAPE)*/
	{
		m_data.m_color = color;
		m_data.m_backgroundColor = backgroundColor;
		m_data.m_size = size;
		m_data.m_objectType = EObjectType::SHAPE;
	}
	
	//void Shape::SetSize(const size_t size) {
	//	m_data.m_size = size;
	//}
	//
	////inline size_t Shape::GetSize() noexcept {
	////	return m_data.size;
	////}
	//
	//void Shape::SetBorderSize(const size_t size) {
	//	m_data.m_borderSize = size;
	//}
	//
	////inline size_t Shape::GetBorderSize() noexcept {
	////	return m_data.borderSize;
	////}
	//
	//void Shape::SetColor(const EColor color) {
	//	m_data.m_color = color;
	//}
	//
	////inline Color Shape::GetColor() noexcept {
	////	return m_data.color;
	////}
	//
	//void Shape::SetBackgroundColor(const EColor color) {
	//	m_data.m_backgroundColor = color;
	//}
	
	//inline Color Shape::GetBackgroundColor() noexcept {
	//	return m_data.backgroundColor;
	//}
	
	//void Shape::PrintMe() const noexcept { // TODO
	//
	//}
	
	Shape::~Shape() {
	}
}

#endif // __SHAPE__IMPL__CPP__
