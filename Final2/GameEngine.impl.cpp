#ifndef __GAME__ENGINE__IMPL__CPP__
#define __GAME__ENGINE__IMPL__CPP__

#include <memory>
#include <vector>
#include <utility>

#include "Man.hpp"
#include "Snowball.hpp"
#include "Line.hpp"
#include "Point.hpp"
#include "Utility.hpp"
#include "FileManager.hpp"

namespace Snowball{

	GameEngine& GameEngine::getInstance(){
		static GameEngine instance;
		return instance;
	}

	void GameEngine::execute(){
		FileManager& fileManager = FileManager::getInstance();
		fileManager.logMessage(std::string(TAB) + "GAME RESULTS");
		std::cout << TAB << "GAME RESULTS" << std::endl;
		std::shared_ptr<Man> man = std::make_shared<Man>();
		Snowball& snowball = Snowball::getInstance();
		man->moveTo(findNearestPointPair(man->getPoints(), snowball.getPoints()));

		int x = generateRandomValue(X_MIN_POINT, X_MAX_POINT);
		if(x < snowball.getPoints()[0].x){
			snowball.moveTo(std::pair<Point, Point>(Point(snowball.getPoints()[0].x, snowball.getPoints()[0].y), Point(x, snowball.getPoints()[0].y)));
		} else if(x > snowball.getPoints()[6].x){
			snowball.moveTo(std::pair<Point, Point>(Point(snowball.getPoints()[6].x, snowball.getPoints()[0].y), Point(x, snowball.getPoints()[0].y)));
		} else {
			std::cout << "Snowball already touched target !" << std::endl;
		}

	}

	GameEngine::GameEngine(){}

}

#endif // __GAME__ENGINE__IMPL__CPP__
