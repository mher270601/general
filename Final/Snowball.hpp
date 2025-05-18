#ifndef __SNOWBALL__HPP__
#define __SNOWBALL__HPP__

#include <memory>
#include <vector>
#include <string>

#include "IMovable.hpp"
#include "Point.hpp"
#include "IPointContainer.hpp"

namespace Snowball{

	class Snowball : public IPointContainer, public IMovable{
	public:
		static Snowball& getInstance();
		Snowball& operator=(const Snowball& rhs) = delete;
		Snowball(const Snowball& rhs) = delete;
		std::vector<Point> getPoints() const override;
		void moveTo(const std::pair<Point, Point>& target) override;
	private:	
		std::string getCoordsInfo() const override;
		Snowball();
	private:
		std::vector<std::shared_ptr<Line>> m_coords;
	};

}

#include "Snowball.impl.cpp"

#endif // __SNOWBALL__HPP__
