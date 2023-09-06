#include "IObject.hpp"

namespace PowerPoint{

	class IModifierObject : public IObject{
	public:
		virtual bool RemoveObject() = 0;
		virtual bool AddObject() = 0;
	};

} // namespace PowerPoint
