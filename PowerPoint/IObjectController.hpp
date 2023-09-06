#ifndef __IOBJECT__CONTROLLER__HPP__
#define __IOBJECT__CONTROLLER__HPP__

#include <memory>

#include "IObject.hpp"

namespace PowerPoint{

	class IObjectController{
	public:
		virtual void RemoveObject(const IObjectPtr& ObjectForAdd) = 0;
		virtual void AddObject(const IObjectPtr& ObjectForRemove) = 0;
	};

	using IObjectControllerPtr = std::shared_ptr<IObjectController>;

} // namespace PowerPoint

#endif // __IOBJECT__CONTROLLER__HPP__
