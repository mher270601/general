#ifndef __COMMAND__TOKENIZER__IMPL__CPP__
#define __COMMAND__TOKENIZER__IMPL__CPP__

#include <cctype>

#include "Token.hpp"
#include "CmdException.hpp"

namespace PowerPoint{

    Tokenizer& Tokenizer::GetInstance(){
        static Tokenizer instance;
        return instance;
    }
    void Tokenizer::Lexemmer(std::stringstream& expr){
        // TODO
        if(!IsWord(expr.str()) && !IsNumber(expr.str())){
            std::string _lexemmerError = "COMPILE ERROR: in case of \"";
            _lexemmerError = _lexemmerError + expr.str();
            _lexemmerError = _lexemmerError + "\"\n";
            throw CmdException(_lexemmerError);
        }
        //if(isdigit(expr.str()[0])){
        //    if(!IsNumber(expr.str())){
        //
        //    }
        //}
    }
    bool Tokenizer::IsWord(const std::string& expr) const noexcept{ // Need optimization
        if(expr[0] == '_' || isalpha(expr[0])){
            for(size_t i = 1; i < expr.length(); ++i){
                if(!isalpha(expr[i]) && !isdigit(expr[i]) && expr[i] != '_'){
                    return false;
                }
            }
            return true;
        }
        
        return false;
    }
    bool Tokenizer::IsNumber(const std::string& expr) const noexcept{
        for(const auto& _char : expr){
            if(!isdigit(_char)){
                return false;
            }
        }
        return true;
    }
}

#endif // __COMMAND__TOKENIZER__IMPL__CPP__