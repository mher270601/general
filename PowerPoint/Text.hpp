#ifndef __TEXT__HPP__
#define __TEXT__HPP__

#include <memory>
#include <string>

#include "ETypes.hpp"
#include "IObject.hpp"

namespace PowerPoint{
    class Text : public IObject {
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
}
#include "Text.impl.cpp"

#endif // __TEXT__HPP__
