#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class IObserver{
public:
	virtual void update(const size_t& price) = 0;
};

class IObservable{
public:
	virtual void addObserver(IObserver* observer) = 0;
	virtual void removeObserver(IObserver* observer) = 0;

	virtual void Notify() = 0;
	virtual ~IObservable(){}
};

class Product : public IObservable{
public:
	Product(const size_t& price) : m_price(price){}
	void changePrice(const size_t& price){
		m_price = price;
		Notify();
	}
	void addObserver(IObserver* observer){
		std::cout << "Observer added" << std::endl;
		m_observers.push_back(observer);
	}
	void removeObserver(IObserver* observer){
		std::cout << "removed" << std::endl;
		auto it = std::find(m_observers.begin(), m_observers.end(), observer);
		if(it != m_observers.end()){
			m_observers.erase(it);
		}
	}
	void Notify() override{
		for(const auto& observer : m_observers){
			observer->update(m_price);
		}	
	}
private:
	std::vector<IObserver*> m_observers;
	size_t m_price;
};

class WhoLesaler : public IObserver{
public:
	WhoLesaler(IObservable* obj) : m_product(obj){
		obj->addObserver(this);
	}
	void update(const size_t& price) override{
		if(price < 100){
			std::cout << "Less than 100" << std::endl;
			m_product->removeObserver(this);
		}
	}
private:
	IObservable* m_product;
};

class Buyer : public IObserver{
public:
	Buyer(IObservable* obj) : m_product(obj){
		obj->addObserver(this);
	}
	void update(const size_t& price) override{
		if(price < 500){
			std::cout << "Less than 500" << std::endl;
			m_product->removeObserver(this);
		}
	}
private:
	IObservable* m_product;
};

int main(){
	
	Product* product = new Product(400);

	WhoLesaler* wholesaler = new WhoLesaler(product);
	Buyer* buyer = new Buyer(product);

	product->changePrice(700);
	product->changePrice(50);

	return 0;
}
