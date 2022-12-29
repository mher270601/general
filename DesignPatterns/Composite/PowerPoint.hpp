#ifndef __POWER__POINT__H__
#define __POWER__POINT__H__

#include <string>
#include <memory>
#include <vector>

#include "ETypes.hpp"

namespace PowerPoint {
    
    class IAttributeModifier { // Interface - abstract class
    public:
        using IObjectPtr = std::shared_ptr<IAttributeModifier>;
    public:
        IAttributeModifier() = default;
        virtual ~IAttributeModifier() = default;

        void virtual SetSize(const size_t) = 0;
        void virtual SetBorderSize(const size_t) = 0;
        void virtual SetColor(const Color) = 0;
        void virtual SetBackgroundColor(const Color) = 0;
	void virtual PrintMe() const noexcept = 0;
    private:

    }; // IAttributeModifier


    class Text : public IAttributeModifier {
    public:
        using TextPtr = std::shared_ptr<Text>;
        Text(const std::string&, Color, Color, const size_t);

        void SetSize(const size_t) override;
        void SetBorderSize(const size_t) override;
        void SetColor(const Color) override;
        void SetBackgroundColor(const Color) override;
	void PrintMe() const noexcept override;
        ~Text();
    private:
        std::string m_text{ "" };
        ItemData m_data;

    }; // Text

    class Shape : public IAttributeModifier {
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

    class Group : public IAttributeModifier {
    public:
        using GroupPtr = std::shared_ptr<Group>;
        void AddGroup(const IObjectPtr&);
        Group()=default;
	~Group();
        void SetSize(const size_t) override;
        void SetBorderSize(const size_t) override;
        void SetColor(const Color) override;
        void SetBackgroundColor(const Color) override;
	void PrintMe() const noexcept override;
    private:
        std::vector<IObjectPtr> m_groupItems;

    }; // ShapeGroup


    class Rectangle : public Shape {
    public:
        Rectangle(Color, Color, const size_t);
        Rectangle() = default;
        void PrintMe() const noexcept override;
    private:

    }; // Rectangle

    class Square : public Shape {
    public:
        Square(Color, Color, const size_t);
        void PrintMe() const noexcept override;
    private:

    }; // Square

    class Triangle : public Shape {
    public:
        Triangle(Color, Color, const size_t);
        void PrintMe() const noexcept override;
    private:

    }; // Triangle

    class Circle : public Shape {
    public:
        Circle(Color, Color, const size_t);
        void PrintMe() const noexcept override;
    private:

    }; // Circle

} // PowerPoint namespace

#include "PowerPoint.impl.hpp"

#endif // __POWER__POINT__H__
