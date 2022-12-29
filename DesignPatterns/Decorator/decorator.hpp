#ifndef __DECORATOR__HPP__
#define __DECORATOR__HPP__

#include <iostream>

class IBurger{
public:
    virtual void process() = 0;
    virtual size_t getPrice() const noexcept = 0;
    virtual size_t getKcal() const noexcept = 0;
};

class ClassicBurger : public IBurger{
public:
    void process() override{
        std::cout << "Classic burger is done" << std::endl;
    }
    size_t getPrice() const noexcept {
        return m_price;
    }
    size_t getKcal() const noexcept {
        return m_kcal;
    }
private:
    size_t m_kcal{40};
    size_t m_price{20};
};

class Ingredient : public IBurger{
public:
    Ingredient(IBurger* ptr) : m_burger(ptr){}
    void process() override{
        m_burger->process();
    }
    size_t getPrice() const noexcept {
        return m_burger->getPrice() + m_price;
    }
    size_t getKcal() const noexcept {
        return m_burger->getKcal() + m_kcal;
    }
protected:
    IBurger* m_burger;
private:
    size_t m_kcal{0};
    size_t m_price{0};
};

class Onion : public Ingredient{
public:
    Onion(IBurger* ptr) : Ingredient(ptr){}
    void process() override{
        std::cout << "Onion is included" << std::endl;
        m_burger->process();
    }
    size_t getPrice() const noexcept {
        return m_burger->getPrice() + m_price;
    }
    size_t getKcal() const noexcept {
        return m_burger->getKcal() + m_kcal;
    }
private:
    size_t m_kcal{15};
    size_t m_price{8};
};

class Tomat : public Ingredient{
public:
    Tomat(IBurger* ptr) : Ingredient(ptr) {}
    void process() override{
        std::cout << "Tomat is included" << std::endl;
        m_burger->process();
    }
    size_t getPrice() const noexcept {
        return m_burger->getPrice() + m_price;
    }
    size_t getKcal() const noexcept {
        return m_burger->getKcal() + m_kcal;
    }
private:
    size_t m_kcal{120};
    size_t m_price{70};
};

#endif // __DECORATOR__HPP__
