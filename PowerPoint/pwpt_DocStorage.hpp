#include <memory>
#include <unordered_map>
#include <string>

#include "Slide.hpp"
#include "Group.hpp"
#include "IObjectController.hpp"

namespace PowerPoint{

	class DocumentStorage /* : public IObjectController */ {
	public:
		// Meyer's Singleton
		static DocumentStorage& GetInstance();
		DocumentStorage(const DocumentStorage& rhs) = delete; // Copy init
		DocumentStorage& operator=(const DocumentStorage& rhs) = delete; // Copy assign
		
		void RemoveObject(const std::string& ObjectForRemove);
		void AddObject(const std::string& ObjectForAdd);
	private:
		DocumentStorage() = default;
	private:
		std::unordered_map<std::string, SlidePtr> m_Slides;
		std::unordered_map<std::string, GroupPtr> m_Groups;
	};
	using DocumentStoragePtr = std::shared_ptr<DocumentStorage>;
} // namespace PowerPoint

#include "pwpt_DocStorage.impl.cpp"
