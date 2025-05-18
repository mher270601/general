#ifndef __LINE__HPP__
#define __LINE__HPP__

#include <utility>
#include <vector>
#include <string>

#include "Point.hpp"
#include "APoint.hpp"

namespace Snowball{

	class Line{
	public:
		virtual APoint::coords getPoints() const noexcept;
		
		Line(std::pair<int, int> coord1, std::pair<int, int> coord2);
		Line(const std::pair<int, int>& coord1, const int& length, const int& ang);
		
		bool crossed(const Line& line) const;
		size_t getLength() const noexcept;
		size_t getAng() const noexcept;
		Point getStart() const noexcept;
		Point getEnd() const noexcept;
		void moveRight();
		void moveLeft();
		void moveUp();
		void moveDown();
		std::string getCoords() const;
		virtual ~Line() = default;
	private:
		int orientation(const Point& a, const Point& b, const Point& c);
		bool onSegment(const Point& a, const Point& b, const Point& c);
	private:
		Point m_start;
		Point m_end;
		int m_length{0};
		int m_ang{0};
	};

}

#include "Line.impl.cpp"

#endif // __LINE__HPP__
