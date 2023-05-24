#ifndef __TOKEN__HPP__
#define __TOKEN__HPP__

#include <string>

namespace PowerPoint{

    enum class ETokenType{
        Invalid,
        Identifier,
        Number
    };

    enum class EActionType{
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
            EActionType m_actionType;
            int number;
        };
    };

}

#endif // __TOKEN__HPP__