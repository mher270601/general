#ifndef __SHAPE__HPP__
#define __SHAPE__HPP__

#include <memory>
#include <string>

#include "ETypes.hpp"
#include "IObject.hpp"

namespace PowerPoint{

    class Shape : public IObject {
    public:
	Shape(const std::string& objectName, const EShape& shape, EColor color, EColor backgroundColor, const size_t size);
	//virtual EShape GetShapeType() const noexcept = 0;
        
	//Shape(const Shapes&, Color, Color, const size_t);

        //void SetSize(const size_t) override;
        //void SetBorderSize(const size_t) override;
        //void SetColor(const Color) override;
        //void SetBackgroundColor(const Color) override;
        //void PrintMe() const noexcept override;

        virtual ~Shape();
    //protected:
	//virtual void generateIdentifier() = 0;
    protected:
        //Shapes m_shape;
        //ItemData m_data;

    }; // Shape
        
    using ShapePtr = std::shared_ptr<Shape>;

}

#include "Shape.impl.cpp"

#endif // __SHAPE__HPP__
