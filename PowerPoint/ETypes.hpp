#ifndef __ETYPES__HPP__
#define __ETYPES__HPP__

#include "ECoordinates.hpp"

enum class Color {
    RED,
    BLUE,
    GREEN,
    BLACK,
    WHITE,
    YELLOW,
    PINK,
    GREY
};

struct ItemData {
    Color color = Color::BLACK;
    Color backgroundColor = Color::WHITE;
    Coords m_coords;
    size_t size{ 12 };
    size_t borderSize{ 2 };
    ItemData(const Color& _color, const Color& _backColor, const size_t _size) :
        									color{ _color },
        									backgroundColor{ _backColor },
        									size{ _size }
    {}
    ItemData() = default;
};

enum class Shapes {
    Square,
    Rectangle,
    Circle,
    Triangle,
    Oval
};


#endif // __ETYPES__HPP__
