#ifndef __POWER__POINT__HPP__
#define __POWER__POINT__HPP__

//#include "IObject.hpp"

#include "Text.hpp"
#include "Shape.hpp"
#include "Group.hpp"
#include "Slide.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

//#include <string>
//#include <memory>
//#include <vector>
//
//#include "Coordinates.hpp"
//#include "ETypes.hpp"
//
//namespace PowerPoint {
//
//    /*class IObject {
//    public:
//        virtual Color color() const noexcept = 0;
//        virtual Color backgroundColor() const noexcept = 0;
//        virtual size_t borderSize() const noexcept = 0;
//        virtual size_t size() const noexcept = 0;
//    };*/
//    
//
//
//    //class IObject { // Interface - abstract class
//    //public:
//    //    using IObjectPtr = std::shared_ptr<IObject>;
//    //public:
//    //    IObject() = default;
//    //    virtual ~IObject() = default;
//    //    //virtual std::string getTypeName() const = 0;
//    //    virtual void SetSize(const size_t) = 0;
//    //    virtual void SetBorderSize(const size_t) = 0;
//    //    virtual void SetColor(const Color) = 0;
//    //    virtual void SetBackgroundColor(const Color) = 0;
//    //    virtual void PrintMe() const noexcept = 0;
//    //private:
//
//    //}; // IObject
//
//
//    //class Text : public IObject {
//    //public:
//    //    using TextPtr = std::shared_ptr<Text>;
//    //    Text(const std::string&, Color, Color, const size_t);
//
//    //    void SetSize(const size_t) override;
//    //    void SetBorderSize(const size_t) override;
//    //    void SetColor(const Color) override;
//    //    void SetBackgroundColor(const Color) override;
//    //    void PrintMe() const noexcept override;
//    //    ~Text();
//    //private:
//    //    std::string m_text{ "" };
//    //    ItemData m_data;
//
//    //}; // Text
//
//    //class Shape : public IObject {
//    //public:
//    //    using ShapePtr = std::shared_ptr<Shape>;
//    //    Shape(const Shapes&, Color, Color, const size_t);
//
//    //    void SetSize(const size_t) override;
//    //    void SetBorderSize(const size_t) override;
//    //    void SetColor(const Color) override;
//    //    void SetBackgroundColor(const Color) override;
//    //    virtual void PrintMe() const noexcept;
//
//    //    virtual ~Shape();
//    //protected:
//    //    Shapes m_shape;
//    //    ItemData m_data;
//
//    //}; // Shape
//
//    /*class IItemGroup {
//    public:
//        virtual void SetSize(const size_t) = 0;
//        virtual void SetBorderSize(const size_t) = 0;
//        virtual void SetColor(const Color) = 0;
//        virtual void SetBackgroundColor(const Color) = 0;
//        virtual void PrintMe() const noexcept = 0;
//    private:
//    };*/
//
//    /*class Item {
//    public:
//        using ItemPtr = std::shared_ptr<Item>;
//    protected:
//        void MoveRight(const size_t plusX);
//        void MoveLeft(const size_t minusX);
//        void MoveTop(const size_t plusY);
//        void MoveBottom(const size_t minusY);
//        Coords m_coords;
//    private:
//    };*/
//
//    //class GroupItem : public IObject {
//    //public:
//    //    using ItemPtr = std::shared_ptr<GroupItem>;
//    //    void AddObject(ItemPtr);
//    //    void SetSize(const size_t) override;
//    //    void SetBorderSize(const size_t) override;
//    //    void SetColor(const Color) override;
//    //    void SetBackgroundColor(const Color) override;
//    //    void PrintMe() const noexcept override;
//    //    void MoveRight(const size_t plusX);
//    //    void MoveLeft(const size_t minusX);
//    //    void MoveTop(const size_t plusY);
//    //    void MoveBottom(const size_t minusY);
//    //    Coords m_coords;
//    //private:
//    //    std::vector<ItemPtr> m_group;
//    //};
//
//
//    /*class IItemGroup {
//    public:
//        virtual void SetSize(const size_t) = 0;
//        virtual void SetBorderSize(const size_t) = 0;
//        virtual void SetColor(const Color) = 0;
//        virtual void SetBackgroundColor(const Color) = 0;
//        virtual void PrintMe() const noexcept = 0;
//    private:
//    };
//
//    class Item {
//    public:
//        using ItemPtr = std::shared_ptr<Item>;
//    protected:
//        void MoveRight(const size_t plusX);
//        void MoveLeft(const size_t minusX);
//        void MoveTop(const size_t plusY);
//        void MoveBottom(const size_t minusY);
//        Coords m_coords;
//    private:
//    };
//
//    class GroupItem : public IItemGroup, public Item {
//    public:
//        void AddObject(ItemPtr);
//        void SetSize(const size_t) override;
//        void SetBorderSize(const size_t) override;
//        void SetColor(const Color) override;
//        void SetBackgroundColor(const Color) override;
//        void PrintMe() const noexcept override;
//    private:
//        std::vector<ItemPtr> m_group;
//    };
//
//    class Slide : public IItemGroup { 
//    public:
//        ~Slide();
//        void AddObject(Item* object);
//        void SetSize(const size_t) override;
//        void SetBorderSize(const size_t) override;
//        void SetColor(const Color) override;
//        void SetBackgroundColor(const Color) override;
//        void PrintMe() const noexcept override;
//    private:
//        std::vector<Item*> m_slide;
//    };*/
//
//    //class Group : public IObject {
//    //public:
//    //    using GroupPtr = std::shared_ptr<Group>;
//    //    void AddGroup(const IObjectPtr&);
//    //    ~Group();
//    //    void SetSize(const size_t) override;
//    //    void SetBorderSize(const size_t) override;
//    //    void SetColor(const Color) override;
//    //    void SetBackgroundColor(const Color) override;
//    //    void PrintMe() const noexcept override;
//    //    void MoveRight(const size_t plusX);
//    //    void MoveLeft(const size_t minusX);
//    //    void MoveTop(const size_t plusY);
//    //    void MoveBottom(const size_t minusY);
//    //private:
//    //    std::vector<IObjectPtr> m_groupItems;
//
//    //}; // ShapeGroup
//
//    //class Slide/* : public IObject*/ {
//    //public:
//    //    virtual ~Slide();
//    //    using GroupPtr = std::shared_ptr<Group>;
//    //    using SIObjectPtr = std::shared_ptr<IObject>;
//    //    void AddObject(SIObjectPtr object);
//    //    //void SetSize(const size_t) override;
//    //    //void SetBorderSize(const size_t) override;
//    //    //void SetColor(const Color) override;
//    //    //void SetBackgroundColor(const Color) override;
//    //    //void PrintMe() const noexcept override;
//    //private:
//    //    std::vector<SIObjectPtr> m_slide;
//    //};
//
//    //class Rectangle : public Shape {
//    //public:
//    //    Rectangle(Color, Color, const size_t);
//    //    Rectangle() = default;
//    //    void PrintMe() const noexcept override;
//    //	~Rectangle();
//    //private:
//
//    //}; // Rectangle
//
//    //class Square : public Shape {
//    //public:
//    //    Square(Color, Color, const size_t);
//    //    void PrintMe() const noexcept override;
//    //private:
//
//    //}; // Square
//
//    //class Triangle : public Shape {
//    //public:
//    //    Triangle(Color, Color, const size_t);
//    //    void PrintMe() const noexcept override;
//    //private:
//
//    //}; // Triangle
//
//    //class Circle : public Shape {
//    //public:
//    //    Circle(Color, Color, const size_t);
//    //    void PrintMe() const noexcept override;
//    //private:
//
//    //}; // Circle
//
//    class Data{
//    public:
//	    
//    private:
//	std::vector<std::shared_ptr<Slide>> m_slides;
//	//std::vector<std::shared_ptr<GroupItem>> m_groups;
//    };
//
//} // PowerPoint namespace
//
//#include "PowerPoint.impl.hpp"

#endif // __POWER__POINT__HPP__
