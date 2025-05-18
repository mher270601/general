#ifndef __IPOINT__CONTAINER__HPP__
#define __IPOINT__CONTAINER__HPP__

#include <vector>

#include "Point.hpp"

namespace Snowball{

	class IPointContainer{
	public:
		virtual std::vector<Point> getPoints() const = 0;
	private:
	};

}

#endif // __IPOINT__CONTAINER__HPP__
