#ifndef __UTILITY__HPP__
#define __UTILITY__HPP__

#include <algorithm>
#include <cassert>
#include <string>

#include "ETypes.hpp"

Color getColor(std::string color){
	//Color _color;
	std::transform(color.begin(), color.end(), color.begin(), ::toupper);
	if(color == "BLACK"){
		return Color::BLACK;
	}
	else if(color == "RED"){
		return Color::RED;
	}
	else if(color == "BLUE"){
		return Color::BLUE;
	}
	else if(color == "GREEN"){
		return Color::GREEN;
	}
	else if(color == "WHITE"){
		return Color::WHITE;
	}
	else if(color == "YELLOW"){
		return Color::YELLOW;
	}
	else if(color == "PINK"){
		return Color::PINK;
	}
	else if(color == "GREY"){
		return Color::PINK;
	}
	assert(false && "Invalid color: Must not reach here !");
	//return _color;	
}

#endif // __UTILITY__HPP__
