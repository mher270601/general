#include <string>

#include "IObject.hpp"
#include "IObjectController.hpp"
#include "Slide.hpp"
#include "Group.hpp"

namespace PowerPoint{

	DocumentStorage& GetInstance() {
		static DocumentStorage Instance;
		return Instance;
	}

	void RemoveObject(const std::string& ObjectForRemove) {
		if(m_Groups.count(ObjectForRemove) || m_Slides.count(ObjectForRemove)){
			if(dynamic_cast<Group*>(&m_Groups[ObjectForRemove]) || dynamic_cast<Slide*>(&m_Slides[ObjectForRemove])){

				if(m_Slides.count(ObjectForRemove)){
					m_Slides.erase(ObjectForRemove);
				} else if(m_Groups.count(ObjectForRemove)){
					m_Groups.erase(ObjectForRemove);
				}

			}
		}
	}

	void AddObject(const std::string& ObjectForAdd, const std::string& StorageName) {
		if(m_Slides.count(StorageName)){
			IObjectControllerPtr _slide = m_Slides[StorageName];
			_slide->AddObject();
		}
		else if(m_Groups.count(StorageName)){
			IObjectControllerPtr _group = m_Groups[StorageName];
			_group->AddObject();

		}
	}

};
