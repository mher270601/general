#ifndef __IOBJECT__HPP__
#define __IOBJECT__HPP__

#include <utility>
#include <vector>

#include "Point.hpp"

namespace Snowball{
	
	class APoint;

	class IObject{
	public:
		virtual Point distanceTo(const APoint& other) const = 0;
    		//virtual std::vector<std::pair<int, int>> getPoints() const = 0;
    		virtual ~IObject() = default;
	private:
	};
}

#endif // __IOBJECT__HPP__
