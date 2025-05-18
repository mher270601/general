#ifndef __MAN__HPP__
#define __MAN__HPP__

#include <memory>
#include <vector>
#include <utility>

#include "IMovable.hpp"
#include "Line.hpp"
#include "Body.hpp"
#include "IPointContainer.hpp"

namespace Snowball{

	class Man : public IPointContainer, public IMovable{
	public:
		using Head = std::vector<std::shared_ptr<Line>>;
	public:
		void moveTo(const std::pair<Point, Point>& points) override;
		std::vector<Point> getPoints() const override;
		Man();
	private:
		std::string getCoordsInfo() const override;
	private:
		std::shared_ptr<Body> m_body;
	};

}

#include "Man.impl.cpp"

#endif // __MAN__HPP__
