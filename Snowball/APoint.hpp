#ifndef __APOINT__HPP__
#define __APOINT__HPP__

#include <utility>
#include <vector>

#include "IObject.hpp"
#include "Point.hpp"

namespace Snowball{

	class APoint : public IObject{
	public:
		using coords = std::pair<Point, Point>;
	public:
		APoint(int x, int y);
		Point distanceTo(const APoint& object) const override;
		virtual coords getPoints() const noexcept = 0;
	protected:
		Point m_point1;
	};

}

#include "APoint.impl.cpp"

#endif // __APOINT__HPP__
