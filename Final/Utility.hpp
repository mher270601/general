#ifndef __UTILITY__HPP__
#define __UTILITY__HPP__

#include <memory>
#include <utility>
#include <vector>

#include "Point.hpp"
#include "Line.hpp"

#define TAB "\t\t\t\t\t\t\t\t\t\t"

std::pair<Snowball::Point, Snowball::Point> findNearestPointPair(const std::vector<Snowball::Point>& bodyPoints, const std::vector<Snowball::Point>& snowballPoints);
std::vector<Snowball::Point> getLinePoints(const std::shared_ptr<Snowball::Line>& line);
int generateRandomValue(int start, int end);

#include "Utility.impl.cpp"

#endif // __UTILITY__HPP__
