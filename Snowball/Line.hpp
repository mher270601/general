#ifndef __LINE__HPP__
#define __LINE__HPP__

#include <utility>
#include <vector>

#include "Point.hpp"
#include "APoint.hpp"

namespace Snowball{

	class Line : public Snowball::APoint{
	public:
		//virtual std::pair<Snowball::Point, Snowball::Point> getPoints() const noexcept = 0;
		//std::pair<int, int> distanceTo(const IPoint& object) const override;
		virtual Point distanceToLine(const Line& object) const noexcept;
		coords getPoints() const noexcept override;
	private:
		bool findNearestPoint(const Line& object) const;
	private:
		Point m_point2;
	};

}

#include "Line.impl.cpp"

#endif // __LINE__HPP__
