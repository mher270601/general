#ifndef __SLIDE__IMPL__CPP__
#define __SLIDE__IMPL__CPP__

#include <iostream>
#include <memory>
#include <string>

#include "ETypes.hpp"
#include "IObject.hpp"
#include "UniqueIdGenerator.hpp"

namespace PowerPoint{
	
	Slide::Slide(const std::string& objectName) : ASimpleObject(objectName)/*, m_Identifier(UniqueIdGenerator::GenerateId())*/{

	}

	void Slide::AddObject(const IObjectPtr& ObjectForAdd) {
		if(m_objectNameTranslater.count(ObjectForAdd->getName()/*ObjectForAdd->GetIdentifier()*/)){
			std::cerr << "WARNING: Object is already exists\n" << std::endl;
			return;
		}
		m_objectNameTranslater.emplace(ObjectForAdd->getName()/*ObjectForAdd->GetIdentifier()*/, m_slideObjects.size());
		m_slideObjects.push_back(ObjectForAdd);
	}
		
	void Slide::RemoveObject(const IObjectPtr& ObjectForRemove){
		if(m_objectNameTranslater.count(ObjectForRemove->getName()/*ObjectForRemove->GetIdentifier()*/)){
			auto iter = m_slideObjects.begin() + m_objectNameTranslater[ObjectForRemove->getName()/*ObjectForRemove->GetIdentifier()*/];
			m_slideObjects.erase(iter);
			return;
		}
		//for(auto it = m_groupObjects.begin(); it != m_groupObjects.end(); ++it){
		//	if(!strcmp(*it->GetIdentifier().c_str(), ObjectForRemove->GetIdentifier().c_str())){
		//		m_groupObjects.erase(it);
		//		return;
		//	}
		//}
		std::cerr << "WARNING: The object to be removed was not found" << std::endl;
	}

	//inline size_t Slide::GetIdentifier() const noexcept {	
	//	return m_Identifier;
	//}

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
