#ifndef __ETYPES__HPP__
#define __ETYPES__HPP__

#include <string>

#include "ECoordinates.hpp"

enum class EObjectType{
	TEXT,
	SHAPE,
};

enum class EColor {
    RED,
    BLUE,
    GREEN,
    BLACK,
    WHITE,
    YELLOW,
    PINK,
    GREY,
};

enum class EShape {
    Square,
    Rectangle,
    Circle,
    Triangle,
    Oval,
};

struct ItemData {
    //ItemData() = default;
    ItemData(){}
    ItemData(const EColor& _color, const EColor& _backColor, const size_t _size, const EObjectType _objectType) :
        									m_color{ _color },
        									m_backgroundColor{ _backColor },
        									m_size{ _size },
										m_objectType{ _objectType }
    {}
    ~ItemData(){}
    EObjectType m_objectType;
    EColor m_color = EColor::BLACK;
    EColor m_backgroundColor = EColor::WHITE;
    Coords m_coords;
    size_t m_size{ 12 };
    size_t m_borderSize{ 2 };
    union{
	std::string m_text;
	EShape m_shapeType;
    };
};

#endif // __ETYPES__HPP__
