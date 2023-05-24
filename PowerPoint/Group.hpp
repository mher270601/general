#ifndef __GROUP__HPP__
#define __GROUP__HPP__

#include <memory>
#include <string>
#include <vector>

#include "ETypes.hpp"
#include "IObject.hpp"

namespace PowerPoint{

    class Group : public IObject {
    public:
        using GroupPtr = std::shared_ptr<Group>;
        void AddGroup(const IObjectPtr&);
        ~Group();
        void SetSize(const size_t) override;
        void SetBorderSize(const size_t) override;
        void SetColor(const Color) override;
        void SetBackgroundColor(const Color) override;
        void PrintMe() const noexcept override;
        void MoveRight(const size_t plusX);
        void MoveLeft(const size_t minusX);
        void MoveTop(const size_t plusY);
        void MoveBottom(const size_t minusY);
    private:
        std::vector<IObjectPtr> m_groupItems;

    }; // ShapeGroup
	
}

#include "Group.impl.cpp"

#endif // __GROUP__HPP__
