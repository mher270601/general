#ifndef __POINT__HPP__
#define __POINT__HPP__

#include <utility>

#define X_MAX_POINT 50
#define X_MIN_POINT 0
#define Y_MAX_POINT 10
#define Y_MIN_POINT 0
#define SIDE_LENGTH 5

namespace Snowball{

	struct Point{
		int x;
		int y;
		Point(int x_ = 0, int y_ = 0) : x(x_), y(y_){}
		Point(const Point& rhs){
			this->x = rhs.x;
			this->y = rhs.y;
		}
		Point& operator=(const Point& rhs){
			this->x = rhs.x;
			this->y = rhs.y;
			return *this;
		}
		Point(const std::pair<int, int> pair){
			this->x = pair.first;
			this->y = pair.second;
		}
		std::pair<int, int> distanceTo(Point rhs) const{
			return std::make_pair(rhs.x - this->x, rhs.y - this->y);
		}
	};

}

#endif // __POINT__HPP__
