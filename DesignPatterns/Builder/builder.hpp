#ifndef __BUILDER__HPP__
#define __BUILDER__HPP__

#include <iostream>
#include <string>

using namespace std;

class Phone {
public:
    Phone(){}
    string aboutPhone() const noexcept{
        return m_info;
    }
    void appendInfo(string info){
        m_info += info + ", ";
    }
private:
    string m_info{""};
};

class IDeveloper{
public:
    virtual void createDisplay() = 0;
    virtual void createBox() = 0;
    virtual void systemInstall() = 0;
    
    virtual Phone* getPhone() = 0;
};

class AndroidDeveloper : public IDeveloper {
public:
    AndroidDeveloper(){
        m_phone = new Phone();
    }
    ~AndroidDeveloper(){
        delete m_phone;
    }
    
    void createDisplay() override{
        m_phone->appendInfo("Created display of Samsung");
    }
    void createBox() override{
        m_phone->appendInfo("Created box of Samsung");
    }
    void systemInstall() override{
        m_phone->appendInfo("Installed Android system");
    }
    
    Phone* getPhone() override{
        return m_phone;
    }
private:
    Phone* m_phone;
};

class IPhoneDeveloper : public IDeveloper{
public:
    IPhoneDeveloper(){
        m_phone = new Phone();
    }
    ~IPhoneDeveloper(){
        delete m_phone;
    }
    
    void createDisplay() override{
        m_phone->appendInfo("Created display of Apple");
    }
    void createBox() override{
        m_phone->appendInfo("Created box of Apple");
    }
    void systemInstall() override{
        m_phone->appendInfo("Installed IOS system");
    }
    
    Phone* getPhone() override{
        return m_phone;
    }
private:
    Phone* m_phone;
};

class Director{
public:
    Director(IDeveloper* developer) : m_developer(developer){}
    
    void setDeveloper(IDeveloper* developer){
        m_developer = developer;
    }
    
    Phone* MountOnlyPhone(){
        m_developer->createBox();
        m_developer->createDisplay();
        return m_developer->getPhone();
    }
    
    Phone* MountFullPhone(){
        m_developer->createBox();
        m_developer->createDisplay();
        m_developer->systemInstall();
        return m_developer->getPhone();
    }
private:
    IDeveloper* m_developer;
};

#endif // __BUILDER__HPP__