#ifndef __SLIDE__HPP__
#define __SLIDE__HPP__

#include <memory>
#include <vector>
#include <string>
#include <unordered_map>

#include "ETypes.hpp"
#include "IObject.hpp"
#include "ASimpleObject.hpp"
#include "IObjectController.hpp"

namespace PowerPoint{
	
    	class Slide : public ASimpleObject, public IObjectController {
    	public:
		//using SIObjectPtr = std::shared_ptr<IObject>;
       		Slide(const std::string& objectName);
		void AddObject(const IObjectPtr& ObjectForAdd) override;
		void RemoveObject(const IObjectPtr& ObjectForRemove) override;
		IObjectPtr GetObject(const std::string& ObjectName);
		//void SetSize(const size_t) override;
        	//void SetBorderSize(const size_t) override;
        	//void SetColor(const Color) override;
        	//void SetBackgroundColor(const Color) override;
        	//void PrintMe() const noexcept override;
        	virtual ~Slide();
	protected:
		//size_t GetIdentifier() const noexcept override;
    	private:
        	std::vector<IObjectPtr> m_slideObjects;
		std::unordered_map<std::string, size_t> m_objectNameTranslater;
	//protected:
		//size_t m_Identifier{0};
    	};
	
	using SlidePtr = std::shared_ptr<Slide>;

}

#include "Slide.impl.cpp"

#endif // __SLIDE__HPP__
