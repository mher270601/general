#ifndef __SLIDE__HPP__
#define __SLIDE__HPP__

#include <memory>
#include <string>

#include "ETypes.hpp"

namespace PowerPoint{
	
    class Slide/* : public IObject*/ {
    public:
        virtual ~Slide();
        using GroupPtr = std::shared_ptr<Group>;
	using SIObjectPtr = std::shared_ptr<IObject>;
        void AddObject(SIObjectPtr object);
        //void SetSize(const size_t) override;
        //void SetBorderSize(const size_t) override;
        //void SetColor(const Color) override;
        //void SetBackgroundColor(const Color) override;
        //void PrintMe() const noexcept override;
    private:
        std::vector<SIObjectPtr> m_slide;
    };

}

#include "Slide.impl.cpp"

#endif // __SLIDE__HPP__
