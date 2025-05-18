#ifndef __APOINT__IMPL__CPP__
#define __APOINT__IMPL__CPP__

#include <utility>
#include <vector>

#include "Point.hpp"

namespace Snowball{

	APoint::APoint(int x, int y) : m_point1(x, y){} // Take it under try catch TODO

	Point APoint::distanceTo(const Point& object) const{
		return Point(object.x - this->m_point1.x, object.y - this->m_point1.y);
	}

}

#endif // __APOINT__IMPL__CPP__
