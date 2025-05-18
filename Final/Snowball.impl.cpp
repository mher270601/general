#ifndef __SNOWBALL__IMPL__CPP__
#define __SNOWBALL__IMPL__CPP__

#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>

#include "Utility.hpp"
#include "Point.hpp"

namespace Snowball{

	std::string Snowball::getCoordsInfo() const{
		std::string coordsInfo = "";
		for(auto& line : m_coords){
			coordsInfo += line->getCoords();
		}
		return coordsInfo;
	}

	Snowball& Snowball::getInstance(){
		static Snowball instance;
		return instance;
	}

	Snowball::Snowball(){
		int x = generateRandomValue(X_MIN_POINT, X_MAX_POINT);
		int y = generateRandomValue(Y_MIN_POINT, Y_MAX_POINT);
		m_coords.push_back(std::make_shared<Line>(std::pair<int,int>(x, y), std::pair<int, int>(x, y + SIDE_LENGTH)));
		m_coords.push_back(std::make_shared<Line>(std::pair<int,int>(x, y + SIDE_LENGTH), std::pair<int, int>(x + SIDE_LENGTH, y + SIDE_LENGTH)));
		m_coords.push_back(std::make_shared<Line>(std::pair<int,int>(x + SIDE_LENGTH, y + SIDE_LENGTH), std::pair<int, int>(x + SIDE_LENGTH, y)));
		m_coords.push_back(std::make_shared<Line>(std::pair<int,int>(x + SIDE_LENGTH, y), std::pair<int, int>(x, y)));
	}

	void Snowball::moveTo(const std::pair<Point, Point>& points){
		FileManager& fileMng = FileManager::getInstance();
		fileMng.logMessage("Nearest target coords x: " + std::to_string(points.second.x) + " y: " + std::to_string(points.second.y));
		std::cout << "Nearest target coords x: " << std::to_string(points.second.x) << " y: " << std::to_string(points.second.y) << std::endl;
		int currX = points.first.x;
		int currY = points.first.y;
		fileMng.logMessage("Go to target from nearest x: " + std::to_string(currX) + " y: " + std::to_string(currY));
		std::cout << "Go to target from nearest x: " << std::to_string(currX) << " y: " << std::to_string(currY) << std::endl;
		if(currX < points.second.x){
			fileMng.logMessage("\t\t(Snowball move right)");
			std::cout << "\t\t(Snowball move right)" << std::endl;
			while(currX != points.second.x){
				for(auto& line : m_coords){
					line->moveRight();
				}
				std::string coordsInfo = this->getCoordsInfo();
				fileMng.logMessage(coordsInfo);
				std::cout << coordsInfo << std::endl;
				++currX;
			}
		} else {
			fileMng.logMessage("\t\t(Snowball move left)");
			std::cout << "\t\t(Snowball move left)" << std::endl;
			while(currX != points.second.x){
				for(auto& line : m_coords){
					line->moveLeft();
				}
				std::string coordsInfo = this->getCoordsInfo();
				fileMng.logMessage(coordsInfo);
				std::cout << coordsInfo << std::endl;
				--currX;
			}
		}
		if(currY < points.second.y){
			fileMng.logMessage("\t\t(Snowball move up)");
			std::cout << "\t\t(Snowball move up)" << std::endl;
			while(currY != points.second.y){
				for(auto& line : m_coords){
					line->moveUp();
				}
				std::string coordsInfo = this->getCoordsInfo();
				fileMng.logMessage(coordsInfo);
				std::cout << coordsInfo << std::endl;
				++currY;
			}
		} else if(currY > points.second.y) {
			fileMng.logMessage("\t\t(Snowball move down)");
			std::cout << "\t\t(Snowball move down)" << std::endl;
			while(currY != points.second.y){
				for(auto& line : m_coords){
					line->moveDown();
				}
				std::string coordsInfo = this->getCoordsInfo();
				fileMng.logMessage(coordsInfo);
				std::cout << coordsInfo << std::endl;
				--currY;
			}
		}
		std::string congratulationMsg = std::string(TAB) + "*********************************\n" + 
						TAB + "*  Congratulations!             *\n" + 
						TAB + "*  The snowball hit the target! *\n" +
						TAB + "*********************************\n";
		fileMng.logMessage(congratulationMsg);
		std::cout << congratulationMsg << std::endl;
	}

	std::vector<Point> Snowball::getPoints() const{
		std::vector<Point> allPoints;

		for(const auto& line : m_coords){
			auto points = line->getPoints();
			allPoints.push_back(points.first);
			allPoints.push_back(points.second);
		}

		return allPoints;
	}

}

#endif // __SNOWBALL__IMPL__CPP__
