#ifndef __GROUP__HPP__
#define __GROUP__HPP__

#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

#include "ETypes.hpp"
#include "IObject.hpp"
#include "IObjectController.hpp"

namespace PowerPoint{

    	class Group : public IObject, public IObjectController {
    	public:
		Group(const std::string& objectName);

		using GroupPtr = std::shared_ptr<Group>;
		void SetSize(const size_t) override;
        	void SetBorderSize(const size_t) override;
        	void SetColor(const EColor) override;
        	void SetBackgroundColor(const EColor) override;
        	void PrintMe() const noexcept override;
        	void MoveRight(const size_t plusX) override;
        	void MoveLeft(const size_t minusX) override;
        	void MoveTop(const size_t plusY) override;
        	void MoveBottom(const size_t minusY) override;
        	void AddObject(const IObjectPtr& ObjectForAdd) override;
		void RemoveObject(const IObjectPtr& ObjectForRemove) override;
		IObjectPtr GetObject(const std::string& ObjectName);
        	virtual ~Group();
	private:

		//size_t GetIdentifier() const noexcept override;
    	private:
        	std::vector<IObjectPtr> m_groupObjects;
		std::unordered_map<std::string, size_t> m_objectNameTranslater;
		//size_t m_Identifier{0};
    	}; // ShapeGroup
	
        using GroupPtr = std::shared_ptr<Group>;
}

#include "Group.impl.cpp"

#endif // __GROUP__HPP__
