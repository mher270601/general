#ifndef __TEXT__IMPL__CPP__
#define __TEXT__IMPL__CPP__

#include <iostream>
#include <string>
#include <memory>

#include "ETypes.hpp"

namespace PowerPoint{
	Text::Text(const std::string& objectName, const std::string& Paragraph, EColor color, EColor backgroundColor, const size_t size) : IObject(objectName), m_data(color, backgroundColor, size, EObjectType::TEXT)
	{
		m_data.m_text = Paragraph;
	}

	Text::Text(const std::string& objectName) : IObject(objectName){

	}

	void Text::SetSize(const size_t size) {
		m_data.m_size = size;
	}
	
	void Text::SetBorderSize(const size_t size) {
		m_data.m_borderSize = size;
	}
	
	void Text::SetColor(const EColor color) {
		m_data.m_color = color;
	}
	
	void Text::SetBackgroundColor(const EColor backgroundColor) {
		m_data.m_backgroundColor = backgroundColor;
	}
	
	inline void Text::PrintMe() const noexcept {
		std::cout << m_data.m_text << std::endl;
	}
	
	void Text::MoveRight(const size_t plusX) {
		m_data.m_coords.x += plusX;
	}
	
	void Text::MoveLeft(const size_t minusX) {
		m_data.m_coords.x -= minusX;
	}
	
	void Text::MoveTop(const size_t plusY) {
		m_data.m_coords.y += plusY;
	}
	
	void Text::MoveBottom(const size_t minusY) {
		m_data.m_coords.y -= minusY;
	}

	inline std::string Text::GetText() const noexcept {
		return m_data.m_text;
	}

	Text::~Text() {
	
	}
}

#endif // __TEXT__IMPL__CPP__
