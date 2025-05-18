#ifndef __IMOVABLE__HPP__
#define __IMOVABLE__HPP__

#include "Point.hpp"

namespace Snowball{

	class IMovable{
	public:
		virtual void moveTo(const std::pair<Point, Point>& snowball) = 0;
		virtual std::string getCoordsInfo() const = 0;
		~IMovable() = default;
	};

}

#endif // __IMOVABLE__HPP__
