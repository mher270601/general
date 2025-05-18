#ifndef __LINE__IMPL__CPP__
#define __LINE__IMPL__CPP__

#include <cstdlib>
#include <utility>
#include <string>

#include "Point.hpp"

namespace Snowball{
		
	std::string Line::getCoords() const{
		std::string coords = "";
		coords += "x1: " + std::to_string(m_start.x) + 
			" y1: " + std::to_string(m_start.y) + 
			" x2: " + std::to_string(m_end.x) + 
			" y2: " + std::to_string(m_end.y) + "\n";
		return coords;
	}	

	APoint::coords Line::getPoints() const noexcept{
		return std::pair<Point, Point>(m_start, m_end);
	}

	void Line::moveRight(){
		m_start.x += 1;
		m_end.x += 1;
	}
	
	void Line::moveLeft(){
		m_start.x -= 1;
		m_end.x -= 1;
	}
	
	void Line::moveUp(){
		m_start.y += 1;
		m_end.y += 1;
	}
	
	void Line::moveDown(){
		m_start.y -= 1;
		m_end.y -= 1;
	}

	bool Line::crossed(const Line& other) const {
	    auto [p1, p2] = this->getPoints();
	    auto [q1, q2] = other.getPoints();
	
	    auto orientation = [](const Point& a, const Point& b, const Point& c) -> int {
	        int val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
	        return val;
	    };
	
	    auto onSegment = [](const Point& a, const Point& b, const Point& c) -> bool {
	        return std::min(a.x, c.x) <= b.x && b.x <= std::max(a.x, c.x) &&
	               std::min(a.y, c.y) <= b.y && b.y <= std::max(a.y, c.y);
	    };
	
	    int o1 = orientation(p1, p2, q1);
	    int o2 = orientation(p1, p2, q2);
	    int o3 = orientation(q1, q2, p1);
	    int o4 = orientation(q1, q2, p2);
	
	    if ((o1 * o2 < 0) && (o3 * o4 < 0)) {
	        return true;
	    }
	
	    if (o1 == 0 && onSegment(p1, q1, p2)) return true;
	    if (o2 == 0 && onSegment(p1, q2, p2)) return true;
	    if (o3 == 0 && onSegment(q1, p1, q2)) return true;
	    if (o4 == 0 && onSegment(q1, p2, q2)) return true;
	
	    return false;
	}
	
	int Line::orientation(const Point& a, const Point& b, const Point& c) {
	    return (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
	}

	bool onSegment(const Point& a, const Point& b, const Point& c) {
    		return std::min(a.x, c.x) <= b.x && b.x <= std::max(a.x, c.x) && std::min(a.y, c.y) <= b.y && b.y <= std::max(a.y, c.y);
	}

	size_t Line::getLength() const noexcept{
		return m_length;
	}
	size_t Line::getAng() const noexcept{
		return m_ang;
	}
	Point Line::getStart() const noexcept{
		return m_start;
	}
	Point Line::getEnd() const noexcept{
		return m_end;
	}

	Line::Line(std::pair<int, int> coord1, std::pair<int, int> coord2) : m_start(coord1.first, coord1.second), m_end(coord2.first, coord2.second){
	}
		
	Line::Line(const std::pair<int, int>& coord1, const int& length, const int& ang) : m_start(coord1.first, coord1.second), m_length(length), m_ang(ang){}

}

#endif // __LINE__IMPL__CPP__
