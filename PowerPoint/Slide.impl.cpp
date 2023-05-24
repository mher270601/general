#ifndef __SLIDE__IMPL__CPP__
#define __SLIDE__IMPL__CPP__

#include <memory>
#include <string>

#include "ETypes.hpp"

namespace PowerPoint{
	
	void Slide::AddObject(SIObjectPtr object) {
		m_slide.push_back(object);
	}
	
	//void Slide::PrintMe() const noexcept {
	//	for (const auto& item : m_slide) {
	//		item->PrintMe();
	//	}
	//}
	
	Slide::~Slide() {
		//for (auto& elem : m_slide) {
		//	delete elem;
		//}
	}

}

#endif // __SLIDE__IMPL__CPP__
