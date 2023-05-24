#ifndef __TEXT__IMPL__CPP__
#define __TEXT__IMPL__CPP__

#include <iostream>
#include <string>
#include <memory>

#include "ETypes.hpp"

namespace PowerPoint{
	Text::Text(const std::string& paragraph, Color color, Color backgroundColor, const size_t size) :
		m_text{ paragraph },
		m_data(color, backgroundColor, size)
	{
	}
	
	void Text::SetSize(const size_t size) {
		m_data.size = size;
	}
	
	void Text::SetBorderSize(const size_t size) {
		m_data.borderSize = size;
	}
	
	void Text::SetColor(const Color color) {
		m_data.color = color;
	}
	
	void Text::SetBackgroundColor(const Color color) {
		m_data.backgroundColor = color;
	}
	
	void Text::PrintMe() const noexcept {
		std::cout << m_text << std::endl;
	}
	
	Text::~Text() {
	
	}
}

#endif // __TEXT__IMPL__CPP__
