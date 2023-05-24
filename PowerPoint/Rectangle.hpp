#ifndef __RECTANGLE__HPP__
#define __RECTANGLE__HPP__

#include <memory>
#include <string>

#include "ETypes.hpp"
#include "IObject.hpp"

namespace PowerPoint{

    class Rectangle : public Shape {
    public:
        Rectangle(Color, Color, const size_t);
        Rectangle() = default;
        void PrintMe() const noexcept override;
    	~Rectangle();
    private:

    }; // Rectangle

}

#include "Rectangle.impl.cpp"

#endif // __RECTANGLE__HPP__
