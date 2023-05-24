#ifndef __SHAPE__HPP__
#define __SHAPE__HPP__

#include <memory>
#include <string>

#include "ETypes.hpp"
#include "IObject.hpp"

namespace PowerPoint{

    class Shape : public IObject {
    public:
        using ShapePtr = std::shared_ptr<Shape>;
        Shape(const Shapes&, Color, Color, const size_t);

        void SetSize(const size_t) override;
        void SetBorderSize(const size_t) override;
        void SetColor(const Color) override;
        void SetBackgroundColor(const Color) override;
        virtual void PrintMe() const noexcept;

        virtual ~Shape();
    protected:
        Shapes m_shape;
        ItemData m_data;

    }; // Shape

}

#include "Shape.impl.cpp"

#endif // __SHAPE__HPP__
