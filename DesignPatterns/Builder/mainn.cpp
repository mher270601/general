#include <iostream>
#include <memory>

class Engine{
public:
	virtual void SetPower(const size_t power) {
		m_power = power;
	}
	virtual size_t GetPower() noexcept {
		return m_power;
	}
private:
	size_t m_power{2};
};

class Wheel{
public:
	virtual void SetWheelSize(const size_t wheelSize) {
		m_wheelSize = wheelSize;
	}
	virtual size_t GetWheelSize() noexcept {
		return m_wheelSize;
	}
private:
	size_t m_wheelSize{14};
};

class Body{
public:
	virtual void SetBodySize(const size_t bodySize) {
		m_bodySize = bodySize;
	}
	virtual size_t GetBodySize() noexcept {
		return m_bodySize;
	}
private:
	size_t m_bodySize{14};
};

class Car{
public:

//private:
	Engine m_engine;
	Wheel m_wheel;
	Body m_body;
};

class Builder{
protected:
	std::unique_ptr<Car> m_car;
private:
	virtual void BuildEngine() = 0;
	virtual void BuildWheel() = 0;
	virtual void BuildBody() = 0;
	virtual std::unique_ptr<Car> getCar() = 0;
};

class MercedeW221 : public Builder{
public:
	void BuildEngine() override {
		m_car->m_engine.SetPower(6);
	}
	void BuildWheel() override {
		m_car->m_wheel.SetWheelSize(18);
	}
	void BuildBody() override {
		m_car->m_body.SetBodySize(140);
	}
	std::unique_ptr<Car> getCar() override {
		return std::move(m_car);
	}
private:

};

int main(){

	return 0;
}
