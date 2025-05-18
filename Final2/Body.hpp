#ifndef __BODY__HPP__
#define __BODY__HPP__

#include <memory>
#include <vector>
#include <utility>

#include "Line.hpp"

namespace Snowball{

	struct Body{
		Body() = default;
		using Head = std::vector<std::shared_ptr<Line>>;
		Head m_head;
		std::shared_ptr<Line> m_body;
		std::shared_ptr<Line> m_rh;
		std::shared_ptr<Line> m_lh;
		std::shared_ptr<Line> m_rf;
		std::shared_ptr<Line> m_lf;
	};

}

#endif // __BODY__HPP__
