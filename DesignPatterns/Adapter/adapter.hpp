#ifndef __ADAPTER__HPP__
#define __ADAPTER__HPP__

class exchangeRate{
public:
    virtual size_t getValue() = 0;
    virtual ~exchangeRate(){}
private:
};

class ArmenianRate : public exchangeRate{
public:
    ArmenianRate(size_t value) : m_value(value){}
    size_t getValue(){
        return m_value;
    }
private:
    size_t m_value{0};
};

class USARate{
public:
    USARate(size_t value) : m_value(value){}
    size_t getValue() const{
        return m_value;
    }

    size_t m_value{0};
};

class AdapterForUSARate : public exchangeRate{
public:
    AdapterForUSARate(const USARate& USARatePtr) : m_USARate(USARatePtr.m_value){
    }
    ~AdapterForUSARate(){
    }
    size_t getValue(){
        m_value = m_USARate.getValue();
        m_value *= 404; 
        return m_value;
    }
private:
    USARate m_USARate;
    size_t m_value{0};
};

#endif // __ADAPTER__HPP__