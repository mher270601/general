#ifndef __GROUP__IMPL__CPP__
#define __GROUP__IMPL__CPP__

#include <string>
#include <memory>

#include "ETypes.hpp"

namespace PowerPoint{

	void Group::SetSize(const size_t size) {
		for (const auto& item : m_groupItems) {
			item->SetSize(size);
		}
	}
	void Group::SetBorderSize(const size_t borderSize) {
		for (const auto& item : m_groupItems) {
			item->SetBorderSize(borderSize);
		}
	}
	void Group::SetColor(const Color color) {
		for (const auto& item : m_groupItems) {
			item->SetColor(color);
		}
	}
	void Group::SetBackgroundColor(const Color backgroundColor) {
		for (const auto& item : m_groupItems) {
			item->SetBackgroundColor(backgroundColor);
		}
	}
	
	void Group::AddGroup(const IObjectPtr& groupItem) {
		m_groupItems.push_back(groupItem);
	}
	
	void Group::PrintMe() const noexcept {
		for(const auto& item : m_groupItems){
			item->PrintMe();
		}
	}

	void Group::MoveRight(const size_t plusX) {
	//m_coords.x += plusX;
	}
	
	void Group::MoveLeft(const size_t minusX) {
		//m_coords.x -= minusX;
	}
	
	void Group::MoveTop(const size_t plusY) {
		//m_coords.y += plusY;
	}
	
	void Group::MoveBottom(const size_t minusY) {
		//m_coords.y -= minusY;
	}
	
	Group::~Group() {
	}
	
}

#endif // __GROUP__IMPL__CPP__
