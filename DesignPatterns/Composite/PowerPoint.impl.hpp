#ifndef __POWER__POINT__IMPL__CPP__
#define __POWER__POINT__IMPL__CPP__

#include <string>
#include <vector>

#include "ETypes.hpp"

// Text
PowerPoint::Text::Text(const std::string& paragraph, Color color, Color backgroundColor, const size_t size) :
	m_text{ paragraph },
	m_data(color, backgroundColor, size)
{
}

void PowerPoint::Text::SetSize(const size_t size) {
	m_data.size = size;
}

void PowerPoint::Text::SetBorderSize(const size_t size) {
	m_data.borderSize = size;
}

void PowerPoint::Text::SetColor(const Color color) {
	m_data.color = color;
}

void PowerPoint::Text::SetBackgroundColor(const Color color) {
	m_data.backgroundColor = color;
}

void PowerPoint::Text::PrintMe() const noexcept{
	std::cout << m_text << std::endl;
}

PowerPoint::Text::~Text() {

}
// Shape
PowerPoint::Shape::Shape(const Shapes& shape, Color color, Color backgroundColor, const size_t size) :
	m_shape{ shape },
	m_data(color, backgroundColor, size)
{
}

void PowerPoint::Shape::SetSize(const size_t size) {
	m_data.size = size;
}

void PowerPoint::Shape::SetBorderSize(const size_t size) {
	m_data.borderSize = size;
}

void PowerPoint::Shape::SetColor(const Color color) {
	m_data.color = color;
}

void PowerPoint::Shape::SetBackgroundColor(const Color color) {
	m_data.backgroundColor = color;
}

void PowerPoint::Shape::PrintMe() const noexcept {
}

PowerPoint::Shape::~Shape() {
}

// Rectangle

PowerPoint::Rectangle::Rectangle(Color color, Color backgroundColor, const size_t size) :
	Shape(Shapes::Rectangle, color, backgroundColor, size) {

}

void PowerPoint::Rectangle::PrintMe() const noexcept {
	std::cout << "I Rectangle" << std::endl;
}

PowerPoint::Square::Square(Color color, Color backgroundColor, const size_t size) :
	Shape(Shapes::Square, color, backgroundColor, size) {

}

void PowerPoint::Square::PrintMe() const noexcept {
	std::cout << "I Square" << std::endl;
}

PowerPoint::Triangle::Triangle(Color color, Color backgroundColor, const size_t size) :
	Shape(Shapes::Triangle, color, backgroundColor, size) {

}

void PowerPoint::Triangle::PrintMe() const noexcept {
	std::cout << "I Triangle" << std::endl;
}

PowerPoint::Circle::Circle(Color color, Color backgroundColor, const size_t size) :
	Shape(Shapes::Circle, color, backgroundColor, size) {

}

void PowerPoint::Circle::PrintMe() const noexcept {
	std::cout << "I Circle" << std::endl;
}

void PowerPoint::Group::SetSize(const size_t size) {
	for (const auto& item : m_groupItems) {
		item->SetSize(size);
	}
}
void PowerPoint::Group::SetBorderSize(const size_t borderSize) {
	for (const auto& item : m_groupItems) {
		item->SetBorderSize(borderSize);
	}
}
void PowerPoint::Group::SetColor(const Color color) {
	for (const auto& item : m_groupItems) {
		item->SetColor(color);
	}
}
void PowerPoint::Group::SetBackgroundColor(const Color backgroundColor) {
	for (const auto& item : m_groupItems) {
		item->SetBackgroundColor(backgroundColor);
	}
}

void PowerPoint::Group::AddGroup(const IObjectPtr& groupItem) {
	/*ptr.push_back(shape);*/
	m_groupItems.push_back(groupItem);
	/*v.push_back(7);*/
}

void PowerPoint::Group::PrintMe() const noexcept{
	for(const auto& item : m_groupItems){
		item->PrintMe();
	}	
}

PowerPoint::Group::~Group() {
}

#endif // #ifndef __POWER__POINT__IMPL__CPP__
