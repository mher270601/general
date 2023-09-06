#ifndef __TOKEN__HPP__
#define __TOKEN__HPP__

#include <string>

namespace PowerPoint{

    enum class ETokenType{
        Invalid,
        Identifier,
        Number
    };

    enum class ECommandType{
        Set,
        Reset,
        Create,
        Present,
        Add,
        Remove
    };

    struct Token{
        ETokenType m_tokenType;
        union{
            ECommandType m_commandType;
            int number;
        };
    };

}

#endif // __TOKEN__HPP__
