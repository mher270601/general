#ifndef __GROUP__IMPL__CPP__
#define __GROUP__IMPL__CPP__

#include <iostream>
#include <string>
#include <memory>
#include <cstring>

#include "ETypes.hpp"
#include "UniqueIdGenerator.hpp"

#define GET_VARIABLE_NAME(Variable) (#Variable)

namespace PowerPoint{

	Group::Group(const std::string& objectName) : IObject(objectName)/*, m_Identifier(UniqueIdGenerator::GenerateId())*/ { // Ctor
		
	}

	void Group::SetSize(const size_t size) {
		for (const auto& item : m_groupObjects) {
			item->SetSize(size);
		}
	}
	void Group::SetBorderSize(const size_t borderSize) {
		for (const auto& item : m_groupObjects) {
			item->SetBorderSize(borderSize);
		}
	}
	void Group::SetColor(const EColor color) {
		for (const auto& item : m_groupObjects) {
			item->SetColor(color);
		}
	}
	void Group::SetBackgroundColor(const EColor backgroundColor) {
		for (const auto& item : m_groupObjects) {
			item->SetBackgroundColor(backgroundColor);
		}
	}
	
	//inline size_t GetIdentifier() const noexcept {
	//	return m_Identifier;
	//}

	void Group::AddObject(const IObjectPtr& ObjectForAdd) {
		if(m_objectNameTranslater.count(ObjectForAdd->getName()/*ObjectForAdd->GetIdentifier()*/)){
			std::cerr << "WARNING: Object is already exists\n" << std::endl;
			return;
		}
		m_objectNameTranslater.emplace(ObjectForAdd->getName()/*ObjectForAdd->GetIdentifier()*/, m_groupObjects.size());
		m_groupObjects.push_back(ObjectForAdd);
	}

	void Group::RemoveObject(const IObjectPtr& ObjectForRemove) {
		if(!m_objectNameTranslater.count(ObjectForRemove->getName()/*ObjectForRemove->GetIdentifier()*/)){
			auto iter = m_groupObjects.begin() + m_objectNameTranslater[ObjectForRemove->getName()/*ObjectForRemove->GetIdentifier()*/];
			m_groupObjects.erase(iter);
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
	
	void Group::PrintMe() const noexcept {
		for(const auto& item : m_groupObjects){
			item->PrintMe();
		}
	}

	void Group::MoveRight(const size_t plusX) {
		for (const auto& item : m_groupObjects) {
			item->MoveRight(plusX);
		}
	//m_coords.x += plusX;
	}
	
	void Group::MoveLeft(const size_t minusX) {
		for (const auto& item : m_groupObjects) {
			item->MoveLeft(minusX);
		}
		//m_coords.x -= minusX;
	}
	
	void Group::MoveTop(const size_t plusY) {
		for (const auto& item : m_groupObjects) {
			item->MoveTop(plusY);
		}
		//m_coords.y += plusY;
	}
	
	void Group::MoveBottom(const size_t minusY) {
		for (const auto& item : m_groupObjects) {
			item->MoveBottom(minusY);
		}
		//m_coords.y -= minusY;
	}
	
	Group::~Group() {
	}
	
} // namespace PowerPoint

#endif // __GROUP__IMPL__CPP__
