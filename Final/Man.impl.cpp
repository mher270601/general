#ifndef __MAN__IMPL__CPP__
#define __MAN__IMPL__CPP__

#include <memory>
#include <vector>
#include <string>

#include "Point.hpp"
#include "Line.hpp"
#include "Utility.hpp"
#include "FileManager.hpp"

namespace Snowball{

	std::string Man::getCoordsInfo() const{
		std::string coordsInfo = "";
		coordsInfo += "Left foot\n";
		coordsInfo += m_body->m_lf->getCoords();
		coordsInfo += "Right foot\n";
		coordsInfo += m_body->m_rf->getCoords();
		coordsInfo += "Body\n";
		coordsInfo += m_body->m_body->getCoords();
		coordsInfo += "Left hand\n";
		coordsInfo += m_body->m_lh->getCoords();
		coordsInfo += "Right hand\n";
		coordsInfo += m_body->m_rh->getCoords();
		coordsInfo += "Head\n";
		for(auto& line : m_body->m_head){
			coordsInfo += line->getCoords();
		}
		return coordsInfo;
	}

	void Man::moveTo(const std::pair<Point, Point>& points){
		FileManager& fileMng = FileManager::getInstance();
		std::cout << "Nearest snowball coords x: " << std::to_string(points.second.x) << " y: " << std::to_string(points.second.y) << std::endl;
		fileMng.logMessage("Nearest snowball coords x: " + std::to_string(points.second.x) + " y: " + std::to_string(points.second.y));
		int currX = points.first.x;
		int currY = points.first.y;
		fileMng.logMessage("Walk to snowball from nearest x: " + std::to_string(currX) + " y: " + std::to_string(currY));
		std::cout << "Walk to snowball from nearest x: " << std::to_string(currX) << " y: " << std::to_string(currY) << std::endl;
		std::string logCoords = "";
		if(currX < points.second.x){
			fileMng.logMessage("\t\t(Man move right)");
			std::cout << "\t\t(Man move right)" << std::endl;
			while(currX != points.second.x){
				m_body->m_lf->moveRight();
				m_body->m_rf->moveRight();
				m_body->m_lh->moveRight();
				m_body->m_rh->moveRight();
				m_body->m_body->moveRight();
				for(auto& line : m_body->m_head){
					line->moveRight();
				}
				std::string coordsInfo = this->getCoordsInfo();
				fileMng.logMessage(coordsInfo);
				std::cout << coordsInfo << std::endl;
				++currX;
			}
		} else{
			fileMng.logMessage("\t\t(Man move left)");
			std::cout << "\t\t(Man move left)" << std::endl;
			while(currX != points.second.x){
				m_body->m_lf->moveLeft();
				m_body->m_rf->moveLeft();
				m_body->m_lh->moveLeft();
				m_body->m_rh->moveLeft();
				m_body->m_body->moveLeft();
				for(auto& line : m_body->m_head){
					line->moveLeft();
				}
				std::string coordsInfo = this->getCoordsInfo();
				fileMng.logMessage(coordsInfo);
				std::cout << coordsInfo << std::endl;
				--currX;
			}
		}
		std::string reachingMsg = std::string(TAB) + "**********************************\n" +
						      TAB + "*  The man reached the snowball. *\n" +
						      TAB + "**********************************\n";
		fileMng.logMessage(reachingMsg);
		std::cout << reachingMsg << std::endl;
	}

	Man::Man() {
		m_body = std::make_shared<Body>();
		using Pair = std::pair<int, int>;
		int x = generateRandomValue(X_MIN_POINT, X_MAX_POINT);
		int y = 0;
		int footsDistance = SIDE_LENGTH % 2 ? (SIDE_LENGTH - 1) : SIDE_LENGTH;
		std::pair<int, int> p1(x, y);	
		std::pair<int, int> p2(x + SIDE_LENGTH / 2, y + SIDE_LENGTH);	
		
		// Construct foots
		m_body->m_lf = std::make_shared<Line>(p1, p2);
		m_body->m_rf = std::make_shared<Line>(Pair(x + SIDE_LENGTH / 2, y + SIDE_LENGTH), Pair(x + footsDistance, y));
		
		// Construct body
		m_body->m_body = std::make_shared<Line>(Pair(x + SIDE_LENGTH / 2, y + SIDE_LENGTH), Pair(x + SIDE_LENGTH / 2, y + SIDE_LENGTH * 2));

		// Construct left hand
		m_body->m_lh = std::make_shared<Line>(Pair(x + SIDE_LENGTH / 2, y + SIDE_LENGTH * 2), Pair(x, y + SIDE_LENGTH));

		// Construct right hand
		m_body->m_rh = std::make_shared<Line>(Pair(x + SIDE_LENGTH / 2, y + SIDE_LENGTH * 2), Pair(x + footsDistance, y + SIDE_LENGTH));

		// Construct head
		m_body->m_head.push_back(std::make_shared<Line>(Pair(x + SIDE_LENGTH / 4, y + footsDistance), Pair(x + SIDE_LENGTH / 4, y + footsDistance + SIDE_LENGTH)));
		m_body->m_head.push_back(std::make_shared<Line>(Pair(x + SIDE_LENGTH / 4, y + footsDistance + SIDE_LENGTH), Pair(x + SIDE_LENGTH - SIDE_LENGTH / 4, y + footsDistance + SIDE_LENGTH)));
		m_body->m_head.push_back(std::make_shared<Line>(Pair(x + SIDE_LENGTH - SIDE_LENGTH / 4, y + footsDistance + SIDE_LENGTH), Pair(x + SIDE_LENGTH - SIDE_LENGTH / 4, y + footsDistance)));
		m_body->m_head.push_back(std::make_shared<Line>(Pair(x + SIDE_LENGTH - SIDE_LENGTH / 4, y + footsDistance), Pair(x + SIDE_LENGTH / 4, y + footsDistance)));
	}

	std::vector<Point> Man::getPoints() const{
		std::vector<Point> allPoints;

		// Add head
		for(const auto& line : m_body->m_head){
			auto points = line->getPoints();
			allPoints.push_back(points.first);
			allPoints.push_back(points.second);
		}
		
		// Add body
		for(const auto& point : getLinePoints(m_body->m_body)){
			allPoints.push_back(point);
		}
		// Add right hand
		for(const auto& point : getLinePoints(m_body->m_rh)){
			allPoints.push_back(point);
		}
		// Add left hand
		for(const auto& point : getLinePoints(m_body->m_lf)){
			allPoints.push_back(point);
		}
		// Add right foot
		for(const auto& point : getLinePoints(m_body->m_rf)){
			allPoints.push_back(point);
		}
		// Add left hand
		for(const auto& point : getLinePoints(m_body->m_lf)){
			allPoints.push_back(point);
		}
		return allPoints;
	}

}

#endif // __MAN__IMPL__CPP__
