#ifndef __ITOKENIZER__HPP__
#define __ITOKENIZER__HPP__

#include <iostream>

#include "Token.hpp"

namespace PowerPoint{
    class ITokenizer{
    public:
        virtual void Lexemmer(std::stringstream& expr) = 0;
        virtual ~ITokenizer() = default;
    protected:
        virtual bool IsWord(const std::string& expr) const noexcept = 0;
        virtual bool IsNumber(const std::string& expr) const noexcept = 0;
    };
}

#endif // __ITOKENIZER__HPP__