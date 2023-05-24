#ifndef __COMMAND__TOKENIZER__HPP__
#define __COMMAND__TOKENIZER__HPP__

#include <exception>

#include "ITokenizer.hpp"

namespace PowerPoint{

    class Tokenizer : public ITokenizer{
    public:
        void Lexemmer(std::stringstream& expr) override;
        ~Tokenizer() = default;
        Tokenizer(const Tokenizer& rhs) = delete;
        Tokenizer& operator=(const Tokenizer& rhs) = delete;
        static Tokenizer& GetInstance();
    private:
        Tokenizer() = default;
        bool IsWord(const std::string& expr) const noexcept override;
        bool IsNumber(const std::string& expr) const noexcept override;
    };
}

#include "CmdTokenizer.impl.cpp"

#endif // __COMMAND__TOKENIZER__HPP__