#ifndef __POWER__POINT__IMPL__CPP__
#define __POWER__POINT__IMPL__CPP__

#include <iostream>
#include <string>
#include <vector>

#include "ETypes.hpp"

// Text
namespace PowerPoint{
//Text::Text(const std::string& paragraph, Color color, Color backgroundColor, const size_t size) :
//	m_text{ paragraph },
//	m_data(color, backgroundColor, size)
//{
//}
//
//void Text::SetSize(const size_t size) {
//	m_data.size = size;
//}
//
//void Text::SetBorderSize(const size_t size) {
//	m_data.borderSize = size;
//}
//
//void Text::SetColor(const Color color) {
//	m_data.color = color;
//}
//
//void Text::SetBackgroundColor(const Color color) {
//	m_data.backgroundColor = color;
//}
//
//void Text::PrintMe() const noexcept {
//	std::cout << m_text << std::endl;
//}
//
//Text::~Text() {
//
//}
// Shape
//Shape::Shape(const Shapes& shape, Color color, Color backgroundColor, const size_t size) :
//	m_shape{ shape },
//	m_data(color, backgroundColor, size)
//{
//}
//
//void Shape::SetSize(const size_t size) {
//	m_data.size = size;
//}
//
////inline size_t Shape::GetSize() noexcept {
////	return m_data.size;
////}
//
//void Shape::SetBorderSize(const size_t size) {
//	m_data.borderSize = size;
//}
//
////inline size_t Shape::GetBorderSize() noexcept {
////	return m_data.borderSize;
////}
//
//void Shape::SetColor(const Color color) {
//	m_data.color = color;
//}
//
////inline Color Shape::GetColor() noexcept {
////	return m_data.color;
////}
//
//void Shape::SetBackgroundColor(const Color color) {
//	m_data.backgroundColor = color;
//}
//
////inline Color Shape::GetBackgroundColor() noexcept {
////	return m_data.backgroundColor;
////}
//
//void Shape::PrintMe() const noexcept {
//
//}
//
//Shape::~Shape() {
//}

// Rectangle

//Rectangle::Rectangle(Color color, Color backgroundColor, const size_t size) :
//	Shape(Shapes::Rectangle, color, backgroundColor, size) {
//
//}
//
//void Rectangle::PrintMe() const noexcept {
//
//}
//
//Rectangle::~Rectangle(){
//	
//}

//Square::Square(Color color, Color backgroundColor, const size_t size) :
//	Shape(Shapes::Square, color, backgroundColor, size) {
//
//}
//
//void Square::PrintMe() const noexcept {
//
//}


//Triangle::Triangle(Color color, Color backgroundColor, const size_t size) :
//	Shape(Shapes::Triangle, color, backgroundColor, size) {
//
//}
//
//void Triangle::PrintMe() const noexcept {
//
//}

//Circle::Circle(Color color, Color backgroundColor, const size_t size) :
//	Shape(Shapes::Circle, color, backgroundColor, size) {
//
//}
//
//void Circle::PrintMe() const noexcept {
//
//}

// Group
//void Group::SetSize(const size_t size) {
//	for (const auto& item : m_groupItems) {
//		item->SetSize(size);
//	}
//}
//void Group::SetBorderSize(const size_t borderSize) {
//	for (const auto& item : m_groupItems) {
//		item->SetBorderSize(borderSize);
//	}
//}
//void Group::SetColor(const Color color) {
//	for (const auto& item : m_groupItems) {
//		item->SetColor(color);
//	}
//}
//void Group::SetBackgroundColor(const Color backgroundColor) {
//	for (const auto& item : m_groupItems) {
//		item->SetBackgroundColor(backgroundColor);
//	}
//}
//
//void Group::AddGroup(const IObjectPtr& groupItem) {
//	m_groupItems.push_back(groupItem);
//}
//
//void Group::PrintMe() const noexcept {
//	for(const auto& item : m_groupItems){
//		item->PrintMe();
//	}
//}
//
//Group::~Group() {
//}


//void Slide::SetSize(const size_t size) {
//	for (const auto& item : m_slide) {
//		item->SetSize(size);
//	}
//}
//void Slide::SetBorderSize(const size_t borderSize) {
//	for (const auto& item : m_slide) {
//		item->SetBorderSize(borderSize);
//	}
//}
//void Slide::SetColor(const Color color) {
//	for (const auto& item : m_slide) {
//		item->SetColor(color);
//	}
//}
//void Slide::SetBackgroundColor(const Color backgroundColor) {
//	for (const auto& item : m_slide) {
//		item->SetBackgroundColor(backgroundColor);
//	}
//}

//void Slide::AddObject(SIObjectPtr object) {
//	m_slide.push_back(object);
//}
//
////void Slide::PrintMe() const noexcept {
////	for (const auto& item : m_slide) {
////		item->PrintMe();
////	}
////}
//
//Slide::~Slide() {
//	//for (auto& elem : m_slide) {
//	//	delete elem;
//	//}
//}

//void GroupItem::SetSize(const size_t size) {
//	for (const auto& item : m_group) {
//		item->SetSize(size);
//	}
//}
//void GroupItem::SetBorderSize(const size_t borderSize) {
//	for (const auto& item : m_group) {
//		item->SetBorderSize(borderSize);
//	}
//}
//void GroupItem::SetColor(const Color color) {
//	for (const auto& item : m_group) {
//		item->SetColor(color);
//	}
//}
//void GroupItem::SetBackgroundColor(const Color backgroundColor) {
//	for (const auto& item : m_group) {
//		item->SetBackgroundColor(backgroundColor);
//	}
//}
//
//void GroupItem::AddObject(ItemPtr object) {
//	m_group.push_back(object);
//}
//
//void GroupItem::PrintMe() const noexcept {
//	for (const auto& item : m_group) {
//		item->PrintMe();
//	}
//}

//void Group::MoveRight(const size_t plusX) {
//	//m_coords.x += plusX;
//}
//
//void Group::MoveLeft(const size_t minusX) {
//	//m_coords.x -= minusX;
//}
//
//void Group::MoveTop(const size_t plusY) {
//	//m_coords.y += plusY;
//}
//
//void Group::MoveBottom(const size_t minusY) {
//	//m_coords.y -= minusY;
//}
}
#endif // #ifndef __POWER__POINT__IMPL__CPP__
