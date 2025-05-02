#ifndef __LINE__IMPL__CPP__
#define __LINE__IMPL__CPP__

#include <cstdlib>

#include "Point.hpp"

namespace Snowball{

	Line::coords Line::getPoints() const noexcept{
		return coords(m_point1, m_point2);
	}

	Point Line::distanceToLine(const Line& object) const noexcept{
		Point p1, p2, p3, p4;
		//p1()

	}


	bool Line::findNearestPoint(const Line& object) const{
		//if(std::abs(object.m_point1.x, m_point1.x) <= std::abs(object.m_))
	}

}

#endif // __LINE__IMPL__CPP__
