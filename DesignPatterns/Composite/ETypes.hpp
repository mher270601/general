#ifndef __ETYPES__H__
#define __ETYPES__H__

enum class Color {
    Red,
    Blue,
    Green,
    Black,
    White,
    Yellow,
    Pink,
    Grey
};

struct ItemData {
    Color color = Color::Black;
    Color backgroundColor = Color::White;
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


#endif // __ETYPES__H__