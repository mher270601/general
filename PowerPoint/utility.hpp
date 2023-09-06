#ifndef __UTILITY__HPP__
#define __UTILITY__HPP__

#include <algorithm>
#include <cassert>
#include <string>

#include "ETypes.hpp"

EColor getColor(std::string color){
	//Color _color;
	std::transform(color.begin(), color.end(), color.begin(), ::toupper);
	if(color == "BLACK"){
		return EColor::BLACK;
	}
	else if(color == "RED"){
		return EColor::RED;
	}
	else if(color == "BLUE"){
		return EColor::BLUE;
	}
	else if(color == "GREEN"){
		return EColor::GREEN;
	}
	else if(color == "WHITE"){
		return EColor::WHITE;
	}
	else if(color == "YELLOW"){
		return EColor::YELLOW;
	}
	else if(color == "PINK"){
		return EColor::PINK;
	}
	else if(color == "GREY"){
		return EColor::GREY;
	}
	assert(false && "Invalid color: Must not reach here !");
	//return _color;	
}

#endif // __UTILITY__HPP__
