#ifndef __APOINT__IMPL__CPP__
#define __APOINT__IMPL__CPP__

#include <utility>
#include <vector>

#include "Point.hpp"

namespace Snowball{

	APoint::APoint(int x, int y) : m_point1(x, y){} // Take it under try catch TODO

	Point APoint::distanceTo(const APoint& object) const{
		return Point(object.m_point1.x - this->m_point1.x, object.m_point1.y - this->m_point1.y);
		//return std::pair<int, int>(object.m_x - this->m_x, object.m_y - this->m_y);
	}

}

#endif // __APOINT__IMPL__CPP__
