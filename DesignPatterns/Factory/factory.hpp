#ifndef __FACTORY__HPP__
#define __FACTORY__HPP__

#include <iostream>

class IProduction {
public:
	virtual void release() = 0;
};

class iPhone : public IProduction{
public:
	void release() override {
		std::cout << "New iPhone released" << std::endl;
	}
};

class Samsung : public IProduction {
public:
	void release() override {
		std::cout << "New Samsung released" << std::endl;
	}
};

class IWorkShop {
public:
	virtual IProduction* create() = 0;
};

class iPhoneWorkShop : public IWorkShop{
	IProduction* create() override {
		return new iPhone();
	}
};

class SamsungWorkShop : public IWorkShop{
	IProduction* create() override {
		return new Samsung();
	}
};

#endif // __FACTORY__HPP__
