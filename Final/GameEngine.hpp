#ifndef __GAME__ENGINE__HPP__
#define __GAME__ENGINE__HPP__

#include <memory>
#include <vector>
#include <utility>

#include "Man.hpp"
#include "Snowball.hpp"
#include "Line.hpp"
#include "Point.hpp"

namespace Snowball{

	class GameEngine{
	public:
		static GameEngine& getInstance();
		GameEngine& operator=(const GameEngine& rhs) = delete;
		GameEngine(const GameEngine& rhs) = delete;
		void execute();
	private:
		GameEngine();
	};

}

#include "GameEngine.impl.cpp"

#endif // __GAME__ENGINE__HPP__
