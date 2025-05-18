#ifndef __UTILITY__IMPL__CPP__
#define __UTILITY__IMPL__CPP__

#include <utility>
#include <vector>
#include <random>

#include "Point.hpp"

std::pair<Snowball::Point, Snowball::Point> findNearestPointPair(const std::vector<Snowball::Point>& bodyPoints, const std::vector<Snowball::Point>& snowballPoints){
    double minDist = std::numeric_limits<double>::max();
    std::pair<Snowball::Point, Snowball::Point> closestPair;

    for (const auto& p1 : bodyPoints) {
        for (const auto& p2 : snowballPoints) {
            double dist = std::hypot(p1.x - p2.x, p1.y - p2.y);
            if (dist < minDist) {
                minDist = dist;
                closestPair = {p1, p2};
            }
        }
    }

    return closestPair;
}
	
std::vector<Snowball::Point> getLinePoints(const std::shared_ptr<Snowball::Line>& line){
	std::vector<Snowball::Point> linePoints;
	std::pair<Snowball::Point, Snowball::Point> points = line->getPoints();
	linePoints.push_back(points.first);
	linePoints.push_back(points.second);
	return linePoints;
}

int generateRandomValue(int start, int end){	
	std::random_device rd;
    	std::mt19937 gen(rd());
    	std::uniform_int_distribution<> distr(start, end);

    	int randomNum = distr(gen);
	return randomNum;
}

#endif // __UTILITY__IMPL__CPP__
