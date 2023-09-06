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
        Text(const std::string& objectName, const std::string&, EColor, EColor, const size_t);
	Text(const std::string& objectName);
        void SetSize(const size_t) override;
        void SetBorderSize(const size_t) override;
        void SetColor(const EColor) override;
        void SetBackgroundColor(const EColor backgroundColor) override;
        void PrintMe() const noexcept override;
        void MoveRight(const size_t plusX) override;
        void MoveLeft(const size_t minusX) override;
        void MoveTop(const size_t plusY) override;
        void MoveBottom(const size_t minusY) override;
	//void GenerateIdentifier() override;
	std::string GetText() const noexcept;
        virtual ~Text();
    private:
        //std::string m_text{ "" };
        ItemData m_data;

    }; // Text
}
#include "Text.impl.cpp"

#endif // __TEXT__HPP__
